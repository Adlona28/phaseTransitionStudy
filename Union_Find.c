#include "Union_Find.h"


Union_Find::~Union_Find(){}
Union_Find::Union_Find(int n) {
	id = std::vector<int>(n);
	size = std::vector<int>(n);
	for (int i = 0; i < n; ++i) {
		size[i] = 1;
		id[i] = i;
	}
}

int Union_Find::find(int i) {
	 if (id[i] == -1) return -1;
	 while (i != id[i])
	 {
		id[i] = id[id[i]];
		i = id[i];
	 }
	 return i;
}

void Union_Find::delfind(int i) {
	id[i] = -1;
}

void Union_Find::unir(int q, int p) { 
	int i = find(p);
	int j = find(q);
	if (i == j) return;
	if (size[i] < size[j]) {
		id[i] = j; 
		size[j] += size[i];
	} 
	else {
		id[j] = i; 
		size[i] += size[j]; 
	}
}
