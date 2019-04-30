//Union Find

#ifndef UNION_FIND_H
#define UNION_FIND_H

class Union_Find {
	public:
	vector<int> id;
	vector<int> size;
	int find(int i);
	void union(int q, int p);
	