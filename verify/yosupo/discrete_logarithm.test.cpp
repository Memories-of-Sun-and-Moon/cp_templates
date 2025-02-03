#define PROBLEM "https://judge.yosupo.jp/problem/discrete_logarithm_mod"

#include "./../../template/template.hpp"
#include "./../../math/discrete_logarithm.hpp"

using namespace mmrz;

void SOLVE(){
	int x, y, m;
	cin >> x >> y >> m;
	cout << discrete_logarithm(x, y, m) << '\n';
}

void mmrz::solve(){
	int t = 1;
	cin >> t;
	while(t--)SOLVE();
}
