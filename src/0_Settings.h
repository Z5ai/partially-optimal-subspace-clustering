// A: Organisational Stuff
//TODO A1: ask Julius:
// now:
// - git clone https://github.com/Z5ai/subspace-clustering.git --recurse-submodules
// - define settings in go and c++ settingfiles
// - run go-code with: go run ./main.go
//   run c++-code with: g++ -o program *.cpp && ./program && rm program
// possible improvement:
// - run code with one command:
//   go run ./{local_search_dir}/main_synthesize_data.go     &&    cd {partial_optimality_dir} g++ -o program *.cpp && ./program && rm program && cd ..     &&    go run ./{local_search_dir}/main_local_search.go

//TODO A2: ask Julius: settings like partially-optimal-subspace-clustering/src/0_Settings.h:
// - switch for 'synthesizing graph and creating 0_cubic_costs and creating 0_vertices' vs 'local search based on 1_predecided_edges'
// - number vertices
// - sigma
// - paths

//TODO A3: ask Julius: create data/0_cubic_costs.csv

//TODO A4: ask Julius: location for 0_cubic_costs.csv and 0_vertices


// B: Data Structures and Formats
//TODO: ask Julius:
// - data structure for graph (used in program, just use vertices?)
// - data structure for cubic_costs (1_predecided_edges   and   used in program)          map: 3 vertices -> float
// - data structure for predecided_edges                                                  map: 2 vertices -> float









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
