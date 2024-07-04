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
  bundledCode: "#line 1 \"graph/ford_fulkerson.hpp\"\n\ntemplate<typename T>\nstruct\
    \ ford_fulkerson {\n\n    struct edge{\n        int to;\n        T cap;\n    \
    \    T rev;\n    };\n\n    int n;\n    vector<vector<edge>> G;\n    vector<bool>\
    \ used;\n\n    ford_fulkerson(int _v) : n(_v), G(n), used(n) {}\n\n    void add_edge(int\
    \ from, int to, T cap){\n        G[from].push_back((edge){to, cap, (T)G[to].size()});\n\
    \        G[to].push_back((edge){from, 0, (T)(G[from].size() - 1)});\n    }\n\n\
    \    T dfs(int v, int t, T f){\n        if(v == t)return f;\n        used[v] =\
    \ true;\n        for(int i = 0;i < (int)G[v].size();i++){\n            edge &e\
    \ = G[v][i];\n            if(!used[e.to] && e.cap > 0){\n                T d =\
    \ dfs(e.to, t, min(f, e.cap));\n                if(d > 0){\n                 \
    \   e.cap -= d;\n                    G[e.to][e.rev].cap += d;\n              \
    \      return d;\n                }\n            }\n        }\n        return\
    \ 0;\n    }\n\n    T calc(int s, int t){\n        T flow = 0;\n        for(;;){\n\
    \            for(int i = 0;i < n;i++)used[i] = false;\n            int f = dfs(s,\
    \ t, inf<T>());\n            if(f == 0)return flow;\n            flow += f;\n\
    \        }\n    }\n};\n"
  code: "\ntemplate<typename T>\nstruct ford_fulkerson {\n\n    struct edge{\n   \
    \     int to;\n        T cap;\n        T rev;\n    };\n\n    int n;\n    vector<vector<edge>>\
    \ G;\n    vector<bool> used;\n\n    ford_fulkerson(int _v) : n(_v), G(n), used(n)\
    \ {}\n\n    void add_edge(int from, int to, T cap){\n        G[from].push_back((edge){to,\
    \ cap, (T)G[to].size()});\n        G[to].push_back((edge){from, 0, (T)(G[from].size()\
    \ - 1)});\n    }\n\n    T dfs(int v, int t, T f){\n        if(v == t)return f;\n\
    \        used[v] = true;\n        for(int i = 0;i < (int)G[v].size();i++){\n \
    \           edge &e = G[v][i];\n            if(!used[e.to] && e.cap > 0){\n  \
    \              T d = dfs(e.to, t, min(f, e.cap));\n                if(d > 0){\n\
    \                    e.cap -= d;\n                    G[e.to][e.rev].cap += d;\n\
    \                    return d;\n                }\n            }\n        }\n\
    \        return 0;\n    }\n\n    T calc(int s, int t){\n        T flow = 0;\n\
    \        for(;;){\n            for(int i = 0;i < n;i++)used[i] = false;\n    \
    \        int f = dfs(s, t, inf<T>());\n            if(f == 0)return flow;\n  \
    \          flow += f;\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/ford_fulkerson.hpp
  requiredBy: []
  timestamp: '2024-07-04 16:14:16+09:00'
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
