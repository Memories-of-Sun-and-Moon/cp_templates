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
    \ {\n\n    struct edge{\n        int to;\n        T cap;\n        T rev;\n   \
    \ };\n    \n    int n;\n    vector<vector<edge>> G;\n    vector<int> level;\n\
    \    vector<int> iter;\n\n    dinic(int _v) : n(_v), G(n), level(n), iter(n) {}\n\
    \n    void add_edge(int from, int to, T cap){\n        G[from].push_back((edge){to,\
    \ cap, (T)G[to].size()});\n        G[to].push_back((edge){from, 0, (T)(G[from].size()\
    \ - 1)});\n    }\n\n    void bfs(int s){\n        for(int i = 0;i < n;i++)level[i]\
    \ = -1;\n        queue<int> que;\n        level[s] = 0;\n        que.push(s);\n\
    \        while(!que.empty()){\n            int v = que.front();\n            que.pop();\n\
    \            for(int i = 0;i < (int)G[v].size();i++){\n                edge &e\
    \ = G[v][i];\n                if(e.cap > 0 && level[e.to] < 0){\n            \
    \        level[e.to] = level[v] + 1;\n                    que.push(e.to);\n  \
    \              }\n            }\n        }\n    }\n\n    T dfs(int v, int t, T\
    \ f){\n        if(v == t)return f;\n        for(int &i = iter[v];i < (int)G[v].size();i++){\n\
    \            edge &e = G[v][i];\n            if(e.cap > 0 && level[v] < level[e.to]){\n\
    \                T d = dfs(e.to, t, min(f, e.cap));\n                if(d > 0){\n\
    \                    e.cap -= d;\n                    G[e.to][e.rev].cap += d;\n\
    \                    return d;\n                }\n            }\n        }\n\
    \        return 0;\n    }\n\n    T calc(int s, int t){\n        T flow = 0;\n\
    \        for(;;){\n            bfs(s);\n            if(level[t] < 0)return flow;\n\
    \            for(int i = 0;i < n;i++)iter[i] = 0;\n            int f;\n      \
    \      while((f = dfs(s, t, inf<T>())) > 0) {\n                flow += f;\n  \
    \          }\n        }\n    }\n};\n"
  code: "\ntemplate<typename T>\nstruct dinic {\n\n    struct edge{\n        int to;\n\
    \        T cap;\n        T rev;\n    };\n    \n    int n;\n    vector<vector<edge>>\
    \ G;\n    vector<int> level;\n    vector<int> iter;\n\n    dinic(int _v) : n(_v),\
    \ G(n), level(n), iter(n) {}\n\n    void add_edge(int from, int to, T cap){\n\
    \        G[from].push_back((edge){to, cap, (T)G[to].size()});\n        G[to].push_back((edge){from,\
    \ 0, (T)(G[from].size() - 1)});\n    }\n\n    void bfs(int s){\n        for(int\
    \ i = 0;i < n;i++)level[i] = -1;\n        queue<int> que;\n        level[s] =\
    \ 0;\n        que.push(s);\n        while(!que.empty()){\n            int v =\
    \ que.front();\n            que.pop();\n            for(int i = 0;i < (int)G[v].size();i++){\n\
    \                edge &e = G[v][i];\n                if(e.cap > 0 && level[e.to]\
    \ < 0){\n                    level[e.to] = level[v] + 1;\n                   \
    \ que.push(e.to);\n                }\n            }\n        }\n    }\n\n    T\
    \ dfs(int v, int t, T f){\n        if(v == t)return f;\n        for(int &i = iter[v];i\
    \ < (int)G[v].size();i++){\n            edge &e = G[v][i];\n            if(e.cap\
    \ > 0 && level[v] < level[e.to]){\n                T d = dfs(e.to, t, min(f, e.cap));\n\
    \                if(d > 0){\n                    e.cap -= d;\n               \
    \     G[e.to][e.rev].cap += d;\n                    return d;\n              \
    \  }\n            }\n        }\n        return 0;\n    }\n\n    T calc(int s,\
    \ int t){\n        T flow = 0;\n        for(;;){\n            bfs(s);\n      \
    \      if(level[t] < 0)return flow;\n            for(int i = 0;i < n;i++)iter[i]\
    \ = 0;\n            int f;\n            while((f = dfs(s, t, inf<T>())) > 0) {\n\
    \                flow += f;\n            }\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/dinic.hpp
  requiredBy: []
  timestamp: '2024-07-04 16:14:16+09:00'
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
- ``T calc(int a, int b)`` $a$ から $b$ への最大流を求める。頂点 $V$, 辺数 $E$ とすると、最悪計算量 $O(V^2E)$
