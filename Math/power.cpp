# define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B"
# include "bits/stdc++.h"
using namespace std;

long long power(long long n, long long k, long long m) {
    n %= m;
	long long ret = 1;
    while(k > 0){
        if(k & 1)ret = ret * n % m;
        n = n * n % m;
        k >>= 1;
    }
    return ret % m;
}

long long m, n;
const long long mod = 1000000000 + 7;

int main(){
    cin >> m >> n;
    cout << power(m, n, mod) << endl;
}