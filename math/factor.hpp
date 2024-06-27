#include "is_prime.hpp"

long long rho(long long n){
    if(n % 2 == 0)return 2;
    if(is_prime(n))return n;

    auto f = [&](long long x) -> long long {
        return (__int128_t(x) * x + 13) % n;
    };

    long long step = 0;
    while (true) {
        ++step;
        long long x = step, y = f(x);
        while (true) {
            long long p = gcd(y - x + n, n);
            if (p == 0 || p == n) break;
            if (p != 1) return p;
            x = f(x);
            y = f(f(y));
        }
    }

}

vector<long long> factor(long long x){
    if(x == 1)return {};
    long long p = rho(x);
    if(p == x) return {p};
    
    vector<long long> l = factor(p);
    vector<long long> r = factor(x / p);

    l.insert(l.end(), r.begin(), r.end());
    sort(l.begin(), l.end());

    return l;
}
