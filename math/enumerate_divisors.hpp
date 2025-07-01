#pragma once

#include "./factor.hpp"

#include<algorithm>
#include<vector>

template<typename T>
std::vector<T> enumerate_divisors(T n) {
	std::vector<T> ret = {1};

	long long mul = -1;
	long long pre = -1;
	int size_before = 1;

	for(auto p : factor(n)){
		mul = (p == pre ? mul*p : p);
		int sz = (p == pre ? size_before : std::ssize(ret));
		for(int i = 0;i < sz;i++){
			ret.emplace_back(ret[i] * mul);
		}
		pre = p;
		size_before = sz;
	}
	std::sort(ret.begin(), ret.end());
	return ret;
}
