---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/grl/6_A___ford_fulkerson.test.cpp
    title: verify/aoj/grl/6_A___ford_fulkerson.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/ford_fulkerson.hpp\"\n\n#include<vector>\n#include<limits>\n\
    \ntemplate<typename T>\nstruct ford_fulkerson {\n\n\tstruct edge{\n\t\tint to;\n\
    \t\tT cap;\n\t\tT rev;\n\t};\n\n\tint n;\n\tstd::vector<std::vector<edge>> G;\n\
    \tstd::vector<bool> used;\n\n\tford_fulkerson(int _v) : n(_v), G(n), used(n) {}\n\
    \n\tvoid add_edge(int from, int to, T cap){\n\t\tG[from].push_back((edge){to,\
    \ cap, (T)G[to].size()});\n\t\tG[to].push_back((edge){from, 0, (T)(G[from].size()\
    \ - 1)});\n\t}\n\n\tT dfs(int v, int t, T f){\n\t\tif(v == t)return f;\n\t\tused[v]\
    \ = true;\n\t\tfor(int i = 0;i < (int)G[v].size();i++){\n\t\t\tedge &e = G[v][i];\n\
    \t\t\tif(!used[e.to] && e.cap > 0){\n\t\t\t\tT d = dfs(e.to, t, min(f, e.cap));\n\
    \t\t\t\tif(d > 0){\n\t\t\t\t\te.cap -= d;\n\t\t\t\t\tG[e.to][e.rev].cap += d;\n\
    \t\t\t\t\treturn d;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\t}\n\n\tT calc(int\
    \ s, int t){\n\t\tT flow = 0;\n\t\tfor(;;){\n\t\t\tfor(int i = 0;i < n;i++)used[i]\
    \ = false;\n\t\t\tT f = dfs(s, t, std::numeric_limits<T>::max());\n\t\t\tif(f\
    \ == 0)return flow;\n\t\t\tflow += f;\n\t\t}\n\t}\n};\n"
  code: "#pragma once\n\n#include<vector>\n#include<limits>\n\ntemplate<typename T>\n\
    struct ford_fulkerson {\n\n\tstruct edge{\n\t\tint to;\n\t\tT cap;\n\t\tT rev;\n\
    \t};\n\n\tint n;\n\tstd::vector<std::vector<edge>> G;\n\tstd::vector<bool> used;\n\
    \n\tford_fulkerson(int _v) : n(_v), G(n), used(n) {}\n\n\tvoid add_edge(int from,\
    \ int to, T cap){\n\t\tG[from].push_back((edge){to, cap, (T)G[to].size()});\n\t\
    \tG[to].push_back((edge){from, 0, (T)(G[from].size() - 1)});\n\t}\n\n\tT dfs(int\
    \ v, int t, T f){\n\t\tif(v == t)return f;\n\t\tused[v] = true;\n\t\tfor(int i\
    \ = 0;i < (int)G[v].size();i++){\n\t\t\tedge &e = G[v][i];\n\t\t\tif(!used[e.to]\
    \ && e.cap > 0){\n\t\t\t\tT d = dfs(e.to, t, min(f, e.cap));\n\t\t\t\tif(d > 0){\n\
    \t\t\t\t\te.cap -= d;\n\t\t\t\t\tG[e.to][e.rev].cap += d;\n\t\t\t\t\treturn d;\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\t}\n\n\tT calc(int s, int t){\n\t\t\
    T flow = 0;\n\t\tfor(;;){\n\t\t\tfor(int i = 0;i < n;i++)used[i] = false;\n\t\t\
    \tT f = dfs(s, t, std::numeric_limits<T>::max());\n\t\t\tif(f == 0)return flow;\n\
    \t\t\tflow += f;\n\t\t}\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/ford_fulkerson.hpp
  requiredBy: []
  timestamp: '2025-07-01 03:22:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/grl/6_A___ford_fulkerson.test.cpp
documentation_of: graph/ford_fulkerson.hpp
layout: document
title: "\u6700\u5927\u6D41(Ford-Fulkerson)"
---

# 最大流(Ford-Fulkerson)

## 使い方

- ``ford_fulkerson<T>(int V)`` : 頂点数 $V$ の最大流グラフのコンストラクタ
- ``void add edge(int a, int b, T c)`` : $a$ から $b$ に容量 $c$ の辺を張る
- ``T calc(int a, int b)`` $a$ から $b$ への最大流を求める。辺中を流れる最大流量を $f$, 辺数 $E$ とすると、最悪計算量 $O(fE)$
