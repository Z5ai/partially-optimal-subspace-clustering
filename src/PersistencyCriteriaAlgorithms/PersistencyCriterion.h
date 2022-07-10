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
};

#endif //PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_PERSISTENCYCRITERION_H
