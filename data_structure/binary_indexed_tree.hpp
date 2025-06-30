#pragma once

#include<cassert>
#include<vector>

template<typename T>struct binary_indexed_tree {
	int n;
	std::vector<T> BIT;
	binary_indexed_tree(int n_) : n(n_ + 1), BIT(n, 0) {}

	void add(int i, T x){
		assert(1 <= i && i <= n);
		for(int idx = i;idx < n;idx += (idx & -idx)){
			BIT[idx] += x;
		}
	}
	
	T sum(int i) {
		assert(1 <= i && i <= n);
		T ret = 0;
		for(int idx = i;idx > 0;idx -= (idx & -idx)){
			ret += BIT[idx];
		}
		return ret;
	}
};
