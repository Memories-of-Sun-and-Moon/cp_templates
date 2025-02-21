---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/binary_indexed_tree.hpp
    title: BIT(Binary Indexed Tree)
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B
  bundledCode: "#line 1 \"verify/aoj/dsl/2_B___BIT.test.cpp\"\n# define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B\"\n\n#line\
    \ 1 \"template/template.hpp\"\n# include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nusing ull = unsigned long long;\nconst double pi = acos(-1);\n\
    template<class T>constexpr T inf() { return ::std::numeric_limits<T>::max(); }\n\
    template<class T>constexpr T hinf() { return inf<T>() / 2; }\ntemplate <typename\
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
    \ 1 \"data_structure/binary_indexed_tree.hpp\"\n\ntemplate<typename T>struct binary_indexed_tree\
    \ {\n\tint n;\n\tvector<T> BIT;\n\tbinary_indexed_tree(int n_) : n(n_ + 1), BIT(n,\
    \ 0) {}\n\n\tvoid add(int i, T x){\n\t\tfor(int idx = i;idx < n;idx += (idx &\
    \ -idx)){\n\t\t\tBIT[idx] += x;\n\t\t}\n\t}\n\n\tT sum(int i) {\n\t\tT ret = 0;\n\
    \t\tfor(int idx = i;idx > 0;idx -= (idx & -idx)){\n\t\t\tret += BIT[idx];\n\t\t\
    }\n\t\treturn ret;\n\t}\n};\n#line 5 \"verify/aoj/dsl/2_B___BIT.test.cpp\"\n\n\
    void mmrz::solve(){\n\tint n, q;\n\tcin >> n >> q;\n\tbinary_indexed_tree<int>\
    \ BIT(n);\n\twhile(q--){\n\t\tint com, x, y;\n\t\tcin >> com >> x >> y;\n\t\t\
    if(com == 0){\n\t\t\tBIT.add(x, y);\n\t\t}else{\n\t\t\tcout << BIT.sum(y) - (x\
    \ != 1 ? BIT.sum(x - 1) : 0) << endl;\n\t\t}\n\t}\n}\n"
  code: "# define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B\"\
    \n\n#include \"./../../../template/template.hpp\"\n#include \"./../../../data_structure/binary_indexed_tree.hpp\"\
    \n\nvoid mmrz::solve(){\n\tint n, q;\n\tcin >> n >> q;\n\tbinary_indexed_tree<int>\
    \ BIT(n);\n\twhile(q--){\n\t\tint com, x, y;\n\t\tcin >> com >> x >> y;\n\t\t\
    if(com == 0){\n\t\t\tBIT.add(x, y);\n\t\t}else{\n\t\t\tcout << BIT.sum(y) - (x\
    \ != 1 ? BIT.sum(x - 1) : 0) << endl;\n\t\t}\n\t}\n}\n"
  dependsOn:
  - template/template.hpp
  - data_structure/binary_indexed_tree.hpp
  isVerificationFile: true
  path: verify/aoj/dsl/2_B___BIT.test.cpp
  requiredBy: []
  timestamp: '2025-02-14 10:23:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj/dsl/2_B___BIT.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj/dsl/2_B___BIT.test.cpp
- /verify/verify/aoj/dsl/2_B___BIT.test.cpp.html
title: verify/aoj/dsl/2_B___BIT.test.cpp
---
