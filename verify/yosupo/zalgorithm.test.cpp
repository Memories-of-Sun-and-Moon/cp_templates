#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include "./../../template/template.hpp"
#include "./../../string/z_algorithm.hpp"

void mmrz::solve(){
	string s;
	cin >> s;
	vector<int> z = z_algorithm(s);
	rep(i, len(s)){
		cout << z[i] << " \n"[i == len(s)-1];
	}
}
