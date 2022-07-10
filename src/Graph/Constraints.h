#ifndef PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_CONSTRAINTS_H
#define PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_CONSTRAINTS_H


#include <rapidjson.h>
#include <set>
#include "ostreamwrapper.h"
#include "writer.h"

class Constraints {
    std::set<std::set<int>> cuts;
    std::set<std::set<int>> joins;

public:
    Constraints() {}

    void insert_cut(int a, int b){
        cuts.insert({a,b});
    }

    void insert_join(int a, int b){
        joins.insert({a,b});
    }

    std::set<std::set<int>> getCuts() {
        return cuts;
    }

    std::set<std::set<int>> getJoins() {
        return joins;
    }

    void write_to_json(){

        //create document
        rapidjson::Document doc;
        rapidjson::Document::AllocatorType& allocator = doc.GetAllocator();
        rapidjson::Value o(rapidjson::kObjectType);

        rapidjson::Value cuts_json(rapidjson::kArrayType);
        for(std::set<int> cut: cuts){
            rapidjson::Value cut_json(rapidjson::kArrayType);
            for(int vertex: cut)
                cut_json.PushBack(vertex, allocator);
            cuts_json.PushBack(cut_json, allocator);
        }
        o.AddMember("different_partition", cuts_json, allocator);

        rapidjson::Value joins_json(rapidjson::kArrayType);
        for(std::set<int> join: joins){
            rapidjson::Value join_json(rapidjson::kArrayType);
            for(int vertex: join)
                join_json.PushBack(vertex, allocator);
            joins_json.PushBack(join_json, allocator);
        }
        o.AddMember("same_partition", joins_json, allocator);


        //write document to outputstream
        std::ofstream ofs{constraints_path};
        if (!ofs.is_open()) {
            std::cerr << "Could not open file for writing!\n";
            throw std::exception();
        }
        rapidjson::OStreamWrapper osw{ofs};
        rapidjson::Writer<rapidjson::OStreamWrapper> writer(osw);
        doc.Accept(writer);
    }
};


#endif //PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_CONSTRAINTS_H
