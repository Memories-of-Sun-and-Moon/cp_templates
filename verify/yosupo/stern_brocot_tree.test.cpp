#define PROBLEM "https://judge.yosupo.jp/problem/stern_brocot_tree"

#include "./../../template/template.hpp"
#include "./../../math/stern_brocot_tree.hpp"

using namespace mmrz;

void SOLVE(){
	string op;
	cin >> op;
	if(op == "ENCODE_PATH"){
		ll a, b;
		cin >> a >> b;
		vector<ll> path = sbt::encode_path(a, b);
		if(path.empty())cout << 0;
		else if(path.front() == 0)cout << ssize(path) - 1;
		else cout << ssize(path) << " R " << path.front();
		
		for(int i = 1; i < ssize(path); i++){
			cout << (i % 2 == 0 ? " R " : " L ") << path[i];
		}
		cout << "\n";
	}else if(op == "DECODE_PATH"){
		int k;
		cin >> k;
		vector<ll> path;
		rep(i, k){
			char c;
			ll x;
			cin >> c >> x;
			if(i == 0 && c == 'L'){
				path.emplace_back(0);
			}
			path.emplace_back(x);
		}
		auto [p, q, r, s] = sbt::decode_path(path);
		cout << p+r << ' ' << q+s << '\n';
	}else if(op == "LCA"){
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		auto [p, q, r, s] = sbt::lca(a, b, c, d);
		cout << p+r << ' ' << q+s << '\n';
	}else if(op == "ANCESTOR"){
		ll k, a, b;
		cin >> k >> a >> b;
		auto ret = sbt::ancestor(a, b, k);
		if(!ret){
			cout << "-1\n";
		}else{
			auto [p, q, r, s] = ret.value();
			cout << p+r << ' ' << q+s << '\n';
		}
	}else{
		ll a, b;
		cin >> a >> b;
		auto [p, q, r, s] = sbt::range(a, b);
		cout << p << ' ' << q << ' ' << r << ' ' << s << '\n';
	}
}

void mmrz::solve(){
	int t = 1;
	cin >> t;
	while(t--)SOLVE();
}
