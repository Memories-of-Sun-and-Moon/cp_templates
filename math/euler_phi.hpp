
#include "../math/factor.hpp"

long long euler_phi(long long x){
	auto f = factor(x);
	UNIQUE(f);
	long long ret = x;
	for(auto e : f){
		ret *= (e-1);
		ret /= e;
	}
	return ret;
}
