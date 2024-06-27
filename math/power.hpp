
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
