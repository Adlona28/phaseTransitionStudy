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
MATR genUniform() {
    int n = (rand() % MAX_NODES) + 50;
    MATR graph (n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        graph[i][i] = -1;
    }
    int m = rand() % ((n * (n - 1)) / 2 + 1);

    while (m > 0) {
        int i = rand() % n;
        int j = rand() % n;
        if (i != j and graph[i][j] == 0) {
            graph[i][j] = 1;
            graph[j][i] = 1;
            --m;
        }
    }
    return graph;
}

MATR genRandomGraph(int n, int m) {
    MATR graph (n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        graph[i][i] = -1;
    }

    while (m > 0) {
        int i = rand() % n;
        int j = rand() % n;
        if (i != j and graph[i][j] == 0) {
            graph[i][j] = 1;
            graph[j][i] = 1;
            --m;
        }
    }
    return graph;
}

MATR modeloAleatorio1(int n, int m) {
    assert (m > (n * (n - 1)) / 2);
    MATR graph (n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        graph[i][i] = -1;
    }

    while (m > 0) {
        int i = rand() % n;
        int j = rand() % n;
        if (i != j and graph[i][j] == 0) {
            graph[i][j] = 1;
            graph[j][i] = 1;
            --m;
        }
    }
    return graph;
}

//Models:
MATR erdos (int n, float p) {
    MATR result (n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        result[i][i] = -1;
        for (int j = i + 1; j < n; ++j) {
            if (seBorra(p)) {
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


MATR cyclicGraph () {
    int n = (rand() % MAX_NODES) + 50;
    MATR result (n, vector<int>(n));
	for (int i = 0; i < n; ++i)
		result[i][i] = 1;
	int ciclos = rand()%(n/2)+1;
	for (int i = 0; i < ciclos; i++) {
		int mainNode = (rand() % n); //Node that generate the cycle
		vector<bool> visited(n, false);
		visited[mainNode]=true;
		int numCycle = (rand() % n); //Number of nodes that form the cycle
		int oldN = mainNode;
		int newN = (rand() % n);
		for (int i = 0; i < numCycle-1; ++i) {
			while (visited[newN]) newN = rand()%n;
			result[oldN][newN]=1;
			result[newN][oldN]=1;
			visited[newN]=true;
			oldN = newN;
		}
		result[newN][mainNode] = 1;
		result[mainNode][newN] = 1;
	}
    return result;
}

MATR watts_strogatzGraph (int n, int k, float p) {
	assert (k<n);
    MATR result (n, vector<int>(n));
	for (int i = 0; i < n; ++i) {
        result[i][i] = -1;
		int j = i+1;
		for (int t = 0; t <= k; ++t) {  //Connecting with k-neighbours
			result[i][j%n] = 1;
			result[j%n][i] = 1;
			++j;
            if(j==i) ++j;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
		    if (result[i][j] and i != j and not seBorra((float)((float)1-(float)p))) {
				int newN = (rand() % n);
				if (newN != i and newN != j and not result[i][newN]) {
				    result[i][j] = 0;
				    result[j][i] = 0;
				    result[i][newN] = 1;
				    result[newN][i] = 1;
				}
		    }
		}
	}
    return result;
}
