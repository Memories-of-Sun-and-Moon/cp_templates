#define PROBLEM "https://yukicoder.me/problems/no/1250"

#include "./../../template/template.hpp"
#include "./../../math/binary_gcd.hpp"

void mmrz::solve(){
	int n, h;
	cin >> n >> h;
	while(n--){
		int a;
		cin >> a;
		a = abs(a);
		int g = binary_gcd(a, h);
		h /= g;
	}
	cout << (h == 1 ? "YES\n" : "NO\n");
}
