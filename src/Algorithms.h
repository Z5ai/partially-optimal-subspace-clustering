#ifndef PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_ALGORITHMS_H
#define PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_ALGORITHMS_H


#include "Graph.h"
#include "Constants.h"

class Algorithms {

public:
    void evaluate_triangle_criterion();

    void evaluate_edge_criterion_join();

    void evaluate_edge_criterion_cut();

    void evaluate_edge_criterion_cut(Graph graph, auto triple_cost, auto constraints);

    std::vector<edge> evaluate_edge_criterion_cut(Graph graph, auto triple_cost, auto constraints);

    std::vector<edge> evaluate_edge_criterion_cut(Graph graph, auto triple_cost);

    std::vector<edge> evaluate_edge_criterion_join(Graph graph, auto triple_cost);

    std::vector<edge> evaluate_triangle_criterion(Graph graph, auto triple_cost);
};


#endif //PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_ALGORITHMS_H
