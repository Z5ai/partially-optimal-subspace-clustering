#ifndef PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_CONSTRAINTS_H
#define PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_CONSTRAINTS_H


class Constraints {
    std::vector<std::array<int,2>> cuts;
    std::vector<std::array<int,2>> joins;

public:
    Constraints() {}

    void insert_cut(int a, int b){
        cuts.push_back({a,b});
    }

    void insert_join(int a, int b){
        joins.push_back({a,b});
    }

    void write_to_json(){

    }
};


#endif //PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_CONSTRAINTS_H
