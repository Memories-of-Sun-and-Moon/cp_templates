ll binary_gcd(ll a, ll b){
	if(a == 0)return b;
	if(b == 0)return a;

	a = abs(a);
	b = abs(b);

	int a_zero = __builtin_ctzll(a);
	int b_zero = __builtin_ctzll(b);
	a >>= a_zero;
	b >>= b_zero;
	
	while(a != b){
		if(a > b){
			swap(a, b);
		}
		b -= a;
		b >>= __builtin_ctzll(b);
	}
	return a << min(a_zero, b_zero);
}
