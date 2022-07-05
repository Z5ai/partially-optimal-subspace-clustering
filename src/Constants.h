#ifndef PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_CONSTANTS_H
#define PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_CONSTANTS_H


#include <string>
#include <unordered_map>

//Settings
const int n_plane{3};
const int n_vertices_per_plane{33};
const int n_vertices{n_plane * n_vertices_per_plane};
const float sigma{0.01};
const bool edge_criterion_cut{true};
const bool edge_criterion_join{false};
const bool triangle_criterion{false};

//Paths
const std::string project_path{R"(~/3_01__educ__TUD/INF-PM-FPA/partially-optimal-subspace-clustering)"};

const std::string temp_path{project_path + R"(/temp/)"};
const std::string triple_costs_path{temp_path + "triple_costs.json"};
const std::string synthesized_instance_path{temp_path + "synthesized_instance.csv"};
const std::string constraints_path{temp_path + "constraints.json"};

const std::string go_script_path{project_path + R"(/dependencies/local-search-algorithm-for-cubic-clustering/)"};

#endif //PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_CONSTANTS_H
