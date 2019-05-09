#include <iostream>
#include <vector>
#include <stdlib.h>
#include <assert.h>
#include "percolacio.cc"

using namespace std;

typedef vector < vector<int> > MATR;
const uint MAX_NODES = 1000;
const uint MAX_WEIGHT = 100;

//Undirected graphs generacion
MATR genRandomGraph(){
    int n = (rand() % MAX_NODES) + 1;
    MATR graph (n,vector<int>(n));

    for (int i = 0; i < n; i++) {
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
    MATR graph (n,vector<int>(n));

    for (int i = 0; i < n; i++) {
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

MATR genErdos(int n, int m){
    assert (m > (n*(n-1))/2);
    MATR graph (n,vector<int>(n));

    for (int i = 0; i < n; i++) {
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

//Models:
MATR gilbert (int n, float p) {
	MATR result (n,vector<int>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i != j and not seBorra((float)((float)1-(float)p))) {
				result[i][j] = 1;
				result[j][i] = 1;
			}
			else {
				result[i][j] = 0;
				result[j][i] = 0;
			}
		}
	}
	return result;
}


int calcul(int n, int m) {
	int val = n*(n-1)/2;
	int rest = val - m;
	int parcial = 1;
	while (val >= m) {
		parcial *= val;
		val = val-1;
	}
	while (rest >= 1) {
		parcial /= rest;
	}
	return parcial;
}


MATR erdos (int n, int m) {
	MATR result (n,vector<int>(n));
	double p = 1/calcul(n,m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (not seBorra(p)) {
				result[i][j] = true;
				result[j][i] = true;
			}
			else {
				result[i][j] = false;
				result[j][i] = false;
			}
		}
	}
  return result;
}



/*
Sources:
https://www.quora.com/How-could-a-random-graph-e-g-Erdos-Renyi-graphs-be-implemented-in-the-C-language-no-C-and-C++
https://en.wikipedia.org/wiki/Erd%C5%91s%E2%80%93R%C3%A9nyi_model
https://en.wikipedia.org/wiki/Random_graph
*/
