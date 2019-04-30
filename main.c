#include "percolacio.h"
#include "Union_Find.h"
#include "graphgen.h"

using namespace std;

int testValue(MATR matrix, float q, bool node) {
	Union_Find u = Union_Find(matrix.size());
	if (node) {
	}
	else {
		for (int i = 0; i < matrix.size(); ++i) {
			for (int j = 0; j < matrix.size(); ++j) {
				if (matrix[i][j] == 1 and not seBorra(q)) {
					union(i,j);
				}
			}
		}
	}
}


int main() {
	cout << "Dime el número de vertices que quieres" << endl;
	int n;
	cin >> n;
	cout << "Dime la probabilidad de Gilbert" << endl;
	float p;
	cin >> p;
	MATR resultats(100,vector<int>(1000));
	for (int i = 0; i < 100; ++i) {
		MATR gilbert = gilbert(n,p);
		for (float q = 0; q <= 1; q = q+0.001) {
			resultats[i][(int)q*1000] = testValue(gilbert,q);
		}
	}
}
