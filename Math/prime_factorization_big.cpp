#include<bits/stdc++.h>
using namespace std;

// https://judge.yosupo.jp/submission/124918

// 大きな数に対する素因数分解はこっちの方がはやい
// ただ、ロー法の疑似乱数生成が甘いようだ

__int128_t power(__int128_t n, __int128_t k, __int128_t m) {
    n %= m;
	__int128_t ret = 1;
    while(k > 0){
        if(k & 1)ret = ret * n % m;
        n = __int128_t(n) * n % m;
        k >>= 1;
    }
    return ret % m;
}


bool is_prime(int64_t n){
    if(n <= 1)return false;
    if(n == 2 || n == 3 || n == 5)return true;
    if(n % 2 == 0)return false;
    if(n % 3 == 0)return false;
    if(n % 5 == 0)return false;

    vector<int64_t> A = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};

    int64_t s = 0, d = n - 1;
    while(d % 2 == 0){
        s++;
        d >>= 1;
    }

    for (auto a : A){
        if(a % n == 0)return true;
        int64_t t, x = power(a, d, n);
        if(x != 1){
            for(t = 0;t < s;t++){
                if(x == n - 1)break;
                x = __int128_t(x) * x % n;
            }
            if(t == s)return false;
        }
    }
    return true;
}

int64_t rho(int64_t n){
    if(n % 2 == 0)return 2;
    if(is_prime(n))return n;

    auto f = [&](int64_t x) -> int64_t {
        return (__int128_t(x) * x + 13) % n;
    };

    int64_t step = 0;
    while (true) {
        ++step;
        int64_t x = step, y = f(x);
        while (true) {
            int64_t p = gcd(y - x + n, n);
            if (p == 0 || p == n) break;
            if (p != 1) return p;
            x = f(x);
            y = f(f(y));
        }
    }

}

vector<int64_t> factorize(int64_t x){
    if(x == 1)return {};
    int64_t p = rho(x);
    if(p == x) return {p};
    
    vector<int64_t> l = factorize(p);
    vector<int64_t> r = factorize(x / p);

    l.insert(l.end(), r.begin(), r.end());
    sort(l.begin(), l.end());

    return l;
}

void solve(){
    long long n;
    cin >> n;
    auto ret = factorize(n);
    int k = ret.size();
    cout << k;
    for(int i = 0;i < k;i++){
        cout << " ";
        cout << ret[i];
    }
    cout << endl;
}

int main(){
    int t = 1;
    cin >> t;
    while(t--)solve();
}