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
    \ {\n\n\tstruct edge{\n\t\tint to;\n\t\tT cap;\n\t\tT rev;\n\t};\n\t\t\n\tint\
    \ n;\n\tvector<vector<edge>> G;\n\tvector<int> level;\n\tvector<int> iter;\n\n\
    \tdinic(int _v) : n(_v), G(n), level(n), iter(n) {}\n\n\tvoid add_edge(int from,\
    \ int to, T cap){\n\t\tG[from].push_back((edge){to, cap, (T)G[to].size()});\n\t\
    \tG[to].push_back((edge){from, 0, (T)(G[from].size() - 1)});\n\t}\n\n\tvoid bfs(int\
    \ s){\n\t\tfor(int i = 0;i < n;i++)level[i] = -1;\n\t\tqueue<int> que;\n\t\tlevel[s]\
    \ = 0;\n\t\tque.push(s);\n\t\twhile(!que.empty()){\n\t\t\tint v = que.front();\n\
    \t\t\tque.pop();\n\t\t\tfor(int i = 0;i < (int)G[v].size();i++){\n\t\t\t\tedge\
    \ &e = G[v][i];\n\t\t\t\tif(e.cap > 0 && level[e.to] < 0){\n\t\t\t\t\tlevel[e.to]\
    \ = level[v] + 1;\n\t\t\t\t\tque.push(e.to);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\
    \n\tT dfs(int v, int t, T f){\n\t\tif(v == t)return f;\n\t\tfor(int &i = iter[v];i\
    \ < (int)G[v].size();i++){\n\t\t\tedge &e = G[v][i];\n\t\t\tif(e.cap > 0 && level[v]\
    \ < level[e.to]){\n\t\t\t\tT d = dfs(e.to, t, min(f, e.cap));\n\t\t\t\tif(d >\
    \ 0){\n\t\t\t\t\te.cap -= d;\n\t\t\t\t\tG[e.to][e.rev].cap += d;\n\t\t\t\t\treturn\
    \ d;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\t}\n\n\tT calc(int s, int t){\n\
    \t\tT flow = 0;\n\t\tfor(;;){\n\t\t\tbfs(s);\n\t\t\tif(level[t] < 0)return flow;\n\
    \t\t\tfor(int i = 0;i < n;i++)iter[i] = 0;\n\t\t\tint f;\n\t\t\twhile((f = dfs(s,\
    \ t, inf<T>())) > 0) {\n\t\t\t\tflow += f;\n\t\t\t}\n\t\t}\n\t}\n};\n"
  code: "\ntemplate<typename T>\nstruct dinic {\n\n\tstruct edge{\n\t\tint to;\n\t\
    \tT cap;\n\t\tT rev;\n\t};\n\t\t\n\tint n;\n\tvector<vector<edge>> G;\n\tvector<int>\
    \ level;\n\tvector<int> iter;\n\n\tdinic(int _v) : n(_v), G(n), level(n), iter(n)\
    \ {}\n\n\tvoid add_edge(int from, int to, T cap){\n\t\tG[from].push_back((edge){to,\
    \ cap, (T)G[to].size()});\n\t\tG[to].push_back((edge){from, 0, (T)(G[from].size()\
    \ - 1)});\n\t}\n\n\tvoid bfs(int s){\n\t\tfor(int i = 0;i < n;i++)level[i] = -1;\n\
    \t\tqueue<int> que;\n\t\tlevel[s] = 0;\n\t\tque.push(s);\n\t\twhile(!que.empty()){\n\
    \t\t\tint v = que.front();\n\t\t\tque.pop();\n\t\t\tfor(int i = 0;i < (int)G[v].size();i++){\n\
    \t\t\t\tedge &e = G[v][i];\n\t\t\t\tif(e.cap > 0 && level[e.to] < 0){\n\t\t\t\t\
    \tlevel[e.to] = level[v] + 1;\n\t\t\t\t\tque.push(e.to);\n\t\t\t\t}\n\t\t\t}\n\
    \t\t}\n\t}\n\n\tT dfs(int v, int t, T f){\n\t\tif(v == t)return f;\n\t\tfor(int\
    \ &i = iter[v];i < (int)G[v].size();i++){\n\t\t\tedge &e = G[v][i];\n\t\t\tif(e.cap\
    \ > 0 && level[v] < level[e.to]){\n\t\t\t\tT d = dfs(e.to, t, min(f, e.cap));\n\
    \t\t\t\tif(d > 0){\n\t\t\t\t\te.cap -= d;\n\t\t\t\t\tG[e.to][e.rev].cap += d;\n\
    \t\t\t\t\treturn d;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\t}\n\n\tT calc(int\
    \ s, int t){\n\t\tT flow = 0;\n\t\tfor(;;){\n\t\t\tbfs(s);\n\t\t\tif(level[t]\
    \ < 0)return flow;\n\t\t\tfor(int i = 0;i < n;i++)iter[i] = 0;\n\t\t\tint f;\n\
    \t\t\twhile((f = dfs(s, t, inf<T>())) > 0) {\n\t\t\t\tflow += f;\n\t\t\t}\n\t\t\
    }\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/dinic.hpp
  requiredBy: []
  timestamp: '2024-10-08 21:36:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/grl/6_A___dinic.test.cpp
documentation_of: graph/dinic.hpp
layout: document
title: "\u6700\u5927\u6D41(Dinic)"
---

# 最大流(Dinic)

## 使い方

- ``dinic<T>(int V)`` : 頂点数 $V$ の最大流グラフのコンストラクタ
- ``void add edge(int a, int b, T c)`` : $a$ から $b$ に容量 $c$ の辺を張る
- ``T calc(int a, int b)`` $a$ から $b$ への最大流を求める。頂点 $V$, 辺数 $E$ とすると、最悪計算量 $O(E \sqrt{V})$
