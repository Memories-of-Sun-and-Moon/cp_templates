#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_C"

#include "./../../../template/template.hpp"
#include "./../../../geometry/util.hpp"

using namespace mmrz;

void mmrz::solve(){
	segment seg;
	cin >> seg.p1.x >> seg.p1.y >> seg.p2.x >> seg.p2.y;
	int q;
	cin >> q;
	while(q--){
		point p;
		cin >> p.x >> p.y;
		int ret = ccw(seg.p1, seg.p2, p);
		if(ret == 1)cout << "COUNTER_CLOCKWISE" << endl;
		if(ret == -1)cout << "CLOCKWISE" << endl;
		if(ret == 2)cout << "ONLINE_BACK" << endl;
		if(ret == -2)cout << "ONLINE_FRONT" << endl;
		if(ret == 0)cout << "ON_SEGMENT" << endl;
	}
}
