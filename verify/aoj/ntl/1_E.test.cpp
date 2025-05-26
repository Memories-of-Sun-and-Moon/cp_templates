#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E"

#include "./../../../template/template.hpp"
#include "./../../../math/extgcd.hpp"

void mmrz::solve(){
	ll a, b;
	cin >> a >> b;
	ll x, y;
	extgcd(a, b, x, y);
	cout << x << ' ' << y << '\n';
}
