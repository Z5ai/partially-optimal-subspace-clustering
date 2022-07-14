#ifndef PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_CONSTANTS_H
#define PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_CONSTANTS_H


enum Mode {EDGE_CUT, TRIANGLE_CUT, TRIANGLE_JOIN};


//settings
const int n_planes{3};
const int n_vertices_per_plane{33};
const float stddev{0.001};
const Mode mode{TRIANGLE_JOIN};
const std::string project_path{R"(/home/david/3_01__educ__TUD/INF-PM-FPA/partially-optimal-subspace-clustering)"};


//derived from settings
const int n_vertices{n_planes * n_vertices_per_plane};
const float threshold{3 * stddev};

//paths
const std::string temp_path{project_path + R"(/temp)"};
const std::string triple_costs_path{temp_path + "/triple_costs.json"};
const std::string synthesized_instance_path{temp_path + "/synthesized_instance.csv"};

const std::string go_project_path{project_path + R"(/dependencies/local-search-algorithm-for-cubic-clustering)"};
const std::string go_script_path{go_project_path + R"(/src/partitioning3D/evaluation)"};

#endif //PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_CONSTANTS_H
