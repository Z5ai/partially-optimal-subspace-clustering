#include <vector>
#include <iostream>
#include "Constants.h"
#include "Graph/TripleCosts.h"

int main() {
    // TODO: restructuring: put local-search-algorithm project into dependencies folder. make partial-optimal subspace-clustering to main project. call go script here in main function.
    // TODO: write tests
    // flag -stddev(sigma): 0.03:much 0.01:little(try this and then smaller values) 0.001:very_little
    // flag -constraintFile is optional (path to constraints.json file)
    // path and name for storing synthesized_instance.csv and triple_costs.json can be set individually in call 1 and 2. In command 3 and 4 the same names must be used again
    $ go test ./src/partitioning3D/evaluation/ -run=^TestSaveTestDataToFile$ -numberOfPlanes 3 -pointsPerPlane 33 -mean 0 -stddev 0.1 -outputFile /home/david/3_01__educ__TUD/INF-PM-FPA/subspace-clustering/data/synthesized_instance.csv
    $ go test ./src/partitioning3D/evaluation/ -run=^TestSaveCostToFile$ -inputFile /home/david/3_01__educ__TUD/INF-PM-FPA/subspace-clustering/data/synthesized_instance.csv -outputFile /home/david/3_01__educ__TUD/INF-PM-FPA/subspace-clustering/data/triple_costs.json -threshold 0.001 -amplification 3
    // read data
    TripleCosts triple_costs{n_vertices};

    /*
    // evaluate data by partial optimality criterion
    Algorithms algorithms{};
    std::vector<edge_type> cuts{};
    std::vector<edge_type> joins{};
    std::vector<edge_type> result{};
    if(edge_criterion_cut==true){
        result = algorithms.evaluate_edge_criterion_cut(graph, triple_costs);
        cuts.insert(cuts.end(), result.begin(), result.end());
    }
    if(edge_criterion_join==true){
        result = algorithms.evaluate_edge_criterion_join(graph, triple_costs);
        joins.insert(joins.end(), result.begin(), result.end());
    }
    if(triangle_criterion==true){
        result = algorithms.evaluate_triangle_criterion(graph, triple_costs);
        joins.insert(joins.end(), result.begin(), result.end());
    }

    // write data
    // map -> json
    trip.write_constraints(cuts, joins);
     */
    return 0;
}
