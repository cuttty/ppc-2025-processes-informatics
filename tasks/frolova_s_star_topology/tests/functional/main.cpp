#include <gtest/gtest.h>
#include <mpi.h>

#include <cstdint>
#include <random>
#include <vector>

#include "frolova_s_star_topology/mpi/include/ops_mpi.hpp"

namespace frolova_s_star_topology {

std::vector<int> make_random_vector(size_t sz) {
  std::random_device dev;
  std::mt19937 gen(dev());
  std::vector<int> vec(sz);
  for (size_t i = 0; i < sz; i++) {
    vec[i] = gen() % 200 - 100;
  }
  return vec;
}

}  // namespace frolova_s_star_topology

TEST(frolova_s_star_topology, data_length_0) {
  const size_t DataLength = 0;
  int rank = 0;
  int size = 0;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  if (size < 3) {
    GTEST_SKIP();
    return;
  }

  std::vector<int> destinations(size - 1);
  std::vector<int> data((size - 1) * DataLength);
  std::vector<int> res(DataLength);

  if (rank == 0) {
    std::random_device rd;
    destinations.resize(size - 1);
    std::iota(destinations.begin(), destinations.end(), 1);
    std::shuffle(destinations.begin(), destinations.end(), rd);
    data = frolova_s_star_topology::make_random_vector((size - 1) * DataLength);
  }

  MPI_Bcast(destinations.data(), size - 1, MPI_INT, 0, MPI_COMM_WORLD);
  MPI_Bcast(data.data(), (size - 1) * DataLength, MPI_INT, 0, MPI_COMM_WORLD);

  if (rank != 0) {
    int dst = destinations[rank - 1];
    frolova_s_star_topology::FrolovaSStarTopologyMPI task(dst);
    ASSERT_EQ(task.validation(), true);
    task.pre_processing();
    task.run();
    task.post_processing();
  }

  int is_failed = 0;
  if (rank != 0) {
    res = data;
  }

  int failures = 0;
  MPI_Reduce(&is_failed, &failures, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
  if (rank == 0) {
    EXPECT_EQ(failures, 0);
  }
}

TEST(frolova_s_star_topology, data_length_64) {
  const size_t DataLength = 64;
  int rank = 0;
  int size = 0;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  if (size < 3) {
    GTEST_SKIP();
    return;
  }

  std::vector<int> destinations(size - 1);
  std::vector<int> data((size - 1) * DataLength);
  std::vector<int> res(DataLength);

  if (rank == 0) {
    std::random_device rd;
    destinations.resize(size - 1);
    std::iota(destinations.begin(), destinations.end(), 1);
    std::shuffle(destinations.begin(), destinations.end(), rd);
    data = frolova_s_star_topology::make_random_vector((size - 1) * DataLength);
  }

  MPI_Bcast(destinations.data(), size - 1, MPI_INT, 0, MPI_COMM_WORLD);
  MPI_Bcast(data.data(), (size - 1) * DataLength, MPI_INT, 0, MPI_COMM_WORLD);

  if (rank != 0) {
    int dst = destinations[rank - 1];
    frolova_s_star_topology::FrolovaSStarTopologyMPI task(dst);
    ASSERT_EQ(task.validation(), true);
    task.pre_processing();
    task.run();
    task.post_processing();
  }

  int is_failed = 0;
  if (rank != 0) {
    res = data;
  }

  int failures = 0;
  MPI_Reduce(&is_failed, &failures, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
  if (rank == 0) {
    EXPECT_EQ(failures, 0);
  }
}

TEST(frolova_s_star_topology, data_length_1024) {
  const size_t DataLength = 1024;
  int rank = 0;
  int size = 0;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  if (size < 3) {
    GTEST_SKIP();
    return;
  }

  std::vector<int> destinations(size - 1);
  std::vector<int> data((size - 1) * DataLength);
  std::vector<int> res(DataLength);

  if (rank == 0) {
    std::random_device rd;
    destinations.resize(size - 1);
    std::iota(destinations.begin(), destinations.end(), 1);
    std::shuffle(destinations.begin(), destinations.end(), rd);
    data = frolova_s_star_topology::make_random_vector((size - 1) * DataLength);
  }

  MPI_Bcast(destinations.data(), size - 1, MPI_INT, 0, MPI_COMM_WORLD);
  MPI_Bcast(data.data(), (size - 1) * DataLength, MPI_INT, 0, MPI_COMM_WORLD);

  if (rank != 0) {
    int dst = destinations[rank - 1];
    frolova_s_star_topology::FrolovaSStarTopologyMPI task(dst);
    ASSERT_EQ(task.validation(), true);
    task.pre_processing();
    task.run();
    task.post_processing();
  }

  int is_failed = 0;
  if (rank != 0) {
    res = data;
  }

  int failures = 0;
  MPI_Reduce(&is_failed, &failures, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
  if (rank == 0) {
    EXPECT_EQ(failures, 0);
  }
}

TEST(frolova_s_star_topology, data_length_32768) {
  const size_t DataLength = 32768;
  int rank = 0;
  int size = 0;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  if (size < 3) {
    GTEST_SKIP();
    return;
  }

  std::vector<int> destinations(size - 1);
  std::vector<int> data((size - 1) * DataLength);
  std::vector<int> res(DataLength);

  if (rank == 0) {
    std::random_device rd;
    destinations.resize(size - 1);
    std::iota(destinations.begin(), destinations.end(), 1);
    std::shuffle(destinations.begin(), destinations.end(), rd);
    data = frolova_s_star_topology::make_random_vector((size - 1) * DataLength);
  }

  MPI_Bcast(destinations.data(), size - 1, MPI_INT, 0, MPI_COMM_WORLD);
  MPI_Bcast(data.data(), (size - 1) * DataLength, MPI_INT, 0, MPI_COMM_WORLD);

  if (rank != 0) {
    int dst = destinations[rank - 1];
    frolova_s_star_topology::FrolovaSStarTopologyMPI task(dst);
    ASSERT_EQ(task.validation(), true);
    task.pre_processing();
    task.run();
    task.post_processing();
  }

  int is_failed = 0;
  if (rank != 0) {
    res = data;
  }

  int failures = 0;
  MPI_Reduce(&is_failed, &failures, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
  if (rank == 0) {
    EXPECT_EQ(failures, 0);
  }
}
