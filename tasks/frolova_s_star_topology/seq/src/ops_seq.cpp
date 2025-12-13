#include "frolova_s_star_topology/seq/include/ops_seq.hpp"

#include <vector>

#include "frolova_s_star_topology/common/include/common.hpp"

namespace frolova_s_star_topology {

FrolovaSStarTopologySEQ::FrolovaSStarTopologySEQ(const InType &in) {
  SetTypeOfTask(GetStaticTypeOfTask());
  GetInput() = in;
  GetOutput() = 0;
}

bool FrolovaSStarTopologySEQ::ValidationImpl() {
  return true;
}

bool FrolovaSStarTopologySEQ::PreProcessingImpl() {
  return true;
}

bool FrolovaSStarTopologySEQ::RunImpl() {
  const int size = 1e7;

  std::vector<int> tmp;
  tmp.reserve(size);

  for (int i = 0; i < size; i++) {
    tmp.push_back(i);
  }

  GetOutput() = static_cast<int>(tmp.size());

  return true;
}

bool FrolovaSStarTopologySEQ::PostProcessingImpl() {
  return true;
}

}  // namespace frolova_s_star_topology
