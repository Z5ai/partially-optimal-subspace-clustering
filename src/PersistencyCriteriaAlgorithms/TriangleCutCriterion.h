#ifndef PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_TRIANGLECUTCRITERION_H
#define PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_TRIANGLECUTCRITERION_H


#include "PersistencyCriterion.h"


class TriangleCutCriterion: public PersistencyCriterion {


public:
    TriangleCutCriterion(Instance &instance, Constraints &constraints, int n_vertices)
        :PersistencyCriterion{instance, constraints, n_vertices} {
    }

    float sum_costs_neg_one_fixed_vertex(int u){
        return sum_costs_one_fixed_vertex(u, [](float cost) -> float {return std::min(0.0f, cost); });
    }

    void evaluate_all_triple_for_one_singlet(float c_TdU_neg, int u){
        for(int i{0}; i<n_vertices; i++){ if(i==u) continue;
            for(int j{i+1}; j<n_vertices; j++){ if(j==u) continue;
                float c_uvw = instance.get_cost(u,i,j);
                float c_TdU_neg_wo_Tuvw = c_TdU_neg - std::min(0.0f, c_uvw);
                if(-c_TdU_neg_wo_Tuvw <= c_uvw){
                    constraints.cut_one_vertex(u);
                }
            }
        }
    }

    void evaluate_all_singlets(){
        for(int u{0}; u<n_vertices;u++){
            float c_TdU_neg = sum_costs_neg_one_fixed_vertex(u);
            evaluate_all_triple_for_one_singlet(c_TdU_neg, u);
        }
    }
};


#endif //PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_TRIANGLECUTCRITERION_H
