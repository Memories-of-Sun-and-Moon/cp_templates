---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/tree_diameter.test.cpp
    title: verify/yosupo/tree_diameter.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/tree_diameter.hpp\"\n\ntemplate<typename T=ll>\npair<T,\
    \ vector<int>> tree_diameter(const vector<vector<pair<int, T>>> &g){\n\tint n\
    \ = (int)g.size();\n\tvector dis(n, inf<T>());\n\tqueue<int> q;\n\tdis[0] = 0;\n\
    \tq.push(0);\n\n\twhile(not q.empty()){\n\t\tint v = q.front();\n\t\tq.pop();\n\
    \t\tfor(auto [to, c] : g[v]){\n\t\t\tif(dis[to] != inf<T>())continue;\n\t\t\t\
    dis[to] = dis[v]+c;\n\t\t\tq.push(to);\n\t\t}\n\t}\n\n\tint r1 = -1;\n\tT mx =\
    \ 0;\n\tfor(int v = 0;v < n;v++){\n\t\tif(chmax(mx, dis[v])){\n\t\t\tr1 = v;\n\
    \t\t}\n\t}\n\n\tdis.assign(n, inf<T>());\n\tvector<int> par(n, -1);\n\tdis[r1]\
    \ = 0;\n\tq.push(r1);\n\n\twhile(not q.empty()){\n\t\tint v = q.front();\n\t\t\
    q.pop();\n\t\tfor(auto [to, c] : g[v]){\n\t\t\tif(dis[to] != inf<T>())continue;\n\
    \t\t\tdis[to] = dis[v]+c;\n\t\t\tpar[to] = v;\n\t\t\tq.push(to);\n\t\t}\n\t}\n\
    \n\tint r2 = -1;\n\tT diameter = 0;\n\tfor(int v = 0;v < n;v++){\n\t\tif(chmax(diameter,\
    \ dis[v])){\n\t\t\tr2 = v;\n\t\t}\n\t}\n\n\tvector<int> path;\n\tfor(int cur =\
    \ r2;cur != -1;cur = par[cur]){\n\t\tpath.eb(cur);\n\t}\n\n\treturn {diameter,\
    \ path};\n}\n\npair<int, vector<int>> tree_diameter(const vector<vector<int>>\
    \ &g_unweighted){\n\tint n = (int)g_unweighted.size();\n\tvector<vector<pair<int,\
    \ int>>> g(n);\n\n\tfor(int u = 0;u < n;u++){\n\t\tfor(int v : g_unweighted[u]){\n\
    \t\t\tg[u].eb(v, 1);\n\t\t\tg[v].eb(u, 1);\n\t\t}\n\t}\n\treturn tree_diameter(g);\n\
    }\n"
  code: "\ntemplate<typename T=ll>\npair<T, vector<int>> tree_diameter(const vector<vector<pair<int,\
    \ T>>> &g){\n\tint n = (int)g.size();\n\tvector dis(n, inf<T>());\n\tqueue<int>\
    \ q;\n\tdis[0] = 0;\n\tq.push(0);\n\n\twhile(not q.empty()){\n\t\tint v = q.front();\n\
    \t\tq.pop();\n\t\tfor(auto [to, c] : g[v]){\n\t\t\tif(dis[to] != inf<T>())continue;\n\
    \t\t\tdis[to] = dis[v]+c;\n\t\t\tq.push(to);\n\t\t}\n\t}\n\n\tint r1 = -1;\n\t\
    T mx = 0;\n\tfor(int v = 0;v < n;v++){\n\t\tif(chmax(mx, dis[v])){\n\t\t\tr1 =\
    \ v;\n\t\t}\n\t}\n\n\tdis.assign(n, inf<T>());\n\tvector<int> par(n, -1);\n\t\
    dis[r1] = 0;\n\tq.push(r1);\n\n\twhile(not q.empty()){\n\t\tint v = q.front();\n\
    \t\tq.pop();\n\t\tfor(auto [to, c] : g[v]){\n\t\t\tif(dis[to] != inf<T>())continue;\n\
    \t\t\tdis[to] = dis[v]+c;\n\t\t\tpar[to] = v;\n\t\t\tq.push(to);\n\t\t}\n\t}\n\
    \n\tint r2 = -1;\n\tT diameter = 0;\n\tfor(int v = 0;v < n;v++){\n\t\tif(chmax(diameter,\
    \ dis[v])){\n\t\t\tr2 = v;\n\t\t}\n\t}\n\n\tvector<int> path;\n\tfor(int cur =\
    \ r2;cur != -1;cur = par[cur]){\n\t\tpath.eb(cur);\n\t}\n\n\treturn {diameter,\
    \ path};\n}\n\npair<int, vector<int>> tree_diameter(const vector<vector<int>>\
    \ &g_unweighted){\n\tint n = (int)g_unweighted.size();\n\tvector<vector<pair<int,\
    \ int>>> g(n);\n\n\tfor(int u = 0;u < n;u++){\n\t\tfor(int v : g_unweighted[u]){\n\
    \t\t\tg[u].eb(v, 1);\n\t\t\tg[v].eb(u, 1);\n\t\t}\n\t}\n\treturn tree_diameter(g);\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/tree_diameter.hpp
  requiredBy: []
  timestamp: '2025-04-18 17:04:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/tree_diameter.test.cpp
documentation_of: graph/tree_diameter.hpp
layout: document
title: "\u6728\u306E\u76F4\u5F84\u8A08\u7B97"
---

# 木の直径計算

## 使い方

- ``auto [diameter, path] = tree_diameter(vector<vector<pair<int, ll>>> g)`` : 重み付き木 $G$ の直径とそのパスを返す。 $O(N)$
- ``auto [diameter, path] = tree_diameter(vector<vector<int>> g)`` : 重み無し木 $G$ の直径とそのパスを返す。 $O(N)$
