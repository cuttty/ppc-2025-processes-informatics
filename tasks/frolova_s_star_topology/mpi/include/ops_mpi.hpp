#pragma once

#include <mpi.h>

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

 private:
  bool ValidationImpl() override;
  bool PreProcessingImpl() override;
  bool RunImpl() override;
  bool PostProcessingImpl() override;
  std::vector<int> data;
  std::vector<int> output;
  int dest;
};

}  // namespace frolova_s_star_topology
