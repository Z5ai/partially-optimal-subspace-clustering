#define FMT_HEADER_ONLY
#include <vector>
#include <core.h>
#include <iostream>
#include <fstream>
#include "Constants.h"
#include "Graph/TripleCosts.h"

int main() {
    // create data
    std::system(fmt::format("cd {} && go test {} -run=^TestSaveTestDataToFile$ -numberOfPlanes {} -pointsPerPlane {} -mean 0 -stddev {} -outputFile {}", go_project_path, go_script_path, n_planes, n_vertices_per_plane, stddev, synthesized_instance_path).c_str());
    std::system(fmt::format("cd {} && go test {} -run=^TestSaveCostToFile$ -inputFile {} -outputFile {} -threshold {} -amplification 3", go_project_path, go_script_path, synthesized_instance_path, triple_costs_path, 3 * stddev).c_str());
    TripleCosts triple_costs{n_vertices};



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
