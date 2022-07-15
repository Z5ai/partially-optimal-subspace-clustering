#ifndef PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_PERSISTENCYCRITERION_H
#define PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_PERSISTENCYCRITERION_H


#include "../Graph/Instance.h"
#include "../Graph/Constraints.h"


class PersistencyCriterion {


protected:
    const Instance& instance;
    Constraints& constraints;
    int n_vertices{};


public:
    PersistencyCriterion(Instance& instance, Constraints& constraints, int n_vertices)
        : instance{instance}, constraints{constraints}, n_vertices{n_vertices}{
    }

    float sum_costs_one_fixed_vertex(int u, float (*evaluate_cost)(float)){
        float sum{0};
        for(int i{0}; i<n_vertices; i++){ if(i==u) continue;
            for(int j{i+1}; j<n_vertices; j++){ if(j==u) continue;
                float cost = instance.get_cost(u,i,j);
                sum = sum + evaluate_cost(cost);
            }
        }
        return sum;
    }

    bool check_costs_for_unique_sign_one_fixed_vertex(int u, bool (*evaluate_cost)(float)){
        bool unique_sign{true};
        for(int i{0}; i<n_vertices; i++){ if(i==u) continue;
            for(int j{i+1}; j<n_vertices; j++){ if(j==u) continue;
                float cost = instance.get_cost(u,i,j);
                unique_sign = unique_sign && evaluate_cost(cost);
            }
        }
        return unique_sign;
    }

     float sum_costs_two_fixed_vertices(int u, int v, float (*evaluate_cost)(float)){
        float sum{0};
        for(int i{0}; i<n_vertices; i++){ if(i==u || i==v) continue;
            float cost = instance.get_cost(u,v,i);
            sum = sum + evaluate_cost(cost);
        }
        return sum;
    }

    bool check_costs_for_unique_sign_two_fixed_vertices(int u, int v, bool (*evaluate_cost)(float)){
        bool unique_sign{true};
        for(int i{0}; i<n_vertices; i++){ if(i==u || i==v) continue;
            float cost = instance.get_cost(u,v,i);
            unique_sign = unique_sign && evaluate_cost(cost);
        }
        return unique_sign;
    }
};


#endif //PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_PERSISTENCYCRITERION_H
