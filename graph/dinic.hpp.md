---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/grl/6_A___dinic.test.cpp
    title: verify/aoj/grl/6_A___dinic.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/dinic.hpp\"\n\ntemplate<typename T>\nstruct dinic\
    \ {\n\n\tstruct edge{\n\t\tint to;\n\t\tT cap;\n\t\tT rev;\n\t\tT init_cap;\n\t\
    };\n\t\t\n\tint n;\n\tvector<vector<edge>> G;\n\tvector<int> level;\n\tvector<int>\
    \ iter;\n\n\tvector<int> from_idx, to_idx;\n\tint edge_idx;\n\n\tdinic(int _v)\
    \ : n(_v), G(n), level(n), iter(n), edge_idx(0) {}\n\n\tint add_edge(int from,\
    \ int to, T cap){\n\t\tG[from].push_back((edge){to, cap, (T)G[to].size(), cap});\n\
    \t\tG[to].push_back((edge){from, 0, (T)(G[from].size() - 1), 0});\n\t\tfrom_idx.emplace_back(from);\n\
    \t\tto_idx.emplace_back((int)G[from].size()-1);\n\t\t\n\t\treturn edge_idx++;\n\
    \t}\n\n\tvoid bfs(int s){\n\t\tfor(int i = 0;i < n;i++)level[i] = -1;\n\t\tqueue<int>\
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
    \t\twhile((f = dfs(s, t, inf<T>())) > 0) {\n\t\t\t\tflow += f;\n\t\t\t}\n\t\t\
    }\n\t}\n\n\tT get_flow(int idx){\n\t\treturn G[from_idx[idx]][to_idx[idx]].init_cap\
    \ - G[from_idx[idx]][to_idx[idx]].cap;\n\t}\n};\n"
  code: "\ntemplate<typename T>\nstruct dinic {\n\n\tstruct edge{\n\t\tint to;\n\t\
    \tT cap;\n\t\tT rev;\n\t\tT init_cap;\n\t};\n\t\t\n\tint n;\n\tvector<vector<edge>>\
    \ G;\n\tvector<int> level;\n\tvector<int> iter;\n\n\tvector<int> from_idx, to_idx;\n\
    \tint edge_idx;\n\n\tdinic(int _v) : n(_v), G(n), level(n), iter(n), edge_idx(0)\
    \ {}\n\n\tint add_edge(int from, int to, T cap){\n\t\tG[from].push_back((edge){to,\
    \ cap, (T)G[to].size(), cap});\n\t\tG[to].push_back((edge){from, 0, (T)(G[from].size()\
    \ - 1), 0});\n\t\tfrom_idx.emplace_back(from);\n\t\tto_idx.emplace_back((int)G[from].size()-1);\n\
    \t\t\n\t\treturn edge_idx++;\n\t}\n\n\tvoid bfs(int s){\n\t\tfor(int i = 0;i <\
    \ n;i++)level[i] = -1;\n\t\tqueue<int> que;\n\t\tlevel[s] = 0;\n\t\tque.push(s);\n\
    \t\twhile(!que.empty()){\n\t\t\tint v = que.front();\n\t\t\tque.pop();\n\t\t\t\
    for(int i = 0;i < (int)G[v].size();i++){\n\t\t\t\tedge &e = G[v][i];\n\t\t\t\t\
    if(e.cap > 0 && level[e.to] < 0){\n\t\t\t\t\tlevel[e.to] = level[v] + 1;\n\t\t\
    \t\t\tque.push(e.to);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\n\tT dfs(int v, int t,\
    \ T f){\n\t\tif(v == t)return f;\n\t\tfor(int &i = iter[v];i < (int)G[v].size();i++){\n\
    \t\t\tedge &e = G[v][i];\n\t\t\tif(e.cap > 0 && level[v] < level[e.to]){\n\t\t\
    \t\tT d = dfs(e.to, t, min(f, e.cap));\n\t\t\t\tif(d > 0){\n\t\t\t\t\te.cap -=\
    \ d;\n\t\t\t\t\tG[e.to][e.rev].cap += d;\n\t\t\t\t\treturn d;\n\t\t\t\t}\n\t\t\
    \t}\n\t\t}\n\t\treturn 0;\n\t}\n\n\tT calc(int s, int t){\n\t\tT flow = 0;\n\t\
    \tfor(;;){\n\t\t\tbfs(s);\n\t\t\tif(level[t] < 0)return flow;\n\t\t\tfor(int i\
    \ = 0;i < n;i++)iter[i] = 0;\n\t\t\tT f;\n\t\t\twhile((f = dfs(s, t, inf<T>()))\
    \ > 0) {\n\t\t\t\tflow += f;\n\t\t\t}\n\t\t}\n\t}\n\n\tT get_flow(int idx){\n\t\
    \treturn G[from_idx[idx]][to_idx[idx]].init_cap - G[from_idx[idx]][to_idx[idx]].cap;\n\
    \t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/dinic.hpp
  requiredBy: []
  timestamp: '2025-03-04 07:06:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/grl/6_A___dinic.test.cpp
documentation_of: graph/dinic.hpp
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
