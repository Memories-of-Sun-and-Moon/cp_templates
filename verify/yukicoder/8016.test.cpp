#define PROBLEM "https://yukicoder.me/problems/no/8016"

#include "./../../template/template.hpp"
#include "./../../data_structure/hash_map.hpp"

using namespace mmrz;

void mmrz::solve(){
	int n, m;
	cin >> n >> m;
	hash_map<ll, ll, bit(20)> mp;
	while(n--){
		ll a;
		cin >> a;
		mp[a]++;
	}
	rep(i, m){
		ll b;
		cin >> b;
		cout << mp[b] << " \n"[i == m-1];
	}
}
