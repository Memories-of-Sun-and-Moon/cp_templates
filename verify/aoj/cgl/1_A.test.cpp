#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_A"
#define ERROR "1e-8"

#include "./../../../template/template.hpp"
#include "./../../../geometry/util.hpp"

using namespace mmrz;

void mmrz::solve(){
	segment s;
	cin >> s;
	int q;
	cin >> q;
	while(q--){
		point p;
		cin >> p;
		point ret = project(s, p);
		cout << ret.x << " " << ret.y << endl;
	}
}
