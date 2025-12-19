#include <gtest/gtest.h>
#include <mpi.h>

#include <algorithm>
#include <cstddef>
#include <numeric>
#include <random>
#include <vector>

#include "frolova_s_star_topology/mpi/include/ops_mpi.hpp"

namespace frolova_s_star_topology {

static std::vector<int> MakeRandomVector(size_t sz) {
  std::random_device dev;
  std::mt19937 gen(dev());
  std::vector<int> vec(sz);
  for (size_t i = 0; i < sz; i++) {
    vec[i] = static_cast<int>((gen() % 200) - 100);
  }
  return vec;
}

}  // namespace frolova_s_star_topology

TEST(frolovaSStar, pipelineRun) {
  int rank = 0;
  int size = 0;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  if (size < 3) {
    GTEST_SKIP();
    return;
  }

  const size_t data_length = 4096;
  std::vector<int> destinations(size - 1);
  std::vector<int> data((size - 1) * data_length);

  if (rank == 0) {
    std::random_device rd;
    destinations.resize(size - 1);
    std::iota(destinations.begin(), destinations.end(), 1);
    std::shuffle(destinations.begin(), destinations.end(), rd);
    data = frolova_s_star_topology::MakeRandomVector((size - 1) * data_length);
  }

  MPI_Bcast(destinations.data(), size - 1, MPI_INT, 0, MPI_COMM_WORLD);
  MPI_Bcast(data.data(), static_cast<int>((size - 1) * data_length), MPI_INT, 0, MPI_COMM_WORLD);

  if (rank != 0) {
    int dst = destinations[rank - 1];
    frolova_s_star_topology::FrolovaSStarTopologyMPI task(dst);
    ASSERT_EQ(task.ValidationImpl(), true);
    task.PreProcessingImpl();
    task.RunImpl();
    task.PostProcessingImpl();
  }
}

TEST(frolovaSStar, taskRun) {
  int rank = 0;
  int size = 0;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  if (size < 3) {
    GTEST_SKIP();
    return;
  }

  const size_t data_length = 4096;
  std::vector<int> destinations(size - 1);
  std::vector<int> data((size - 1) * data_length);

  if (rank == 0) {
    std::random_device rd;
    destinations.resize(size - 1);
    std::iota(destinations.begin(), destinations.end(), 1);
    std::shuffle(destinations.begin(), destinations.end(), rd);
    data = frolova_s_star_topology::MakeRandomVector((size - 1) * data_length);
  }

  MPI_Bcast(destinations.data(), size - 1, MPI_INT, 0, MPI_COMM_WORLD);
  MPI_Bcast(data.data(), static_cast<int>((size - 1) * data_length), MPI_INT, 0, MPI_COMM_WORLD);

  if (rank != 0) {
    int dst = destinations[rank - 1];
    frolova_s_star_topology::FrolovaSStarTopologyMPI task(dst);

    ASSERT_EQ(task.ValidationImpl(), true);
    task.PreProcessingImpl();
    task.RunImpl();
    task.PostProcessingImpl();
  }
}
