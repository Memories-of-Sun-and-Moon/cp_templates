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
  bundledCode: "#line 1 \"graph/max_flow_dinic O(E V^2).cpp\"\n# define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A\"\n# include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n//dinic algorithm O(|E||v|^2)\u3088\
    \u308A\u3082\u975E\u5E38\u306B\u9AD8\u901F\u306B\u52D5\u4F5C \ntemplate<typename\
    \ T>struct max_flow {\n\n    struct edge{\n        int to;\n        T cap;\n \
    \       T rev;\n    };\n    \n    int n;\n    vector<vector<edge>> G;\n    vector<int>\
    \ level; // s\u304B\u3089\u306E\u8DDD\u96E2\n    vector<int> iter; // \u3069\u3053\
    \u307E\u3067\u8ABF\u3079\u7D42\u308F\u3063\u305F\u304B\n\n    max_flow(int _v)\
    \ : n(_v) {\n        G.resize(n);\n        level.resize(n);\n        iter.resize(n);\n\
    \    }\n\n    void add_edge(int from, int to, T cap){\n        G[from].push_back((edge){to,\
    \ cap, (T)G[to].size()});\n        G[to].push_back((edge){from, 0, (T)(G[from].size()\
    \ - 1)});\n    }\n\n    // s \u7A7A\u306E\u6700\u77ED\u8DDD\u96E2\u3092\u8A08\u7B97\
    \n    void bfs(int s){\n        for(int i = 0;i < n;i++)level[i] = -1;\n     \
    \   queue<int> que;\n        level[s] = 0;\n        que.push(s);\n        while(!que.empty()){\n\
    \            int v = que.front();\n            que.pop();\n            for(int\
    \ i = 0;i < (int)G[v].size();i++){\n                edge &e = G[v][i];\n     \
    \           if(e.cap > 0 && level[e.to] < 0){\n                    level[e.to]\
    \ = level[v] + 1;\n                    que.push(e.to);\n                }\n  \
    \          }\n        }\n    }\n\n    //\u5897\u52A0\u30D1\u30B9\u3092DFS\u3067\
    \u63A2\u3059\n    T dfs(int v, int t, T f){\n        if(v == t)return f;\n   \
    \     for(int &i = iter[v];i < (int)G[v].size();i++){\n            edge &e = G[v][i];\n\
    \            if(e.cap > 0 && level[v] < level[e.to]){\n                T d = dfs(e.to,\
    \ t, min(f, e.cap));\n                if(d > 0){\n                    e.cap -=\
    \ d;\n                    G[e.to][e.rev].cap += d;\n                    return\
    \ d;\n                }\n            }\n        }\n        return 0;\n    }\n\n\
    \    T calc(int s, int t){\n        T flow = 0;\n        for(;;){\n          \
    \  bfs(s);\n            if(level[t] < 0)return flow;\n            for(int i =\
    \ 0;i < n;i++)iter[i] = 0;\n            int f;\n            while((f = dfs(s,\
    \ t, inf<T>())) > 0) {\n                flow += f;\n            }\n        }\n\
    \    }\n};\n\nint v, e;\n\nint main(){\n    cin >> v >> e;\n    max_flow<int>\
    \ mf(v);\n\n    for(int i = 0;i < e;i++){\n        int a, b, c;\n        cin >>\
    \ a >> b >> c;\n        mf.add_edge(a, b, c);\n    }\n    cout << mf.calc(0, v\
    \ - 1) << endl;\n}\n"
  code: "# define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A\"\
    \n# include <bits/stdc++.h>\nusing namespace std;\n\n//dinic algorithm O(|E||v|^2)\u3088\
    \u308A\u3082\u975E\u5E38\u306B\u9AD8\u901F\u306B\u52D5\u4F5C \ntemplate<typename\
    \ T>struct max_flow {\n\n    struct edge{\n        int to;\n        T cap;\n \
    \       T rev;\n    };\n    \n    int n;\n    vector<vector<edge>> G;\n    vector<int>\
    \ level; // s\u304B\u3089\u306E\u8DDD\u96E2\n    vector<int> iter; // \u3069\u3053\
    \u307E\u3067\u8ABF\u3079\u7D42\u308F\u3063\u305F\u304B\n\n    max_flow(int _v)\
    \ : n(_v) {\n        G.resize(n);\n        level.resize(n);\n        iter.resize(n);\n\
    \    }\n\n    void add_edge(int from, int to, T cap){\n        G[from].push_back((edge){to,\
    \ cap, (T)G[to].size()});\n        G[to].push_back((edge){from, 0, (T)(G[from].size()\
    \ - 1)});\n    }\n\n    // s \u7A7A\u306E\u6700\u77ED\u8DDD\u96E2\u3092\u8A08\u7B97\
    \n    void bfs(int s){\n        for(int i = 0;i < n;i++)level[i] = -1;\n     \
    \   queue<int> que;\n        level[s] = 0;\n        que.push(s);\n        while(!que.empty()){\n\
    \            int v = que.front();\n            que.pop();\n            for(int\
    \ i = 0;i < (int)G[v].size();i++){\n                edge &e = G[v][i];\n     \
    \           if(e.cap > 0 && level[e.to] < 0){\n                    level[e.to]\
    \ = level[v] + 1;\n                    que.push(e.to);\n                }\n  \
    \          }\n        }\n    }\n\n    //\u5897\u52A0\u30D1\u30B9\u3092DFS\u3067\
    \u63A2\u3059\n    T dfs(int v, int t, T f){\n        if(v == t)return f;\n   \
    \     for(int &i = iter[v];i < (int)G[v].size();i++){\n            edge &e = G[v][i];\n\
    \            if(e.cap > 0 && level[v] < level[e.to]){\n                T d = dfs(e.to,\
    \ t, min(f, e.cap));\n                if(d > 0){\n                    e.cap -=\
    \ d;\n                    G[e.to][e.rev].cap += d;\n                    return\
    \ d;\n                }\n            }\n        }\n        return 0;\n    }\n\n\
    \    T calc(int s, int t){\n        T flow = 0;\n        for(;;){\n          \
    \  bfs(s);\n            if(level[t] < 0)return flow;\n            for(int i =\
    \ 0;i < n;i++)iter[i] = 0;\n            int f;\n            while((f = dfs(s,\
    \ t, inf<T>())) > 0) {\n                flow += f;\n            }\n        }\n\
    \    }\n};\n\nint v, e;\n\nint main(){\n    cin >> v >> e;\n    max_flow<int>\
    \ mf(v);\n\n    for(int i = 0;i < e;i++){\n        int a, b, c;\n        cin >>\
    \ a >> b >> c;\n        mf.add_edge(a, b, c);\n    }\n    cout << mf.calc(0, v\
    \ - 1) << endl;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/max_flow_dinic O(E V^2).cpp
  requiredBy: []
  timestamp: '2024-05-23 22:55:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/max_flow_dinic O(E V^2).cpp
layout: document
redirect_from:
- /library/graph/max_flow_dinic O(E V^2).cpp
- /library/graph/max_flow_dinic O(E V^2).cpp.html
title: graph/max_flow_dinic O(E V^2).cpp
---
