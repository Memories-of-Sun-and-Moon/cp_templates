#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "./../../template/template.hpp"
#include "./../../data_structure/union_find.hpp"

void mmrz::solve(){
	int n, q;
	cin >> n >> q;
	union_find uf(n);
	while(q--){
		int t;
		cin >> t;
		if(t == 0){
			int u, v;
			cin >> u >> v;
			uf.unite(u, v);
		}else{
			int u, v;
			cin >> u >> v;
			cout << (uf.is_same(u, v) ? 1 : 0) << '\n';
		}
	}
}
