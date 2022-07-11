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



    template<typename T>
    T evaluate_triples_to_one_fixed_vertex(int u, T (*evaluate_triple)(T, int, int, int, operator)){
        float sum;
        for(int i{0}; i<n_vertices; i++){ if(i==u) continue;
            for(int j{i+1}; j<n_vertices; j++){ if(j==u) continue;
                sum = sum operator evaluate_triple(u,i,j);
            }
        }
        return sum;
    }

    template<typename T>
    T evaluate_triples_to_two_fixed_vertices(int u, int v, T (*evaluate_triple)(T, int, int, int, operator)){
        float sum{0};
        for(int i{0}; i<n_vertices; i++){ if(i==u || i==v) continue;
            sum = sum operator evaluate_triple(u,v,i);
        }
        return sum;
    }



};

#endif //PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_PERSISTENCYCRITERION_H
