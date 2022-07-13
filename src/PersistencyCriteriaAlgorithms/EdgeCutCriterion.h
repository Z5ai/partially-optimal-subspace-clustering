#ifndef PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_EDGECUTCRITERION_H
#define PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_EDGECUTCRITERION_H


#include <iostream>
#include "PersistencyCriterion.h"

class EdgeCutCriterion: public PersistencyCriterion {


public:
    EdgeCutCriterion(Instance& instance, Constraints& constraints, int n_vertices)
        :PersistencyCriterion{instance, constraints, n_vertices}{
    }

    // returns true, if all costs to one vertex u are zero or positive
    bool check_costs_for_unique_sign_pos_one_fixed_vertex(int u){
        return check_costs_for_unique_sign_one_fixed_vertex(u, [](float cost) -> bool {if(cost<0){return false;}else{return true;}});
    }

    // returns true, if all costs to two vertices u,v are zero or positive
    bool check_costs_for_unique_sign_pos_two_fixed_vertices(int u, int v){
        return check_costs_for_unique_sign_two_fixed_vertices(u,v, [](float cost) -> bool {if(cost<0){return false;}else{return true;}});
    }

    void evaluate_U_size_1(){
        for (int u{0}; u<n_vertices; u++)
            // for U = {u} query edge_cut_criterion
            if(check_costs_for_unique_sign_pos_one_fixed_vertex(u))
                // write result into constraints: cut U = {u}
                constraints.cut_one_vertex(u);
    }

    // can be optimized by using return from 'evaluate_U_size_1()' as parameterinput. replace time by memory.
    void evaluate_U_size_2(){
        for (int u{0}; u<n_vertices; u++)
            for (int v{u+1}; v<n_vertices; v++)
                // for U = {u,v} query edge_cut_criterion
                if(check_costs_for_unique_sign_pos_one_fixed_vertex(u)
                   && check_costs_for_unique_sign_pos_one_fixed_vertex(v)
                   && check_costs_for_unique_sign_pos_two_fixed_vertices(u, v)){
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

#endif //PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_EDGECUTCRITERION_H
