---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/lowest_common_ancestor.hpp
    title: Lowest Common Ancestor
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
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"verify/yosupo/lca.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\
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
    \ 2 \"graph/lowest_common_ancestor.hpp\"\n\n#line 4 \"graph/lowest_common_ancestor.hpp\"\
    \n\nstruct lowest_common_ancestor {\nprivate:\n\tint n;\n\tint root;\n\tstd::vector<std::vector<int>>par;\n\
    public:\n\tstd::vector<int>depth;\n\n\tlowest_common_ancestor(std::vector<std::vector<int>>&\
    \ g, int Root) : n((int)g.size()) {\n\t\tdepth.resize(n);\n\t\tpar.resize(n);\n\
    \t\tfor (int i = 0; i < n; i++)par[i].resize(31);\n\t\troot = Root;\n\n\t\tauto\
    \ dfs = [&](auto f, int v, int p, int d) -> void {\n\t\t\tpar[v][0] = p;\n\t\t\
    \tdepth[v] = d;\n\t\t\tfor(size_t i = 0;i < g[v].size();i++){\n\t\t\t\tif(g[v][i]\
    \ == p)continue;\n\t\t\t\tf(f, g[v][i], v, d+1);\n\t\t\t}\n\t\t};\n\n\t\tdfs(dfs,\
    \ root, -1, 0);\n\t\t\n\t\tfor (int i = 0; i < 30; i++) {\n\t\t\tfor (int j =\
    \ 0; j < n; j++) {\n\t\t\t\tif (par[j][i] == -1)par[j][i + 1] = -1;\n\t\t\t\t\
    else par[j][i + 1] = par[par[j][i]][i];\n\t\t\t}\n\t\t}\n\t}\n\n\tint get(int\
    \ u, int v) {\n\t\tif (depth[u] > depth[v])std::swap(u, v);\n\t\tfor (int i =\
    \ 30; i >= 0; i--) {\n\t\t\tif (((depth[v] - depth[u]) >> i) & 1) {\n\t\t\t\t\
    v = par[v][i];\n\t\t\t}\n\t\t}\n\t\tif (u == v)return u;\n\n\t\tfor (int i = 30;\
    \ i >= 0; i--) {\n\t\t\tif (par[u][i] != par[v][i]) {\n\t\t\t\tu = par[u][i];\n\
    \t\t\t\tv = par[v][i];\n\t\t\t}\n\t\t}\n\t\treturn par[u][0];\n\t}\n};\n#line\
    \ 5 \"verify/yosupo/lca.test.cpp\"\n\nvoid mmrz::solve(){\n\tint n, q;\n\tcin\
    \ >> n >> q;\n\tvector<vector<int>> g(n);\n\tfor(int i = 1;i < n;i++){\n\t\tint\
    \ p;\n\t\tcin >> p;\n\t\tg[i].eb(p);\n\t\tg[p].eb(i);\n\t}\n\n\tlowest_common_ancestor\
    \ lca(g, 0);\n\n\twhile(q--){\n\t\tint u, v;\n\t\tcin >> u >> v;\n\t\tcout <<\
    \ lca.get(u, v) << '\\n';\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include \"./../../template/template.hpp\"\
    \n#include \"./../../graph/lowest_common_ancestor.hpp\"\n\nvoid mmrz::solve(){\n\
    \tint n, q;\n\tcin >> n >> q;\n\tvector<vector<int>> g(n);\n\tfor(int i = 1;i\
    \ < n;i++){\n\t\tint p;\n\t\tcin >> p;\n\t\tg[i].eb(p);\n\t\tg[p].eb(i);\n\t}\n\
    \n\tlowest_common_ancestor lca(g, 0);\n\n\twhile(q--){\n\t\tint u, v;\n\t\tcin\
    \ >> u >> v;\n\t\tcout << lca.get(u, v) << '\\n';\n\t}\n}\n"
  dependsOn:
  - template/template.hpp
  - graph/lowest_common_ancestor.hpp
  isVerificationFile: true
  path: verify/yosupo/lca.test.cpp
  requiredBy: []
  timestamp: '2025-07-01 03:22:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/lca.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/lca.test.cpp
- /verify/verify/yosupo/lca.test.cpp.html
title: verify/yosupo/lca.test.cpp
---
