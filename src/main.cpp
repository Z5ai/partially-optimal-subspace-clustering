#define FMT_HEADER_ONLY
#include <vector>
#include <core.h>
#include "Constants.h"
#include "Graph/Instance.h"
#include "PersistencyCriteriaAlgorithms/EdgeCutCriterion.h"
#include "Graph/Constraints.h"
#include "PersistencyCriteriaAlgorithms/TriangleJoinCriterion.h"
#include "PersistencyCriteriaAlgorithms/TriangleCutCriterion.h"

//TODO presentation:
// 1. Proof: define notation, explain mappings p(x), join_mapping and cut_mapping are valide: map from multicut to multicut(reference to paper): but also combinations of mappings are valid
// 2. Implementation:
// 3. Result of Implementation: result in table. discuss bad results!: reason are also synthesized instances (planes) and their costs. to one vertex there will be two other vertices from synthesized plane, where cost is negative, but we need all costs to be positive to cut outlier. But algorithm tests work.


int main() {

    // create data
    std::system(fmt::format("cd {} && go test {} -run=^TestSaveTestDataToFile$ -numberOfPlanes {} -pointsPerPlane {} -mean 0 -stddev {} -outputFile {}", go_project_path, go_script_path, n_planes, n_vertices_per_plane, stddev, synthesized_instance_path).c_str());
    std::system(fmt::format("cd {} && go test {} -run=^TestSaveCostToFile$ -inputFile {} -outputFile {} -threshold {} -amplification 3", go_project_path, go_script_path, synthesized_instance_path, triple_costs_path, threshold).c_str());
    Instance instance{n_vertices};
    Constraints constraints{n_vertices};

    // evaluate data by partial optimality criterion
    switch(mode){
        case(EDGE_CUT):{
            EdgeCutCriterion edge_cut_criterion{instance, constraints, n_vertices};
            edge_cut_criterion.evaluate_U_size_1();
            edge_cut_criterion.evaluate_U_size_2();
            break;
        }
        case(TRIANGLE_CUT):{
            TriangleCutCriterion triangle_cut_criterion{instance, constraints, n_vertices};
            triangle_cut_criterion.evaluate_all_singlets();
            break;
        }
        case(TRIANGLE_JOIN):{
            TriangleJoinCriterion triangle_join_criterion{instance, constraints, n_vertices};
            triangle_join_criterion.evaluate_all_triangles_with_singlets();
            break;
        }
    }

    //print result
    constraints.print_constraints();
    return 0;
}
