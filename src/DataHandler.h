#ifndef PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_DATAHANDLER_H
#define PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_DATAHANDLER_H


#include "Graph.h"
#include "Constants.h"

class DataHandler {

public:
    Graph create_graph();
    void write_constraints(std::vector<edge> cuts, std::vector<edge> joins);
};


#endif //PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_DATAHANDLER_H
