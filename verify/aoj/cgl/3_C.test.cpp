#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_3_C"

#include "./../../../template/template.hpp"
#include "./../../../geometry/util.hpp"

using namespace mmrz;

void mmrz::solve(){
	int n;
	cin >> n;
	polygon ps(n);
	rep(i, n)cin >> ps[i];
	int q;
	cin >> q;
	while(q--){
		point p;
		cin >> p;
		cout << contains(ps, p) << endl;
	}
}
