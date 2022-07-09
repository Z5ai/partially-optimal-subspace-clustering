#ifndef PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_CONSTANTS_H
#define PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_CONSTANTS_H


#include <string>
#include <unordered_map>
enum Mode {EDGE, TRIANGLE};

//Settings

const int n_planes{3};
const int n_vertices_per_plane{2};
const int n_vertices{n_planes * n_vertices_per_plane};
const float stddev{0.01};
const float threshold_factor{0};
const float threshold{threshold_factor * stddev};
const Mode mode{TRIANGLE};


//Paths
const std::string project_path{R"(/home/david/3_01__educ__TUD/INF-PM-FPA/partially-optimal-subspace-clustering)"};

const std::string temp_path{project_path + R"(/temp)"};
const std::string triple_costs_path{temp_path + "/triple_costs.json"};
const std::string synthesized_instance_path{temp_path + "/synthesized_instance.csv"};
const std::string constraints_path{temp_path + "/constraints.json"};

const std::string go_project_path{project_path + R"(/dependencies/local-search-algorithm-for-cubic-clustering)"};
const std::string go_script_path{go_project_path + R"(/src/partitioning3D/evaluation)"};

#endif //PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_CONSTANTS_H
