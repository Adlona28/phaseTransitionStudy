
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;
typedef vector < vector<int> > MATR;

bool seBorra(float q){
    int prob = (int) (q*1000);
    return (rand()%1000)<prob;
}


void percolacionNodos(MATR graph, float q){
    for (uint i = 0; i < graph.size()) {
        if(seBorra(q)){
            graph.erase(vec.begin() + i);
            for (uint j = 0; j < graph.size(); j++) {
                graph[j].erase(graph[j].begin() + i)
            }
        }
        else{
            i++;
        }
    }
}

void percolacionAristas(MATR graph, float q){
    for (uint i = 0; i < graph.size(); i++) {
        for (uint j = i+1; j < graph.size(); j++) {
            if(seBorra(q)){
                graph[i][j] = 0;
                graph[j][i] = 0;
            }
        }
}

void percolacionAristasDirigit(MATR graph, float q){
    for (uint i = 0; i < graph.size(); i++) {
        for (uint j = 0; j < graph.size(); j++) {
            if(seBorra(q)){
                graph[i][j] = 0;
            }
        }
}
