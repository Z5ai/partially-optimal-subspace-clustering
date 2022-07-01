#include <iostream>
#include <vector>
#include <unordered_map>
#include "document.h"
#include "writer.h"
#include "stringbuffer.h"
#include "DataHandler.h"
#include "Algorithms.h"
#include "Constants.h"

int main() {
    // read data
    // TODO: concrete structure of triple_costs: 3-dimensional array, lookup details Julius code
    //  function InitializeTripleCosts from GreedyMoving class, line 348 to generate triplecostarray
    //  function GetTripleCost from GreedyMoving class, line 45 to access triplecostarray
    // std::array 1.000.000 int       built-in array 1.000.000.000     =>  use std::vector as this can use maximum amount of RAM
    // TODO: concrete structure of graph: lookup details in Julius code











//    DataHandler data_handler{};
//    std::vector<vertex_type> vertices {data_handler.create_vertices()};
//    triple_costs_type triple_costs = data_handler.create_triple_costs(vertices.size());  // how?: parse triple_costs.json

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
