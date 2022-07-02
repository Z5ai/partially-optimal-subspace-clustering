#include <vector>
#include <iostream>
#include "Constants.h"
#include "DataHandler.h"


int main() {
    // TODO: restructuring: put local-search-algorithm project into dependencies folder. make partial-optimal subspace-clustering to main project. call go script here in main function.

    // read data
    //  function GetTripleCost from GreedyMoving class, line 45 to access triplecostarray
    DataHandler data_handler{};
    std::vector<vertex_type> vertices {data_handler.create_vertices()};
    triple_costs_type triple_costs = data_handler.create_triple_costs(vertices.size());

    /*
    // evaluate data by partial optimality criterion
    Algorithms algorithms{};
    std::vector<edge_type> cuts{};
    std::vector<edge_type> joins{};
    std::vector<edge_type> result{};
    if(edge_criterion_cut==true){
        result = algorithms.evaluate_edge_criterion_cut(graph, triple_costs);
        cuts.insert(cuts.end(), result.begin(), result.end());
    }
    if(edge_criterion_join==true){
        result = algorithms.evaluate_edge_criterion_join(graph, triple_costs);
        joins.insert(joins.end(), result.begin(), result.end());
    }
    if(triangle_criterion==true){
        result = algorithms.evaluate_triangle_criterion(graph, triple_costs);
        joins.insert(joins.end(), result.begin(), result.end());
    }

    // write data
    // map -> json
    data_handler.write_constraints(cuts, joins);
     */
    return 0;
}
