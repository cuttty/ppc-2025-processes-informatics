#pragma once

#include "frolova_s_star_topology/common/include/common.hpp"
#include "task/include/task.hpp"

namespace frolova_s_star_topology {

class FrolovaSStarTopologySEQ : public BaseTask {
 public:
  static constexpr ppc::task::TypeOfTask GetStaticTypeOfTask() {
    return ppc::task::TypeOfTask::kSEQ;
  }
  explicit FrolovaSStarTopologySEQ(const InType &in);

 private:
  bool ValidationImpl() override;
  bool PreProcessingImpl() override;
  bool RunImpl() override;
  bool PostProcessingImpl() override;
};

}  // namespace frolova_s_star_topology
