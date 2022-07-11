cmake_minimum_required(VERSION 3.22)
project(partially_optimal_subspace_clustering)

set(CMAKE_CXX_STANDARD 20)

include_directories(dependencies/doctest)
include_directories(dependencies/rapidjson)
include_directories(dependencies/fmt)

add_library(doctest INTERFACE dependencies/doctest/doctest.h tests/TriangleCutCriterion_test.cpp)
add_library(rapidjson INTERFACE dependencies/rapidjson/rapidjson.h)
add_library(fmt::fmt-header-only INTERFACE IMPORTED)


#main code
add_executable(partially_optimal_subspace_clustering src/main.cpp src/Graph/Instance.h src/Constants.h src/PersistencyCriteriaAlgorithms/PersistencyCriterion.h src/PersistencyCriteriaAlgorithms/EdgeCutCriterion.h src/PersistencyCriteriaAlgorithms/TriangleJoinCriterion.h src/Graph/Constraints.h src/PersistencyCriteriaAlgorithms/TriangleCutCriterion.h)
target_link_libraries(partially_optimal_subspace_clustering PRIVATE rapidjson PRIVATE fmt::fmt-header-only)

#tests
add_executable(EdgeCutCriterion_test tests/EdgeCutCriterion_test.cpp)
target_link_libraries(EdgeCutCriterion_test PRIVATE doctest PRIVATE rapidjson PRIVATE fmt::fmt-header-only)

add_executable(TriangleCutCriterion_test tests/TriangleCutCriterion_test.cpp)
target_link_libraries(TriangleCutCriterion_test PRIVATE doctest PRIVATE rapidjson PRIVATE fmt::fmt-header-only)

enable_testing()
add_test(NAME EdgeCutCriterion_test COMMAND $<TARGET_FILE:EdgeCutCriterion_test>)
add_test(NAME TriangleCutCriterion_test COMMAND $<TARGET_FILE:TriangleCutCriterion_test>)