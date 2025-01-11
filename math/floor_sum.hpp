
ll floor_sum(ll n, ll m, ll a, ll b){
	ll ans = 0;
	if(a >= m){
		ans += (n-1) * n * (a/m) / 2;
		a %= m;
	}
	if(b >= m){
		ans += n * (b/m);
		b %= m;
	}

	ll x = a * (n-1) + b;
	if(x < m) return ans;
	ll x_div = x/m;
	ll x_mod = x%m;
	ans += x_div + floor_sum(x_div, a, m, x_mod);
	return ans;
}
