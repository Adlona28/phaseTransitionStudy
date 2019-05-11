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
	cout << "Dime el número de vertices que quieres" << endl;
	int n;
	cin >> n;
	MATR resultats(100, vector<int>(1001)); //Matriz de resultados (exito o no)
	//Generamos 100 grafos aleatorios con la probabilidad de Gilbert dada y, para cada uno, hacemos los test con diferentes probabilidades de percolacion.
	for (int g = 0; g < 100; ++g) {

		for (int q = 0; q <= 1000; q = q + 1) {
			
			MATR erd = erdos(n, (float)q / 1000.0);
			vector<bool> erased(n, false);
			bool res = testConnex(erd, erased);\
			cout << (float)q / 1000.0 << " -> " << res << endl;
			//cout << (float)q / 1000.0 << endl << res << endl; printMatr(erd);
			if (res) {
				resultats[g][q] = 1;
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
		cout << (float) q / 1000 << ": " << mean[q] <<  "  ";
		if (q % 10 == 0) cout << endl;
	}
}
