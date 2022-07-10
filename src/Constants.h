#ifndef PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_CONSTANTS_H
#define PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_CONSTANTS_H


enum Mode {EDGE, TRIANGLE};


//settings
const int n_planes{3};
const int n_vertices_per_plane{33};
const float stddev{0.01};
const float threshold_factor{3};
const Mode mode{EDGE};
const std::string project_path{R"(/home/david/3_01__educ__TUD/INF-PM-FPA/partially-optimal-subspace-clustering)"};


//derived from settings
const int n_vertices{n_planes * n_vertices_per_plane};
const float threshold{threshold_factor * stddev};

//paths
const std::string temp_path{project_path + R"(/temp)"};
const std::string triple_costs_path{temp_path + "/triple_costs.json"};
const std::string synthesized_instance_path{temp_path + "/synthesized_instance.csv"};
const std::string constraints_path{temp_path + "/constraints.json"};

const std::string go_project_path{project_path + R"(/dependencies/local-search-algorithm-for-cubic-clustering)"};
const std::string go_script_path{go_project_path + R"(/src/partitioning3D/evaluation)"};

#endif //PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_CONSTANTS_H
