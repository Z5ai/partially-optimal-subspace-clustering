#include <iostream>
#include <vector>
#include "DataHandler.h"
#include "Algorithms.h"
#include "0_Settings.h"

int main() {
    // read data
    // TODO: concrete structure of graph: lookup details in Julius code
    // TODO: concrete structure of costtriangles: 3-dimensional array, lookup details in Julius code
    DataHandler data_handler{};
    Graph graph = data_handler.create_graph();
    auto costtriangles = data_handler.create_costtriangles();

    // evaluate data by partial optimality criterion
    Algorithms algorithms{};
    switch(criterion){
        case edge: predecided_edges = algorithms.evaluate_edge_criterion(graph, costtriangles);
        case triangle: predecided_edges = algorithms.evaluate_triangle_criterion(graph, costtriangles);
    }

    // write data
    // TODO: data format for predecided edges
    data_handler.write_predecided_edges(predecided_edges);
    return 0;
}
