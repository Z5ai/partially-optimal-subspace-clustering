#ifndef PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_EDGECRITERIONCUT_H
#define PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_EDGECRITERIONCUT_H


#include <iostream>
#include "PersistencyCriterion.h"

class EdgeCriterionCut: public PersistencyCriterion {


public:
    EdgeCriterionCut(Instance& instance, Constraints& constraints, int n_vertices)
        : PersistencyCriterion{instance, constraints, n_vertices}{
    }

    // returns true, if all costs to one vertex u are zero or positive
    bool evaluate_all_triples_to_one_vertex(int u){
        for(int i{0}; i<n_vertices; i++){ if(i==u) continue;
            for(int j{i+1}; j<n_vertices; j++){ if(j==u) continue;
                float cost = instance.get_cost(u, i, j);
                if(cost < 0)
                    // there is a negative triple
                    return false;
            }
        }
        return true;
    }

    // returns true, if all costs to two vertices u,v are zero or positive
    bool evaluate_all_triples_to_two_vertices(int u, int v){
        for(int i{0}; i<n_vertices; i++){ if(i==u || i==v) continue;
            float cost = instance.get_cost(u, v, i);
            if(cost < 0)
                // there is a negative triple
                return false;
        }
        return true;
    }

    void evaluate_U_size_1(){
        for (int u{0}; u<n_vertices; u++)
            // for U = {u} query edge_cut_criterion
            if(evaluate_all_triples_to_one_vertex(u))
                // write result into constraints: cut U = {u}
                for(int r{0}; r<n_vertices; r++){ if(r==u) continue;
                    constraints.insert_cut(u, r);
                }
    }

    // can be optimized by using return from 'evaluate_U_size_1()' as parameterinput. replace time by memory.
    void evaluate_U_size_2(){
        for (int u{0}; u<n_vertices; u++)
            for (int v{u+1}; v<n_vertices; v++)
                // for U = {u,v} query edge_cut_criterion
                if(evaluate_all_triples_to_one_vertex(u)
                   && evaluate_all_triples_to_one_vertex(v)
                   && evaluate_all_triples_to_two_vertices(u, v)){
                    // write result into constraints: cut U = {u,v}
                    for(int r{0}; r<n_vertices; r++){ if(r==u || r==v) continue;
                        constraints.insert_cut(u, r);
                    }
                    for(int r{0}; r<n_vertices; r++){ if(r==u || r==v) continue;
                        constraints.insert_cut(v, r);
                    }
                }
    }
};

#endif //PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_EDGECRITERIONCUT_H
