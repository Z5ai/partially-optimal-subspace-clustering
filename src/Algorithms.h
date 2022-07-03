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

    std::vector<edge_type>
    evaluate_edge_criterion_cut(std::vector<vertex_type> vertices, triple_costs_type triple_cost, int n);

    std::vector<std::array<int, 2>> pairs_from_component(std::vector<int> P);

    std::vector<std::array<int, 1>> singles_from_component(std::vector<int> P);

    std::vector<std::array<int, 3>> synthesize_triples(singles_type singles, pairs_type pairs);

    triples_type get_triples_at_border_of_component_U(int n_vertices, std::vector<int> U);
};


#endif //PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_ALGORITHMS_H
