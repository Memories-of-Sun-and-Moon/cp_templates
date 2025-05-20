#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2286"

#include "./../../../template/template.hpp"
#include "./../../../math/euler_phi_table.hpp"

using namespace mmrz;

void mmrz::solve(){
	const int max_n = 1000000;
	
	vector<int> phi = euler_phi_table(max_n);
	vector<ll> s(max_n+1);
	for(int i = 1;i <= max_n;i++){
		s[i] += s[i-1] + phi[i];
	}

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		cout << s[n]+1 << '\n';
	}

}
