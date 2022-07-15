#define FMT_HEADER_ONLY
#include <vector>
#include <core.h>
#include "Graph/Instance.h"
#include "PersistencyCriteriaAlgorithms/EdgeCutCriterion.h"
#include "Graph/Constraints.h"
#include "PersistencyCriteriaAlgorithms/TriangleJoinCriterion.h"
#include "PersistencyCriteriaAlgorithms/TriangleCutCriterion.h"


enum Mode {EDGE_CUT, TRIANGLE_CUT, TRIANGLE_JOIN};
std::unordered_map<std::string, Mode> mode_map{{"EDGE_CUT", EDGE_CUT}, {"TRIANGLE_CUT", TRIANGLE_CUT}, {"TRIANGLE_JOIN", TRIANGLE_JOIN}};


int main(int argc, char* argv[]){

    if(argc!=1 && argc!=6)
        throw std::invalid_argument("argc must be 1 or 6.");

    //settings
    const int n_planes = (argc==6)?atoi(argv[1]): 3;
    const int n_vertices_per_plane = (argc==6)?atoi(argv[2]): 33;
    const float stddev = (argc==6)?atof(argv[3]): 0.001;
    const Mode mode = (argc==6)?mode_map[argv[4]]:TRIANGLE_CUT;
    const std::string project_path = (argc==6)?argv[5]: R"(/home/david/3_01__educ__TUD/INF-PM-FPA/partially-optimal-subspace-clustering)";

    const int n_vertices{n_planes * n_vertices_per_plane};
    const float threshold{3 * stddev};

    //paths
    const std::string temp_path{project_path + R"(/temp)"};
    const std::string triple_costs_path{temp_path + "/triple_costs.json"};
    const std::string synthesized_instance_path{temp_path + "/synthesized_instance.csv"};

    const std::string go_project_path{project_path + R"(/dependencies/local-search-algorithm-for-cubic-clustering)"};
    const std::string go_script_path{go_project_path + R"(/src/partitioning3D/evaluation)"};


    //create data
    std::system(fmt::format("cd {} && go test {} -run=^TestSaveTestDataToFile$ -numberOfPlanes {} -pointsPerPlane {} -mean 0 -stddev {} -outputFile {}", go_project_path, go_script_path, n_planes, n_vertices_per_plane, stddev, synthesized_instance_path).c_str());
    std::system(fmt::format("cd {} && go test {} -run=^TestSaveCostToFile$ -inputFile {} -outputFile {} -threshold {} -amplification 3", go_project_path, go_script_path, synthesized_instance_path, triple_costs_path, threshold).c_str());
    Instance instance{n_vertices, triple_costs_path};
    Constraints constraints{n_vertices};


    //evaluate data by partial optimality criterion
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
