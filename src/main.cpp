#include <vector>
#include <iostream>
#include "Constants.h"
#include "TripleCosts.h"


int main() {
    // TODO: restructuring: put local-search-algorithm project into dependencies folder. make partial-optimal subspace-clustering to main project. call go script here in main function.
    // TODO: erase this and use later instead of vertices.size() a new parameter n_plane, n_vertices_per_plane, n_vertices = n_vertices_per_plane * n_plane which is also used for call of go script
    // TODO: make own class for triple_costs
    // TODO: write tests
    // read data
    //  function GetTripleCost from GreedyMoving class, line 45 to access triplecostarray
    TripleCosts triple_costs{n_vertices};
    float cost = triple_costs.get_triple_cost(4, 3, 5);



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
    trip.write_constraints(cuts, joins);
     */
    return 0;
}
