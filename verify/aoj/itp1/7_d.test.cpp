#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/7/ITP1_7_D"

#include "./../../../template/template.hpp"
#include "./../../../math/matrix.hpp"

void mmrz::solve(){
	int n, m, l;
	cin >> n >> m >> l;
	matrix<int> a(n, m), b(m, l);
	rep(i, n)rep(j, m)cin >> a[i][j];
	rep(i, m)rep(j, l)cin >> b[i][j];
	auto c = a*b;
	rep(i, n){
		rep(j, l){
			cout << c[i][j] << " \n"[j == l-1];
		}
	}
}
