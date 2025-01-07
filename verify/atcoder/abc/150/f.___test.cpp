#define PROBLEM "https://atcoder.jp/contests/abc150/tasks/abc150_f"

#include "./../../../../template/template.hpp"
#include "./../../../../string/z_algorithm.hpp"

void mmrz::solve(){
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(auto &x : a)cin >> x;
	for(auto &x : b)cin >> x;
	
	vector<int> c;
	rep(i, n)c.pb(b[i]^b[(i+1)%n]);
	rep(i, n)c.pb(a[i]^a[(i+1)%n]);
	rep(i, n)c.pb(a[i]^a[(i+1)%n]);

	auto z = z_algorithm(c);
	
	rep(i, n){
		if(z[n+i] >= n){
			cout << i << " " << (a[i]^b[0]) << '\n';
		}
	}
}
