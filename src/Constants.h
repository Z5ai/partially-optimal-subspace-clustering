#ifndef PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_CONSTANTS_H
#define PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_CONSTANTS_H


#include <string>
#include <unordered_map>

//Types
typedef std::array<float,3> vertex_type;
typedef std::array<int,2> edge_type;
typedef std::vector<std::vector<std::vector<float>>> triple_costs_type;
typedef std::unordered_map<std::string, std::vector<edge_type>> constraints_map;
typedef std::vector<std::array<int,1>> singles_type;
typedef std::vector<std::array<int,2>> pairs_type;
typedef std::vector<std::array<int,3>> triples_type;


//Settings
const bool edge_criterion_cut{true};
const bool edge_criterion_join{false};
const bool triangle_criterion{false};
const std::string data_path{R"(/home/david/3_01__educ__TUD/INF-PM-FPA/subspace-clustering/data/)"};
const std::string triple_costs_path{data_path + "triple_costs.json"};
const std::string synthesized_instance_path{data_path + "synthesized_instance.csv"};
const std::string constraints_path{data_path + "constraints.json"};


#endif //PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_CONSTANTS_H
