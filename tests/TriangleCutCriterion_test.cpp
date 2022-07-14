#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../src/Graph/Instance.h"
#include "../src/PersistencyCriteriaAlgorithms/EdgeCutCriterion.h"
#include "../src/PersistencyCriteriaAlgorithms/TriangleCutCriterion.h"


TEST_CASE("testing_4_vertices") {
    std::vector<std::vector<std::vector<float>>> triple_costs{{{{-1,-1},{-1}},{{20}}}};
    int n_vertices{4};
    Instance instance{n_vertices,triple_costs};
    Constraints constraints{n_vertices};
    TriangleCutCriterion triangle_cut_criterion{instance, constraints, n_vertices};
    triangle_cut_criterion.evaluate_all_singlets();

    Constraints constraints_expected_result{n_vertices};
    bool comp;
    comp = constraints.getCuts() != constraints_expected_result.getCuts();
    CHECK(comp);
    constraints_expected_result.insert_cut(0,1);
    constraints_expected_result.insert_cut(0,2);
    constraints_expected_result.insert_cut(0,3);
    constraints_expected_result.insert_cut(1,2);
    constraints_expected_result.insert_cut(1,3);
    constraints_expected_result.insert_cut(2,3);
    comp = constraints.getCuts() == constraints_expected_result.getCuts();
    CHECK(comp);
}

TEST_CASE("testing_only_positive_costs") {
    std::vector<std::vector<std::vector<float>>> triple_costs{{{{1,1},{1}},{{1}}}};
    int n_vertices{4};
    Instance instance{n_vertices,triple_costs};
    Constraints constraints{n_vertices};
    TriangleCutCriterion triangle_cut_criterion{instance, constraints, n_vertices};
    triangle_cut_criterion.evaluate_all_singlets();

    Constraints constraints_expected_result{n_vertices};
    bool comp;
    comp = constraints.getCuts() != constraints_expected_result.getCuts();
    CHECK(comp);
    constraints_expected_result.insert_cut(0,1);
    constraints_expected_result.insert_cut(0,2);
    constraints_expected_result.insert_cut(0,3);
    constraints_expected_result.insert_cut(1,2);
    constraints_expected_result.insert_cut(1,3);
    constraints_expected_result.insert_cut(2,3);
    comp = constraints.getCuts() == constraints_expected_result.getCuts();
    CHECK(comp);
}

TEST_CASE("testing_no_edge_cut") {
    std::vector<std::vector<std::vector<float>>> triple_costs{{{{1,-1},{-1}},{{-1}}}};
    int n_vertices{4};
    Instance instance{n_vertices,triple_costs};
    Constraints constraints{n_vertices};
    TriangleCutCriterion triangle_cut_criterion{instance, constraints, n_vertices};
    triangle_cut_criterion.evaluate_all_singlets();

    Constraints constraints_expected_result{n_vertices};
    bool comp;
    comp = constraints.getCuts() == constraints_expected_result.getCuts();
    CHECK(comp);
}

TEST_CASE("testing_only_one_edge_not_cut") {
    std::vector<std::vector<std::vector<float>>> triple_costs{{{{1,1},{-1}},{{-1}}}};
    int n_vertices{4};
    Instance instance{n_vertices,triple_costs};
    Constraints constraints{n_vertices};
    TriangleCutCriterion triangle_cut_criterion{instance, constraints, n_vertices};
    triangle_cut_criterion.evaluate_all_singlets();

    Constraints constraints_expected_result{n_vertices};
    bool comp;
    comp = constraints.getCuts() != constraints_expected_result.getCuts();
    CHECK(comp);
    constraints_expected_result.insert_cut(0,1);
    constraints_expected_result.insert_cut(0,2);
    constraints_expected_result.insert_cut(0,3);
    constraints_expected_result.insert_cut(1,2);
    constraints_expected_result.insert_cut(1,3);
    comp = constraints.getCuts() == constraints_expected_result.getCuts();
    CHECK(comp);
}
