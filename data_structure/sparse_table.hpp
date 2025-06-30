#pragma once

#include<cassert>
#include<functional>
#include<vector>

template<typename T>
struct sparse_table {
	using F = std::function<T(T, T)>;

	F f;
	std::vector<std::vector<T>> table;
	std::vector<int> lr_length;

	sparse_table() = default;

	sparse_table(const std::vector<T> &v, const F &_f) : f(_f) {
		const int n = (int)v.size();
		const int msb = 32 - __builtin_clz(n);
		
		table.assign(msb, std::vector<T>(n));
		for(int i = 0;i < std::ssize(v);i++){
			table[0][i] = v[i];
		}
		for(int i = 1;i < msb;i++){
			for(int j = 0;j + (1 << i) <= n;j++){
				table[i][j] = f(table[i-1][j], table[i-1][j + (1 << (i-1))]);
			}
		}

		lr_length.resize(std::ssize(v) + 1);
		for(int i = 2;i < std::ssize(lr_length);i++){
			lr_length[i] = lr_length[i >> 1] + 1;
		}
	}

	T fold(int l, int r) const {
		return f(table[lr_length[r-l]][l], table[lr_length[r-l]][r-(1 << lr_length[r-l])]);
	}
};
