#include <vector>
#include "Algorithms.h"
#include "Constants.h"


// join: 1
// cut: 0
//

std::vector<edge_type> Algorithms::evaluate_edge_criterion_cut(std::vector<vertex_type> vertices, triple_costs_type triple_costs, int U_max_size){
    for(int i{1}; i<=U_max_size; i++){
        //create all possible U with size i and store all that U in a std::vector all_U
        all_U = .....;
        for(std::vector<int> U:all_U){
            triples_type triples_at_border{get_triples_at_border_of_component_U(vertices.size(), U)};
            for(<std::array<int,3> triple: triples_at_border){
                float cost = DataHandler::gettripleCost(triple[0], triple[1], triple[2], triple_costs);
                if cost.ispositive: break break
            }
        }
    }
};

std::vector<edge_type> Algorithms::evaluate_edge_criterion_join(std::vector<vertex_type> vertices, triple_costs_type triple_costs){

};

std::vector<edge_type> Algorithms::evaluate_triangle_criterion(std::vector<vertex_type> vertices, triple_costs_type triple_costs){

};




singles_type Algorithms::singles_from_component(std::vector<int> P){
    auto n_singles = P.size();
    singles_type singles(n_singles);
    for(int i{0}; i<P.size(); i++){
        std::array<int, 1> single{P.at(i)};
        singles.push_back(single);
    }
    return singles;
}

pairs_type Algorithms::pairs_from_component(std::vector<int> P){
    auto n_pairs{(P.size()*P.size()-P.size())/2};
    pairs_type pairs(n_pairs);
    for(int i{0}; i<P.size(); i++){
        for(int j{i+1}; i<P.size(); j++){
            std::array<int, 2> pair{P.at(i),P.at(j)};
            pairs.push_back(pair);
        }
    }
    return pairs;
}

triples_type Algorithms::synthesize_triples(singles_type singles, pairs_type pairs){
    auto n_triples(singles.size()*pairs.size());
    triples_type triples(n_triples);
    for(std::array<int,1> single: singles){
        for(std::array<int,2> pair: pairs){
            std::array<int,3> triple;
            triple[0] = single.at(0);
            triple[1] = pair.at(0);
            triple[2] = pair.at(1);
            triples.push_back(triple);
        }
    }
    return triples;
}

std::vector<int> V_subtracted_by_U(int n_vertices, std::vector<int> U){
    std::sort(U.begin(), U.end());
    std::vector<int> R(n_vertices-U.size());
    int u{0};
    for(int i{0}; i<n_vertices; i++){
        if(U.at(u)==i){
            u++;
        }
        else{
            R.push_back(i);
        }
    }
}

triples_type Algorithms::get_triples_at_border_of_component_U(int n_vertices, std::vector<int> U){
    std::vector<int> R{V_subtracted_by_U(n_vertices,U)};
    triples_type a {synthesize_triples(singles_from_component(U), pairs_from_component(R))};
    triples_type b (synthesize_triples(singles_from_component(R), pairs_from_component(U)));
    triples_type ab {a.size() +b.size()};
    ab.insert(ab.end(), a.begin(), a.end());
    ab.insert(ab.end(), b.begin(),b.end());
    return ab;
}
