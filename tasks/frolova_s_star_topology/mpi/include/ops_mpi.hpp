#pragma once

#include <vector>

#include "frolova_s_star_topology/common/include/common.hpp"
#include "task/include/task.hpp"

namespace frolova_s_star_topology {

class FrolovaSStarTopologyMPI : public BaseTask {
 public:
  static constexpr ppc::task::TypeOfTask GetStaticTypeOfTask() {
    return ppc::task::TypeOfTask::kMPI;
  }
  explicit FrolovaSStarTopologyMPI(const InType &in);

 public:
  bool ValidationImpl() override;
  bool PreProcessingImpl() override;
  bool RunImpl() override;
  bool PostProcessingImpl() override;

 private:
  std::vector<int> data_;
  std::vector<int> output_;
  int dest_;
};
}  // namespace frolova_s_star_topology
