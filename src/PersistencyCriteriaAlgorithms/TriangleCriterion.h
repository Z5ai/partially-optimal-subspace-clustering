#ifndef PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_TRIANGLECRITERION_H
#define PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_TRIANGLECRITERION_H


#include "PersistencyCriterion.h"

//TODO: when triangle criterion is true several times
// and a join mapping from one triangle interferes with a cut mapping from another mapping, than this must be investigated
// => constraints must be synchronized or updated somehow (for now: leave out this detail)
class TriangleCriterion: public PersistencyCriterion {

public:
    TriangleCriterion(Instance& instance, Constraints& constraints, int n_vertices)
    : PersistencyCriterion{instance, constraints, n_vertices}{
    }

    std::vector<float> create_costs_abs_singlet(){
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

    float get_costs_abs_to_two_vertices(int u, int v){
        float sum{0};
        for(int i{0}; i<n_vertices; i++){ if(i==u || i==v) continue;
            sum += std::abs(instance.get_cost(u, v, i));
        }
        return sum;
    }

    float get_costs_pos_to_two_vertices(int u, int v){
        float sum{0};
        for(int i{0}; i<n_vertices; i++){ if(i==u || i==v) continue;
            sum += std::max(0.0f, instance.get_cost(u, v, i));
        }
        return sum;
    }

    float get_costs_neg_with_only_one_vertex_in_triangle(int u, int v, int w){
        float sum{0};
        for(int i{0}; i<n_vertices; i++){ if(i==u || i==v || i==w) continue;
            for(int j{i+1}; j<n_vertices; j++){ if(j==u || j==v || j==w) continue;
                sum += std::min(0.0f, instance.get_cost(u, i, j));
                sum += std::min(0.0f, instance.get_cost(v, i, j));
                sum += std::min(0.0f, instance.get_cost(w, i, j));
            }
        }
        return sum;
    }

    bool evaluate_one_triangle(int u, int v, int w, std::vector<float> costs_singlet){
        //terms for right side of inequality
        float c_uvw = instance.get_cost(u, v, w);
        float c_Tuw_pos_wo_Tuvw = get_costs_pos_to_two_vertices(u, w) - (std::max(0.0f, c_uvw));
        float c_Tuv_pos_wo_Tuvw = get_costs_pos_to_two_vertices(u, v) - (std::max(0.0f, c_uvw));
        float c_Twv_pos_wo_Tuvw = get_costs_pos_to_two_vertices(w, v) - (std::max(0.0f, c_uvw));
        float c_Tduvw_neg_wo_Tuw_Tuv_Tvw = get_costs_neg_with_only_one_vertex_in_triangle(u, v, w);
        //terms for left side of inequality
        float c_Tuw_abs =  get_costs_abs_to_two_vertices(u,w);
        float c_TdU_abs_wo_Tuv_wo_Tuw = costs_singlet.at(u) - get_costs_abs_to_two_vertices(u,v) - c_Tuw_abs;
        float c_TdW_abs_wo_Twv_wo_Twu = costs_singlet.at(w) - get_costs_abs_to_two_vertices(w,v) - c_Tuw_abs;
        // evaluate triangle criterion
        bool case1 {c_TdU_abs_wo_Tuv_wo_Tuw <= -c_Tuw_pos_wo_Tuvw -c_Tuv_pos_wo_Tuvw -c_uvw};
        bool case2 {c_TdW_abs_wo_Twv_wo_Twu <= -c_Tuw_pos_wo_Tuvw -c_Twv_pos_wo_Tuvw -c_uvw};
        bool case3 {0 <= c_Tduvw_neg_wo_Tuw_Tuv_Tvw-c_uvw};
        return case1 && case2 && case3;
    }

    void evaluate_all_triangles_with_singlets(){
        std::vector<float> costs_singlet = create_costs_abs_singlet();
        for(int x{0}; x<n_vertices; x++){
            for(int y{x+1}; y<n_vertices; y++){
                for(int z{y+1}; z<n_vertices; z++){
                    if(evaluate_one_triangle(x, y, z, costs_singlet))
                        constraints.insert_join(x,z);
                    if(evaluate_one_triangle(y, z, x, costs_singlet))
                        constraints.insert_join(y,x);
                    if(evaluate_one_triangle(y, x, z, costs_singlet))
                        constraints.insert_join(y, z);
                }
            }
        }
    }
};


#endif //PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_TRIANGLECRITERION_H
