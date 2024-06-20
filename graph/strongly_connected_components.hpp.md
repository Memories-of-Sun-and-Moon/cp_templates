---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/two_sat.hpp
    title: 2-SAT
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/grl/3_C.test.cpp
    title: verify/aoj/grl/3_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/two_sat.test.cpp
    title: verify/yosupo/two_sat.test.cpp
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
  bundledCode: "#line 1 \"graph/strongly_connected_components.hpp\"\n\nstruct scc_graph\
    \ {\n\tvector<vector<int>> g;\n\tvector<vector<int>> rg;\n\tvector<bool> used;\n\
    \tvector<int> cmp;\n\tvector<int> vs;\n\tint n;\n\tint k;\n\n\tscc_graph(int _n)\
    \ : n(_n), k(0) {\n\t\tg.resize(n);\n\t\trg.resize(n);\n\t\tused.resize(n);\n\t\
    \tcmp.resize(n);\n\t}\n\n\tvoid add_edge(int a, int b) {\n\t\tg[a].push_back(b);\n\
    \t\trg[b].push_back(a);\n\t}\n\n\tvoid dfs(int v){\n\t\tused[v] = true;\n\t\t\
    for(auto to : g[v]){\n\t\t\tif(not used[to])dfs(to);\n\t\t}\n\t\tvs.pb(v);\n\t\
    }\n\n\tvoid rdfs(int v, int col){\n\t\tused[v] = true;\n\t\tcmp[v] = col;\n\t\t\
    for(auto to : rg[v]){\n\t\t\tif(not used[to])rdfs(to, col);\n\t\t}\n\t}\n\n\t\
    vector<vector<int>> scc() {\n\t\tfor(int i = 0;i < n;i++){\n\t\t\tif(not used[i])dfs(i);\n\
    \t\t}\n\t\tfor(int i = 0;i < n;i++){\n\t\t\tused[i] = false;\n\t\t}\n\t\tfor(auto\
    \ i = vs.rbegin();i != vs.rend();i++){\n\t\t\tif(not used[*i])rdfs(*i, k++);\n\
    \t\t}\n\t\tvector<vector<int>> ret(k);\n\t\tfor(int i = 0;i < n;i++){\n\t\t\t\
    ret[cmp[i]].push_back(i);\n\t\t}\n\t\treturn ret;\n\t}\n};\n"
  code: "\nstruct scc_graph {\n\tvector<vector<int>> g;\n\tvector<vector<int>> rg;\n\
    \tvector<bool> used;\n\tvector<int> cmp;\n\tvector<int> vs;\n\tint n;\n\tint k;\n\
    \n\tscc_graph(int _n) : n(_n), k(0) {\n\t\tg.resize(n);\n\t\trg.resize(n);\n\t\
    \tused.resize(n);\n\t\tcmp.resize(n);\n\t}\n\n\tvoid add_edge(int a, int b) {\n\
    \t\tg[a].push_back(b);\n\t\trg[b].push_back(a);\n\t}\n\n\tvoid dfs(int v){\n\t\
    \tused[v] = true;\n\t\tfor(auto to : g[v]){\n\t\t\tif(not used[to])dfs(to);\n\t\
    \t}\n\t\tvs.pb(v);\n\t}\n\n\tvoid rdfs(int v, int col){\n\t\tused[v] = true;\n\
    \t\tcmp[v] = col;\n\t\tfor(auto to : rg[v]){\n\t\t\tif(not used[to])rdfs(to, col);\n\
    \t\t}\n\t}\n\n\tvector<vector<int>> scc() {\n\t\tfor(int i = 0;i < n;i++){\n\t\
    \t\tif(not used[i])dfs(i);\n\t\t}\n\t\tfor(int i = 0;i < n;i++){\n\t\t\tused[i]\
    \ = false;\n\t\t}\n\t\tfor(auto i = vs.rbegin();i != vs.rend();i++){\n\t\t\tif(not\
    \ used[*i])rdfs(*i, k++);\n\t\t}\n\t\tvector<vector<int>> ret(k);\n\t\tfor(int\
    \ i = 0;i < n;i++){\n\t\t\tret[cmp[i]].push_back(i);\n\t\t}\n\t\treturn ret;\n\
    \t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/strongly_connected_components.hpp
  requiredBy:
  - graph/two_sat.hpp
  timestamp: '2024-06-08 00:30:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yukicoder/274.test.cpp
  - verify/yukicoder/2780.test.cpp
  - verify/aoj/grl/3_C.test.cpp
  - verify/yosupo/two_sat.test.cpp
documentation_of: graph/strongly_connected_components.hpp
layout: document
title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
---

# 強連結成分分解

## 使い方

グラフ $G$ は頂点数 $N$, 辺数 $M$ の有向グラフとする。

- ``scc_graph(n)`` : 頂点数 $N$ の有向グラフを定義する
- ``add_edge(int a, int b)`` : $a$ から $b$ へ向かう辺を追加する
- ``vector<vector<int>> scc()`` : 強連結成分分解をする。トポロジカルソートされた強連結成分・その強連結成分に属する頂点集合を返す。 $O(N+M)$
