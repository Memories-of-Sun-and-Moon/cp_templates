#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_D"

#include "./../../../template/template.hpp"
#include "./../../../math/euler_phi.hpp"

void mmrz::solve(){
	ll x;
	cin >> x;
	cout << euler_phi(x) << '\n';
}
