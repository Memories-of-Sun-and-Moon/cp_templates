#pragma once

#include "../math/iroot.hpp"
#include "../math/power.hpp"

#include<algorithm>
#include<cassert>
#include<cmath>
#include<map>
#include<numeric>
#include<vector>

long long __modinv(long long a, long long m){
	long long b=m, u=1, v=0;
	while(b){
		long long t = a/b;
		a -= t*b; std::swap(a, b);
		u -= t*v; std::swap(u, v);
	}
	u %= m;
	if(u < 0)u += m;
	return u;
}

long long discrete_logarithm(long long x, long long y, long long m) {
	assert(x < m && y < m);
	if(m == 1)return 0;
	if(y == 1)return 0;
	if(x == 0){
		if(y == 1)return 0;
		else if(y == 0)return 1;
		else return -1;
	}

	if(std::gcd(x, m) != 1){
		long long d = std::gcd(x, m);
		if(y%d)return -1;
		y /= d;
		m /= d;
		long long ret = discrete_logarithm(x%m, (y*__modinv(x/d, m))%m, m);
		if(ret == -1)return -1;
		else return ret+1;
	}

	long long sq = iroot(m);
	if(sq < 3)sq = 3;
	std::vector<long long> _b(sq);
	for(int i = 0;i < sq;i++)_b[i] = (i == 0 ? 1 : (_b[i-1]*x)%m);

	std::map<long long, long long> b;
	for(int i = sq-1;i >= 0;i--)b[_b[i]] = i;

	long long inv = __modinv((_b.back()*x)%m, m);

	for(int i = 0;i < sq;i++){
		long long num = (y*power(inv, i, m))%m;
		if(b.contains(num)){
			return i*sq + b[num];
		}
	}
	return -1;
};
