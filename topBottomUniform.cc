#include "properties.cc"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <assert.h>

using namespace std;

int main() {
	cout << "Generador de grafos uniforme" << endl;
	cout << "Percolación por nodos (1) o por aristas (0)" << endl;
	int node;
	cin >> node;
	MATR resultats(100,vector<int>(1001)); //Matriz de resultados (exito o no)
	for (int g = 0; g < 100; ++g) {
		MATR uniform = genUniform();
		int n = uniform.size();
		vector<int> top;
		top.push_back(0);
		int count = 1;
		vector<int> bottom;
		for (int i = 0; i < n and count < n/10; i++) {
			if (uniform[top[0]][i]) {
				top.push_back(i);
				count++;
			}
			else if (i != top[0]) bottom.push_back(i);
		}
		if (bottom.size() == 0) {
			int i = 1; 
			while (uniform[top[0]][i] and i < n) i++;
			if (i < n) bottom.push_back(i);
			else bottom.push_back(n/4);
		}
		count = bottom.size();
		for (int i = 0; i < n and count < n/10; i++) {
			if (uniform[bottom[0]][i] and not uniform[top[0]][i] and i != top[0]) {
				bottom.push_back(i);
				count++;
			}
		}
		//for (int i = 0; i < top.size(); ++i) cout << top[i] << " ";
		//cout << endl;
		//for (int i = 0; i < bottom.size(); ++i) cout << bottom[i] << " ";
		cout << g+1 << "th Graph generated..." << endl;
		for (int q = 0; q <= 1000; q = q+1) {
			resultats[g][q] = (int) testTopBottom(uniform, (float)((float)q/(float)1000), node == 1, top, bottom);
		}
	}
	vector<float> mean(1000);
	for (int q = 0; q <= 1000; q = q+1) {
		mean[q] = 0.;
		for (int i = 0; i < 100; ++i) {
			mean[q] += (float) resultats[i][q];
		}
		mean[q] = (float) mean[q] / 100;
		cout << (float) q/1000 << ": " << mean[q] <<  endl;
	}
}
