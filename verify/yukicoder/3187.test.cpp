#define PROBLEM "https://yukicoder.me/problems/no/3187"

#include "./../../template/template.hpp"
#include "./../../math/dynamic_modint.hpp"

using namespace mmrz;

void mmrz::solve(){
	int n, p;
	cin >> n >> p;
	dynamic_modint::set_mod(p);

	vector d(n+1, vector<int>());
	reps(i, n){
		for(int j = i;j <= n;j += i){
			d[j].eb(i);
		}
	}
	
	vector<dynamic_modint> f(n+1, dynamic_modint(0));
	dynamic_modint tot = 0;
	for(int i = 3;i <= n;i++){
		dynamic_modint sum = tot;
		for(auto j : d[i])sum -= f[j];
		f[i] = (sum/i + 1)*i/(i-len(d[i]));
		tot = sum + f[i]*len(d[i]);
		for(auto j : d[i])f[j] = f[i];
	}
	cout << f[n] << '\n';
}
