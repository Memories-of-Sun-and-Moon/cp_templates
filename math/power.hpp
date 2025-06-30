
#pragma once

#include <type_traits>

template<typename T>
concept NotPrimitiveInt =
	!(std::is_same_v<T, int> ||
		std::is_same_v<T, long> ||
		std::is_same_v<T, long long> ||
		std::is_same_v<T, unsigned> ||
		std::is_same_v<T, unsigned long> ||
		std::is_same_v<T, unsigned long long>);

template<NotPrimitiveInt T>
T power(T n, long long k) {
	T ret = 1;
	while(k > 0) {
		if(k & 1)ret *= n;
		n = n*n;
		k >>= 1;
	}
	return ret;
}

long long power(long long n, long long k, long long p) {
	long long ret = 1;
	while(k > 0){
		if(k & 1)ret = ret*n % p;
		n = n*n % p;
		k >>= 1;
	}
	return ret;
}
