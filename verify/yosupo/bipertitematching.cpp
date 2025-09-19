# define PROBLEM "https://judge.yosupo.jp/problem/bipertitematching"

#include "./../../template/template.hpp"
#include "./../../graph/bipartite_matching.hpp"

void mmrz::solve(){
	int l, r, m;
	cin >> l >> r >> m;
	vector<pair<int, int>> es;
	while(m--){
		int a, b;
		cin >> a >> b;
		es.emplace_back(a, b);
	}

	auto bm = bipartite_matching(l, r, es);

	cout << ssize(bm) << '\n';
	for(auto [l_v, r_v] : bm){
		cout << l_v << ' ' << r_v << '\n';
	}
}
