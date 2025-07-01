---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data_structure/sparse_table.hpp
    title: data_structure/sparse_table.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"verify/yosupo/staticrmq.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\
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
    \ 2 \"data_structure/sparse_table.hpp\"\n\n#line 6 \"data_structure/sparse_table.hpp\"\
    \n\ntemplate<typename T>\nstruct sparse_table {\n\tusing F = std::function<T(T,\
    \ T)>;\n\n\tF f;\n\tstd::vector<std::vector<T>> table;\n\tstd::vector<int> lr_length;\n\
    \n\tsparse_table() = default;\n\n\tsparse_table(const std::vector<T> &v, const\
    \ F &_f) : f(_f) {\n\t\tconst int n = (int)v.size();\n\t\tconst int msb = 32 -\
    \ __builtin_clz(n);\n\t\t\n\t\ttable.assign(msb, std::vector<T>(n));\n\t\tfor(int\
    \ i = 0;i < std::ssize(v);i++){\n\t\t\ttable[0][i] = v[i];\n\t\t}\n\t\tfor(int\
    \ i = 1;i < msb;i++){\n\t\t\tfor(int j = 0;j + (1 << i) <= n;j++){\n\t\t\t\ttable[i][j]\
    \ = f(table[i-1][j], table[i-1][j + (1 << (i-1))]);\n\t\t\t}\n\t\t}\n\n\t\tlr_length.resize(std::ssize(v)\
    \ + 1);\n\t\tfor(int i = 2;i < std::ssize(lr_length);i++){\n\t\t\tlr_length[i]\
    \ = lr_length[i >> 1] + 1;\n\t\t}\n\t}\n\n\tT fold(int l, int r) const {\n\t\t\
    return f(table[lr_length[r-l]][l], table[lr_length[r-l]][r-(1 << lr_length[r-l])]);\n\
    \t}\n};\n#line 5 \"verify/yosupo/staticrmq.test.cpp\"\n\nusing namespace mmrz;\n\
    \nvoid mmrz::solve(){\n\tint n, q;\n\tcin >> n >> q;\n\tvector<int> a(n);\n\t\
    for(auto &x : a)cin >> x;\n\tsparse_table<int> table(a, [](int l, int r){return\
    \ min(l, r);});\n\twhile(q--){\n\t\tint l, r;\n\t\tcin >> l >> r;\n\t\tcout <<\
    \ table.fold(l, r) << '\\n';\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ \"./../../template/template.hpp\"\n#include \"./../../data_structure/sparse_table.hpp\"\
    \n\nusing namespace mmrz;\n\nvoid mmrz::solve(){\n\tint n, q;\n\tcin >> n >> q;\n\
    \tvector<int> a(n);\n\tfor(auto &x : a)cin >> x;\n\tsparse_table<int> table(a,\
    \ [](int l, int r){return min(l, r);});\n\twhile(q--){\n\t\tint l, r;\n\t\tcin\
    \ >> l >> r;\n\t\tcout << table.fold(l, r) << '\\n';\n\t}\n}\n"
  dependsOn:
  - template/template.hpp
  - data_structure/sparse_table.hpp
  isVerificationFile: true
  path: verify/yosupo/staticrmq.test.cpp
  requiredBy: []
  timestamp: '2025-07-01 03:22:56+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo/staticrmq.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/staticrmq.test.cpp
- /verify/verify/yosupo/staticrmq.test.cpp.html
title: verify/yosupo/staticrmq.test.cpp
---
