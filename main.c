#include "properties.c"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <assert.h>

using namespace std;

int main() {
	cout << "Dime el número de vertices que quieres" << endl;
	int n;
	cin >> n;
	cout << "Dime la probabilidad de Gilbert" << endl;
	float p;
	cin >> p;
	cout << "Percolación por nodos (1) o por aristas (0)" << endl;
	int node;
	cin >> node;
	MATR resultats(100,vector<int>(1000)); //Matriz de resultados (exito o no
	//Generamos 100 grafos aleatorios con la probabilidad de Gilbert dada y, para cada uno, hacemos los test con diferentes probabilidades de percolacion.
	cout << "Dime los nodos que pertenecen a top terminando en -1" << endl;
	vector<int> top;
	int nodo = -2;
	while (nodo != -1) {
		cin >> nodo;
		top.push_back(nodo);
	}
	cout << "Dime los nodos que pertenecen a bottom terminando en -1" << endl;
	vector<int> bottom;
	nodo = -2;
	while (nodo != -1) {
		cin >> nodo;
		bottom.push_back(nodo);
	}
	for (int i = 0; i < 100; ++i) {
		MATR gilb = gilbert(n,p);
		cout << i+1 << "st Graph generated..." << endl;
		for (int q = 0; q <= 1000; q = q+1) {
			resultats[i][(int) (q*1000.0)] = (int) testTopBottom(gilb, (float)(q/1000), node == 1, top, bottom);
			cout << "Asignado." << endl;
		}
	}
}
