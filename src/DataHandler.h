//
// Created by david on 24.06.22.
//

#ifndef PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_DATAHANDLER_H
#define PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_DATAHANDLER_H




class DataHandler {
    typedef std::array<float,3> vertex;
    std::string data_dir{"/home/david/3_01__educ__TUD/INF-PM-FPA/partially-optimal-subspace-clustering/data/"};

public:
    std::vector<vertex> parse();
};




#endif //PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_DATAHANDLER_H