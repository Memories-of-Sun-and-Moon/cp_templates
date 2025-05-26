#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_C"

#include "./../../../template/template.hpp"
#include "./../../../geometry/util.hpp"

using namespace mmrz;

void mmrz::solve(){
	segment seg;
	cin >> seg;
	int q;
	cin >> q;
	while(q--){
		point p;
		cin >> p;
		int ret = ccw(seg.p1, seg.p2, p);
		if(ret == 1)cout << "COUNTER_CLOCKWISE" << '\n';
		if(ret == -1)cout << "CLOCKWISE" << '\n';
		if(ret == 2)cout << "ONLINE_BACK" << '\n';
		if(ret == -2)cout << "ONLINE_FRONT" << '\n';
		if(ret == 0)cout << "ON_SEGMENT" << '\n';
	}
}
