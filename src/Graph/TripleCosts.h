#ifndef PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_TRIPLECOSTS_H
#define PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_TRIPLECOSTS_H


#include <vector>
#include "../Constants.h"
#include "istreamwrapper.h"
#include "document.h"

class TripleCosts {
    std::vector<std::vector<std::vector<float>>> triple_costs;


public:
    TripleCosts(int n_vertices) {
        std::ifstream ifs{triple_costs_path};
        if (!ifs.is_open()) {
            std::cerr << "Could not open file for reading!\n";
            throw std::exception();
        }
        rapidjson::IStreamWrapper isw{ifs};
        rapidjson::Document doc{};
        doc.ParseStream(isw);


        triple_costs.reserve(n_vertices - 2);
        for (int i{0}; i < n_vertices - 2; i++) {

            std::vector<std::vector<float>> second_dim(n_vertices - i - 2);
            for (int j{i + 1}; j < n_vertices - 1; j++) {

                std::vector<float> third_dim(n_vertices - j - 1);
                for (int k{j + 1}; k < n_vertices; k++) {
                    float cost{doc[i][j - i - 1][k - j - 1].GetFloat()};
                    third_dim[k - j - 1] = cost;
                }
                second_dim[j - i - 1] = third_dim;
            }
            triple_costs[i] = second_dim;
        }
    }

    float get_triple_cost(int i, int j, int k) const {
        if (i > j)
            std::swap(i, j);
        if (i > k)
            std::swap(i, k);
        if (j > k)
            std::swap(j, k);
        return triple_costs.at(i).at(j - i - 1).at(k - j - 1);
    }
};

#endif //PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_TRIPLECOSTS_H
