---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/union_find.hpp
    title: Union-Find
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
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"verify/yosupo/unionfind.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
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
    # define pb push_back\n# define exists(c, e)         ((c).find(e) != (c).end())\n\
    \nstruct INIT{\n\tINIT(){\n\t\tstd::ios::sync_with_stdio(false);\n\t\tstd::cin.tie(0);\n\
    \t\tcout << fixed << setprecision(20);\n\t}\n}INIT;\n\nnamespace mmrz {\n\tvoid\
    \ solve();\n}\n\nint main(){\n\tmmrz::solve();\n}\n#line 1 \"data_structure/union_find.hpp\"\
    \n\nstruct union_find {\n\tvector<int> v;\n\tint g_size;\n\n\tunion_find(size_t\
    \ size) : v(size, -1), g_size(size) {}\n\n\tint root(int x){\n\t\treturn (v[x]\
    \ < 0 ? x : v[x] = root(v[x]));\n\t}\n\n\tbool is_root(int x){\n\t\treturn root(x)\
    \ == x;\n\t}\n\n\tbool unite(int x, int y){\n\t\tx = root(x);\n\t\ty = root(y);\n\
    \t\tif(x != y){\n\t\t\tif(v[x] > v[y])swap(x, y);\n\t\t\tv[x] += v[y];\n\t\t\t\
    v[y] = x;\n\t\t\tg_size--;\n\t\t\treturn true;\n\t\t}\n\t\treturn false;\n\t}\n\
    \n\tbool is_same(int x,int y){\n\t\treturn root(x) == root(y);\n\t}\n\n\tint get_size(int\
    \ x){\n\t\tx = root(x);\n\t\treturn -v[x];\n\t}\n\n\tint groups_size(){\n\t\t\
    return g_size;\n\t}\n};\n#line 5 \"verify/yosupo/unionfind.test.cpp\"\n\nvoid\
    \ mmrz::solve(){\n\tint n, q;\n\tcin >> n >> q;\n\tunion_find uf(n);\n\twhile(q--){\n\
    \t\tint t;\n\t\tcin >> t;\n\t\tif(t == 0){\n\t\t\tint u, v;\n\t\t\tcin >> u >>\
    \ v;\n\t\t\tuf.unite(u, v);\n\t\t}else{\n\t\t\tint u, v;\n\t\t\tcin >> u >> v;\n\
    \t\t\tcout << (uf.is_same(u, v) ? 1 : 0) << endl;\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ \"./../../template/template.hpp\"\n#include \"./../../data_structure/union_find.hpp\"\
    \n\nvoid mmrz::solve(){\n\tint n, q;\n\tcin >> n >> q;\n\tunion_find uf(n);\n\t\
    while(q--){\n\t\tint t;\n\t\tcin >> t;\n\t\tif(t == 0){\n\t\t\tint u, v;\n\t\t\
    \tcin >> u >> v;\n\t\t\tuf.unite(u, v);\n\t\t}else{\n\t\t\tint u, v;\n\t\t\tcin\
    \ >> u >> v;\n\t\t\tcout << (uf.is_same(u, v) ? 1 : 0) << endl;\n\t\t}\n\t}\n\
    }\n"
  dependsOn:
  - template/template.hpp
  - data_structure/union_find.hpp
  isVerificationFile: true
  path: verify/yosupo/unionfind.test.cpp
  requiredBy: []
  timestamp: '2024-07-07 01:02:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/unionfind.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/unionfind.test.cpp
- /verify/verify/yosupo/unionfind.test.cpp.html
title: verify/yosupo/unionfind.test.cpp
---