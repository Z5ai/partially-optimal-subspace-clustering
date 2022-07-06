#ifndef PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_EDGECRITERIONCUT_H
#define PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_EDGECRITERIONCUT_H


#include <iostream>
#include "PersistencyCriterion.h"

class EdgeCriterionCut: public PersistencyCriterion {

//TODO: replace i<n_vertices && i!=u
public:
    EdgeCriterionCut(TripleCosts& triple_costs, Constraints& constraints)
        : PersistencyCriterion{triple_costs, constraints}{
    }

    bool evaluate_all_triples_to_one_vertex(int u){
        for(int i{0}; i<n_vertices && i!=u; i++){
            for(int j{i+1}; j<n_vertices && j!=u; j++){
                float cost = triple_costs.get_triple_cost(u, i, j);
                if(cost < 0)
                    // there is a negative triple
                    return false;
            }
        }
        return true;
    }

    bool evaluate_all_triples_to_two_vertices(int u, int v){
        for(int i{0}; i<n_vertices && i!=u && i!=v; i++){
            float cost = triple_costs.get_triple_cost(u, v, i);
            if(cost < 0)
                // there is a negative triple
                return false;
        }
        return true;
    }

    void iterate_all_U(int U_max_size){
        switch(U_max_size){
            // |U| <= 1
            case 1:
                for (int u{0}; u<n_vertices; u++)
                    // for U = {u} query edge_cut_criterion
                    if(evaluate_all_triples_to_one_vertex(u) == true)
                        for(int r{0}; r<n_vertices && r!=u; r++)
                            constraints.insert_cut(u, r);

            // |U| <= 2
            case 2:
                for (int u{0}; u<n_vertices; u++)
                    for (int v{u+1}; v<n_vertices; v++)
                        // for U = {u,v} query edge_cut_criterion
                        if(evaluate_all_triples_to_one_vertex(u) == true
                        // this can be optimized by using memory
                        && evaluate_all_triples_to_one_vertex(v) == true
                        && evaluate_all_triples_to_two_vertices(u,v) == true){
                            for(int r{0}; r<n_vertices && r!=u && r!=v; r++)
                                constraints.insert_cut(u, r);
                            for(int r{0}; r<n_vertices && r!=u && r!=v; r++)
                                constraints.insert_cut(v, r);
                        }
        }
    }
};

#endif //PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_EDGECRITERIONCUT_H
