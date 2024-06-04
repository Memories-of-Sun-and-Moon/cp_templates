#define PROBLEM "https://yukicoder.me/problems/no/2219"

#include "./../../template/template.hpp"
#include "./../../math/modint.hpp"

using namespace mmrz;
using mint = modint<998244353>;

void mmrz::solve(){
    string s;
    cin >> s;
    int n = len(s);
    vector<vector<mint>> dp(n + 1, vector<mint>(4));
    dp[0][0] = 1;
    rep(i, n){
        if(s[i] == '0' || s[i] == '?'){
            dp[i + 1][1] += dp[i][0];
            dp[i + 1][3] += dp[i][2];
        }
        if(s[i] == '1' || s[i] == '?'){
            dp[i + 1][2] += dp[i][1];
        }
        rep(j, 4){
            dp[i + 1][j] += dp[i][j] * (s[i] == '?' ? 2 : 1);
        }
    }

    cout << dp[n][3] << endl;
}
