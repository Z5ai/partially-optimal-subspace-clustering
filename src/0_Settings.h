//
// Created by david on 28.06.22.
//

//TODO: ask Julius: settings like partially-optimal-subspace-clustering/src/0_Settings.h:
// switch       for synthesizing graph and creating 0_cubic_costs and creating 0_vertices     vs    local search based on 1_predecided_edges
// paths

//TODO: ask Julius: create data/0_cubic_costs.csv

//TODO: ask Julius: put 0_cubic_costs.csv and 0_vertices

//TODO: ask Julius:
// data structure for graph (used in program, just use vertices?)
// data structure for cubic_costs (1_predecided_edges   and   used in program)

//TODO: ask Julius:
// later combine both main-functions?: C-wrapper for C++ Code and the call C-Code with Go-Code
// or somehow sequential?  ... but this is something for later





#ifndef PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_0_SETTINGS_H
#define PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_0_SETTINGS_H

#include <string>

//Data Structures
enum Criterion { edge, triangle };

//Settings
const Criterion criterion{edge};
const std::string data_path{"/home/david/3_01__educ__TUD/INF-PM-FPA/subspace-clustering/data/"};
const std::string cubic_cost_path{data_path+"0_cubic_costs.csv"};
const std::string vertices_path{data_path+"0_vertices.csv"};
const std::string predecided_edges_path{data_path+"1_predecided_edges"};

#endif //PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_0_SETTINGS_H
