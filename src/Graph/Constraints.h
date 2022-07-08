#ifndef PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_CONSTRAINTS_H
#define PARTIALLY_OPTIMAL_SUBSPACE_CLUSTERING_CONSTRAINTS_H


#include <rapidjson.h>
#include "ostreamwrapper.h"
#include "writer.h"

class Constraints {
    std::vector<std::array<int,2>> cuts;
    std::vector<std::array<int,2>> joins;

public:
    Constraints() {}

    void insert_cut(int a, int b){
        cuts.push_back({a,b});
    }

    void insert_join(int a, int b){
        joins.push_back({a,b});
    }

    void write_to_json(){
        //TODO:

        //create document
        rapidjson::Document doc;
        rapidjson::Document::AllocatorType& allocator = doc.GetAllocator();
        rapidjson::Value o(rapidjson::kObjectType);

        rapidjson::Value cuts_json(rapidjson::kArrayType);
        for(std::array<int,2> cut: cuts){
            rapidjson::Value cut_json(rapidjson::kArrayType);
            cut_json.PushBack(cut[0], allocator);
            cut_json.PushBack(cut[1], allocator);
            cuts_json.PushBack(cut_json, allocator);
        }
        o.AddMember("different_partition", cuts_json, allocator);

        rapidjson::Value joins_json(rapidjson::kArrayType);
        for(std::array<int,2> join: joins){
            rapidjson::Value join_json(rapidjson::kArrayType);
            join_json.PushBack(join[0], allocator);
            join_json.PushBack(join[1], allocator);
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
