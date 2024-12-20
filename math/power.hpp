
template<typename mint>
mint power(mint n, long long k) {
	mint ret = 1;
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
