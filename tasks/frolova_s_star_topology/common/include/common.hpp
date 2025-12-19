#pragma once

#include <string>
#include <tuple>

#include "task/include/task.hpp"

namespace frolova_s_star_topology {

using InType = int;
using OutType = int;
using TestType = std::tuple<int, std::string>;
using BaseTask = ppc::task::Task<InType, OutType>;

}  // namespace frolova_s_star_topology
