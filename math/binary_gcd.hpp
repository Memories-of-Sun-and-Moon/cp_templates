
#pragma once

#include<algorithm>
#include<cmath>

long long binary_gcd(long long a, long long b){
	if(a == 0)return b;
	if(b == 0)return a;

	a = std::abs(a);
	b = std::abs(b);

	int a_zero = __builtin_ctzll(a);
	int b_zero = __builtin_ctzll(b);
	a >>= a_zero;
	b >>= b_zero;
	
	while(a != b){
		if(a > b){
			std::swap(a, b);
		}
		b -= a;
		b >>= __builtin_ctzll(b);
	}
	return a << std::min(a_zero, b_zero);
}
