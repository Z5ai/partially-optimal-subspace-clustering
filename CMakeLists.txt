cmake_minimum_required(VERSION 3.22)
project(partially_optimal_subspace_clustering)

set(CMAKE_CXX_STANDARD 20)

include_directories(dependencies/rapidjson)
include_directories(dependencies/doctest)
include_directories(dependencies/fmt)

add_library(rapidjson INTERFACE dependencies/rapidjson/rapidjson.h)
add_library(doctest INTERFACE dependencies/doctest/doctest.h)
add_library(fmt::fmt-header-only INTERFACE IMPORTED)

add_executable(partially_optimal_subspace_clustering src/main.cpp src/Graph/TripleCosts.h src/Constants.h src/PersistencyCriteriaAlgorithms/PersistencyCriterion.h src/PersistencyCriteriaAlgorithms/EdgeCriterionCut.h src/PersistencyCriteriaAlgorithms/EdgeCriterionJoin.h src/PersistencyCriteriaAlgorithms/TriangleCriterion.h src/Graph/Constraints.h)
target_link_libraries(partially_optimal_subspace_clustering PRIVATE rapidjson PRIVATE fmt::fmt-header-only)