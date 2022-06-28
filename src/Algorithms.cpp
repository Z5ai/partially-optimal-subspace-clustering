//
// Created by david on 26.06.22.
//

#include "Algorithms.h"


//input: complete graph, calculated cost per costtriangle of this graph
//output: graph with predecided edges (0:cut, 1:join)
void Algorithms::evaluate_edge_criterion(){
    for v_dim1 in graph.vertices:
        for v_dim2 in graph.vertices:
            for v_dim3 in graph.vertices:
                look if edges[v_dim1][v_dim2][v_dim3] is    negative, positive
                or add edges[v_dim1][v_dim2][v_dim3] up to something.
};

void Algorithms::evaluate_triangle_criterion(){

};
