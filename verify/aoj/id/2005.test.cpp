#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2005"

#include "./../../../template/template.hpp"
#include "./../../../graph/warshall_floyd.hpp"

using namespace mmrz;

bool SOLVE(){
	int n, m, s, g1, g2;
	cin >> n >> m >> s >> g1 >> g2;
	if(n == 0)return 1;
	s--, g1--, g2--;
	vector dist(n, vector(n, inf<int>()/3));
	rep(i, n)dist[i][i] = 0;
	while(m--){
		int u, v, c;
		cin >> u >> v >> c;
		u--, v--;
		dist[u][v] = c;
	}
	warshall_floyd wf(dist, inf<int>()/3);
	int ans = hinf<int>();
	rep(i, n){
		chmin(ans, wf.dist[s][i]+wf.dist[i][g1]+wf.dist[i][g2]);
	}
	cout << ans << '\n';
	return 0;
}

void mmrz::solve(){
	while(!SOLVE());
}
