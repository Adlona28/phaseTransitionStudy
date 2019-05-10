#include "unionFind.hh"
#include "graphgen.cc"

using namespace std;


bool testTopBottom(const MATR& matrix, float q, bool node, const vector<int>& top, const vector<int>& bottom) {
	//Top Auxiliar=n, Bottom Auxiliar=n+1
	int n = matrix.size();
	unionFind u(n + 2);
	if (node) {
		for (uint i = 0; i < matrix.size(); ++i) {
			if (seBorra(q)) u.delfind(i);
		}
		for (uint i = 0; i < matrix.size(); ++i) {
			if (u.find(i) != -1) {
				for (uint j = i + 1; j < matrix.size(); ++j) {
					if (u.find(j) != -1 and matrix[i][j])
						u.unir(i, j);
				}
			}
		}
		for (uint i = 0; i < top.size(); ++i) {
			if (u.find(top[i]) != -1)
				u.unir(n, top[i]);
		}
		for (uint i = 0; i < bottom.size(); ++i) {
			if (u.find(bottom[i]) != -1)
				u.unir(n + 1, bottom[i]);
		}
	}
	else {
		for (uint i = 0; i < matrix.size(); ++i) {
			for (uint j = i + 1; j < matrix.size(); ++j) {
				if (matrix[i][j] == 1 and not seBorra(q)) {
					u.unir(i, j);
				}
			}
		}
		for (uint i = 0; i < top.size(); ++i)
			u.unir(n, top[i]);
		for (uint i = 0; i < bottom.size(); ++i)
			u.unir(n + 1, bottom[i]);
	}
	return (u.find(n) == u.find(n + 1));
}

void DFS(int i, uint numVertices, vector<bool>& visited, vector<bool>& even, const vector<bool>& erased, const MATR& graph)
{
	if (erased[i]) DFS(i + 1, numVertices, visited, even, erased, graph);
	else {
		int connections = 0;
		visited[i] = true;
		for (uint j = 0; j < numVertices; j++) {
			if (graph[i][j] == 1 and !erased[j]) {
				connections++;
				if (!visited[j]) {
					DFS(j, numVertices, visited, even, erased, graph);
				}
			}
		}
		if (connections == 0) {
			if (i + 1 < (int)numVertices)DFS(i + 1, numVertices, visited, even, erased, graph);
			even[i] = true;
		}
		else if (connections % 2 == 0) even[i] = true;
	}
}

//0: el graf no es euleria ni te un sendero euleria
//1: el graf no es euleria pero si te un sendero euleria
//2: el graf es euleria
int testEulerian(const MATR& graph, const vector<bool>& erased) {
	vector<bool> even(graph.size(), false);
	vector<bool> visited(graph.size(), false);
	DFS(0, graph.size(), visited, even, erased, graph);
	int odds = 0;
	for (uint j = 0; j < graph.size(); j++) {
		if (!visited[j] and !erased[j]) {
			for (int adj : graph[j]) if (adj == 1) return 0;
		}
		else {
			if (!even[j] and !erased[j]) odds++;
			if (odds > 2) return 0;
		}
	}
	if (odds == 2) return 1;
	return 2;
}
