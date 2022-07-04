#ifndef PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_TRIPLECOSTS_H
#define PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_TRIPLECOSTS_H


#include "Constants.h"

class TripleCosts {



public:
    void write_constraints(std::vector<edge_type> cuts, std::vector<edge_type> joins);

    triple_costs_type create_triple_costs(int n);

    std::vector<vertex_type> create_vertices();

    float get_triple_costs(int i, int j, int k);

    float get_triple_cost(int i, int j, int k, triple_costs_type triple_costs);
};


#endif //PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_TRIPLECOSTS_H
