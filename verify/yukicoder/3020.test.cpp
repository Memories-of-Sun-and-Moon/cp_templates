#define PROBLEM "https://yukicoder.me/problems/no/3020"

#include "./../../template/template.hpp"
#include "./../../math/binary_gcd.hpp"

using namespace mmrz;

void mmrz::solve(){
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	ll g = binary_gcd(abs(a), binary_gcd(abs(b), binary_gcd(abs(c), abs(d))));
	if(g == 0){
		cout << "0 0\n";
		return;
	}
	ll det = a*d - b*c;
	cout << g << " " << abs(det/g) << endl;
}
