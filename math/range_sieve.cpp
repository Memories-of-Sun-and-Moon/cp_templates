// 未検証
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

class range_sieve {
	ll l, r, m;
	vector<int> small;
	vector<vector<ll>> large;
	vector<ll> aux;

public:
	range_sieve(ll l, ll r) : l(l), r(r), m(sqrt(r)+1) {
		small.resize(m);
		iota(small.begin(), small.end(), 0);
		large.resize(r-l);
		aux.assign(r-l, 1);

		for(ll i = 2;i*i < r;i++){
			if(small[i] < i)continue;
			small[i] = i; // これ要るか？
			for(ll j = i*i;j < m;j += i){
				if(small[j] == j)small[j] = i;
			}
			for(ll j = (l+i-1)/i*i;j < r;j += i){
				ll k = j;
				do{
					if(aux[j-l] * aux[j-l] > r)break;

					large[j-l].push_back(i);
					aux[j-l] *= i;
					k /= i;
				}while(k % i == 0);
			}
		}
	}

	vector<ll> factor(ll n) {
		assert(l <= n && n < r);
		vector<ll> res = large[n-l];
		n /= aux[n-l];
		if(n >= m){
			res.push_back(n);
			return res;
		}
		while(n > 1){
			res.push_back(small[n]);
			n /= small[n];
		}
		return res;
	}
};
