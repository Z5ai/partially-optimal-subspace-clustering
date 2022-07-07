#ifndef PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_PERSISTENCYCRITERION_H
#define PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_PERSISTENCYCRITERION_H


#include "../Graph/Triples.h"
#include "../Graph/Constraints.h"

class PersistencyCriterion {
protected:
    const Triples& triples;
    Constraints& constraints;
public:
    PersistencyCriterion(Triples& triple_costs, Constraints& constraints)
        : triples{triple_costs}, constraints{constraints}{
    }
};

#endif //PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_PERSISTENCYCRITERION_H
