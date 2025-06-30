
#pragma once

#include<functional>
#include<vector>

template<typename T>
struct [[deprecated("use 1-indexed segment tree (segment_tree.hpp)")]] segment_tree {
	using F = std::function<T(T, T)>;

	int n;
	std::vector<T> node;
	F combine;
	T identify;

	segment_tree(std::vector<T> v, F _combine, T _identity) : combine(_combine), identify(_identity) {
		int sz = (int)v.size();
		n = 1;
		while(n < sz)n *= 2;
		node.resize(2 * n - 1, identify);

		for(int i = 0;i < sz;i++)node[i + n - 1] = v[i];
		for(int i = n - 2;i >= 0;i--)node[i] = combine(node[2 * i + 1], node[2 * i + 2]);
	}

	segment_tree(int _n, F _combine, T _identify) : combine(_combine), identify(_identify){
		int sz = _n;
		n = 1;
		while(n < sz)n *= 2;
		node.resize(2 * n - 1, identify);
	}

	T operator[](int x) {return node[x + n - 1]; }

	void set(int x, T val){
		x += (n - 1);

		node[x] = val;
		while(x > 0){
			x = (x - 1) / 2;
			node[x] = combine(node[2 * x + 1], node[2 * x + 2]);
		}
	}

	T fold(int a, int b, int k = 0, int l = 0, int r = -1){
		if(r < 0) r = n;

		if(r <= a || b <= l)return identify;
		
		if(a <= l && r <= b)return node[k];

		T vl = fold(a, b, 2 * k + 1, l, (l + r) / 2);
		T vr = fold(a, b, 2 * k + 2, (l + r) / 2, r);
		return combine(vl, vr);
	}
};
