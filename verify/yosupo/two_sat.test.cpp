# define PROBLEM "https://judge.yosupo.jp/problem/two_sat"

#include "./../../template/template.hpp"
#include "./../../graph/two_sat.hpp"

void mmrz::solve(){
	char _p;
	string _cnf;
	int n, m;
	cin >> _p >> _cnf >> n >> m;

	auto f = [](int x) -> pair<int, bool> {
		bool tf = (x > 0 ? true : false);
		x = abs(x)-1;
		return make_pair(x, tf);
	};

	two_sat ts(n);
	while(m--){
		int x, y, _zero;
		cin >> x >> y >> _zero;
		auto [nx, x_tf] = f(x);
		auto [ny, y_tf] = f(y);
		ts.add_clause(nx, x_tf, ny, y_tf);
	}

	auto ret = ts.solve();
	if(ret.empty()){
		cout << "s UNSATISFIABLE" << '\n';
		return;
	}
	cout << "s SATISFIABLE" << '\n';
	cout << "v";
	rep(i, n){
		cout << " " << (ret[i] ? "" : "-") << i+1;
	}
	cout << " 0" << '\n';
}
