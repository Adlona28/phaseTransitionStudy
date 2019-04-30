	
#include "Union_Find.h"

	Union_Find::~Union_Find(){}
	Union_Find::Union_Find(int n) {
		id = vector<int>(n);
		size = vector<int>(n);
		for (int i = 0; i < n; ++i) {
			size[i] = 1;
			id[i] = i;
		}
	}
	
	int Union_Find::find(int i) {
		 while (i != id[i])
		 {
			id[i] = id[id[i]];
			i = id[i];
		 }
		 return i;
	}
	
	
	void Union_Find::union(int q, int p) { 
		int i = find(p);
		int j = find(q);
		if (i == j) return;
		if (sz[i] < sz[j]) id[i] = j; sz[j] += sz[i]; 
		else id[j] = i; sz[i] += sz[j]; 
	}