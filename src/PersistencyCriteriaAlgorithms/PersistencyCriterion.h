#ifndef PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_PERSISTENCYCRITERION_H
#define PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_PERSISTENCYCRITERION_H


#include "../Graph/TripleCosts.h"
#include "../Graph/Constraints.h"

class PersistencyCriterion {
protected:
    const TripleCosts& triple_costs;
    Constraints& constraints;
public:
    PersistencyCriterion(TripleCosts& triple_costs, Constraints& constraints)
        :triple_costs{triple_costs},constraints{constraints}{
    }
};

#endif //PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_PERSISTENCYCRITERION_H
