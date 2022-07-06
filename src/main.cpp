#define FMT_HEADER_ONLY
#include <vector>
#include <core.h>
#include <iostream>
#include <fstream>
#include "Constants.h"
#include "Graph/TripleCosts.h"
#include "PersistencyCriteriaAlgorithms/EdgeCriterionCut.h"
#include "Graph/Constraints.h"

int main() {

    // create data
    std::system(fmt::format("cd {} && go test {} -run=^TestSaveTestDataToFile$ -numberOfPlanes {} -pointsPerPlane {} -mean 0 -stddev {} -outputFile {}", go_project_path, go_script_path, n_planes, n_vertices_per_plane, stddev, synthesized_instance_path).c_str());
    std::system(fmt::format("cd {} && go test {} -run=^TestSaveCostToFile$ -inputFile {} -outputFile {} -threshold {} -amplification 3", go_project_path, go_script_path, synthesized_instance_path, triple_costs_path, 3 * stddev).c_str());
    TripleCosts triple_costs{n_vertices};
    Constraints constraints{};

    // evaluate data by partial optimality criterion
    if(edge_criterion_cut==true){
        EdgeCriterionCut edge_criterion_cut{triple_costs, constraints};
        edge_criterion_cut.iterate_all_U(edge_criterion_cut_U_max_size);
    }
    if(edge_criterion_join==true){

    }
    if(triangle_criterion==true){

    }

    // write data
    constraints.write_to_json();

    return 0;
}
