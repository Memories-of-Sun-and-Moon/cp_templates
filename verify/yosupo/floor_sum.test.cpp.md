---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/floor_sum.hpp
    title: floor_sum
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_floor_of_linear
    links:
    - https://judge.yosupo.jp/problem/sum_of_floor_of_linear
  bundledCode: "#line 1 \"verify/yosupo/floor_sum.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\
    \n\n#line 1 \"template/template.hpp\"\n# include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\nusing ull = unsigned long long;\nconst double pi\
    \ = acos(-1);\ntemplate<class T>constexpr T inf() { return ::std::numeric_limits<T>::max();\
    \ }\ntemplate<class T>constexpr T hinf() { return inf<T>() / 2; }\ntemplate <typename\
    \ T_char>T_char TL(T_char cX) { return tolower(cX); }\ntemplate <typename T_char>T_char\
    \ TU(T_char cX) { return toupper(cX); }\ntemplate<class T> bool chmin(T& a,T b)\
    \ { if(a > b){a = b; return true;} return false; }\ntemplate<class T> bool chmax(T&\
    \ a,T b) { if(a < b){a = b; return true;} return false; }\nint popcnt(unsigned\
    \ long long n) { int cnt = 0; for (int i = 0; i < 64; i++)if ((n >> i) & 1)cnt++;\
    \ return cnt; }\nint d_sum(ll n) { int ret = 0; while (n > 0) { ret += n % 10;\
    \ n /= 10; }return ret; }\nint d_cnt(ll n) { int ret = 0; while (n > 0) { ret++;\
    \ n /= 10; }return ret; }\nll gcd(ll a, ll b) { if (b == 0)return a; return gcd(b,\
    \ a%b); };\nll lcm(ll a, ll b) { ll g = gcd(a, b); return a / g*b; };\nll MOD(ll\
    \ x, ll m){return (x%m+m)%m; }\nll FLOOR(ll x, ll m) {ll r = (x%m+m)%m; return\
    \ (x-r)/m; }\ntemplate<class T> using dijk = priority_queue<T, vector<T>, greater<T>>;\n\
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
    \ 1 \"math/floor_sum.hpp\"\n\nll floor_sum(ll n, ll m, ll a, ll b){\n\tll ans\
    \ = 0;\n\tif(a >= m){\n\t\tans += (n-1) * n * (a/m) / 2;\n\t\ta %= m;\n\t}\n\t\
    if(b >= m){\n\t\tans += n * (b/m);\n\t\tb %= m;\n\t}\n\n\tll x = a * (n-1) + b;\n\
    \tif(x < m) return ans;\n\tll x_div = x/m;\n\tll x_mod = x%m;\n\tans += x_div\
    \ + floor_sum(x_div, a, m, x_mod);\n\treturn ans;\n}\n#line 5 \"verify/yosupo/floor_sum.test.cpp\"\
    \n\nusing namespace mmrz;\n\nvoid mmrz::solve(){\n\tint t;\n\tcin >> t;\n\twhile(t--){\n\
    \t\tll n, m, a, b;\n\t\tcin >> n >> m >> a >> b;\n\t\tcout << floor_sum(n, m,\
    \ a, b) << '\\n';\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\
    \n\n#include \"./../../template/template.hpp\"\n#include \"./../../math/floor_sum.hpp\"\
    \n\nusing namespace mmrz;\n\nvoid mmrz::solve(){\n\tint t;\n\tcin >> t;\n\twhile(t--){\n\
    \t\tll n, m, a, b;\n\t\tcin >> n >> m >> a >> b;\n\t\tcout << floor_sum(n, m,\
    \ a, b) << '\\n';\n\t}\n}\n"
  dependsOn:
  - template/template.hpp
  - math/floor_sum.hpp
  isVerificationFile: true
  path: verify/yosupo/floor_sum.test.cpp
  requiredBy: []
  timestamp: '2025-05-20 21:02:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/floor_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/floor_sum.test.cpp
- /verify/verify/yosupo/floor_sum.test.cpp.html
title: verify/yosupo/floor_sum.test.cpp
---
