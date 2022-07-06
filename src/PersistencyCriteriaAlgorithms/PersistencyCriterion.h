#ifndef PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_PERSISTENCYCRITERION_H
#define PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_PERSISTENCYCRITERION_H



class PersistencyCriterion {
    const TripleCosts& triple_costs;
public:
    PersistencyCriterion(TripleCosts& triple_costs):triple_costs{triple_costs}{
    }
};


#endif //PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_PERSISTENCYCRITERION_H
