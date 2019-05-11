#include "properties.cc"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <assert.h>

using namespace std;

int main() {
	cout << "Generador de grafos ciclicos" << endl;
	cout << "Percolación por nodos (1) o por aristas (0)" << endl;
	int node;
	cin >> node;
	MATR resultats(100,vector<int>(1001)); //Matriz de resultados (exito o no)
	for (int g = 0; g < 100; ++g) {
		MATR cyclic = cyclicGraph();
		cout << g+1 << "th Graph generated..." << endl;
		for (int q = 0; q <= 1000; q = q+1) {
			resultats[g][q] = (int) testCycle(cyclic, (float)((float)q/(float)1000), node == 1);
		}
	}
	vector<float> mean(1001);
	for (int q = 0; q <= 1000; q = q+1) {
		mean[q] = 0.;
		for (int i = 0; i < 100; ++i) {
			mean[q] += (float) resultats[i][q];
		}
		mean[q] = (float) mean[q] / 100;
		printf("%.3f %.2f\n",(float)((float)1 -(float) q/1000),mean[q]);
		//cout << (float)((float)1 -(float) q/1000) << "\t" << mean[q] <<  endl;
	}
}
