#include "properties.cc"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <assert.h>

using namespace std;
void printMatr(MATR& prueba) {
	for (uint i = 0; i < prueba.size(); ++i) {
		for (uint j = 0; j < prueba.size(); j++) {
			cout << prueba[i][j] << "  ";
		}
		cout << endl;
	}
	vector<bool> erased(10, false);
}
int main() {
	//cout << "Dime el número de vertices que quieres" << endl;
	int n;
	cin >> n;
	//cout << "Percolacion de nodos (1) o aristas (0)" << endl;
	int nodos;
	cin >> nodos;
	MATR resultats(n, vector<int>(1001)); //Matriz de resultados (exito o no)
	//Generamos n grafos aleatorios con la probabilidad de Gilbert dada y, para cada uno, hacemos los test con diferentes probabilidades de percolacion.
	for (int g = 0; g < n; ++g) {
		MATR newman = newman_watts_strogatzGraph(n, g , 0.5);
		for (int q = 0; q <= 1000; q = q + 1) {

			vector<bool> erased(n, false);
			if (nodos) percolacionNodos(erased, (float)q / 1000.0);
			else percolacionAristas(newman, (float)q / 1000.0);
			bool res = testConnex(newman, erased);
			if (res) {
				resultats[g][q] = 1;
			}
			else {
				resultats[g][q] = 0;
			}
			if (!nodos)  desPercolacionAristas(newman);
		}
	}
	vector<float> mean(n);

	for (int q = 0; q < n; q = q + 1) {
		mean[q] = 0.;

		for (int i = 0; i < 1001; ++i) {
			mean[q] += (float) resultats[q][i];
		}
		mean[q] = (float) mean[q] / 1001;
		cout << q << ", " << mean[q] <<  endl;
	}
}
