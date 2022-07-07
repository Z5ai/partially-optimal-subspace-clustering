#define FMT_HEADER_ONLY
#include <vector>
#include <core.h>
#include "Constants.h"
#include "Graph/Triples.h"
#include "PersistencyCriteriaAlgorithms/EdgeCriterionCut.h"
#include "Graph/Constraints.h"

int main() {

    // create data
    std::system(fmt::format("cd {} && go test {} -run=^TestSaveTestDataToFile$ -numberOfPlanes {} -pointsPerPlane {} -mean 0 -stddev {} -outputFile {}", go_project_path, go_script_path, n_planes, n_vertices_per_plane, stddev, synthesized_instance_path).c_str());
    std::system(fmt::format("cd {} && go test {} -run=^TestSaveCostToFile$ -inputFile {} -outputFile {} -threshold {} -amplification 3", go_project_path, go_script_path, synthesized_instance_path, triple_costs_path, threshold).c_str());
    Triples triple_costs{};
    Constraints constraints{};

    // evaluate data by partial optimality criterion
    if(edge_criterion_cut==true){
        EdgeCriterionCut edge_criterion_cut{triple_costs, constraints};
        //TODO: stddev 0.001 threshold_factor 0.03 (the higher boths values, the less cuts are found)
        // 450 vertices: no cuts found       99 vertices: 98 cuts found => 1 outlier
        edge_criterion_cut.evaluate_U_size_1();
        //edge_criterion_cut.evaluate_U_size_2();
    }
    if(edge_criterion_join==true){

    }
    if(triangle_criterion==true){

    }

    // write data
    constraints.write_to_json();
    return 0;
}
