#ifndef GRAPHGEN_H
#define GRAPHGEN_H

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <assert.h>

using namespace std;

typedef vector < vector<int> > MATR;
const uint MAX_NODES = 1000;
const uint MAX_WEIGHT = 100;

//Undirected graphs generacion
MATR genRandomGraph(){
    int n = (rand() % MAX_NODES) + 1;
    MATR graph;
    graph.resize(n);

    for (uint i = 0; i < n; i++) {
        graph[n].resize(n, 0);
        graph[i][i] = -1;
    }
    int m = rand() % ((n*(n-1))/2+1);

    while (m > 0){
        int i = rand() % n;
        int j = rand() % n;
        if(i != j and graph[i][j] == 0){
             graph[i][j] = 1;
             graph[j][i] = 1;
             --m;
        }
    }
    return graph;
}

MATR genRandomGraph(int n){
    MATR graph;
    graph.resize(n);

    for (uint i = 0; i < n; i++) {
        graph[n].resize(n, 0);
        graph[i][i] = -1;
    }
    int m = rand() % ((n*(n-1))/2+1);

    while (m > 0){
        int i = rand() % n;
        int j = rand() % n;
        if(i != j and graph[i][j] == 0){
             graph[i][j] = 1;
             graph[j][i] = 1;
             --m;
        }
    }
    return graph;
}

MATR genRandomGraph(int n, int m){
    assert (m > (n*(n-1))/2);
    MATR graph;
    graph.resize(n);

    for (uint i = 0; i < n; i++) {
        graph[n].resize(n, 0);
        graph[i][i] = -1;
    }

    while (m > 0){
        int i = rand() % n;
        int j = rand() % n;
        if(i != j and graph[i][j] == 0){
             graph[i][j] = 1;
             graph[j][i] = 1;
             --m;
        }
    }
    return graph;
}

//Directed graphs generation
MATR genRandomDiGraph(){
    int n = (rand() % MAX_NODES) + 1;
    MATR graph;
    graph.resize(n);

    for (uint i = 0; i < n; i++) {
        graph[n].resize(n, 0);
        graph[i][i] = -1;
    }
    int m = rand() % ((n*(n-1))+1);

    while (m > 0){
        int i = rand() % n;
        int j = rand() % n;
        if(i != j and graph[i][j] == 0){
             graph[i][j] = rand()%2;
             --m;
        }
    }
    return graph;
}

MATR genRandomDiGraph(int n){
    MATR graph;
    graph.resize(n);

    for (uint i = 0; i < n; i++) {
        graph[n].resize(n, 0);
        graph[i][i] = -1;
    }
    int m = rand() % ((n*(n-1))+1);

    while (m > 0){
        int i = rand() % n;
        int j = rand() % n;
        if(i != j and graph[i][j] == 0){
             graph[i][j] = rand()%2;
             --m;
        }
    }
    return graph;
}

MATR genRandomDiGraph(int n, int m){
    assert (m > (n*(n-1)));
    MATR graph;
    graph.resize(n);

    for (uint i = 0; i < n; i++) {
        graph[n].resize(n, 0);
        graph[i][i] = -1;
    }

    while (m > 0){
        int i = rand() % n;
        int j = rand() % n;
        if(i != j and graph[i][j] == 0){
             graph[i][j] = rand()%2;
             --m;
        }
    }
    return graph;
}


//Undirected weighted graphs generation
MATR genRandomWeightedGraph(){
    int n = (rand() % MAX_NODES) + 1;
    MATR graph;
    graph.resize(n);

    for (uint i = 0; i < n; i++) {
        graph[n].resize(n, 0);
        graph[i][i] = -1;
    }
    int m = rand() % ((n*(n-1))/2+1);

    while (m > 0){
        int i = rand() % n;
        int j = rand() % n;
        if(i != j and graph[i][j] == 0){
             graph[i][j] = (rand()%MAX_WEIGHT) + 1;
             graph[j][i] = (rand()%MAX_WEIGHT) + 1;
             --m;
        }
    }
    return graph;
}

MATR genRandomWeightedGraph(int n){
    MATR graph;
    graph.resize(n);

    for (uint i = 0; i < n; i++) {
        graph[n].resize(n, 0);
        graph[i][i] = -1;
    }
    int m = rand() % ((n*(n-1))/2+1);

    while (m > 0){
        int i = rand() % n;
        int j = rand() % n;
        if(i != j and graph[i][j] == 0){
             graph[i][j] = (rand()%MAX_WEIGHT) + 1;
             graph[j][i] = (rand()%MAX_WEIGHT) + 1;
             --m;
        }
    }
    return graph;
}

MATR genRandomWeightedGraph(int n, int m){
    assert (m > (n*(n-1))/2);
    MATR graph;
    graph.resize(n);

    for (uint i = 0; i < n; i++) {
        graph[n].resize(n, 0);
        graph[i][i] = -1;
    }

    while (m > 0){
        int i = rand() % n;
        int j = rand() % n;
        if(i != j and graph[i][j] == 0){
             graph[i][j] = (rand()%MAX_WEIGHT) + 1;
             graph[j][i] = (rand()%MAX_WEIGHT) + 1;
             --m;
        }
    }
    return graph;
}


//Directed weighted graphs generation

MATR genRandomWeightedDiGraph(){
    int n = (rand() % MAX_NODES) + 1;
    MATR graph;
    graph.resize(n);

    for (uint i = 0; i < n; i++) {
        graph[n].resize(n, 0);
        graph[i][i] = -1;
    }
    int m = rand() % ((n*(n-1))+1);

    while (m > 0){
        int i = rand() % n;
        int j = rand() % n;
        if(i != j and graph[i][j] == 0){
             graph[i][j] = (rand()%MAX_WEIGHT) + 1;
             --m;
        }
    }
    return graph;
}

MATR genRandomWeightedDiGraph(int n){
    MATR graph;
    graph.resize(n);

    for (uint i = 0; i < n; i++) {
        graph[n].resize(n, 0);
        graph[i][i] = -1;
    }
    int m = rand() % ((n*(n-1))+1);

    while (m > 0){
        int i = rand() % n;
        int j = rand() % n;
        if(i != j and graph[i][j] == 0){
             graph[i][j] = (rand()%MAX_WEIGHT) + 1;
             --m;
        }
    }
    return graph;
}

MATR genRandomWeightedDiGraph(int n, int m){
    assert (m > (n*(n-1)));
    MATR graph;
    graph.resize(n);

    for (uint i = 0; i < n; i++) {
        graph[n].resize(n, 0);
        graph[i][i] = -1;
    }

    while (m > 0){
        int i = rand() % n;
        int j = rand() % n;
        if(i != j and graph[i][j] == 0){
             graph[i][j] = (rand()%MAX_WEIGHT) + 1;
             --m;
        }
    }
    return graph;
}
