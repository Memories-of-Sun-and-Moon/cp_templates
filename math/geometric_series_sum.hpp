#pragma once

#include "../math/power.hpp"

long long geometric_series_sum(long long a, long long n, long long m){
	if(n == 0)return 0;
	if(n & 1){
		return (geometric_series_sum(a, n-1, m) + power(a, n-1, m)) % m;
	}
	return (geometric_series_sum(a, n/2, m) * (1LL + power(a, n/2, m))) % m;
}
