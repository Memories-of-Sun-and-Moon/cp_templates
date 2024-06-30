---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: verify/yosupo/zalgorithm.cpp
    title: verify/yosupo/zalgorithm.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/alds1/14_B.test.cpp
    title: verify/aoj/alds1/14_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj/dsl/1_A.test.cpp
    title: verify/aoj/dsl/1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj/dsl/2_A___segment_tree.test.cpp
    title: verify/aoj/dsl/2_A___segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj/dsl/2_A___segment_tree_0-indexed.test.cpp
    title: verify/aoj/dsl/2_A___segment_tree_0-indexed.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj/dsl/2_B___segment_tree.test.cpp
    title: verify/aoj/dsl/2_B___segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj/dsl/2_B___segment_tree_0-indexed.test.cpp
    title: verify/aoj/dsl/2_B___segment_tree_0-indexed.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj/dsl/5_B.test.cpp
    title: verify/aoj/dsl/5_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj/grl/2_A.test.cpp
    title: verify/aoj/grl/2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj/grl/3_C.test.cpp
    title: verify/aoj/grl/3_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj/grl/6_B.test.cpp
    title: verify/aoj/grl/6_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj/id/2286.test.cpp
    title: verify/aoj/id/2286.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj/id/2828.test.cpp
    title: verify/aoj/id/2828.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/lc/assignment.test.cpp
    title: verify/lc/assignment.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/assignment.test.cpp
    title: verify/yosupo/assignment.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/convolution_mod.test.cpp
    title: verify/yosupo/convolution_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/factorize.test.cpp
    title: verify/yosupo/factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/number_of_substrings.test.cpp
    title: verify/yosupo/number_of_substrings.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/primality_test.test.cpp
    title: verify/yosupo/primality_test.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/suffixarray.test.cpp
    title: verify/yosupo/suffixarray.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/two_sat.test.cpp
    title: verify/yosupo/two_sat.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/unionfind.test.cpp
    title: verify/yosupo/unionfind.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yukicoder/1435.test.cpp
    title: verify/yukicoder/1435.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yukicoder/2219.test.cpp
    title: verify/yukicoder/2219.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yukicoder/274.test.cpp
    title: verify/yukicoder/274.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yukicoder/2780.test.cpp
    title: verify/yukicoder/2780.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"template/template.hpp\"\n# include <bits/stdc++.h>\nusing\
    \ namespace std;\nusing ll = long long;\nusing ull = unsigned long long;\nconst\
    \ double pi = acos(-1);\ntemplate<class T>constexpr T inf() { return ::std::numeric_limits<T>::max();\
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
    # define pb push_back\n# define exists(c, e)         ((c).find(e) != (c).end())\n\
    \nstruct INIT{\n\tINIT(){\n\t\tstd::ios::sync_with_stdio(false);\n\t\tstd::cin.tie(0);\n\
    \t\tcout << fixed << setprecision(20);\n\t}\n}INIT;\n\nnamespace mmrz {\n\tvoid\
    \ solve();\n}\n\nint main(){\n\tmmrz::solve();\n}\n"
  code: "# include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\
    using ull = unsigned long long;\nconst double pi = acos(-1);\ntemplate<class T>constexpr\
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
    # define pb push_back\n# define exists(c, e)         ((c).find(e) != (c).end())\n\
    \nstruct INIT{\n\tINIT(){\n\t\tstd::ios::sync_with_stdio(false);\n\t\tstd::cin.tie(0);\n\
    \t\tcout << fixed << setprecision(20);\n\t}\n}INIT;\n\nnamespace mmrz {\n\tvoid\
    \ solve();\n}\n\nint main(){\n\tmmrz::solve();\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: template/template.hpp
  requiredBy:
  - verify/yosupo/zalgorithm.cpp
  timestamp: '2024-05-24 13:30:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yukicoder/1435.test.cpp
  - verify/yukicoder/2219.test.cpp
  - verify/yukicoder/274.test.cpp
  - verify/yukicoder/2780.test.cpp
  - verify/lc/assignment.test.cpp
  - verify/aoj/alds1/14_B.test.cpp
  - verify/aoj/grl/3_C.test.cpp
  - verify/aoj/grl/2_A.test.cpp
  - verify/aoj/grl/6_B.test.cpp
  - verify/aoj/dsl/2_A___segment_tree_0-indexed.test.cpp
  - verify/aoj/dsl/2_B___segment_tree_0-indexed.test.cpp
  - verify/aoj/dsl/2_B___segment_tree.test.cpp
  - verify/aoj/dsl/1_A.test.cpp
  - verify/aoj/dsl/2_A___segment_tree.test.cpp
  - verify/aoj/dsl/5_B.test.cpp
  - verify/aoj/id/2286.test.cpp
  - verify/aoj/id/2828.test.cpp
  - verify/yosupo/two_sat.test.cpp
  - verify/yosupo/factorize.test.cpp
  - verify/yosupo/convolution_mod.test.cpp
  - verify/yosupo/unionfind.test.cpp
  - verify/yosupo/suffixarray.test.cpp
  - verify/yosupo/primality_test.test.cpp
  - verify/yosupo/number_of_substrings.test.cpp
  - verify/yosupo/assignment.test.cpp
documentation_of: template/template.hpp
layout: document
redirect_from:
- /library/template/template.hpp
- /library/template/template.hpp.html
title: template/template.hpp
---