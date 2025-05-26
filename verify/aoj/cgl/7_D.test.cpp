#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_7_D"
#define ERROR "1e-6"

#include "./../../../template/template.hpp"
#include "./../../../geometry/util.hpp"

using namespace mmrz;

void mmrz::solve(){
	circle c;
	cin >> c;
	segment s;
	int q;
	cin >> q;
	while(q--){
		cin >> s;
		auto [p1, p2] = get_crosspoints(c, s);
		if(p1.x > p2.x)swap(p1, p2);
		else if (fabs(p1.x - p2.x) < EPS && p1.y > p2.y)swap(p1, p2);
		cout << p1 << " " << p2 << '\n';
	}
}
