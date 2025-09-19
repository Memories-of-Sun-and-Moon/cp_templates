---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: graph/bipartite_matching.hpp
    title: "\u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\
      \u30B0"
  - icon: ':heavy_check_mark:'
    path: graph/dinic.hpp
    title: "\u6700\u5927\u6D41(Dinic)"
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/bipertitematching
  bundledCode: "#line 1 \"verify/yosupo/bipertitematching.cpp\"\n# define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/bipertitematching\"\n\n#line 1 \"template/template.hpp\"\
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
    \ 2 \"graph/bipartite_matching.hpp\"\n\n#line 2 \"graph/dinic.hpp\"\n\n#line 6\
    \ \"graph/dinic.hpp\"\n\ntemplate<typename T>\nstruct dinic {\n\n\tstruct edge{\n\
    \t\tint to;\n\t\tT cap;\n\t\tT rev;\n\t\tT init_cap;\n\t};\n\t\t\n\tint n;\n\t\
    std::vector<std::vector<edge>> G;\n\tstd::vector<int> level;\n\tstd::vector<int>\
    \ iter;\n\n\tstd::vector<int> from_idx, to_idx;\n\tint edge_idx;\n\n\tdinic(int\
    \ _v) : n(_v), G(n), level(n), iter(n), edge_idx(0) {}\n\n\tint add_edge(int from,\
    \ int to, T cap){\n\t\tG[from].push_back((edge){to, cap, (T)G[to].size(), cap});\n\
    \t\tG[to].push_back((edge){from, 0, (T)(G[from].size() - 1), 0});\n\t\tfrom_idx.emplace_back(from);\n\
    \t\tto_idx.emplace_back((int)G[from].size()-1);\n\t\t\n\t\treturn edge_idx++;\n\
    \t}\n\n\tvoid bfs(int s){\n\t\tfor(int i = 0;i < n;i++)level[i] = -1;\n\t\tstd::queue<int>\
    \ que;\n\t\tlevel[s] = 0;\n\t\tque.push(s);\n\t\twhile(!que.empty()){\n\t\t\t\
    int v = que.front();\n\t\t\tque.pop();\n\t\t\tfor(int i = 0;i < (int)G[v].size();i++){\n\
    \t\t\t\tedge &e = G[v][i];\n\t\t\t\tif(e.cap > 0 && level[e.to] < 0){\n\t\t\t\t\
    \tlevel[e.to] = level[v] + 1;\n\t\t\t\t\tque.push(e.to);\n\t\t\t\t}\n\t\t\t}\n\
    \t\t}\n\t}\n\n\tT dfs(int v, int t, T f){\n\t\tif(v == t)return f;\n\t\tfor(int\
    \ &i = iter[v];i < (int)G[v].size();i++){\n\t\t\tedge &e = G[v][i];\n\t\t\tif(e.cap\
    \ > 0 && level[v] < level[e.to]){\n\t\t\t\tT d = dfs(e.to, t, min(f, e.cap));\n\
    \t\t\t\tif(d > 0){\n\t\t\t\t\te.cap -= d;\n\t\t\t\t\tG[e.to][e.rev].cap += d;\n\
    \t\t\t\t\treturn d;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\t}\n\n\tT calc(int\
    \ s, int t){\n\t\tT flow = 0;\n\t\tfor(;;){\n\t\t\tbfs(s);\n\t\t\tif(level[t]\
    \ < 0)return flow;\n\t\t\tfor(int i = 0;i < n;i++)iter[i] = 0;\n\t\t\tT f;\n\t\
    \t\twhile((f = dfs(s, t, std::numeric_limits<T>::max())) > 0) {\n\t\t\t\tflow\
    \ += f;\n\t\t\t}\n\t\t}\n\t}\n\n\tT get_flow(int idx){\n\t\treturn G[from_idx[idx]][to_idx[idx]].init_cap\
    \ - G[from_idx[idx]][to_idx[idx]].cap;\n\t}\n};\n#line 4 \"graph/bipartite_matching.hpp\"\
    \n\n#line 6 \"graph/bipartite_matching.hpp\"\n#include<ranges>\n\nvector<pair<int,\
    \ int>> bipartite_matching(const int &l, const int &r, const vector<pair<int,\
    \ int>> &es) {\n\n\tdinic<int> matching(l+r+2);\n\tconst int S = l+r+0;\n\tconst\
    \ int T = l+r+1;\n\n\tfor(int i = 0;i < l;i++)matching.add_edge(S, i, 1);\n\t\
    for(int i = 0;i < r;i++)matching.add_edge(l+i, T, 1);\n\tfor(auto [u, v] : es){\n\
    \t\tmatching.add_edge(u, l+v, 1);\n\t}\n\n\tmatching.calc(S, T);\n\n\tstd::vector<pair<int,\
    \ int>> ret;\n\t\n\t// C++23\n\t// for(auto [idx, edge] : es | std::views::enumerate)\
    \ {\n\tfor(int idx = 0;idx < ssize(es);idx++){\n\t\tauto &edge = es[idx];\n\t\t\
    if(matching.get_flow(l+r+idx) == 1){\n\t\t\tret.emplace_back(edge);\n\t\t}\n\t\
    }\n\n\treturn ret;\n}\n#line 5 \"verify/yosupo/bipertitematching.cpp\"\n\nvoid\
    \ mmrz::solve(){\n\tint l, r, m;\n\tcin >> l >> r >> m;\n\tvector<pair<int, int>>\
    \ es;\n\twhile(m--){\n\t\tint a, b;\n\t\tcin >> a >> b;\n\t\tes.emplace_back(a,\
    \ b);\n\t}\n\n\tauto bm = bipartite_matching(l, r, es);\n\n\tcout << ssize(bm)\
    \ << '\\n';\n\tfor(auto [l_v, r_v] : bm){\n\t\tcout << l_v << ' ' << r_v << '\\\
    n';\n\t}\n}\n"
  code: "# define PROBLEM \"https://judge.yosupo.jp/problem/bipertitematching\"\n\n\
    #include \"./../../template/template.hpp\"\n#include \"./../../graph/bipartite_matching.hpp\"\
    \n\nvoid mmrz::solve(){\n\tint l, r, m;\n\tcin >> l >> r >> m;\n\tvector<pair<int,\
    \ int>> es;\n\twhile(m--){\n\t\tint a, b;\n\t\tcin >> a >> b;\n\t\tes.emplace_back(a,\
    \ b);\n\t}\n\n\tauto bm = bipartite_matching(l, r, es);\n\n\tcout << ssize(bm)\
    \ << '\\n';\n\tfor(auto [l_v, r_v] : bm){\n\t\tcout << l_v << ' ' << r_v << '\\\
    n';\n\t}\n}\n"
  dependsOn:
  - template/template.hpp
  - graph/bipartite_matching.hpp
  - graph/dinic.hpp
  isVerificationFile: false
  path: verify/yosupo/bipertitematching.cpp
  requiredBy: []
  timestamp: '2025-09-19 19:07:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: verify/yosupo/bipertitematching.cpp
layout: document
redirect_from:
- /library/verify/yosupo/bipertitematching.cpp
- /library/verify/yosupo/bipertitematching.cpp.html
title: verify/yosupo/bipertitematching.cpp
---
