#ifndef PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_ALGORITHMS_H
#define PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_ALGORITHMS_H

#include "Constants.h"

class Algorithms {

public:


    std::vector<edge_type>
    evaluate_edge_criterion_cut(std::vector<vertex_type> vertices, triple_costs_type triple_cost);

    std::vector<edge_type>
    evaluate_edge_criterion_join(std::vector<vertex_type> vertices, triple_costs_type triple_cost);

    std::vector<edge_type>
    evaluate_triangle_criterion(std::vector<vertex_type> vertices, triple_costs_type triple_cost);
};


#endif //PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_ALGORITHMS_H
