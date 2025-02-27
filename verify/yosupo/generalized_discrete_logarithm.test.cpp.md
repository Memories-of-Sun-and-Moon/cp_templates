---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/generalized_discrete_logarithm.hpp
    title: generalized_discrete_logarithm
  - icon: ':heavy_check_mark:'
    path: math/power.hpp
    title: math/power.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/discrete_logarithm_mod
    links:
    - https://judge.yosupo.jp/problem/discrete_logarithm_mod
  bundledCode: "#line 1 \"verify/yosupo/generalized_discrete_logarithm.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\n\n\
    #line 1 \"template/template.hpp\"\n# include <bits/stdc++.h>\nusing namespace\
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
    \ 1 \"math/generalized_discrete_logarithm.hpp\"\n\ntemplate<typename T>\nT generalized_discrete_logarithm(T\
    \ x, T y, auto f, int n, auto f_m, int m){\n\tif(x == y){\n\t\treturn 0;\n\t}\n\
    \n\tunordered_set<T> baby_steps;\n\tT fy = y;\n\tfor(int i = 0;i < m;i++){\n\t\
    \tbaby_steps.insert(fy);\n\t\tfy = f(fy);\n\t}\n\n\tT fx = x;\n\tbool is_first_loop\
    \ = true;\n\tfor(int i = 0;i <= n;i += m){\n\t\tT next_val = f_m(fx);\n\t\tif(baby_steps.contains(next_val)){\n\
    \t\t\tfor(int j = i+1;j <= i+m;j++){\n\t\t\t\tfx = f(fx);\n\t\t\t\tif(fx == y){\n\
    \t\t\t\t\treturn (j <= n ? j : -1);\n\t\t\t\t}\n\t\t\t}\n\t\t\tif(is_first_loop){\n\
    \t\t\t\tis_first_loop = false;\n\t\t\t}else{\n\t\t\t\treturn -1;\n\t\t\t}\n\t\t\
    }\n\t\tfx = next_val;\n\t}\n\treturn -1;\n}\n#line 1 \"math/power.hpp\"\n\ntemplate<typename\
    \ mint>\nmint power(mint n, long long k) {\n\tmint ret = 1;\n\twhile(k > 0) {\n\
    \t\tif(k & 1)ret *= n;\n\t\tn = n*n;\n\t\tk >>= 1;\n\t}\n\treturn ret;\n}\n\n\
    long long power(long long n, long long k, long long p) {\n\tlong long ret = 1;\n\
    \twhile(k > 0){\n\t\tif(k & 1)ret = ret*n % p;\n\t\tn = n*n % p;\n\t\tk >>= 1;\n\
    \t}\n\treturn ret;\n}\n#line 6 \"verify/yosupo/generalized_discrete_logarithm.test.cpp\"\
    \n\nusing namespace mmrz;\n\nvoid SOLVE(){\n\tll x, y, m;\n\tcin >> x >> y >>\
    \ m;\n\n\tauto f = [&x, &m](ll a) -> ll {\n\t\treturn (a*x)%m;\n\t};\n\n\tint\
    \ sq = sqrt(m);\n\tll x_sq = power(x, sq, m);\n\tauto f_sq = [&x_sq, &m](ll a)\
    \ -> ll {\n\t\treturn (a*x_sq)%m;\n\t};\n\n\tcout << generalized_discrete_logarithm<int>(1%m,\
    \ y, f, m, f_sq, sq) << '\\n';\n}\n\nvoid mmrz::solve(){\n\tint t = 1;\n\tcin\
    \ >> t;\n\twhile(t--)SOLVE();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\
    \n\n#include \"./../../template/template.hpp\"\n#include \"./../../math/generalized_discrete_logarithm.hpp\"\
    \n#include \"./../../math/power.hpp\"\n\nusing namespace mmrz;\n\nvoid SOLVE(){\n\
    \tll x, y, m;\n\tcin >> x >> y >> m;\n\n\tauto f = [&x, &m](ll a) -> ll {\n\t\t\
    return (a*x)%m;\n\t};\n\n\tint sq = sqrt(m);\n\tll x_sq = power(x, sq, m);\n\t\
    auto f_sq = [&x_sq, &m](ll a) -> ll {\n\t\treturn (a*x_sq)%m;\n\t};\n\n\tcout\
    \ << generalized_discrete_logarithm<int>(1%m, y, f, m, f_sq, sq) << '\\n';\n}\n\
    \nvoid mmrz::solve(){\n\tint t = 1;\n\tcin >> t;\n\twhile(t--)SOLVE();\n}\n"
  dependsOn:
  - template/template.hpp
  - math/generalized_discrete_logarithm.hpp
  - math/power.hpp
  isVerificationFile: true
  path: verify/yosupo/generalized_discrete_logarithm.test.cpp
  requiredBy: []
  timestamp: '2025-02-26 06:10:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/generalized_discrete_logarithm.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/generalized_discrete_logarithm.test.cpp
- /verify/verify/yosupo/generalized_discrete_logarithm.test.cpp.html
title: verify/yosupo/generalized_discrete_logarithm.test.cpp
---
