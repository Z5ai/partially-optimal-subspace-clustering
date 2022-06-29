//TODO Commands:
// - flag -stddev between 0 and 0.1 (sigma)
// - flag -constraintFile  is optional (path to constraints.json file)
// - path and name for storing synthesized_instance.csv and triple_costs.json can be set individually in call 1 and 2. In command 3 and 4 the same names must be used again
// - run code with one command:
//      go test ./src/partitioning3D/evaluation/ -run=^TestSaveTestDataToFile$ -numberOfPlanes 3 -pointsPerPlane 33 -mean 0 -stddev 0 -outputFile /home/david/3_01__educ__TUD/INF-PM-FPA/local-search-algorithm-for-cubic-clustering/temp/synthesized_instance.csv
//   && go test     .....triple_cost.json
//   && cd {partial_optimality_dir} g++ -o program *.cpp && ./program && rm program && cd ..
//   && go run ./src/main.go -fileName /home/david/3_01__educ__TUD/INF-PM-FPA/local-search-algorithm-for-cubic-clustering/temp/synthesized_instance.csv -algorithm GreedyJoining -threshold 0.001 -constraintFile .......... //this last flag is optional

//TODO File Formats:
// - synthesized_instance.csv                     3 floats  (synchronization with triple_costs and constraints: first coordinate is at position 0)
// - triple_costs.json                            json: most outer array for first vertex, inner array for second vertex, most inner array for third vertex, value for cost      no parsing necessary because json
//   function InitializeTripleCosts from GreedyMoving class to generate triplecostarray                          function GetTripleCost from GreedyMoving class to access triplecostarray
// - constraints.json                             json: {"same_partition": [[1,2],[4,7],[7,9],[9,10]],"different_partition": [[1,3],[1,4],[4,8],[8,10]]                          no parsing necessary because json




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
