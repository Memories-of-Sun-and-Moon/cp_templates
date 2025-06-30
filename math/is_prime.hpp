#pragma once

#include<vector>

__int128_t __power(__int128_t n, __int128_t k, __int128_t m) {
	n %= m;
	__int128_t ret = 1;
	while(k > 0){
		if(k & 1)ret = ret * n % m;
		n = __int128_t(n) * n % m;
		k >>= 1;
	}
	return ret % m;
}

bool is_prime(long long n){
	if(n <= 1)return false;
	if(n == 2 || n == 3 || n == 5)return true;
	if(n % 2 == 0)return false;
	if(n % 3 == 0)return false;
	if(n % 5 == 0)return false;

	std::vector<long long> A = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};

	long long s = 0, d = n - 1;
	while(d % 2 == 0){
		s++;
		d >>= 1;
	}

	for (auto a : A){
		if(a % n == 0)return true;
		long long t, x = __power(a, d, n);
		if(x != 1){
			for(t = 0;t < s;t++){
				if(x == n - 1)break;
				x = __int128_t(x) * x % n;
			}
			if(t == s)return false;
		}
	}
	return true;
}
