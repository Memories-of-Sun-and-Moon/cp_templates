#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_2_A"

#include "./../../../template/template.hpp"
#include "./../../../geometry/util.hpp"

using namespace mmrz;

void mmrz::solve(){
	int q;
	cin >> q;
	while(q--){
		line s1, s2;
		cin >> s1 >> s2;
		if(is_parallel(s1, s2))cout << 2 << '\n';
		else if(is_orthogonal(s1, s2))cout << 1 << '\n';
		else cout << 0 << '\n';
	}
}
