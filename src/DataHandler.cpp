#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "DataHandler.h"
#include "Constants.h"
#include "istreamwrapper.h"
#include "document.h"

std::vector<vertex_type> DataHandler::create_vertices() {
    std::ifstream file;
    file.open(synthesized_instance_path);
    std::string l;
    std::getline(file, l);
    std::vector<vertex_type> vertices;
    while (std::getline(file, l))
    {
        std::istringstream iss(l);
        float x, y, z;
        char c;
        if (!(iss >> x >> c >> y >> c >> z) && c == ',') { break; }
        vertex_type v{x, y, z};
        vertices.push_back(v);
    }
    file.close();
    return vertices;
}

triple_costs_type DataHandler::create_triple_costs(int v){

    std::ifstream ifs {triple_costs_path};
    if ( !ifs.is_open() )
    {
        std::cerr << "Could not open file for reading!\n";
        throw std::exception();
    }
    rapidjson::IStreamWrapper isw { ifs };
    rapidjson::Document doc {};
    doc.ParseStream( isw );



    std::vector<std::vector<std::vector<float>>> dim_o;
    for(int o{0}; o < v; o++){

        std::vector<std::vector<float>> dim_m;
        for(int m{o+1}; m < v; m++){

            std::vector<float> dim_i;
            for(int i{m+1}; i < v; i++){
                float cost{doc[o][m][i].GetFloat()};
                dim_i.push_back(cost);
            }
            dim_m.push_back(dim_i);
        }
        dim_o.push_back(dim_m);
    }
    return dim_o;
}

void DataHandler::write_constraints(std::vector<edge_type> cuts, std::vector<edge_type> joins){
    for(edge_type cut: cuts){

    }
    for(edge_type join: joins){

    }
}
