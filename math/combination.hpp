#pragma once

#include "modint.hpp"

#include<vector>

constexpr int max_combination = 1010101;
template<typename T>
struct binomial {

	std::vector<T> fact, inv_fact;

	binomial(){
		fact.resize(max_combination);
		inv_fact.resize(max_combination);
		fact[0] = 1, inv_fact[0] = 1;
		for(int i = 1;i < max_combination;i++){
			fact[i] = fact[i - 1];
			fact[i] *= i;
			inv_fact[i] = inv_fact[i - 1];
			inv_fact[i] /= i;
		}
	}

	T nCr(int n, int r){
		if(r < 0 || r > n)return 0;

		modint ret = fact[n];
		ret *= inv_fact[r];
		ret *= inv_fact[n - r];

		return ret;
	}
};
