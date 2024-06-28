# define PROBLEM https://judge.yosupo.jp/problem/convolution_mod

#include "./../../template/template.hpp"
#include "./../../math/modint.hpp"
using mint998 = modint<998244353>;
#include "./../../math/formal_power_series.hpp"
using fps = formal_power_series<mint998>;

using namespace mmrz;

void mmrz::solve(){
	int n, m;
	cin >> n >> m;
	fps a(n), b(m);
	rep(i, n){
		int _a;
		cin >> _a;
		a[i] = _a;
	}
	rep(i, m){
		int _b;
		cin >> _b;
		b[i] = _b;
	}
	fps f{1};
	f *= a;
	f *= b;
	rep(i, n+m-1){
		cout << f[i] << " \n"[i == n+m-1];
	}
}
