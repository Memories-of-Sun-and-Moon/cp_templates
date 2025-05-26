#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_3_B"

#include "./../../../template/template.hpp"
#include "./../../../geometry/util.hpp"

using namespace mmrz;

void mmrz::solve(){
	int n;
	cin >> n;
	vector<point> poly(n);
	for(auto &p : poly) cin >> p;

	cout << (is_convex(poly, true) ? 1 : 0) << '\n';
}
