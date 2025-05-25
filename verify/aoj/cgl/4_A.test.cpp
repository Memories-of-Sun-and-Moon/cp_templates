#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_4_A"

#include "./../../../template/template.hpp"
#include "./../../../geometry/util.hpp"

using namespace mmrz;

void mmrz::solve(){
	int n;
	cin >> n;
	polygon ps(n);
	rep(i, n){
		cin >> ps[i].x >> ps[i].y;
	}
	auto qs = convex_hull(ps, true);
	cout << len(qs) << endl;
	int idx = 0;
	for(int i = 1;i < len(qs);i++){
		if(qs[i].y < qs[idx].y){
			idx = i;
		}
	}
	rep(i, len(qs)){
		cout << int(qs[(i+idx)%len(qs)].x) << " " << int(qs[(i+idx)%len(qs)].y) << endl;
	}
}
