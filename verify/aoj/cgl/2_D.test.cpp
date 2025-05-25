#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_2_D"
#define ERROR "1e-8"

#include "./../../../template/template.hpp"
#include "./../../../geometry/util.hpp"

using namespace mmrz;

void mmrz::solve(){
	segment s1, s2;
	int q;
	cin >> q;
	while(q--){
		cin >> s1.p1.x >> s1.p1.y >> s1.p2.x >> s1.p2.y;
		cin >> s2.p1.x >> s2.p1.y >> s2.p2.x >> s2.p2.y;
		cout << get_distance(s1, s2) << endl;
	}
}
