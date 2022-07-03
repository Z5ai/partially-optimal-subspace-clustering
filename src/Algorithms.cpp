#include <vector>
#include "Algorithms.h"
#include "Constants.h"

// join: 1
// cut: 0
//

std::vector<edge_type> Algorithms::evaluate_edge_criterion_cut(std::vector<vertex_type> vertices, triple_costs_type triple_cost, int n){
    for(int i{1}; i<=n; i++){

    }
};

std::vector<edge_type> Algorithms::evaluate_edge_criterion_join(std::vector<vertex_type> vertices, triple_costs_type triple_cost){

};

std::vector<edge_type> Algorithms::evaluate_triangle_criterion(std::vector<vertex_type> vertices, triple_costs_type triple_cost){

};




std::vector<std::array<int, 1>> Algorithms::singles_from_component(std::vector<int> P){
    auto n_singles = P.size();
    std::vector<std::array<int, 2>>singles(n_singles);
    for(int i{0}; i<P.size(); i++){
        std::array<int, 1>{P.at(i)};
        singles.push_back(single);
    }
    return singles;
}

std::vector<std::array<int, 2>> Algorithms::pairs_from_component(std::vector<int> P){
    auto n_pairs{(P.size()*P.size()-P.size())/2};
    std::vector<std::array<int, 2>>pairs(n_pairs);
    for(int i{0}; i<P.size(); i++){
        for(int j{i+1}; i<P.size(); j++){
            std::array<int, 2> pair{P.at(i),P.at(j)};
            pairs.push_back(pair);
        }
    }
    return pairs;
}
