---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/aoj/grl/6_B.test.cpp
    title: verify/aoj/grl/6_B.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/primal_dual.hpp\"\n\ntemplate<typename T>\nstruct\
    \ primal_dual{\n\tstruct edge {\n\t\tint to;\n\t\tT cap, cost, rev;\n\t\tT max_cap;\n\
    \t};\n\tint V;\n\tT infty;\n\tvector<vector<edge>> G;\n\tvector<T> h, dist;\n\t\
    vector<int> prevv, preve;\n\tvector<bool> used_edge;\n\n\tprimal_dual(int _V)\
    \ : V(_V), infty(numeric_limits<T>::max()/2) {\n\t\tG.resize(V);\n\t\th.resize(V);\n\
    \t\tdist.resize(V);\n\t\tprevv.resize(V);\n\t\tpreve.resize(V);\n\t\tused_edge.resize(V);\n\
    \t}\n\n\tvoid add_edge(int from, int to, T cap, T cost){\n\t\tG[from].push_back((edge){to,\
    \ cap, cost, (int)G[to].size(), cap});\n\t\tG[to].push_back((edge){from, 0, -cost,\
    \ (int)G[from].size()-1, 0});\n\t\tused_edge[from] = true;\n\t\tused_edge[to]\
    \ = true;\n\t}\n\n\tpair<bool, T> min_cost_flow(int s, int t, T f){\n\t\tT res\
    \ = 0;\n\t\twhile(f > 0){\n\t\t\tpriority_queue<pair<T, int>, vector<pair<T, int>>,\
    \ greater<pair<T, int>>> que;\n\t\t\tdist.assign(V, infty);\n\t\t\tdist[s] = 0;\n\
    \t\t\tque.push({0, s});\n\t\t\twhile(not que.empty()){\n\t\t\t\tauto [cst, v]\
    \ = que.top();\n\t\t\t\tque.pop();\n\t\t\t\tif(dist[v] < cst)continue;\n\t\t\t\
    \tfor(int i = 0;i < (int)G[v].size();i++){\n\t\t\t\t\tauto &e = G[v][i];\n\t\t\
    \t\t\tif(e.cap > 0 && dist[e.to] > dist[v]+e.cost+h[v]-h[e.to]){\n\t\t\t\t\t\t\
    dist[e.to] = dist[v]+e.cost+h[v]-h[e.to];\n\t\t\t\t\t\tprevv[e.to] = v;\n\t\t\t\
    \t\t\tpreve[e.to] = i;\n\t\t\t\t\t\tque.push({dist[e.to], e.to});\n\t\t\t\t\t\
    }\n\t\t\t\t}\n\t\t\t}\n\t\t\tif(dist[t] == infty){\n\t\t\t\treturn make_pair(false,\
    \ res);\n\t\t\t}\n\t\t\tfor(int v = 0;v < V;v++){\n\t\t\t\tif(not used_edge[v])continue;\n\
    \t\t\t\th[v] += dist[v];\n\t\t\t}\n\t\t\tT d = f;\n\t\t\tfor(int v = t;v != s;v\
    \ = prevv[v]){\n\t\t\t\td = min(d, G[prevv[v]][preve[v]].cap);\n\t\t\t}\n\t\t\t\
    f -= d;\n\t\t\tres += d*h[t];\n\t\t\tfor(int v = t;v != s;v = prevv[v]){\n\t\t\
    \t\tedge &e = G[prevv[v]][preve[v]];\n\t\t\t\te.cap -= d;\n\t\t\t\tG[v][e.rev].cap\
    \ += d;\n\t\t\t}\n\t\t}\n\t\treturn make_pair(true, res);\n\t}\n};\n"
  code: "\ntemplate<typename T>\nstruct primal_dual{\n\tstruct edge {\n\t\tint to;\n\
    \t\tT cap, cost, rev;\n\t\tT max_cap;\n\t};\n\tint V;\n\tT infty;\n\tvector<vector<edge>>\
    \ G;\n\tvector<T> h, dist;\n\tvector<int> prevv, preve;\n\tvector<bool> used_edge;\n\
    \n\tprimal_dual(int _V) : V(_V), infty(numeric_limits<T>::max()/2) {\n\t\tG.resize(V);\n\
    \t\th.resize(V);\n\t\tdist.resize(V);\n\t\tprevv.resize(V);\n\t\tpreve.resize(V);\n\
    \t\tused_edge.resize(V);\n\t}\n\n\tvoid add_edge(int from, int to, T cap, T cost){\n\
    \t\tG[from].push_back((edge){to, cap, cost, (int)G[to].size(), cap});\n\t\tG[to].push_back((edge){from,\
    \ 0, -cost, (int)G[from].size()-1, 0});\n\t\tused_edge[from] = true;\n\t\tused_edge[to]\
    \ = true;\n\t}\n\n\tpair<bool, T> min_cost_flow(int s, int t, T f){\n\t\tT res\
    \ = 0;\n\t\twhile(f > 0){\n\t\t\tpriority_queue<pair<T, int>, vector<pair<T, int>>,\
    \ greater<pair<T, int>>> que;\n\t\t\tdist.assign(V, infty);\n\t\t\tdist[s] = 0;\n\
    \t\t\tque.push({0, s});\n\t\t\twhile(not que.empty()){\n\t\t\t\tauto [cst, v]\
    \ = que.top();\n\t\t\t\tque.pop();\n\t\t\t\tif(dist[v] < cst)continue;\n\t\t\t\
    \tfor(int i = 0;i < (int)G[v].size();i++){\n\t\t\t\t\tauto &e = G[v][i];\n\t\t\
    \t\t\tif(e.cap > 0 && dist[e.to] > dist[v]+e.cost+h[v]-h[e.to]){\n\t\t\t\t\t\t\
    dist[e.to] = dist[v]+e.cost+h[v]-h[e.to];\n\t\t\t\t\t\tprevv[e.to] = v;\n\t\t\t\
    \t\t\tpreve[e.to] = i;\n\t\t\t\t\t\tque.push({dist[e.to], e.to});\n\t\t\t\t\t\
    }\n\t\t\t\t}\n\t\t\t}\n\t\t\tif(dist[t] == infty){\n\t\t\t\treturn make_pair(false,\
    \ res);\n\t\t\t}\n\t\t\tfor(int v = 0;v < V;v++){\n\t\t\t\tif(not used_edge[v])continue;\n\
    \t\t\t\th[v] += dist[v];\n\t\t\t}\n\t\t\tT d = f;\n\t\t\tfor(int v = t;v != s;v\
    \ = prevv[v]){\n\t\t\t\td = min(d, G[prevv[v]][preve[v]].cap);\n\t\t\t}\n\t\t\t\
    f -= d;\n\t\t\tres += d*h[t];\n\t\t\tfor(int v = t;v != s;v = prevv[v]){\n\t\t\
    \t\tedge &e = G[prevv[v]][preve[v]];\n\t\t\t\te.cap -= d;\n\t\t\t\tG[v][e.rev].cap\
    \ += d;\n\t\t\t}\n\t\t}\n\t\treturn make_pair(true, res);\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/primal_dual.hpp
  requiredBy: []
  timestamp: '2025-02-28 03:58:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/aoj/grl/6_B.test.cpp
documentation_of: graph/primal_dual.hpp
layout: document
title: "\u6700\u5C0F\u8CBB\u7528\u6D41\uFF08primal-dual\u6CD5\uFF09"
---

# 最小費用流

最小費用流を求める。負の辺を張ることはできない。

## 使い方

- ``primal_dual<T>(int V)`` : コンストラクタ。頂点数 $V$ の最小費用流の構築の準備を行う。
- ``add_edge(int from, int to, T cap, T cost)`` : $from$ から $to$ へ、容量 $cap$ で $1$ 流量当たりのコストが $cost$ の辺を張る $O(1)$
- ``pair<bool, T> min_cost_flow(int s, int t, T f)`` : $s$ から $t$ へ、流量 $f$ を流せるだけ流したときの最小費用流を求める。``true`` が返ったときは、$f$ 流すことができたことを示す。 **最悪計算量** $O(fV^2)$
