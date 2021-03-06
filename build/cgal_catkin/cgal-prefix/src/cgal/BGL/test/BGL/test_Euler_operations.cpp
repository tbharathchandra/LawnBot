
#include "test_Prefix.h"
#include <boost/range/distance.hpp>
#include <CGAL/boost/graph/Euler_operations.h>
#include <CGAL/boost/graph/copy_face_graph.h>

template <typename T>
void
test_copy_face_graph_nm_umbrella()
{
  CGAL_GRAPH_TRAITS_MEMBERS(T);

  T g;
  Kernel::Point_3 p;

  CGAL::make_tetrahedron(p, p, p, p, g);
  CGAL::make_tetrahedron(p, p, p, p, g);

  std::vector<vertex_descriptor> verts(vertices(g).begin(), vertices(g).end());

  //merge verts[0] and verts[4]
  for (halfedge_descriptor h : CGAL::halfedges_around_target(verts[4], g))
    set_target(h, verts[0], g);
  remove_vertex(verts[4], g);

  T g_copy;
  CGAL::copy_face_graph(g, g_copy);

  for (halfedge_descriptor h : halfedges(g_copy))
  {
    assert( target(h, g_copy) != Traits::null_vertex() );
  }
}

template <typename T>
void
join_face_test()
{
  CGAL_GRAPH_TRAITS_MEMBERS(T);

  Surface_fixture_1<T> f;

  bool found;
  halfedge_descriptor e;
  boost::tie(e, found) = halfedge(f.w, f.v, f.m);
  assert(found);
  // manually set the halfedge of f.f1 to the edge that is to be
  // removed to provoke a special case
  set_halfedge(f.f1, e, f.m);
  CGAL::Euler::join_face(e,f.m);

  assert(CGAL::internal::exact_num_faces(f.m) == 2);
  assert(CGAL::internal::exact_num_edges(f.m) == 6);

  CGAL::Halfedge_around_face_iterator<T> begin, end;
  boost::tie(begin, end) = CGAL::halfedges_around_face(halfedge(f.f1, f.m), f.m);
  assert(std::distance(begin, end) == 4);
  for(; begin != end; ++begin)
  {

    halfedge_descriptor hd = *begin;
    assert(face(hd, f.m) == f.f1);

  }

  face_iterator fit, fend;
  for(boost::tie(fit, fend) = faces(f.m); fit != fend; ++fit) {
    assert(*fit == f.f1 || *fit == f.f3);
  }

  assert(degree(f.w, f.m) == 2);
  assert(degree(f.v, f.m) == 3);
  assert(CGAL::is_valid_polygon_mesh(f.m));

}



template <typename T>
void
remove_face_test_1()
{
  CGAL_GRAPH_TRAITS_MEMBERS(T);
  Surface_fixture_1<T> f;

  // find the edge between x and y
  bool found;
  halfedge_descriptor e;
  boost::tie(e, found) = halfedge(f.x, f.y, f.m);
  assert(found);
  assert(face(e, f.m) == f.f3);

  CGAL::Euler::remove_face(e,f.m);

  assert(CGAL::is_valid_polygon_mesh(f.m));

  assert_EQUAL(degree(f.v, f.m) == 3);
  assert_EQUAL(degree(f.x, f.m) == 2);
  assert_EQUAL(CGAL::internal::exact_num_faces(f.m) == 2);
  assert_EQUAL(CGAL::internal::exact_num_edges(f.m) == 5);
  assert_EQUAL(CGAL::internal::exact_num_vertices(f.m) == 4);
  halfedge_iterator eb, ee;
  int count = 0;
  for(boost::tie(eb, ee) = halfedges(f.m); eb != ee; ++eb) {
    if(face(*eb,f.m) == boost::graph_traits<T>::null_face())
      ++count;
  }
  assert(count == 4);
}



template <typename T>
void
remove_face_test_2()
{
  CGAL_GRAPH_TRAITS_MEMBERS(T);

  Surface_fixture_2<T> f;

  // find the edge between x and v
  bool found;
  halfedge_descriptor e;

  boost::tie(e, found) = halfedge(f.x, f.w, f.m);
  assert(found);
  boost::tie(e, found) = halfedge(f.x, f.v, f.m);
  assert(found);
  assert(face(e, f.m) == f.f1);
  CGAL::Euler::remove_face(e,f.m);
  assert(CGAL::is_valid_polygon_mesh(f.m));

  assert(CGAL::internal::exact_num_faces(f.m) == 3);
  assert(CGAL::internal::exact_num_edges(f.m) == 7);
  assert(CGAL::internal::exact_num_vertices(f.m) == 5);

  boost::tie(e, found) = halfedge(f.x, f.w, f.m);
  assert(found);
  assert(face(e,f.m) == boost::graph_traits<T>::null_face());

  // check the boundary

  halfedge_descriptor n = next(e, f.m);
  while(n != e) {
    assert(face(n,f.m) == boost::graph_traits<T>::null_face() );
    n = next(n, f.m);
  }
}

template <typename T>
void
add_face_to_border_test()
{
  CGAL_GRAPH_TRAITS_MEMBERS(T);

  Surface_fixture_5<T> f;

  CGAL::Euler::add_face_to_border(f.h1, f.h2, f.m);

  assert(CGAL::is_valid_polygon_mesh(f.m));

}

template <typename T>
void
add_vertex_and_face_to_border_test()
{
  CGAL_GRAPH_TRAITS_MEMBERS(T);

  Surface_fixture_5<T> f;
  typedef typename boost::graph_traits<T>::halfedge_descriptor  halfedge_descriptor;
  halfedge_descriptor h1 = f.h1, h2 = f.h2;
  const T& m = f.m;

  int dist=0;
  halfedge_descriptor hd = h1;
  while(hd != h2){
    ++dist;
    hd = next(hd,m);
  }
  assert(dist == 2);

  int blength = 0;
  for(halfedge_descriptor hd : CGAL::halfedges_around_face(h1,m)){
    CGAL_USE(hd);
    blength++;
  }

  halfedge_descriptor res = CGAL::Euler::add_vertex_and_face_to_border(f.h1, f.h2, f.m);
  assert(CGAL::is_valid_polygon_mesh(f.m));

  assert(! CGAL::is_border(res,m));
  assert(CGAL::is_border(opposite(res,m),m));
  res = opposite(res,m);
  for(halfedge_descriptor hd : CGAL::halfedges_around_face(res,m)){
    CGAL_USE(hd);
    blength--;
  }
  assert(blength == 0);

}


template <typename T>
void
join_vertex_interior_test()
{
  CGAL_GRAPH_TRAITS_MEMBERS(T);

  Surface_fixture_3<T> f;
  halfedge_descriptor e;

  bool found;
  boost::tie(e, found) = halfedge(f.w, f.x, f.m);
  assert(found);
  CGAL::Euler::join_vertex(e,f.m);
  assert(CGAL::internal::exact_num_faces(f.m) == 2);
  assert(CGAL::internal::exact_num_vertices(f.m) == 5);
  assert(CGAL::internal::exact_num_edges(f.m) == 6);
  assert(boost::distance(CGAL::halfedges_around_face(halfedge(f.f1, f.m), f.m)) == 3);
  assert(boost::distance(CGAL::halfedges_around_face(halfedge(f.f2, f.m), f.m)) == 3);
  assert(degree(f.x, f.m) == 4);
  assert(CGAL::is_valid_polygon_mesh(f.m));
}

template <typename T>
void
join_vertex_exterior_test()
{
  CGAL_GRAPH_TRAITS_MEMBERS(T);

  {
    // exterior edge is collapsed
    Surface_fixture_3<T> f;
    halfedge_descriptor e;
    bool found;
    boost::tie(e, found) = halfedge(f.w, f.y, f.m);
    assert(source(e,f.m) == f.w);
    assert(target(e,f.m) == f.y);
    assert(found);
    CGAL::Euler::join_vertex(e,f.m);
    assert(CGAL::internal::exact_num_faces(f.m) == 2);
    assert(CGAL::internal::exact_num_vertices(f.m) == 5);
    assert(CGAL::internal::exact_num_edges(f.m) == 6);
    assert(boost::distance(CGAL::halfedges_around_face(halfedge(f.f1, f.m), f.m)) == 4);
    assert(boost::distance(CGAL::halfedges_around_face(halfedge(f.f2, f.m), f.m)) == 3);
    assert(degree(f.y, f.m) == 3);
    assert(CGAL::is_valid_polygon_mesh(f.m));
  }

  {
    Surface_fixture_3<T> f;
    halfedge_descriptor e;
    bool found;
    boost::tie(e, found) = halfedge(f.y, f.w, f.m);

    assert(source(e,f.m) == f.y);
    assert(target(e,f.m) == f.w);
    assert(found);
    CGAL::Euler::join_vertex(e,f.m);
    assert(CGAL::internal::exact_num_faces(f.m) == 2);
    assert(CGAL::internal::exact_num_vertices(f.m) == 5);
    assert(CGAL::internal::exact_num_edges(f.m) == 6);
    assert(boost::distance(CGAL::halfedges_around_face(halfedge(f.f1, f.m), f.m)) == 4);
    assert(boost::distance(CGAL::halfedges_around_face(halfedge(f.f2, f.m), f.m)) == 3);

    assert(CGAL::is_valid_polygon_mesh(f.m));
    assert(degree(f.w, f.m) == 3);

  }
}


template <typename T>
void
split_vertex()
{
  CGAL_GRAPH_TRAITS_MEMBERS(T);

  Surface_fixture_3<T> f;
  halfedge_descriptor h1, h2;
  bool found;
  boost::tie(h1, found) = halfedge(f.w, f.y, f.m);
  assert(found);
  boost::tie(h2, found) = halfedge(f.z, f.y, f.m);
  assert(found);
  assert(face(h2, f.m) == Traits::null_face());

  // split border vertex y
  CGAL::Euler::split_vertex(h1, h2,f.m);
  assert(CGAL::is_valid_polygon_mesh(f.m));
  assert(CGAL::internal::exact_num_vertices(f.m) == 7);
  assert(CGAL::internal::exact_num_edges(f.m) == 8);
  assert(boost::distance(CGAL::halfedges_around_face(h1, f.m)) == 5);
  assert(boost::distance(CGAL::halfedges_around_face(h2, f.m)) == 7);
}

template <typename T>
void
split_join_vertex_inverse()
{
  CGAL_GRAPH_TRAITS_MEMBERS(T);
  Surface_fixture_3<T> f;
  halfedge_descriptor h, h1, h2;
  bool found;
  boost::tie(h, found) = halfedge(f.w, f.x, f.m);
  assert(found);
  CGAL::Euler::join_vertex(h,f.m);
  assert(CGAL::is_valid_polygon_mesh(f.m));
  boost::tie(h1, found) = halfedge(f.z, f.x, f.m);
  assert(found);
  boost::tie(h2, found) = halfedge(f.v, f.x, f.m);
  assert(found);
  CGAL::Euler::join_vertex(CGAL::Euler::split_vertex(h1, h2,f.m),f.m);
  assert(CGAL::is_valid_polygon_mesh(f.m));

  assert(CGAL::internal::exact_num_vertices(f.m)== 5);
  assert(CGAL::internal::exact_num_faces(f.m) == 2);
  assert(CGAL::internal::exact_num_edges(f.m) == 6);
  assert(CGAL::internal::exact_num_halfedges(f.m) == 12);
  assert(boost::distance(CGAL::halfedges_around_face(h1, f.m)) == 3);
  assert(boost::distance(CGAL::halfedges_around_face(h2, f.m)) == 3);
}


template <typename T>
void
join_loop_test()
{
  CGAL_GRAPH_TRAITS_MEMBERS(T);
  Surface_fixture_4<T> f;

  CGAL::Euler::join_loop(f.h1, f.h2, f.m);

  assert(CGAL::is_valid_polygon_mesh(f.m));
}

template <typename T>
void
split_loop_test()
{
  CGAL_GRAPH_TRAITS_MEMBERS(T);
  Surface_fixture_8<T> f;

  CGAL::Euler::split_loop(f.h1, f.h2, f.h3, f.m);
  assert(CGAL::internal::exact_num_vertices(f.m) == 8);
  assert(CGAL::internal::exact_num_faces(f.m) == 8);
  assert(CGAL::internal::exact_num_halfedges(f.m) == 24);
  assert(CGAL::is_valid_polygon_mesh(f.m));
}

template <typename T>
void
split_face_test()
{
 Surface_fixture_6<T> f;
 CGAL::Euler::split_face(f.h1, f.h2,f.m);
 assert(num_vertices(f.m) == 4);
 assert(num_faces(f.m) == 2);
 assert(num_halfedges(f.m) == 10);
}

template <typename T>
void
 make_hole_test()
{
 Surface_fixture_7<T> f;
 std::size_t nv = num_vertices(f.m);
 std::size_t nf = num_faces(f.m);
 std::size_t nh = num_halfedges(f.m);

 CGAL::Euler::make_hole(f.h, f.m);

 assert(CGAL::internal::exact_num_vertices(f.m) == nv);
 assert(CGAL::internal::exact_num_faces(f.m) == nf-1 );
 assert(CGAL::internal::exact_num_halfedges(f.m) == nh);
}

template <typename T>
void
remove_center_vertex_test()
{
 Surface_fixture_7<T> f;
 std::size_t nv = num_vertices(f.m);
 std::size_t nf = num_faces(f.m);
 std::size_t nh = num_halfedges(f.m);

 typename boost::graph_traits<T>::degree_size_type deg = degree(target(f.h,f.m),f.m);
 CGAL::Euler::remove_center_vertex(f.h,f.m);

 assert(CGAL::internal::exact_num_vertices(f.m) == nv-1);
 assert(CGAL::internal::exact_num_faces(f.m) == (nf-deg)+1);
 assert(CGAL::internal::exact_num_halfedges(f.m) == nh-(2*deg));
}

template <typename T>
void
join_split_inverse()
{

}

template <typename T>
void
does_satisfy_link_condition()
{
  Surface_fixture_7<T> f;

  assert(CGAL::Euler::does_satisfy_link_condition(*edges(f.m).first,f.m));
}

template <typename Graph>
void
test_swap_edges()
{
  typedef typename boost::graph_traits<Graph>::halfedge_descriptor halfedge_descriptor;
  std::size_t nbh=12;
  Kernel::Point_3 pt(0,0,0);
  // test all possible pairs of halfedges
  for (std::size_t i=0; i<nbh-1; ++i)
  {
    for(std::size_t j=i+1; j<nbh; ++j)
    {
      Graph g;
      CGAL::make_tetrahedron(pt,pt,pt,pt,g);
      halfedge_descriptor h1 = *std::next(boost::begin(halfedges(g)), i);
      halfedge_descriptor h2 = *std::next(boost::begin(halfedges(g)), j);
      CGAL::internal::swap_edges(h1, h2, g);
      CGAL_assertion(CGAL::is_valid_polygon_mesh(g));
    }
  }
}

template <typename T>
void
add_face_bug()
{
  typedef boost::graph_traits<T> GT;
  typedef typename GT::vertex_descriptor vertex_descriptor;
  typedef typename GT::halfedge_descriptor halfedge_descriptor;

  T g;

  std::vector<vertex_descriptor> vs;
  vs.push_back( add_vertex(g) ); // Kernel::Point_3(0,1,0)
  vs.push_back( add_vertex(g) ); // Kernel::Point_3(4,1,0)
  vs.push_back( add_vertex(g) ); // Kernel::Point_3(5,2,0)
  vs.push_back( add_vertex(g) ); // Kernel::Point_3(4,0,0)

  CGAL::Euler::add_face(CGAL::make_array(vs[0], vs[1], vs[2]), g);
  CGAL::Euler::add_face(CGAL::make_array(vs[1], vs[3], vs[2]), g);

  // force vertex halfedge to not be a border halfedge
  for(vertex_descriptor v : vertices(g))
  {
    halfedge_descriptor h = halfedge(v, g);
    if ( CGAL::is_border(h, g) )
      set_halfedge(v, prev(opposite(h, g), g), g);
    assert(target(halfedge(v, g), g)==v);
  }

  vs.push_back( add_vertex(g) ); // Kernel::Point_3(0,0,0)
  vs.push_back( add_vertex(g) );  // Kernel::Point_3(1,0,0)
  CGAL::Euler::add_face(CGAL::make_array(vs[4],vs[5],vs[0]), g);

  vs.push_back( add_vertex(g) ); // Kernel::Point_3(2,0,0)
  vs.push_back( add_vertex(g) ); // Kernel::Point_3(3,0,0)
  CGAL::Euler::add_face(CGAL::make_array(vs[6],vs[7],vs[1]), g);
  CGAL::Euler::add_face(CGAL::make_array(vs[7],vs[3],vs[1]), g);
}

template <typename Graph>
void
test_Euler_operations()
{
  test_copy_face_graph_nm_umbrella<Graph>();
  join_face_test<Graph>();
  add_vertex_and_face_to_border_test<Graph>();
  add_face_to_border_test<Graph>();
  join_vertex_interior_test<Graph>();
  join_vertex_exterior_test<Graph>();
  split_vertex<Graph>();
  split_join_vertex_inverse<Graph>();
  join_loop_test<Graph>();
  split_loop_test<Graph>();
  split_face_test<Graph>();
  make_hole_test<Graph>();
  remove_center_vertex_test<Graph>();
  join_split_inverse<Graph>();
  does_satisfy_link_condition<Graph>();
  test_swap_edges<Graph>();
  add_face_bug<Graph>();
}

int main()
{
  test_Euler_operations<Polyhedron>();
  test_Euler_operations<SM>();
  test_Euler_operations<LCC>();

#ifdef CGAL_USE_OPENMESH
  test_Euler_operations<OMesh>();
#endif

  std::cerr << "done\n";
  return 0;
}
