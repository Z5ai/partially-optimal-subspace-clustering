#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../src/Graph/Instance.h"
#include "../src/Graph/Constraints.h"
#include "../src/PersistencyCriteriaAlgorithms/EdgeCriterionCut.h"


TEST_CASE("testing_total_numbers_of_cut_found") {
    std::vector<std::vector<std::vector<float>>> triple_costs{{{}}};
    Instance instance{4,triple_costs};
    Constraints constraints{};
    EdgeCriterionCut edge_criterion_cut{instance, constraints, n_vertices};
    CHECK(constraints.getCuts().size() == 15);
}