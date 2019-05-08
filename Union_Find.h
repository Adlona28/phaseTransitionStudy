//Union Find

#ifndef UNION_FIND_H
#define UNION_FIND_H

#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;
class Union_Find {
	public:
	vector<int> id;
	vector<int> size;
	Union_Find(int n);
	~Union_Find();
	int find(int i);
	void delfind(int i);
	void unir(int q, int p);
};
#endif
