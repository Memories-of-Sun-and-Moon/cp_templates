#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"

#include "./../../../template/template.hpp"
#include "./../../../data_structure/union_find.hpp"

using namespace mmrz;

void mmrz::solve(){
	int v, e;
	cin >> v >> e;
	vector<tuple<int, int, int>> wst(e);
	rep(i, e){
		int s, t, w;
		cin >> s >> t >> w;
		wst[i] = {w, s, t};
	}
	sort(all(wst));
	union_find uf(v);
	ll ans = 0;
	for(auto [w, s, t] : wst){
		if(uf.unite(s, t)){
			ans += w;
		}
	}
	assert(uf.groups_size() == 1);
	cout << ans << '\n';
}
