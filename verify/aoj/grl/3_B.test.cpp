#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B"

#include "./../../../template/template.hpp"
#include "./../../../graph/lowlink.hpp"

using namespace mmrz;

void mmrz::solve(){
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n);
	while(m--){
		int a, b;
		cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}

	lowlink l(g);

	rep(i, n){
		sort(all(g[i]));
		for(auto to : g[i]){
			if(i < to && l.is_bridge(i, to)){
				cout << i << " " << to << '\n';
			}
		}
	}
}
