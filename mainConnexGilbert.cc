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
	MATR resultats(100, vector<int>(1001)); //Matriz de resultados (exito o no)
	//Generamos 100 grafos aleatorios con la probabilidad de Gilbert dada y, para cada uno, hacemos los test con diferentes probabilidades de percolacion.
	for (int g = 0; g < 100; ++g) {

		for (int q = 0; q <= 1000; q = q + 1) {
			MATR gilb = gilbert(n, (float)q / 1000.0);
			vector<bool> erased(n, false);
			bool res = testConnex(gilb, erased);
			if (res) {
				resultats[g][q] = 0;
			}
			else {
				resultats[g][q] = 0;
			}
		}
	}
	vector<float> mean(1000);

	for (int q = 0; q <= 1000; q = q + 1) {
		mean[q] = 0.;

		for (int i = 0; i < 100; ++i) {
			mean[q] += (float) resultats[i][q];
		}
		mean[q] = (float) mean[q] / 100;
		cout << (float) q / 1000 << ", " << mean[q] <<  endl;
		//if (q % 10 == 0) cout << endl;
	}
}
