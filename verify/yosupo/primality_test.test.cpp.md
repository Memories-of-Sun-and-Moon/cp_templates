---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/is_prime.hpp
    title: "\u7D20\u6570\u5224\u5B9A\uFF08\u30DF\u30E9\u30FC\u30FB\u30E9\u30D3\u30F3\
      \u7D20\u6570\u5224\u5B9A\u6CD5\uFF09"
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/primality_test
    links:
    - https://judge.yosupo.jp/problem/primality_test
  bundledCode: "#line 1 \"verify/yosupo/primality_test.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/primality_test\"\n\n#line 1 \"template/template.hpp\"\
    \n# include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\nusing\
    \ ull = unsigned long long;\nconst double pi = acos(-1);\ntemplate<class T>constexpr\
    \ T inf() { return ::std::numeric_limits<T>::max(); }\ntemplate<class T>constexpr\
    \ T hinf() { return inf<T>() / 2; }\ntemplate <typename T_char>T_char TL(T_char\
    \ cX) { return tolower(cX); }\ntemplate <typename T_char>T_char TU(T_char cX)\
    \ { return toupper(cX); }\ntemplate<class T> bool chmin(T& a,T b) { if(a > b){a\
    \ = b; return true;} return false; }\ntemplate<class T> bool chmax(T& a,T b) {\
    \ if(a < b){a = b; return true;} return false; }\nint popcnt(unsigned long long\
    \ n) { int cnt = 0; for (int i = 0; i < 64; i++)if ((n >> i) & 1)cnt++; return\
    \ cnt; }\nint d_sum(ll n) { int ret = 0; while (n > 0) { ret += n % 10; n /= 10;\
    \ }return ret; }\nint d_cnt(ll n) { int ret = 0; while (n > 0) { ret++; n /= 10;\
    \ }return ret; }\nll gcd(ll a, ll b) { if (b == 0)return a; return gcd(b, a%b);\
    \ };\nll lcm(ll a, ll b) { ll g = gcd(a, b); return a / g*b; };\nll MOD(ll x,\
    \ ll m){return (x%m+m)%m; }\nll FLOOR(ll x, ll m) {ll r = (x%m+m)%m; return (x-r)/m;\
    \ }\ntemplate<class T> using dijk = priority_queue<T, vector<T>, greater<T>>;\n\
    # define all(qpqpq)           (qpqpq).begin(),(qpqpq).end()\n# define UNIQUE(wpwpw)\
    \        (wpwpw).erase(unique(all((wpwpw))),(wpwpw).end())\n# define LOWER(epepe)\
    \         transform(all((epepe)),(epepe).begin(),TL<char>)\n# define UPPER(rprpr)\
    \         transform(all((rprpr)),(rprpr).begin(),TU<char>)\n# define rep(i,upupu)\
    \         for(ll i = 0, i##_len = (upupu);(i) < (i##_len);(i)++)\n# define reps(i,opopo)\
    \        for(ll i = 1, i##_len = (opopo);(i) <= (i##_len);(i)++)\n# define len(x)\
    \                ((ll)(x).size())\n# define bit(n)               (1LL << (n))\n\
    # define pb push_back\n# define eb emplace_back\n# define exists(c, e)       \
    \  ((c).find(e) != (c).end())\n\nstruct INIT{\n\tINIT(){\n\t\tstd::ios::sync_with_stdio(false);\n\
    \t\tstd::cin.tie(0);\n\t\tcout << fixed << setprecision(20);\n\t}\n}INIT;\n\n\
    namespace mmrz {\n\tvoid solve();\n}\n\nint main(){\n\tmmrz::solve();\n}\n#line\
    \ 2 \"math/is_prime.hpp\"\n\n#line 4 \"math/is_prime.hpp\"\n\n__int128_t __power(__int128_t\
    \ n, __int128_t k, __int128_t m) {\n\tn %= m;\n\t__int128_t ret = 1;\n\twhile(k\
    \ > 0){\n\t\tif(k & 1)ret = ret * n % m;\n\t\tn = __int128_t(n) * n % m;\n\t\t\
    k >>= 1;\n\t}\n\treturn ret % m;\n}\n\nbool is_prime(long long n){\n\tif(n <=\
    \ 1)return false;\n\tif(n == 2 || n == 3 || n == 5)return true;\n\tif(n % 2 ==\
    \ 0)return false;\n\tif(n % 3 == 0)return false;\n\tif(n % 5 == 0)return false;\n\
    \n\tstd::vector<long long> A = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};\n\
    \n\tlong long s = 0, d = n - 1;\n\twhile(d % 2 == 0){\n\t\ts++;\n\t\td >>= 1;\n\
    \t}\n\n\tfor (auto a : A){\n\t\tif(a % n == 0)return true;\n\t\tlong long t, x\
    \ = __power(a, d, n);\n\t\tif(x != 1){\n\t\t\tfor(t = 0;t < s;t++){\n\t\t\t\t\
    if(x == n - 1)break;\n\t\t\t\tx = __int128_t(x) * x % n;\n\t\t\t}\n\t\t\tif(t\
    \ == s)return false;\n\t\t}\n\t}\n\treturn true;\n}\n#line 5 \"verify/yosupo/primality_test.test.cpp\"\
    \n\nusing namespace mmrz;\n\nvoid mmrz::solve(){\n    int t;\n    cin >> t;\n\
    \    while(t--){\n        ll a;\n        cin >> a;\n        cout << (is_prime(a)\
    \ ? \"Yes\" : \"No\") << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/primality_test\"\n\n#include\
    \ \"./../../template/template.hpp\"\n#include \"./../../math/is_prime.hpp\"\n\n\
    using namespace mmrz;\n\nvoid mmrz::solve(){\n    int t;\n    cin >> t;\n    while(t--){\n\
    \        ll a;\n        cin >> a;\n        cout << (is_prime(a) ? \"Yes\" : \"\
    No\") << '\\n';\n    }\n}\n"
  dependsOn:
  - template/template.hpp
  - math/is_prime.hpp
  isVerificationFile: true
  path: verify/yosupo/primality_test.test.cpp
  requiredBy: []
  timestamp: '2025-07-01 03:22:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/primality_test.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/primality_test.test.cpp
- /verify/verify/yosupo/primality_test.test.cpp.html
title: verify/yosupo/primality_test.test.cpp
---
