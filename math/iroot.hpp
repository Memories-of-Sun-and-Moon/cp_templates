#pragma once

#include<cmath>
#include<limits>

unsigned long long iroot(unsigned long long n, int k=2){
	constexpr unsigned long long LIM = std::numeric_limits<unsigned long long>::max();
	if(n <= 1 || k == 1){
		return n;
	}
	if(k >= 64){
		return 1;
	}
	if(k == 2){
		return sqrtl(n);
	}

	if(n == LIM)n--;

	auto safe_mul = [&](unsigned long long &x, unsigned long long &y) -> void {
		if(x <= LIM / y){
			x *= y;
		}else{
			x = LIM;
		}
	};

	auto power = [&](unsigned long long a, int b) -> unsigned long long {
		unsigned long long ret = 1;
		while(b){
			if(b & 1)safe_mul(ret, a);
			safe_mul(a, a);
			b >>= 1;
		}
		return ret;
	};

	unsigned long long ret = (k == 3 ? cbrt(n)-1 : std::pow(n, std::nextafter(1.0/double(k), 0.0)));
	while(power(ret+1, k) <= n)ret++;
	return ret;
}
