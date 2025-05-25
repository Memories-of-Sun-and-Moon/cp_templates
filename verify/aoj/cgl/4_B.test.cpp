#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_4_B"
#define ERROR "1e-6"

#include "./../../../template/template.hpp"
#include "./../../../geometry/util.hpp"

using namespace mmrz;

void mmrz::solve(){
	int n;
	cin >> n;
	polygon ps(n);
	rep(i, n){
		cin >> ps[i];
	}

	cout << diameter(ps) << '\n';
}
