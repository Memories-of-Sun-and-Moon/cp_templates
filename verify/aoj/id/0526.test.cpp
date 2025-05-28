#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0526"

#include "./../../../template/template.hpp"
#include "./../../../graph/warshall_floyd.hpp"

using namespace mmrz;

bool SOLVE(){
	int n, k;
	cin >> n >> k;
	if(n == 0)return 1;
	vector dist(n, vector(n, inf<int>()/3));
	rep(i, n)dist[i][i] = 0;
	warshall_floyd wf(dist, inf<int>()/3);
	while(k--){
		int op;
		cin >> op;
		if(op == 0){
			int a, b;
			cin >> a >> b;
			a--, b--;
			cout << (wf.dist[a][b] == inf<int>()/3 ? -1 : wf.dist[a][b]) << '\n';
		}else{
			int c, d, e;
			cin >> c >> d >> e;
			c--, d--;
			if(wf.dist[c][d] > e){
				wf.update(c, d, e);
				wf.update(d, c, e);
			}
		}
	}
	return 0;
}

void mmrz::solve(){
	while(!SOLVE());
}
