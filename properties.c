#include "Union_Find.h"
#include "graphgen.h"

using namespace std;


bool testTopBottom(const MATR& matrix, float q, bool node, const vector<int>& top, const vector<int>& bottom) {
	//Top Auxiliar=n, Bottom Auxiliar=n+1
	int n = matrix.size();
	Union_Find u(n+2);
	if (node) {
		for (int i = 0; i<matrix.size(); ++i) {
			if(seBorra(q)) u.delfind(i);
		}
		for (int i = 0; i<matrix.size(); ++i) {
			if (u.find(i)!=-1) {
				for (int j= i+1; j<matrix.size(); ++j) {
					if (u.find(j) != -1 and matrix[i][j])
						u.unir(i,j);
				}
			}
		}
		for (int i = 0; i < top.size(); ++i) {
			if (u.find(top[i]) != -1)
				u.unir(n,top[i]);
		}
		for (int i = 0; i < bottom.size(); ++i) {
			if (u.find(bottom[i]) != -1)
				u.unir(n+1,bottom[i]);
		}
	}
	else {
		for (int i = 0; i < matrix.size(); ++i) {
			for (int j = i+1; j < matrix.size(); ++j) {
				if (matrix[i][j] == 1 and not seBorra(q)) {
					u.unir(i,j);
				}
			}
		}
		for (int i = 0; i < top.size(); ++i)
			u.unir(n,top[i]);
		for (int i = 0; i < bottom.size(); ++i)
			u.unir(n+1,bottom[i]);
	}
	return (u.find(n) == u.find(n+1));
}
