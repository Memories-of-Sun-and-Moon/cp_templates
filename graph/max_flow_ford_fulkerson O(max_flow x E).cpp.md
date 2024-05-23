---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A
  bundledCode: "#line 1 \"graph/max_flow_ford_fulkerson O(max_flow x E).cpp\"\n# define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A\"\
    \n# include <bits/stdc++.h>\nusing namespace std;\n\n//Ford-Fulkerson algorithm\
    \ O(max_flow|E|)\ntemplate<typename T>struct max_flow {\n\n    struct edge{\n\
    \        int to;\n        T cap;\n        T rev;\n    };\n\n    int n;\n    vector<vector<edge>>\
    \ G;\n    vector<bool> used;\n\n    max_flow(int _v) : n(_v) {\n        G.resize(n);\n\
    \        used.resize(n, false);\n    }\n\n    void add_edge(int from, int to,\
    \ T cap){\n        G[from].push_back((edge){to, cap, (T)G[to].size()});\n    \
    \    G[to].push_back((edge){from, 0, (T)(G[from].size() - 1)});\n    }\n\n   \
    \ T dfs(int v, int t, T f){\n        if(v == t)return f;\n        used[v] = true;\n\
    \        for(int i = 0;i < (int)G[v].size();i++){\n            edge &e = G[v][i];\n\
    \            if(!used[e.to] && e.cap > 0){\n                T d = dfs(e.to, t,\
    \ min(f, e.cap));\n                if(d > 0){\n                    e.cap -= d;\n\
    \                    G[e.to][e.rev].cap += d;\n                    return d;\n\
    \                }\n            }\n        }\n        return 0;\n    }\n\n   \
    \ T calc(int s, int t){\n        T flow = 0;\n        for(;;){\n            for(int\
    \ i = 0;i < n;i++)used[i] = false;\n            int f = dfs(s, t, inf<T>());\n\
    \            if(f == 0)return flow;\n            flow += f;\n        }\n    }\n\
    };\n\nint v, e;\n\nint main(){\n    cin >> v >> e;\n    max_flow<int> mf(v);\n\
    \n    for(int i = 0;i < e;i++){\n        int a, b, c;\n        cin >> a >> b >>\
    \ c;\n        mf.add_edge(a, b, c);\n    }\n    cout << mf.calc(0, v - 1) << endl;\n\
    }\n"
  code: "# define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A\"\
    \n# include <bits/stdc++.h>\nusing namespace std;\n\n//Ford-Fulkerson algorithm\
    \ O(max_flow|E|)\ntemplate<typename T>struct max_flow {\n\n    struct edge{\n\
    \        int to;\n        T cap;\n        T rev;\n    };\n\n    int n;\n    vector<vector<edge>>\
    \ G;\n    vector<bool> used;\n\n    max_flow(int _v) : n(_v) {\n        G.resize(n);\n\
    \        used.resize(n, false);\n    }\n\n    void add_edge(int from, int to,\
    \ T cap){\n        G[from].push_back((edge){to, cap, (T)G[to].size()});\n    \
    \    G[to].push_back((edge){from, 0, (T)(G[from].size() - 1)});\n    }\n\n   \
    \ T dfs(int v, int t, T f){\n        if(v == t)return f;\n        used[v] = true;\n\
    \        for(int i = 0;i < (int)G[v].size();i++){\n            edge &e = G[v][i];\n\
    \            if(!used[e.to] && e.cap > 0){\n                T d = dfs(e.to, t,\
    \ min(f, e.cap));\n                if(d > 0){\n                    e.cap -= d;\n\
    \                    G[e.to][e.rev].cap += d;\n                    return d;\n\
    \                }\n            }\n        }\n        return 0;\n    }\n\n   \
    \ T calc(int s, int t){\n        T flow = 0;\n        for(;;){\n            for(int\
    \ i = 0;i < n;i++)used[i] = false;\n            int f = dfs(s, t, inf<T>());\n\
    \            if(f == 0)return flow;\n            flow += f;\n        }\n    }\n\
    };\n\nint v, e;\n\nint main(){\n    cin >> v >> e;\n    max_flow<int> mf(v);\n\
    \n    for(int i = 0;i < e;i++){\n        int a, b, c;\n        cin >> a >> b >>\
    \ c;\n        mf.add_edge(a, b, c);\n    }\n    cout << mf.calc(0, v - 1) << endl;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: graph/max_flow_ford_fulkerson O(max_flow x E).cpp
  requiredBy: []
  timestamp: '2024-05-23 22:55:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/max_flow_ford_fulkerson O(max_flow x E).cpp
layout: document
redirect_from:
- /library/graph/max_flow_ford_fulkerson O(max_flow x E).cpp
- /library/graph/max_flow_ford_fulkerson O(max_flow x E).cpp.html
title: graph/max_flow_ford_fulkerson O(max_flow x E).cpp
---
