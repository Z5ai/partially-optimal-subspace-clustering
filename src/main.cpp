#include <iostream>
#include <vector>
#include <unordered_map>
#include <json/json.h>
#include "DataHandler.h"
#include "Algorithms.h"
#include "Constants.h"

int main() {
    // read data
    // TODO  function InitializeTripleCosts from GreedyMoving class to generate triplecostarray
    //       function GetTripleCost from GreedyMoving class to access triplecostarray
    // TODO: concrete structure of graph: lookup details in Julius code
    // TODO: concrete structure of triple_costs: 3-dimensional array, lookup details Julius code
    DataHandler data_handler{};
    Graph graph = data_handler.create_graph();
    auto triple_costs = data_handler.create_triple_costs();

    // evaluate data by partial optimality criterion
    Algorithms algorithms{};
    std::vector<edge> cuts{};
    std::vector<edge> joins{};
    std::vector<edge> result{};
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
    return 0;
}
