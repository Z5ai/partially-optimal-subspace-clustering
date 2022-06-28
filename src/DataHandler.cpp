//
// Created by david on 24.06.22.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include "DataHandler.h"
#include "Graph.h"





Graph DataHandler::create_graph() {
    std::ifstream file;
    file.open(data_dir + "vertices.csv");

    std::string l;
    std::getline(file, l);
    Graph graph{};
    while (std::getline(file, l))
    {
        std::istringstream iss(l);
        float x, y, z;
        char c;
        if (!(iss >> x >> c >> y >> c >> z) && c == ',') { break; }
        vertex v{x,y,z};
        graph.insert_vertex(v);
    }

    file.close();
    return graph;
}



