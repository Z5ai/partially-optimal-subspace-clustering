#ifndef PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_CONSTRAINTS_H
#define PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_CONSTRAINTS_H


#include <rapidjson.h>
#include <set>
#include "../Constants.h"
#include "ostreamwrapper.h"
#include "writer.h"

class Constraints {
    std::set<std::set<int>> cuts;
    std::set<std::set<int>> joins;
    int n_vertices;


public:
    Constraints(int n_vertices)
        :n_vertices{n_vertices}{
    }

    void insert_cut(int a, int b){
        cuts.insert({a,b});
    }

    void insert_join(int a, int b){
        joins.insert({a,b});
    }

    void cut_one_vertex(int u){
        for(int r{0}; r<n_vertices; r++){ if(r==u) continue;
            insert_cut(u, r);
        }
    }

    void cut_two_vertices(int u, int v){
        for(int r{0}; r<n_vertices; r++){ if(r==u || r==v) continue;
            insert_cut(u, r);
        }
        for(int r{0}; r<n_vertices; r++){ if(r==u || r==v) continue;
            insert_cut(v, r);
        }
    }

    std::set<std::set<int>> getCuts() {
        return cuts;
    }

    std::set<std::set<int>> getJoins() {
        return joins;
    }

    void print_constraints(){
        std::cout<<"\nCuts:\n";
        int c{0};
        for(std::set<int> cut: cuts){
            std::cout << "cut " << c << ": ";
            for(int vertex: cut){
                std::cout << vertex << " ";
            }
            std::cout << "\n";
            c++;
        }
        std::cout << "\n";
        std::cout<<"\nJoins:\n";
        int j{0};
        for(std::set<int> join: joins){
            std::cout << "join " << j << ": ";
            for(int vertex: join){
                std::cout << vertex << " ";
            }
            std::cout << "\n";
            j++;
        }
    }
};


#endif //PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_CONSTRAINTS_H
