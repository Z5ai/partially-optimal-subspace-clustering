#define FMT_HEADER_ONLY
#include <vector>
#include <core.h>
#include "Constants.h"
#include "Graph/Triples.h"
#include "PersistencyCriteriaAlgorithms/EdgeCriterionCut.h"
#include "Graph/Constraints.h"
#include "PersistencyCriteriaAlgorithms/TriangleCriterion.h"

//TODO tests: only nodelabels. costs positive or negative.    number of cuts must be okay
//TODO implementation: edge_cut criterion growing: calculate costtriples to one vertex. then try to grow to a vertex, where cost is negative. probably can grow for one vertex all negative triples at once, if this triple do not influence each other
//TODO presentation:
// 1. Proof: define notation, explain mappings p(x), join_mapping and cut_mapping are valide: map from multicut to multicut(reference to paper): but also combinations of mappings are valid
// 2. Implementation:
// 3. Result of Implementation: result in table. discuss bad results!: reason are also synthesized instances (planes) and their costs. to one vertex there will be two other vertices from synthesized plane, where cost is negative, but we need all costs to be positive to cut outlier. But algorithm tests work.

// TODO until monday: 1) implement triangle criterion and maybe tests
//  after that: 2) discuss results + presentation

int main() {

    // create data
    std::system(fmt::format("cd {} && go test {} -run=^TestSaveTestDataToFile$ -numberOfPlanes {} -pointsPerPlane {} -mean 0 -stddev {} -outputFile {}", go_project_path, go_script_path, n_planes, n_vertices_per_plane, stddev, synthesized_instance_path).c_str());
    std::system(fmt::format("cd {} && go test {} -run=^TestSaveCostToFile$ -inputFile {} -outputFile {} -threshold {} -amplification 3", go_project_path, go_script_path, synthesized_instance_path, triple_costs_path, threshold).c_str());
    Triples triple_costs{};
    Constraints constraints{};

    // evaluate data by partial optimality criterion
    switch(mode){
        case(EDGE):{
            std::cout<< "edge criterion";
            EdgeCriterionCut edge_criterion_cut{triple_costs, constraints};
            // TODO: stddev 0.001 threshold_factor 0.03 (the smaller boths values, the more cuts are found)
            //  450 vertices: no cuts found       99 vertices: 98 cuts found => 1 outlier
            edge_criterion_cut.evaluate_U_size_1();
            //edge_criterion_cut.evaluate_U_size_2();
        }
        case(TRIANGLE):{
            std::cout<< "triangle criterion";
            TriangleCriterion triangleCriterion{triple_costs, constraints};
            // TODO: O(n^4) for 99 vertices: 5 minutes, no constraints found
            triangleCriterion.evaluate_all_triangles_with_singlets();
        }
    }

    // write data
    // constraints.write_to_json();
    return 0;
}
