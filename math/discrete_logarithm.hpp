#include "../math/iroot.hpp"
#include "../math/power.hpp"

ll __modinv(ll a, ll m){
	ll b=m, u=1, v=0;
	while(b){
		ll t = a/b;
		a -= t*b;swap(a, b);
		u -= t*v;swap(u, v);
	}
	u %= m;
	if(u < 0)u += m;
	return u;
}

ll discrete_logarithm(ll x, ll y, ll m) {
	assert(x < m && y < m);
	if(m == 1)return 0;
	if(y == 1)return 0;
	if(x == 0){
		if(y == 1)return 0;
		else if(y == 0)return 1;
		else return -1;
	}

	if(gcd(x, m) != 1){
		ll d = gcd(x, m);
		if(y%d)return -1;
		y /= d;
		m /= d;
		ll ret = discrete_logarithm(x%m, (y*__modinv(x/d, m))%m, m);
		if(ret == -1)return -1;
		else return ret+1;
	}

	ll sq = iroot(m);
	if(sq < 3)sq = 3;
	vector<ll> _b(sq);
	for(int i = 0;i < sq;i++)_b[i] = (i == 0 ? 1 : (_b[i-1]*x)%m);

	map<ll, ll> b;
	for(int i = sq-1;i >= 0;i--)b[_b[i]] = i;

	ll inv = __modinv((_b.back()*x)%m, m);

	for(int i = 0;i < sq;i++){
		ll num = (y*power(inv, i, m))%m;
		if(b.contains(num)){
			return i*sq + b[num];
		}
	}
	return -1;
};
