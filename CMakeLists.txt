cmake_minimum_required(VERSION 3.22)
project(partially_optimal_subspace_clustering)

set(CMAKE_CXX_STANDARD 20)

add_executable(partially_optimal_subspace_clustering src/main.cpp src/DataHandler.cpp src/DataHandler.h src/Algorithms.cpp src/Algorithms.h src/Graph.cpp src/Graph.h src/Constants.h)
