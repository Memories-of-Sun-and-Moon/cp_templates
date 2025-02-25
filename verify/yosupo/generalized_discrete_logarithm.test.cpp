#define PROBLEM "https://judge.yosupo.jp/problem/discrete_logarithm_mod"

#include "./../../template/template.hpp"
#include "./../../math/generalized_discrete_logarithm.hpp"
#include "./../../math/power.hpp"

using namespace mmrz;

void SOLVE(){
	ll x, y, m;
	cin >> x >> y >> m;

	auto f = [&x, &m](ll a) -> ll {
		return (a*x)%m;
	};

	int sq = sqrt(m);
	ll x_sq = power(x, sq, m);
	auto f_sq = [&x_sq, &m](ll a) -> ll {
		return (a*x_sq)%m;
	};

	cout << generalized_discrete_logarithm<int>(1%m, y, f, m, f_sq, sq) << '\n';
}

void mmrz::solve(){
	int t = 1;
	cin >> t;
	while(t--)SOLVE();
}
