// Copyright (c) 1997-2000  Max-Planck-Institute Saarbruecken (Germany).
// All rights reserved.
//
// This file is part of CGAL (www.cgal.org).
//
// $URL$
// $Id$
// SPDX-License-Identifier: GPL-3.0-or-later OR LicenseRef-Commercial
//
//
// Author(s)     : Michael Seel <seel@mpi-sb.mpg.de>
//---------------------------------------------------------------------
// file generated by notangle from regl_complex.lw
// please debug or modify LEDA web file
// mails and bugs: Michael.Seel@mpi-sb.mpg.de
// based on LEDA architecture by S. Naeher, C. Uhrig
// coding: K. Mehlhorn, M. Seel
// debugging and templatization: M. Seel
//---------------------------------------------------------------------

#ifndef CGAL_REGULAR_COMPLEX_D_H
#define CGAL_REGULAR_COMPLEX_D_H

#include <CGAL/license/Convex_hull_d.h>

#define CGAL_DEPRECATED_HEADER "<CGAL/Regular_complex_d.h>"
#define CGAL_DEPRECATED_MESSAGE_DETAILS \
  "The Triangulation package (see https://doc.cgal.org/latest/Triangulation) should be used instead."
#include <CGAL/internal/deprecation_warning.h>

#include <CGAL/basic.h>
#include <CGAL/Iterator_project.h>
#include <CGAL/Compact_container.h>
#include <vector>
#include <list>
#include <cstddef>

#include <CGAL/Kernel_d/debug.h>

#ifdef CGAL_USE_LEDA
#include <LEDA/system/memory.h>
#endif

namespace CGAL {

template <class R> class RC_simplex_d;
template <class R> class RC_vertex_d;
template <class R> class Regular_complex_d;
template <class R> class Convex_hull_d;

#define forall_rc_vertices(x,RC)\
for(x = (RC).vertices_begin(); x != (RC).vertices_end(); ++x)
#define forall_rc_simplices(x,RC)\
for(x = (RC).simplices_begin(); x != (RC).simplices_end(); ++x)


template <class Refs>
class RC_vertex_d

{ typedef RC_vertex_d<Refs> Self;
  typedef typename Refs::Point_d Point_d;
  typedef typename Refs::Vertex_handle Vertex_handle;
  typedef typename Refs::Simplex_handle Simplex_handle;
  typedef typename Refs::R R;
  friend class Regular_complex_d<R>;
  friend class Convex_hull_d<R>;
  friend class RC_simplex_d<Refs>;
  Simplex_handle s_;
  int            index_;
  Point_d        point_;

  void set_simplex(Simplex_handle s) { s_=s; }
  void set_index(int i) { index_=i; }
  void set_point(const Point_d& p) { point_=p; }

public:
  RC_vertex_d(Simplex_handle s, int i, const Point_d& p) :
    s_(s), index_(i), point_(p) {}
  RC_vertex_d(const Point_d& p) : point_(p), pp(nullptr) {}
  RC_vertex_d() :  s_(), pp(nullptr) {}
  // beware that ass_point was initialized here by nil_point
  ~RC_vertex_d() {}

  Simplex_handle simplex() const { return s_; }
  int index() const { return index_; }
  const Point_d& point() const { return point_; }

  void* pp;
  void*   for_compact_container() const { return pp; }
  void* & for_compact_container()       { return pp; }

#ifdef CGAL_USE_LEDA
  LEDA_MEMORY(RC_vertex_d)
#endif
};


template <class Refs>
class RC_simplex_d
{ typedef RC_simplex_d<Refs>  Self;
  typedef typename Refs::Point_d Point_d;
  typedef typename Refs::Vertex_handle Vertex_handle;
  typedef typename Refs::Simplex_handle Simplex_handle;
  typedef typename Refs::R R;
  friend class Regular_complex_d<R>;
  friend class Convex_hull_d<R>;
protected:
  std::vector<Vertex_handle>   vertices;    // array of vertices
  std::vector<Simplex_handle>  neighbors;   // opposite simplices
  std::vector<int>             opposite_vertices;
                               // indices of opposite vertices

  //------ only for convex hulls ------------------
  typedef typename R::Hyperplane_d Hyperplane_d;
  Hyperplane_d h_base;   // hyperplane supporting base facet
  bool         visited_; // visited mark when traversing
  //------ only for convex hulls ------------------

  Vertex_handle  vertex(int i) const { return vertices[i]; }
  Simplex_handle neighbor(int i) const { return neighbors[i]; }
  int opposite_vertex_index(int i) const { return opposite_vertices[i]; }

  void set_vertex(int i, Vertex_handle v) { vertices[i] = v; }
  void set_neighbor(int i, Simplex_handle s) { neighbors[i]=s; }
  void set_opposite_vertex_index(int i, int index)
  { opposite_vertices[i]=index; }

  //------ only for convex hulls ------------------
  Hyperplane_d hyperplane_of_base_facet() const { return h_base; }
  void set_hyperplane_of_base_facet(const Hyperplane_d& h) { h_base = h; }
  bool& visited() { return visited_; }
  //------ only for convex hulls ------------------

public:
  typedef typename std::vector<Vertex_handle>::const_iterator
          VIV_iterator;
  struct Point_from_VIV_iterator {
    typedef Vertex_handle argument_type;
    typedef Point_d      result_type;
    result_type& operator()(argument_type& x) const
    { return x->point(); }
    const result_type& operator()(const argument_type& x) const
    { return x->point(); }
  };

  typedef CGAL::Iterator_project<VIV_iterator,Point_from_VIV_iterator,
    const Point_d&, const Point_d*> Point_const_iterator;

  Point_const_iterator points_begin() const
  { return Point_const_iterator(vertices.begin()); }
  Point_const_iterator points_end() const
  { return Point_const_iterator(vertices.end()); }

  void* pp;
  void*   for_compact_container() const { return pp; }
  void* & for_compact_container()       { return pp; }

  #if 0
  struct Point_const_iterator {
    typedef Point_const_iterator self;
    typedef std::random_access_iterator_tag iterator_category;
    typedef const Point_d&                  value_type;
    typedef std::ptrdiff_t                  difference_type;
    typedef const Point_d*                  pointer;
    typedef const Point_d&                  reference;

    typedef typename std::vector<Vertex_handle>::const_iterator
      ra_vertex_iterator;

    Point_const_iterator() : _it() {}
    Point_const_iterator(ra_vertex_iterator it) : _it(it) {}

    value_type operator*() const { return (*_it)->point(); }
    pointer operator->() const { return &(operator*()); }

    self& operator++() { ++_it; return *this; }
    self  operator++(int) { self tmp = *this; ++_it; return tmp; }
    self& operator--() { --_it; return *this; }
    self  operator--(int) { self tmp = *this; --_it; return tmp; }

    self& operator+=(difference_type i) { _it+=i; return *this; }
    self& operator-=(difference_type i) { _it-=i; return *this; }
    self operator+(difference_type i) const
    { self tmp=*this; tmp+=i; return tmp; }
    self operator-(difference_type i) const
    { self tmp=*this; tmp-=i; return tmp; }

    difference_type operator-(self x) const { return _it-x._it; }
    reference operator[](difference_type i) { return *(*this + i); }

    bool operator==(const self& x) const { return _it==x._it; }
    bool operator!=(const self& x) const { return ! (*this==x); }
    bool operator<(self x) const { (x - *this) > 0; }

    private:
      ra_vertex_iterator _it;
  }; // Point_const_iterator

  Point_const_iterator points_begin() const
  { return Point_const_iterator(vertices.begin()); }
  Point_const_iterator points_end() const
  { return Point_const_iterator(vertices.end()); }

  #endif


  RC_simplex_d() : pp(nullptr) {}
  RC_simplex_d(int dmax) :
    vertices(dmax+1), neighbors(dmax+1), opposite_vertices(dmax+1), pp(nullptr)
  { for (int i = 0; i <= dmax; i++) {
      neighbors[i] = Simplex_handle();
      vertices[i] = Vertex_handle();
      opposite_vertices[i] = -1;
    }
    visited_ = false;
  }
  ~RC_simplex_d() {}

  void print(std::ostream& O=std::cout) const
  {
    O << "RC_simplex_d {" ;
    for(int i=0;i < int(vertices.size());++i) {
      Vertex_handle v = vertices[i];
      if ( v != Vertex_handle() ) O << v->point();
      else O << "(nil)";
    }
    O << "}";
  }

#ifdef CGAL_USE_LEDA
  LEDA_MEMORY(RC_simplex_d)
#endif

};

template <typename R>
std::ostream& operator<<(std::ostream& O, const RC_simplex_d<R>& s)
{ s.print(O); return O; }


/*{\Manpage {Regular_complex_d}{R}{Regular Simplicial Complex}{C}}*/
/*{\Mdefinition

An instance |\Mvar| of type |\Mname| is a regular abstract or concrete
simplicial complex. An abstract simplicial complex is a family |\Mvar|
of subsets of some set $V$, called the vertex set of the complex,
which is closed under the subset relation, i.e., if a set $s$ belongs
to the family then all its subsets do. A set $s$ of cardinality $k +
1$ is called a $k$-simplex and $k$ is called its dimension.  If $s$ is
a subset of $t$ then $s$ is called a subsimplex or face of $t$. A
vertex $v$ is called incident to a simplex $s$ if $v$ is an element of
$s$.  A simplex is called \emph{maximal} if it is not a face of any
simplex in |\Mvar|. Two simplices of dimension $k$ are called
neighbors if they share $k-1$ vertices. A complex is connected if its
set of maximal simplices forms a connected set under the neighboring
relation.  A simplicial complex is called \emph{regular} if all
maximal simplices in the complex have the same dimension and if the
complex is connected.

A concrete simplicial complex is an abstract simplicial complex in
which a point in some ambient space is associated with each vertex.
We use |dim| to denote the dimension of ambient space.  Simplices are
now interpreted geometrically as sets of points in ambient space,
namely as the convex hulls of (the points associated with) their
vertices. A $0$-simplex is a point, a $1$-simplex is a line segment, a
$2$-simplex is a triangle, a $3$-simplex is a tetrahedron,
etc.. \emph{The simplices is a concrete simplicial complex must
satisfy the additional conditions that the points associated with the
vertices of any simplex are affinely independet and that the
intersection of any two simplices is a face of both.} We will write
simplicial complex instead of concrete simplicial complex in the
sequel.

All maximal simplices in a regular simplicial complex have the same
dimension, which we denote |dcur|.  For each maximal
simplex\cgalFootnote{we drop the adjective maximal in the sequel} in
|\Mvar| there is an item of type |RC_simplex_d| and for each vertex
there is an item of type |rc_vertex|.  Each maximal simplex has |1+dcur|
vertices indexed from $0$ to |dcur|. For any simplex $s$ and any
index $i$, |C.vertex_of(s,i)| returns the $i$-th vertex of $s$. There
may or may not be a simplex $t$ opposite to (the vertex with index)
$i$, i.e., a maximal simplex $t$ having
\{|C.vertex_of(s,0)|,|C.vertex_of(s,1)|,\ldots,
|C.vertex_of(s,dcur)|\} - \{|C.vertex_of(s,i)|\} in its vertex
set.  The function |C.opposite(s,i)| returns $t$ if it exists and
returns |nil| otherwise. If $t$ exists then $s$ and $t$ share |dcur|
vertices, namely all but vertex $i$ of $s$ and vertex
|C.opposite_vertex(s,i)| of $t$. Assume that $t = |C.opposite(s,i)|$
exists and let |j = C.opposite_vertex(s,i)|. Then |s = C.opposite(t,j)|
and |i = C.opposite_vertex(t,j)| and
\begin{eqnarray*}
\lefteqn{\{|C.vertex_of(s,0)|,|C.vertex_of(s,1)|,\ldots,
|C.vertex_of(s,dcur)|\} - \{|C.vertex_of(s,i)|\} =} \\ & &
\{|C.vertex_of(t,0)|,|C.vertex_of(t,1)|,\ldots,|C.vertex_of(t,dcur)|\}
- \{|C.vertex_of(t,j)|\}.  \end{eqnarray*} In general, a
vertex belongs to many simplices. For an |rc_vertex| $v$,
the functions |C.simplex(v)| and |C.index(v)| return a pair $(s,i)$
such that |v = C.vertex_of(s,i)|.

The class |regl_complex| has a static member |nil_point| of type
|Point_d|. This point is different (= not indentical) from any user
defined point and is the point associated with every vertex of an
abstract simplicial complex. It simulates the use of |nil| to denote
an undefined object.

Regular complexes are designed as the base class for triangulations of
convex hulls and Delaunay triangulations in higher dimensional
space. We have not used them yet for any other purpose. Regular
complexes are built by constructing vertices and simplices, by
assigning positions to vertices and vertices to simplices, and by
establishing neighbor relations. The update operations do not check
whether the data structure built actually encodes a simplicial
complex.  The class provides a function |is_valid()| that performs a
partial check whether the data structure encodes a simplicial
complex. It is not checked whether two simplices intersect without
sharing a face.
}*/

template <class R_>
class Regular_complex_d
{
typedef Regular_complex_d<R_> Self;
public:
/*{\Mtypes 4}*/
typedef R_ R;

typedef RC_vertex_d<Self> Vertex;

  typedef CGAL::Compact_container<Vertex> Vertex_list;

typedef typename Vertex_list::iterator       Vertex_handle;
/*{\Mtypemember the handle type for vertices of the complex.}*/
typedef typename Vertex_list::const_iterator Vertex_const_handle;

typedef typename Vertex_list::iterator       Vertex_iterator;
/*{\Mtypemember the iterator type for vertices of the complex.}*/
typedef typename Vertex_list::const_iterator Vertex_const_iterator;

typedef RC_simplex_d<Self> Simplex;
typedef CGAL::Compact_container<Simplex>    Simplex_list;

typedef typename Simplex_list::iterator       Simplex_handle;
/*{\Mtypemember the handle type for simplices of the complex.}*/
typedef typename Simplex_list::const_iterator Simplex_const_handle;

typedef typename Simplex_list::iterator       Simplex_iterator;
/*{\Mtypemember the iterator type for simplices of the complex.}*/
typedef typename Simplex_list::const_iterator Simplex_const_iterator;

typedef typename R::Point_d Point_d;

protected:
  const R& Kernel_;
  int dcur; // dimension of the current complex
  int dmax; // dimension of ambient space

  Vertex_list  vertices_; // list of all vertices
  Simplex_list simplices_; // list of all simplices

/* the default copy constructor and assignment operator for class
   regl_complex work incorrectly; it is therefore good practice to
   either implement them correctly or to make them inaccessible. We do
   the latter. */

private:

  Regular_complex_d(const Regular_complex_d<R>& );
  Regular_complex_d& operator=(const Regular_complex_d<R>& );

  void clean_dynamic_memory()
  {
    vertices_.clear();
    simplices_.clear();
}

public:

/*{\Mcreation}*/

Regular_complex_d(int d = 2, const R& Kernel = R())
/*{\Mcreate creates an instance |\Mvar| of type |\Mtype|. The
dimension of the underlying space is $d$ and |\Mvar| is initialized to
the empty regular complex.  Thus |dcur| equals $-1$. The traits class
|R| specifies the models of all types and the implementations of
all geometric primitives used by the regular complex class. The
|Kernel| parameter allows you to carry fixed geometric information
into the data type. For the default kernel traits |Homogeneous_d|
the default construction of |Kernel| is enough.

In the following we use further template parameters like the point
type |Point_d=R::Point_d|.  At this point, it suffices to say that
|Point_d| represents points in $d$-space. The complete specification of
the traits class is to be found at the end of this manual page.}*/
 : Kernel_(Kernel) { dmax = d; dcur = -1; }


~Regular_complex_d() { clean_dynamic_memory(); }

/* In the destructor for |Regular_complex_d|, we have to release the
   storage which was allocated for the simplices and the vertices. */

/*{\Mtext The data type |\Mtype| offers neither copy constructor nor
          assignment operator.}*/

/*{\Moperations 3 3}*/
/*{\Mtext \headerline{Access Operations}}*/

int dimension() const { return dmax; }
/*{\Mop returns the dimension of ambient space}*/

int current_dimension() const { return dcur; }
/*{\Mop returns the current dimension of the simplices in the
complex.}*/

Vertex_handle vertex(Simplex_handle s, int i) const
/*{\Mop returns the $i$-th vertex of $s$.\\
\precond $0 \leq i \leq |current_dimension|$. }*/
{ CGAL_assertion(0<=i&&i<=dcur);
  return s->vertex(i); }

Vertex_const_handle vertex(Simplex_const_handle s, int i) const
{ CGAL_assertion(0<=i&&i<=dcur);
  return s->vertex(i); }

Point_d associated_point(Vertex_handle v) const
/*{\Mop returns the point associated with vertex |v|.}*/
{ return v->point(); }

Point_d associated_point(Vertex_const_handle v) const
{ return v->point(); }


int index(Vertex_handle v) const
/*{\Mop returns the index of $v$ in |C.simplex(v)|.}*/
{ return v->index(); }

int index(Vertex_const_handle v) const
{ return v->index(); }


Simplex_handle simplex(Vertex_handle v) const
/*{\Mop returns a simplex of which $v$ is a vertex. Note that this
simplex is not unique. }*/
{ return v->simplex(); }

Simplex_const_handle simplex(Vertex_const_handle v) const
{ return v->simplex(); }

Point_d associated_point(Simplex_handle s, int i) const
/*{\Mop same as |C.associated_point(C.vertex(s,i))|.}*/
{ return associated_point(vertex(s,i)); }

Point_d associated_point(Simplex_const_handle s, int i) const
{ return associated_point(vertex(s,i)); }

Simplex_handle opposite_simplex(Simplex_handle s,int i) const
/*{\Mop returns the simplex opposite to the $i$-th vertex of $s$
(|Simplex_handle()| is there is no such simplex).\\ \precond $0 \leq i \leq |dcur|$. }*/
{ CGAL_assertion(0<=i&&i<=dcur);
  return s->neighbor(i); }

Simplex_const_handle opposite_simplex(Simplex_const_handle s,int i) const
{ CGAL_assertion(0<=i&&i<=dcur);
  return s->neighbor(i); }

int index_of_opposite_vertex(Simplex_handle s, int i) const
{ CGAL_assertion(0<=i&&i<=dcur);
  return s->opposite_vertex_index(i); }
/*{\Mop returns the index of the vertex opposite to the $i$-th vertex
of $s$. \precond $0 \leq i \leq |dcur|$ and there is a
simplex opposite to the $i$-th vertex of $s$.}*/

int index_of_opposite_vertex(Simplex_const_handle s, int i) const
{ CGAL_assertion(0<=i&&i<=dcur);
  return s->opposite_vertex_index(i); }



/*{\Mtext \headerline{Update Operations}

We give operations that allow to update a regular complex. They have
to be used with care as they may invalidate the data structure.}*/

void clear(int d = 0)
/*{\Mop reinitializes |\Mvar| to the empty complex in dimension |dim|.}*/
{ clean_dynamic_memory();
  dmax = d; dcur = -1;
}

void set_current_dimension(int d) { dcur = d; }
/*{\Mop sets |dcur| to |d|. }*/

Simplex_handle new_simplex()
/*{\Mop adds a new simplex to |\Mvar| and returns it. The new simplex
has no vertices yet.}*/
{
  Simplex s(dmax);
  Simplex_handle  h = simplices_.insert(s);
  return h;
}

Vertex_handle  new_vertex()
/*{\Mop adds a new vertex to |\Mvar| and returns it. The new vertex
        has no associated simplex nor index yet. The associated point
        is the point |Regular_complex_d::nil_point| which is a static
        member of class |Regular_complex_d.|}*/
{
  return vertices_.emplace(nil_point);
}

Vertex_handle  new_vertex(const Point_d& p)
/*{\Mop adds a new vertex to |\Mvar| and returns it. The new vertex
        has |p| as the associated point, but is has no associated
        simplex nor index yet.}*/
{
  return vertices_.emplace(p);
}

void associate_vertex_with_simplex(Simplex_handle s, int i, Vertex_handle v)
/*{\Mop sets the $i$-th vertex of |s| to |v| and records this fact in
$v$. The latter occurs only if $v$ is non-nil.}*/
{ s -> set_vertex(i,v);
  if ( v != Vertex_handle() ) {
    v -> set_simplex(s); v -> set_index(i);
  }
}

void associate_point_with_vertex(Vertex_handle v, const Point_d& p)
/*{\Mop sets the point associated with $v$ to $p$.}*/
{ v -> set_point(p); }

void set_neighbor(Simplex_handle s, int i, Simplex_handle s1, int j)
/*{\Mop sets the neihbor opposite to vertex $i$ of |s| to |s1| and
        records vertex $j$ of |s1| as the vertex opposite to $i$.}*/
{ s  -> set_neighbor(i,s1);
  s1 -> set_neighbor(j,s);
  s  -> set_opposite_vertex_index(i,j);
  s1 -> set_opposite_vertex_index(j,i);
}

void check_topology() const;
/*{\Mop Partially checks whether |\Mvar| is an abstract simplicial
complex. This function terminates without error if each vertex is a
vertex of the simplex of which it claims to be a vertex, if the
vertices of all simplices are pairwise distinct, if the neighbor
relationship is symmetric, and if neighboring simplices share exactly
|dcur| vertices.  It returns an error message if one of these
conditions is violated.  Note that it is not checked whether simplices
that share |dcur| vertices are neighbors in the data structure.}*/

void check_topology_and_geometry() const;
/*{\Mop In addition to the above, this function checks whether all
vertices have an associated point different from
|Regular_complex_d::nil_point| and whether the points associated with the
vertices of any simplex are affinely independent. It returns an error
message otherwise.  Note that it is not checked whether the
intersection of any two simplices is a facet of both.}*/


typedef size_t Size_type;

Size_type number_of_vertices() const  { return this->vertices_.size();}
Size_type number_of_simplices() const  { return this->simplices_.size();}

void print_statistics(std::ostream& os = std::cout) const
{
  os << "Regular_complex_d - statistic" << std::endl;
  os << "number of vertices = " << number_of_vertices() << std::endl;
  os << "number of simplices = " << number_of_simplices() << std::endl;
}

/*{\Mtext \headerline{Lists and Iterators}
\setopdims{4.5cm}{3.5cm}}*/

/*{\Mtext The following operation pairs return iterator ranges in
the style of STL.}*/

Vertex_iterator vertices_begin() { return vertices_.begin(); }
/*{\Mop the first vertex of |\Mvar|.}*/
Vertex_iterator vertices_end()   { return vertices_.end(); }
/*{\Mop the beyond vertex of |\Mvar|.}*/
Simplex_iterator simplices_begin() { return simplices_.begin(); }
/*{\Mop the first simplex of |\Mvar|.}*/
Simplex_iterator simplices_end()   { return simplices_.end(); }
/*{\Mop the beyond simplex of |\Mvar|.}*/

Vertex_const_iterator vertices_begin() const { return vertices_.begin(); }
Vertex_const_iterator vertices_end()   const { return vertices_.end(); }
Simplex_const_iterator simplices_begin() const { return simplices_.begin(); }
Simplex_const_iterator simplices_end()   const { return simplices_.end(); }

std::list<Simplex_handle> all_simplices()
/*{\Mop returns the set of all maximal simplices in |\Mvar|.}*/
{ std::list<Simplex_handle> res; Simplex_iterator it;
  forall_rc_simplices(it,*this) res.push_back(it);
  return res; }

std::list<Simplex_const_handle> all_simplices() const
{ std::list<Simplex_const_handle> res; Simplex_const_iterator it;
  forall_rc_simplices(it,*this) res.push_back(it);
  return res; }

std::list<Vertex_handle> all_vertices()
/*{\Mop returns the set of all vertices in |\Mvar|.}*/
{ std::list<Vertex_handle> res; Vertex_iterator it;
  forall_rc_vertices(it,*this) res.push_back(it);
  return res; }

std::list<Vertex_const_handle> all_vertices() const
{ std::list<Vertex_const_handle> res; Vertex_const_iterator it;
  forall_rc_vertices(it,*this) res.push_back(it);
  return res; }



const R& kernel() const { return Kernel_; }
static const Point_d nil_point;

}; // Regular_complex_d<R>

// init static member:
template <class R>
const typename Regular_complex_d<R>::Point_d Regular_complex_d<R>::nil_point;


template <class R>
void Regular_complex_d<R>::check_topology() const
{
  Simplex_const_handle s,t;
  Vertex_const_handle v;
  int i,j,k;
  if (dcur == -1) {
    if (!vertices_.empty() || !simplices_.empty() )
      CGAL_error_msg(      "check_topology: dcur is -1 but there are vertices or simplices");
  }

  forall_rc_vertices(v,*this) {
    if ( v != vertex(simplex(v),index(v)) )
      CGAL_error_msg(      "check_topology: vertex-simplex relationship corrupted");
  }

  forall_rc_simplices(s,*this) {
    for(i = 0; i <= dcur; i++) {
      for (j = i + 1; j <= dcur; j++) {
        if (vertex(s,i) == vertex(s,j))
          CGAL_error_msg(          "check_topology: a simplex with two equal vertices");
      }
    }
  }

  forall_rc_simplices(s,*this) {
    for(i = 0; i <= dcur; i++) {
      if ((t = opposite_simplex(s,i)) != Simplex_const_handle()) {
        int l = index_of_opposite_vertex(s,i);
        if (s != opposite_simplex(t,l) ||
            i != index_of_opposite_vertex(t,l))
          CGAL_error_msg(          "check_topology: neighbor relation is not symmetric");

        for (j = 0; j <= dcur; j++) {
          if (j != i) {
            // j must also occur as a vertex of t
            for (k = 0; k <= dcur &&
                   ( vertex(s,j) != vertex(t,k) || k == l); k++) {}
            if (k > dcur)
              CGAL_error_msg(              "check_topology: too few shared vertices.");
          }
        }
      }
    }
  }
}

template <class R>
void Regular_complex_d<R>::check_topology_and_geometry() const
{
  check_topology();
  Vertex_const_handle v;
  forall_rc_vertices(v,*this) {
    if ( v == Vertex_const_handle() ||
         associated_point(v).identical(Regular_complex_d<R>::nil_point) )
      CGAL_error_msg("check_topology_and_geometry: \
      vertex with nil_point or no associated point.");
  }

  typename R::Affinely_independent_d affinely_independent =
    kernel().affinely_independent_d_object();
  Simplex_const_handle s;
  forall_rc_simplices(s,*this) {
    std::vector<Point_d> A(dcur + 1);
    for (int i = 0; i <= dcur; i++)
      A[i] = associated_point(s,i);
    if ( !affinely_independent(A.begin(),A.end()) )
      CGAL_error_msg("check_topology_and_geometry: \
      corners of some simplex are not affinely independent");
  }
}


/*{\Mtext
\headerline{Iteration Statements}

{\bf forall\_rc\_simplices}($s,C$)
$\{$ ``the simplices of $C$ are successively assigned to $s$'' $\}$

{\bf forall\_rc\_vertices}($v,C$)
$\{$ ``the vertices of $C$ are successively assigned to $v$'' $\}$

}*/

/*{\Mimplementation Each simplex stores its vertices, the adjacent
simplices, and the opposite vertices in arrays. The space requirement
for a simplex is $3 * |dim| * 4$ Bytes for the contents of the arrays
plus the actual space for the points plus the constant space overhead
for the arrays (see the manual pages for arrays).

The class |Regular_complex_d| needs constant space plus space for a list of
simplices (which is about 12 bytes per simplex). The total space
requirement is therefore about $12(|dim| + 2)$ bytes times the number
of simplices.  }*/



} //namespace CGAL
#endif // CGAL_REGULAR_COMPLEX_D_H
