#ifndef PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_CONSTANTS_H
#define PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_CONSTANTS_H


#include <string>
#include <unordered_map>

//Types
typedef std::array<int,2> edge;
typedef std::unordered_map<std::string, std::vector<edge>> constraints_map;

//Settings
const bool edge_criterion_cut{true};
const bool edge_criterion_join{false};
const bool triangle_criterion{false};
const std::string data_path{"/home/david/3_01__educ__TUD/INF-PM-FPA/subspace-clustering/data/"};
const std::string triple_costs_path{data_path + "triple_costs.json"};
const std::string synthesized_instance_path{data_path + "synthesized_instance"};
const std::string constraints_path{data_path + "constraints"};


#endif //PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_CONSTANTS_H
