//Union Find

#ifndef UNIONFIND_H
#define UNIONFIND_H

#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;
class unionFind {
	public:
	vector<int> id;
	vector<int> size;
	unionFind(int n);
	~unionFind();
	int find(int i);
	void delfind(int i);
	void unir(int q, int p);
};
#endif
