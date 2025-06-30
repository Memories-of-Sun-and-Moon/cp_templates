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
  bundledCode: "#line 1 \"graph/tree_diameter.hpp\"\n\n#include<numeric>\n#include<vector>\n\
    #include<utility>\n#include<queue>\n\ntemplate<typename T=long long>\nstd::pair<T,\
    \ std::vector<int>> tree_diameter(const std::vector<std::vector<std::pair<int,\
    \ T>>> &g){\n\tint n = (int)g.size();\n\tstd::vector dis(n, std::numeric_limits<T>::max());\n\
    \tstd::queue<int> q;\n\tdis[0] = 0;\n\tq.push(0);\n\n\twhile(not q.empty()){\n\
    \t\tint v = q.front();\n\t\tq.pop();\n\t\tfor(auto [to, c] : g[v]){\n\t\t\tif(dis[to]\
    \ != std::numeric_limits<T>::max())continue;\n\t\t\tdis[to] = dis[v]+c;\n\t\t\t\
    q.push(to);\n\t\t}\n\t}\n\n\tint r1 = -1;\n\tT mx = 0;\n\tfor(int v = 0;v < n;v++){\n\
    \t\tif(chmax(mx, dis[v])){\n\t\t\tr1 = v;\n\t\t}\n\t}\n\n\tdis.assign(n, std::numeric_limits<T>::max());\n\
    \tstd::vector<int> par(n, -1);\n\tdis[r1] = 0;\n\tq.push(r1);\n\n\twhile(not q.empty()){\n\
    \t\tint v = q.front();\n\t\tq.pop();\n\t\tfor(auto [to, c] : g[v]){\n\t\t\tif(dis[to]\
    \ != std::numeric_limits<T>::max())continue;\n\t\t\tdis[to] = dis[v]+c;\n\t\t\t\
    par[to] = v;\n\t\t\tq.push(to);\n\t\t}\n\t}\n\n\tint r2 = -1;\n\tT diameter =\
    \ 0;\n\tfor(int v = 0;v < n;v++){\n\t\tif(chmax(diameter, dis[v])){\n\t\t\tr2\
    \ = v;\n\t\t}\n\t}\n\n\tstd::vector<int> path;\n\tfor(int cur = r2;cur != -1;cur\
    \ = par[cur]){\n\t\tpath.emplace_back(cur);\n\t}\n\n\treturn {diameter, path};\n\
    }\n\nstd::pair<int, std::vector<int>> tree_diameter(const std::vector<std::vector<int>>\
    \ &g_unweighted){\n\tint n = (int)g_unweighted.size();\n\tstd::vector<std::vector<std::pair<int,\
    \ int>>> g(n);\n\n\tfor(int u = 0;u < n;u++){\n\t\tfor(int v : g_unweighted[u]){\n\
    \t\t\tg[u].emplace_back(v, 1);\n\t\t\tg[v].emplace_back(u, 1);\n\t\t}\n\t}\n\t\
    return tree_diameter(g);\n}\n"
  code: "\n#include<numeric>\n#include<vector>\n#include<utility>\n#include<queue>\n\
    \ntemplate<typename T=long long>\nstd::pair<T, std::vector<int>> tree_diameter(const\
    \ std::vector<std::vector<std::pair<int, T>>> &g){\n\tint n = (int)g.size();\n\
    \tstd::vector dis(n, std::numeric_limits<T>::max());\n\tstd::queue<int> q;\n\t\
    dis[0] = 0;\n\tq.push(0);\n\n\twhile(not q.empty()){\n\t\tint v = q.front();\n\
    \t\tq.pop();\n\t\tfor(auto [to, c] : g[v]){\n\t\t\tif(dis[to] != std::numeric_limits<T>::max())continue;\n\
    \t\t\tdis[to] = dis[v]+c;\n\t\t\tq.push(to);\n\t\t}\n\t}\n\n\tint r1 = -1;\n\t\
    T mx = 0;\n\tfor(int v = 0;v < n;v++){\n\t\tif(chmax(mx, dis[v])){\n\t\t\tr1 =\
    \ v;\n\t\t}\n\t}\n\n\tdis.assign(n, std::numeric_limits<T>::max());\n\tstd::vector<int>\
    \ par(n, -1);\n\tdis[r1] = 0;\n\tq.push(r1);\n\n\twhile(not q.empty()){\n\t\t\
    int v = q.front();\n\t\tq.pop();\n\t\tfor(auto [to, c] : g[v]){\n\t\t\tif(dis[to]\
    \ != std::numeric_limits<T>::max())continue;\n\t\t\tdis[to] = dis[v]+c;\n\t\t\t\
    par[to] = v;\n\t\t\tq.push(to);\n\t\t}\n\t}\n\n\tint r2 = -1;\n\tT diameter =\
    \ 0;\n\tfor(int v = 0;v < n;v++){\n\t\tif(chmax(diameter, dis[v])){\n\t\t\tr2\
    \ = v;\n\t\t}\n\t}\n\n\tstd::vector<int> path;\n\tfor(int cur = r2;cur != -1;cur\
    \ = par[cur]){\n\t\tpath.emplace_back(cur);\n\t}\n\n\treturn {diameter, path};\n\
    }\n\nstd::pair<int, std::vector<int>> tree_diameter(const std::vector<std::vector<int>>\
    \ &g_unweighted){\n\tint n = (int)g_unweighted.size();\n\tstd::vector<std::vector<std::pair<int,\
    \ int>>> g(n);\n\n\tfor(int u = 0;u < n;u++){\n\t\tfor(int v : g_unweighted[u]){\n\
    \t\t\tg[u].emplace_back(v, 1);\n\t\t\tg[v].emplace_back(u, 1);\n\t\t}\n\t}\n\t\
    return tree_diameter(g);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/tree_diameter.hpp
  requiredBy: []
  timestamp: '2025-07-01 01:47:02+09:00'
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
