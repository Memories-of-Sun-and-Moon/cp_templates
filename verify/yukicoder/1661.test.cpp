#define PROBLEM "https://yukicoder.me/problems/no/1661"

#include "./../../template/template.hpp"
#include "./../../math/counting_primes.hpp"

void mmrz::solve(){
	ll l, r;
	cin >> l >> r;
	cout << counting_primes(r) - counting_primes(l-1) + counting_primes(2*r) - counting_primes(2*l) << endl;
}
