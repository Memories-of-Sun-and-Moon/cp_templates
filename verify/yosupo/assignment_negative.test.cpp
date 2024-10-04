#define PROBLEM "https://judge.yosupo.jp/problem/assignment"

#include "./../../template/template.hpp"
#include "./../../graph/hungarian.hpp"

using namespace mmrz;

void mmrz::solve(){
	int n;
	cin >> n;
	vector a(n, vector(n, 0LL));
	rep(i, n)rep(j, n)cin >> a[i][j];
	rep(i, n)rep(j, n)a[i][j] = -a[i][j];

	vector<int> h = hungarian<false, ll>(a);
	ll x = 0;
	rep(i, n)x -= a[i][h[i]];
	cout << x << endl;
	rep(i, n)cout << h[i] << " \n"[i == n-1];
}
