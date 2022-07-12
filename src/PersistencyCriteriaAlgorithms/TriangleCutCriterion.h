#ifndef PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_TRIANGLECUTCRITERION_H
#define PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_TRIANGLECUTCRITERION_H


#include "PersistencyCriterion.h"

class TriangleCutCriterion: public PersistencyCriterion {


public:
    TriangleCutCriterion(Instance &instance, Constraints &constraints, int n_vertices)
        :PersistencyCriterion{instance, constraints, n_vertices} {
    }

    std::vector<float> create_costs_neg_singlet(){
        std::vector<float> singlets(n_vertices*(((n_vertices-1)*(n_vertices-2))/2));
        for(int u{0}; u<n_vertices; u++){
            float singlet_cost = sum_costs_one_fixed_vertex(u, [](float cost) -> float {return std::min(0.0f, cost);});
            singlets.push_back(singlet_cost);
        }
        return singlets;
    }

    void evaluate_one_triangle(int u, int v, int w, std::vector<float> costs_singlet){
        float c_uvw = instance.get_cost(u, v, w);
        //cut around u
        float c_TdU_neg_wo_Tuvw = costs_singlet[u] - std::min(0.0f, c_uvw);
        if(-c_TdU_neg_wo_Tuvw <= c_uvw){
            constraints.insert_cut(u,v);
            constraints.insert_cut(u,w);
        }
        //cut around v
        float c_TdV_neg_wo_Tuvw = costs_singlet[v]- std::min(0.0f, c_uvw);
        if(-c_TdV_neg_wo_Tuvw <= c_uvw){
            constraints.insert_cut(v,u);
            constraints.insert_cut(v,w);
        }
        //cut around w
        float c_TdW_neg_wo_Tuvw = costs_singlet[w]- std::min(0.0f, c_uvw);
        if(-c_TdW_neg_wo_Tuvw <= c_uvw){
            constraints.insert_cut(w,u);
            constraints.insert_cut(w,v);
        }
    }


    void evaluate_all_triangles_with_singlets(){
        std::vector<float> costs_singlet = create_costs_neg_singlet();
        for(int x{0}; x<n_vertices; x++){
            for(int y{x+1}; y<n_vertices; y++){
                for(int z{y+1}; z<n_vertices; z++){
                    evaluate_one_triangle(x,y,z,costs_singlet);
                }
            }
        }
    }
};


#endif //PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_TRIANGLECUTCRITERION_H
