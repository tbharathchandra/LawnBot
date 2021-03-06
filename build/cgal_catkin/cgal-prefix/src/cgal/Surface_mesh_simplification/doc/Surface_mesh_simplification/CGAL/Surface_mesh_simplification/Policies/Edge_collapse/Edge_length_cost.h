
namespace CGAL {
namespace Surface_mesh_simplification {

/*!
\ingroup PkgSurfaceMeshSimplificationRef

The class `Edge_length_cost` is a model for the `GetCost` concept,
which computes the collapse cost as the squared length of the edge.

\tparam TriangleMesh is the type of surface mesh being simplified, and must be a model of the `MutableFaceGraph` and `HalfedgeListGraph` concepts.


\cgalModels `GetCost`

*/
template< typename TriangleMesh >
class Edge_length_cost {
public:

/// \name Creation
/// @{

/*!
Default constructor
*/
Edge_length_cost<TriangleMesh>();

/// @}

/// \name Operations
/// @{

/*!
Returns the <I>collapse cost</I> as the squared distance between the points
of the source and target vertices (that is, `profile.p0()` and `profile.p1()`.

The `placement` argument is ignored.

*/
template <typename Profile, typename T>
optional<typename Profile::FT> operator()( Profile const& profile
, T const& placement ) const;

/// @}

}; /* end Surface_mesh_simplification::Edge_length_cost */
} /* namespace Surface_mesh_simplification */
} /* end namespace CGAL */
