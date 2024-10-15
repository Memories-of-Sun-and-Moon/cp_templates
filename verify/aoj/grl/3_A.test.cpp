#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A"

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
		if(l.is_articulation(i)){
			cout << i << '\n';
		}
	}
}
