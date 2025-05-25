#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_4_C"
#define ERROR "1e-5"

#include "./../../../template/template.hpp"
#include "./../../../geometry/util.hpp"

using namespace mmrz;

void mmrz::solve(){
	int n;
	cin >> n;
	polygon g(n);
	for(auto &gp : g)cin >> gp;
	int q;
	cin >> q;
	while(q--){
		line s;
		cin >> s;
		auto pl = convex_cut(g, s);
		cout << area(pl) << '\n';
	}
}
