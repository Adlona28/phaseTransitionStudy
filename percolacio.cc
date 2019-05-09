#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;
typedef vector < vector<int> > MATR;

bool seBorra(float q){
    int prob = (int) (q*1000);
    return (rand()%1000)<prob;
}


void percolacionNodos(vector<bool>& erased, float q){
    for (uint j = 0; j < erased.size(); j++) {
        if(seBorra(q)){
            erased[j] = true;
        }
    }
}
void percolacionAristas(MATR graph, float q){
    for (uint i = 0; i < graph.size(); i++) {
        for (uint j = i+1; j < graph.size(); j++) {
            if(seBorra(q) and graph[i][j] == 1){
                graph[i][j] = -1;
                graph[j][i] = -1;
            }
        }
    }
}

void desPercolacionAristas(MATR graph){
    for (uint i = 0; i < graph.size(); i++) {
        for (uint j = i+1; j < graph.size(); j++) {
            if(graph[i][j] == -1){
                graph[i][j] = 1;
                graph[j][i] = 1;
            }
        }
    }
}
