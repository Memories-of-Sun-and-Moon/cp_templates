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
  bundledCode: "#line 1 \"graph/warshall_floyd.hpp\"\n\ntemplate<typename T>\nstruct\
    \ warshall_floyd {\nprivate:\n\tint V;\npublic:\n\tvector<vector<T>> dist;\n\n\
    \twarshall_floyd(vector<vector<T>> &edge_cost, T infty=::numeric_limits<T>()/2)\
    \ : V(ssize(edge_cost)), dist(edge_cost){\n\t\tfor(int k = 0;k < V;k++){\n\t\t\
    \tfor(int i = 0;i < V;i++){\n\t\t\t\tif(dist[i][k] == infty)continue;\n\t\t\t\t\
    for(int j = 0;j < V;j++){\n\t\t\t\t\tif(dist[k][j] == infty)continue;\n\t\t\t\t\
    \tdist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);\n\t\t\t\t}\n\t\t\t}\n\
    \t\t}\n\t}\n\n\tvoid update(int s, int t, T cost){\n\t\tdist[s][t] = cost;\n\t\
    \tfor(int u = 0;u < V;u++){\n\t\t\tfor(int v = 0;v < V;v++){\n\t\t\t\tdist[u][v]\
    \ = min(dist[u][v], dist[u][s]+dist[s][t]+dist[t][v]);\n\t\t\t}\n\t\t}\n\t}\n\
    };\n\n"
  code: "\ntemplate<typename T>\nstruct warshall_floyd {\nprivate:\n\tint V;\npublic:\n\
    \tvector<vector<T>> dist;\n\n\twarshall_floyd(vector<vector<T>> &edge_cost, T\
    \ infty=::numeric_limits<T>()/2) : V(ssize(edge_cost)), dist(edge_cost){\n\t\t\
    for(int k = 0;k < V;k++){\n\t\t\tfor(int i = 0;i < V;i++){\n\t\t\t\tif(dist[i][k]\
    \ == infty)continue;\n\t\t\t\tfor(int j = 0;j < V;j++){\n\t\t\t\t\tif(dist[k][j]\
    \ == infty)continue;\n\t\t\t\t\tdist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\n\tvoid update(int s, int t, T cost){\n\t\tdist[s][t]\
    \ = cost;\n\t\tfor(int u = 0;u < V;u++){\n\t\t\tfor(int v = 0;v < V;v++){\n\t\t\
    \t\tdist[u][v] = min(dist[u][v], dist[u][s]+dist[s][t]+dist[t][v]);\n\t\t\t}\n\
    \t\t}\n\t}\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/warshall_floyd.hpp
  requiredBy: []
  timestamp: '2025-05-29 06:44:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/id/0526.test.cpp
  - verify/aoj/id/2005.test.cpp
documentation_of: graph/warshall_floyd.hpp
layout: document
redirect_from:
- /library/graph/warshall_floyd.hpp
- /library/graph/warshall_floyd.hpp.html
title: graph/warshall_floyd.hpp
---
