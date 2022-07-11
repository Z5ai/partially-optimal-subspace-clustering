#ifndef PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_TRIANGLECUTCRITERION_H
#define PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_TRIANGLECUTCRITERION_H


#include "PersistencyCriterion.h"

class TriangleCutCriterion: public PersistencyCriterion {


public:
    TriangleCutCriterion(Instance &instance, Constraints &constraints, int n_vertices)
            : PersistencyCriterion{instance, constraints, n_vertices} {
    }

    std::vector<float> create_costs_neg_singlet(){
        std::vector<float> singlets(n_vertices*(((n_vertices-1)*(n_vertices-2))/2));
        for(int u{0}; u<n_vertices; u++){
            float singlet_cost;
            for(int i{0}; i<n_vertices; i++){ if(i==u) continue;
                for(int j{i+1}; j<n_vertices; j++){ if(j==u) continue;
                    singlet_cost += std::abs(instance.get_cost(u, i, j));
                }
            }
            singlets.push_back(singlet_cost);
        }
        return singlets;
    }
};


#endif //PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_TRIANGLECUTCRITERION_H
