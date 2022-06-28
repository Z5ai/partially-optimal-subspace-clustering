#include <iostream>
#include <vector>
#include "DataHandler.h"
#include "Algorithms.h"
#include "Settings.h"

int main() {
    // read data
    // TODO: concrete structure of graph: lookup details in Julius code
    // TODO: concrete structure of triple_costs: 3-dimensional array, lookup details Julius code
    DataHandler data_handler{};
    Graph graph = data_handler.create_graph();
    auto triple_costs = data_handler.create_triple_costs();

    // evaluate data by partial optimality criterion
    Algorithms algorithms{};
    switch(criterion){
        case edge: constraints = algorithms.evaluate_edge_criterion(graph, triple_costs);
        case triangle: constraints = algorithms.evaluate_triangle_criterion(graph, triple_costs);
    }

    // write data
    // TODO: data format for contraints
    data_handler.write_constraints(constraints);
    return 0;
}
