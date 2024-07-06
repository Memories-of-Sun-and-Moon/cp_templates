#define PROBLEM "https://judge.yosupo.jp/problem/kth_root_integer"

#include "./../../template/template.hpp"
#include "./../../math/iroot.hpp"

using namespace mmrz;

void mmrz::solve(){
	int t;
	cin >> t;
	while(t--){
		ull a, k;
		cin >> a >> k;
		cout << iroot(a, k) << endl;
	}
}
