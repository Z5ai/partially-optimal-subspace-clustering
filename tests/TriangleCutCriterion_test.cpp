#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../src/Graph/Instance.h"
#include "../src/PersistencyCriteriaAlgorithms/EdgeCutCriterion.h"


TEST_CASE("testing_cut_two_components_of_size_1_for_graph_size_5") {
    std::vector<std::vector<std::vector<float>>> triple_costs{{          {{1,1,1},{1,1},{1}},  {{1,-1},{1}},    {{1}}             }};
    int n_vertices{5};
    Instance instance{n_vertices,triple_costs};
    Constraints constraints{n_vertices};
    EdgeCutCriterion edge_cut_criterion{instance, constraints, n_vertices};
    edge_cut_criterion.evaluate_U_size_1();

    Constraints constraints_expected_result{n_vertices};
    bool comp;
    comp = constraints.getCuts() != constraints_expected_result.getCuts();
    CHECK(comp);
    constraints_expected_result.insert_cut(0,1);
    constraints_expected_result.insert_cut(0,2);
    constraints_expected_result.insert_cut(0,3);
    constraints_expected_result.insert_cut(0,4);
    constraints_expected_result.insert_cut(3,1);
    constraints_expected_result.insert_cut(3,2);
    constraints_expected_result.insert_cut(3,4);
    comp = constraints.getCuts() == constraints_expected_result.getCuts();
    CHECK(comp);
}
