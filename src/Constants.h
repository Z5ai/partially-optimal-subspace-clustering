#ifndef PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_CONSTANTS_H
#define PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_CONSTANTS_H


#include <string>
#include <unordered_map>

//Settings
const int n_plane{3};
const int n_vertices_per_plane{33};
const int n_vertices{n_plane * n_vertices_per_plane};
const bool edge_criterion_cut{true};
const bool edge_criterion_join{false};
const bool triangle_criterion{false};

//Paths
const std::string data_path{R"(/home/david/3_01__educ__TUD/INF-PM-FPA/subspace-clustering/partially-optimal-subspace-clustering/temp)"};
const std::string triple_costs_path{data_path + "triple_costs.json"};
const std::string synthesized_instance_path{data_path + "synthesized_instance.csv"};
const std::string constraints_path{data_path + "constraints.json"};


#endif //PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_CONSTANTS_H
