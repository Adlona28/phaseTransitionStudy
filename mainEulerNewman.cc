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
	MATR resultatsEuleria(n, vector<int>(1001)); //Matriz de resultados (exito o no)
	MATR resultatsSendero(n, vector<int>(1001)); //Matriz de resultados (exito o no)
	//Generamos n grafos aleatorios con la probabilidad de Gilbert dada y, para cada uno, hacemos los test con diferentes probabilidades de percolacion.
	cout << "sicansios" << endl;
	for (int g = 0; g < n; ++g) {
		MATR newman = newman_watts_strogatzGraph(n, g , 0.5);

		for (int q = 0; q <= 1000; q = q + 1) {
			vector<bool> erased(n, false);
			int res = testEulerian(newman, erased);
			if (res == 0) {
				resultatsEuleria[g][q] = 0;
				resultatsSendero[g][q] = 0;
			}
			if (res == 1) {
				resultatsEuleria[g][q] = 0;
				resultatsSendero[g][q] = 1;
			}
			if (res == 2) {
				resultatsEuleria[g][q] = 1;
				resultatsSendero[g][q] = 1;
			}
		}
	}
	vector<float> mean(n);

	for (int q = 0; q < n; q = q + 1) {
		mean[q] = 0.;

		for (int i = 0; i < 1001; ++i) {
			mean[q] += (float) resultatsSendero[q][i];
		}
		mean[q] = (float) mean[q] / 1001;
		cout << q << ", " << mean[q] <<  endl;
	}
	cout << endl << endl << endl;

	for (int q = 0; q < n; q = q + 1) {
		mean[q] = 0.;

		for (int i = 0; i < 1001; ++i) {
			mean[q] += (float) resultatsEuleria[q][i];
		}
		mean[q] = (float) mean[q] / 1001;
		cout << q << ", " << mean[q] <<  endl;
	}
}
