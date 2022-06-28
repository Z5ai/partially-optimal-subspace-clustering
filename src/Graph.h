#ifndef PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_GRAPH_H
#define PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_GRAPH_H


#include <array>
#include <vector>

typedef std::array<float,3> vertex;
//typedef std::array<vertex,2> edge;

class Graph {
    std::vector<vertex> vertices;
    //std::vector<edge> edges;

public:
    void insert_vertex(vertex vertex);
};


#endif //PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_GRAPH_H
