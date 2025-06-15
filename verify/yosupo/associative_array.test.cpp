#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"

#include "./../../template/template.hpp"
#include "./../../data_structure/hash_map.hpp"

void mmrz::solve(){
	int q;
	cin >> q;
	hash_map<ll, ll, bit(20)> mp;
	while(q--){
		int op;
		cin >> op;
		if(op == 0){
			ll k, v;
			cin >> k >> v;
			mp[k] = v;
		}else{
			ll k;
			cin >> k;
			cout << mp[k] << '\n';
		}
	}
}
