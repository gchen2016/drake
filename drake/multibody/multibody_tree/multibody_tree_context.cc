#include "drake/multibody/multibody_tree/multibody_tree_context.h"

#include "drake/common/eigen_autodiff_types.h"

namespace drake {
namespace multibody {

// Explicitly instantiates on the most common scalar types.
template class MultibodyTreeContext<double>;
template class MultibodyTreeContext<AutoDiffXd>;

}  // namespace multibody
}  // namespace drake
