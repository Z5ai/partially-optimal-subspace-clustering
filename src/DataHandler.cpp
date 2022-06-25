//
// Created by david on 24.06.22.
//

#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <sstream>
#include "DataHandler.h"




std::vector<DataHandler::vertex> DataHandler::parse() {
    std::ifstream file;
    file.open(data_dir + "vertices.csv");

    std::string l;
    std::getline(file, l);
    std::vector<vertex> vertices;
    while (std::getline(file, l))
    {
        std::istringstream iss(l);
        float x, y, z;
        char c;
        if (!(iss >> x >> c >> y >> c >> z) && c == ',') { break; }
        vertex v{x,y,z};
        vertices.push_back(v);
    }

    file.close();
    return vertices;
}