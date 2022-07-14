#ifndef PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_INSTANCE_H
#define PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_INSTANCE_H


#include <utility>
#include <vector>
#include <fstream>
#include <iostream>
#include "istreamwrapper.h"
#include "document.h"
#include "Constraints.h"

class Instance {
    std::vector<std::vector<std::vector<float>>> triple_costs;
    int n_vertices{};


public:
    Instance(int n_vertices): n_vertices{n_vertices} {
        std::ifstream ifs{triple_costs_path};
        if (!ifs.is_open()) {
            std::cerr << "Could not open file for reading!\n";
            throw std::exception();
        }
        rapidjson::IStreamWrapper isw{ifs};
        rapidjson::Document doc{};
        doc.ParseStream(isw);


        triple_costs.resize(this->n_vertices - 2);
        for (int i{0}; i < this->n_vertices - 2; i++) {

            std::vector<std::vector<float>> second_dim(this->n_vertices - i - 2);
            for (int j{i + 1}; j < this->n_vertices - 1; j++) {

                std::vector<float> third_dim(this->n_vertices - j - 1);
                for (int k{j + 1}; k < this->n_vertices; k++) {
                    float cost{doc[i][j - i - 1][k - j - 1].GetFloat()};
                    third_dim[k - j - 1] = cost;
                }
                second_dim[j - i - 1] = third_dim;
            }
            triple_costs[i] = second_dim;
        }
    }

    Instance(int n_vertices, std::vector<std::vector<std::vector<float>>> triple_costs):
        n_vertices{n_vertices},triple_costs{std::move(triple_costs)}{
    }

    int get_n_vertices() const {
        return n_vertices;
    }

    float get_cost(int i, int j, int k) const {
        if (i > j)
            std::swap(i, j);
        if (i > k)
            std::swap(i, k);
        if (j > k)
            std::swap(j, k);
        return triple_costs.at(i).at(j - i - 1).at(k - j - 1);
    }
};

#endif //PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_INSTANCE_H
