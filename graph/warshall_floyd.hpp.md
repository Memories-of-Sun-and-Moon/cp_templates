---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/id/0526.test.cpp
    title: verify/aoj/id/0526.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj/id/2005.test.cpp
    title: verify/aoj/id/2005.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/warshall_floyd.hpp\"\n\n#include<numeric>\n#include<vector>\n\
    \ntemplate<typename T>\nstruct warshall_floyd {\nprivate:\n\tint V;\npublic:\n\
    \tstd::vector<std::vector<T>> dist;\n\n\twarshall_floyd(std::vector<std::vector<T>>\
    \ &edge_cost, T infty=std::numeric_limits<T>::max()/2) : V(ssize(edge_cost)),\
    \ dist(edge_cost){\n\t\tfor(int k = 0;k < V;k++){\n\t\t\tfor(int i = 0;i < V;i++){\n\
    \t\t\t\tif(dist[i][k] == infty)continue;\n\t\t\t\tfor(int j = 0;j < V;j++){\n\t\
    \t\t\t\tif(dist[k][j] == infty)continue;\n\t\t\t\t\tdist[i][j] = min(dist[i][j],\
    \ dist[i][k] + dist[k][j]);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\n\tvoid update(int\
    \ s, int t, T cost){\n\t\tdist[s][t] = cost;\n\t\tfor(int u = 0;u < V;u++){\n\t\
    \t\tfor(int v = 0;v < V;v++){\n\t\t\t\tdist[u][v] = min(dist[u][v], dist[u][s]+dist[s][t]+dist[t][v]);\n\
    \t\t\t}\n\t\t}\n\t}\n};\n\n"
  code: "\n#include<numeric>\n#include<vector>\n\ntemplate<typename T>\nstruct warshall_floyd\
    \ {\nprivate:\n\tint V;\npublic:\n\tstd::vector<std::vector<T>> dist;\n\n\twarshall_floyd(std::vector<std::vector<T>>\
    \ &edge_cost, T infty=std::numeric_limits<T>::max()/2) : V(ssize(edge_cost)),\
    \ dist(edge_cost){\n\t\tfor(int k = 0;k < V;k++){\n\t\t\tfor(int i = 0;i < V;i++){\n\
    \t\t\t\tif(dist[i][k] == infty)continue;\n\t\t\t\tfor(int j = 0;j < V;j++){\n\t\
    \t\t\t\tif(dist[k][j] == infty)continue;\n\t\t\t\t\tdist[i][j] = min(dist[i][j],\
    \ dist[i][k] + dist[k][j]);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\n\tvoid update(int\
    \ s, int t, T cost){\n\t\tdist[s][t] = cost;\n\t\tfor(int u = 0;u < V;u++){\n\t\
    \t\tfor(int v = 0;v < V;v++){\n\t\t\t\tdist[u][v] = min(dist[u][v], dist[u][s]+dist[s][t]+dist[t][v]);\n\
    \t\t\t}\n\t\t}\n\t}\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/warshall_floyd.hpp
  requiredBy: []
  timestamp: '2025-07-01 01:47:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/id/2005.test.cpp
  - verify/aoj/id/0526.test.cpp
documentation_of: graph/warshall_floyd.hpp
layout: document
title: "\u5168\u9802\u70B9\u9593\u6700\u77ED\u8DDD\u96E2 O(V^3) \u53CA\u3073\u66F4\
  \u65B0\u3092 O(V^2) \u3067\u884C\u3046\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0 (\u30EF\
  \u30FC\u30B7\u30E3\u30EB\u30D5\u30ED\u30A4\u30C9\u6CD5)"
---

# 全頂点間最短距離 O(V^3) 及び更新を O(V^2) で行うアルゴリズム (ワーシャルフロイド法)

## 使い方

- ``warshall_floyd(vector<vector<T>> &edge_cost, T infty=::numeric_limits<T>()/2)`` : コンストラクタ。距離行列を用意する。
  - 全頂点間最短距離を格納した行列 ``dist`` が $O(V^3)$ で求まる。
  - ただし、 ``edge_cost[i][i] = 0``, 結ばれていない頂点間は $\text{infty}$ を格納すること($2 \times \text{infty} < \text(型 T の最大値)$ である必要がある)
- ``void update(int s, int t, T, cost)`` : ``edge_cost[s][t]`` を ``cost`` に更新する。 $O(V^2)$
