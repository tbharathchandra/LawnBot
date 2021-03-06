
namespace CGAL {
namespace Surface_mesh_simplification {
/*!
\ingroup PkgSurfaceMeshSimplificationRef

The class `LindstromTurk_cost` provides a model for the `GetCost` concept.
It computes the collapse cost following the Lindstrom-Turk strategy
(Section \ref SurfaceMeshSimplificationLindstromTurkStrategy)

\tparam TriangleMesh is the type of surface mesh being simplified, and must be a model of the `MutableFaceGraph` and `HalfedgeListGraph` concepts.

\cgalModels `GetCost`

\sa `CGAL::Surface_mesh_simplification::LindstromTurk_placement<TriangleMesh>`

*/
template< typename TriangleMesh >
class LindstromTurk_cost {
public:

/// \name Creation
/// @{

/*!
Initializes the policy with the given <I>weighting unit factor</I>.
See \ref SurfaceMeshSimplificationLindstromTurkStrategy for details on the meaning of this factor.
*/
LindstromTurk_cost<TriangleMesh>( FT const& factor = FT(0.5) );

/// @}

/// \name Operations
/// @{

/*!
Returns the cost of collapsing the edge (represented by its profile) considering
the new `placement` computed for it.
*/
template <typename Profile>
optional<typename Profile::FT>
operator()( Profile const& profile
            , boost::optional<typename Profile::Point> const& placement ) const;

/// @}

}; /* end Surface_mesh_simplification::LindstromTurk_cost */
} /* namespace Surface_mesh_simplification */
} /* end namespace CGAL */
