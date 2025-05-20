#define PROBLEM "https://judge.yosupo.jp/problem/counting_primes"

#include "./../../template/template.hpp"
#include "./../../math/counting_primes.hpp"

using namespace mmrz;

void mmrz::solve(){
	ll n;
	cin >> n;
	cout << counting_primes(n) << '\n';
}
