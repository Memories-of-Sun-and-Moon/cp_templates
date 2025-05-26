---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/tree_diameter.hpp
    title: "\u6728\u306E\u76F4\u5F84\u8A08\u7B97"
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
    PROBLEM: https://judge.yosupo.jp/problem/tree_diameter
    links:
    - https://judge.yosupo.jp/problem/tree_diameter
  bundledCode: "#line 1 \"verify/yosupo/tree_diameter.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/tree_diameter\"\n\n#line 1 \"template/template.hpp\"\
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
    \ 1 \"graph/tree_diameter.hpp\"\n\ntemplate<typename T=ll>\npair<T, vector<int>>\
    \ tree_diameter(const vector<vector<pair<int, T>>> &g){\n\tint n = (int)g.size();\n\
    \tvector dis(n, inf<T>());\n\tqueue<int> q;\n\tdis[0] = 0;\n\tq.push(0);\n\n\t\
    while(not q.empty()){\n\t\tint v = q.front();\n\t\tq.pop();\n\t\tfor(auto [to,\
    \ c] : g[v]){\n\t\t\tif(dis[to] != inf<T>())continue;\n\t\t\tdis[to] = dis[v]+c;\n\
    \t\t\tq.push(to);\n\t\t}\n\t}\n\n\tint r1 = -1;\n\tT mx = 0;\n\tfor(int v = 0;v\
    \ < n;v++){\n\t\tif(chmax(mx, dis[v])){\n\t\t\tr1 = v;\n\t\t}\n\t}\n\n\tdis.assign(n,\
    \ inf<T>());\n\tvector<int> par(n, -1);\n\tdis[r1] = 0;\n\tq.push(r1);\n\n\twhile(not\
    \ q.empty()){\n\t\tint v = q.front();\n\t\tq.pop();\n\t\tfor(auto [to, c] : g[v]){\n\
    \t\t\tif(dis[to] != inf<T>())continue;\n\t\t\tdis[to] = dis[v]+c;\n\t\t\tpar[to]\
    \ = v;\n\t\t\tq.push(to);\n\t\t}\n\t}\n\n\tint r2 = -1;\n\tT diameter = 0;\n\t\
    for(int v = 0;v < n;v++){\n\t\tif(chmax(diameter, dis[v])){\n\t\t\tr2 = v;\n\t\
    \t}\n\t}\n\n\tvector<int> path;\n\tfor(int cur = r2;cur != -1;cur = par[cur]){\n\
    \t\tpath.eb(cur);\n\t}\n\n\treturn {diameter, path};\n}\n\npair<int, vector<int>>\
    \ tree_diameter(const vector<vector<int>> &g_unweighted){\n\tint n = (int)g_unweighted.size();\n\
    \tvector<vector<pair<int, int>>> g(n);\n\n\tfor(int u = 0;u < n;u++){\n\t\tfor(int\
    \ v : g_unweighted[u]){\n\t\t\tg[u].eb(v, 1);\n\t\t\tg[v].eb(u, 1);\n\t\t}\n\t\
    }\n\treturn tree_diameter(g);\n}\n#line 5 \"verify/yosupo/tree_diameter.test.cpp\"\
    \n\nusing namespace mmrz;\n\nvoid mmrz::solve(){\n\tint n;\n\tcin >> n;\n\tvector<vector<pair<int,\
    \ ll>>> g(n);\n\trep(i, n-1){\n\t\tint a, b, c;\n\t\tcin >> a >> b >> c;\n\t\t\
    g[a].eb(b, c);\n\t\tg[b].eb(a, c);\n\t}\n\n\tauto [diameter, path] = tree_diameter(g);\n\
    \n\tcout << diameter << \" \" << len(path) << '\\n';\n\trep(i, len(path))cout\
    \ << path[i] << \" \\n\"[i == len(path)-1];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\n\n#include\
    \ \"./../../template/template.hpp\"\n#include \"./../../graph/tree_diameter.hpp\"\
    \n\nusing namespace mmrz;\n\nvoid mmrz::solve(){\n\tint n;\n\tcin >> n;\n\tvector<vector<pair<int,\
    \ ll>>> g(n);\n\trep(i, n-1){\n\t\tint a, b, c;\n\t\tcin >> a >> b >> c;\n\t\t\
    g[a].eb(b, c);\n\t\tg[b].eb(a, c);\n\t}\n\n\tauto [diameter, path] = tree_diameter(g);\n\
    \n\tcout << diameter << \" \" << len(path) << '\\n';\n\trep(i, len(path))cout\
    \ << path[i] << \" \\n\"[i == len(path)-1];\n}\n"
  dependsOn:
  - template/template.hpp
  - graph/tree_diameter.hpp
  isVerificationFile: true
  path: verify/yosupo/tree_diameter.test.cpp
  requiredBy: []
  timestamp: '2025-04-18 17:04:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/tree_diameter.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/tree_diameter.test.cpp
- /verify/verify/yosupo/tree_diameter.test.cpp.html
title: verify/yosupo/tree_diameter.test.cpp
---
