#ifndef PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_TRIPLECOSTS_H
#define PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_TRIPLECOSTS_H


#include <vector>
#include "../Constants.h"

class TripleCosts {
    std::vector<std::vector<std::vector<float>>> triple_costs;


public:
    TripleCosts(int n_vertices);

    float get_triple_cost(int i, int j, int k);
};


#endif //PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_TRIPLECOSTS_H
