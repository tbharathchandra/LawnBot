
namespace CGAL {
namespace Surface_mesh_simplification {

/*!
\ingroup PkgSurfaceMeshSimplificationRef

The class `Midpoint_placement` is a model for the `GetPlacement` concept
which  computes the placement as the midpoint position along the edge.

\tparam TriangleMesh is the type of surface mesh being simplified, and must be a model of the `MutableFaceGraph` and `HalfedgeListGraph` concepts.

\cgalModels `GetPlacement`

*/
template< typename TriangleMesh >
class Midpoint_placement {
public:

/// \name Creation
/// @{

/*!
Default constructor
*/
Midpoint_placement<TriangleMesh>();

/// @}

/// \name Operations
/// @{

/*!
Returns the <I>placement</I> (vertex position) as the midpoint between
the points of the source and target vertices
(`profile.p0()` and `profile.p1()`)
*/
template <typename Profile>
optional<typename Profile::Point>
operator()( Profile const& profile ) const;

/// @}

}; /* end Surface_mesh_simplification::Midpoint_placement */
} /* end namespace Surface_Mesh_Simplification */
} /* end namespace CGAL */
