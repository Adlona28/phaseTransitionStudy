#include "properties.cc"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <assert.h>

using namespace std;

int main() {
	//cout << "Dime el número de vertices que quieres" << endl;
	int n;
	cin >> n;
	MATR resultatsEuleria(100, vector<int>(1001)); //Matriz de resultados (exito o no)
	MATR resultatsSendero(100, vector<int>(1001)); //Matriz de resultados (exito o no)
	//Generamos 100 grafos aleatorios con la probabilidad de Gilbert dada y, para cada uno, hacemos los test con diferentes probabilidades de percolacion.
	for (int g = 0; g < 100; ++g) {

		MATR uniform(n, vector<int>(n));
		for (int q = 0; q <= 1000; q++) {
			uniform = genRandomGraph(n, q);
			vector<bool> erased(n, false);
			int res = testEulerian(uniform, erased);
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
	vector<float> mean(1000);

	for (int q = 0; q <= 1000; q = q + 1) {
		mean[q] = 0.;

		for (int i = 0; i < 100; ++i) {
			mean[q] += (float) resultatsSendero[i][q];
		}
		mean[q] = (float) mean[q] / 100;
		cout << q << ", " << mean[q] <<  endl;
		//if (q % 10 == 0) cout << endl;
	}
	cout << endl << endl << endl;

	for (int q = 0; q <= 1000; q = q + 1) {
		mean[q] = 0.;

		for (int i = 0; i < 100; ++i) {
			mean[q] += (float) resultatsEuleria[i][q];
		}
		mean[q] = (float) mean[q] / 100;
		cout << q << ", " << mean[q] <<  endl;
		//if (q % 10 == 0) cout << endl;
	}
}
