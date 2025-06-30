
long long floor_sum(long long n, long long m, long long a, long long b){
	long long ans = 0;
	if(a >= m){
		ans += (n-1) * n * (a/m) / 2;
		a %= m;
	}
	if(b >= m){
		ans += n * (b/m);
		b %= m;
	}

	long long x = a * (n-1) + b;
	if(x < m) return ans;
	long long x_div = x/m;
	long long x_mod = x%m;
	ans += x_div + floor_sum(x_div, a, m, x_mod);
	return ans;
}
