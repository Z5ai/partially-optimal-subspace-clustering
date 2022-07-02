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

triple_costs_type DataHandler::create_triple_costs(int n){
    std::ifstream ifs {triple_costs_path};
    if ( !ifs.is_open() )
    {

        std::cerr << "Could not open file for reading!\n";
        throw std::exception();
    }
    rapidjson::IStreamWrapper isw { ifs };
    rapidjson::Document doc {};
    doc.ParseStream( isw );


    triple_costs_type first_dim(n-2);
    for(int i{0}; i < n - 2; i++){

        std::vector<std::vector<float>> second_dim(n-i-2);
        for(int j{i+1}; j < n - 1; j++){

            std::vector<float> third_dim(n-j-1);
            for(int k{j+1}; k < n; k++){
                float cost{doc[i][j-i-1][k-j-1].GetFloat()};
                third_dim[k-j-1] = cost;
            }
            second_dim[j-i-1] = third_dim;
        }
        first_dim[i] = second_dim;
    }
    return first_dim;
}

// TODO: write function to sort vertices and access costtriples


void DataHandler::write_constraints(std::vector<edge_type> cuts, std::vector<edge_type> joins){
    for(edge_type cut: cuts){

    }
    for(edge_type join: joins){

    }
}
