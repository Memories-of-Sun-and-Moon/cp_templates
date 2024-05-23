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
    - https://atcoder.jp/contests/typical90/tasks/typical90_u
  bundledCode: "#line 1 \"graph/strongly_connected_components.cpp\"\n# define PROBLEM\
    \ \"https://atcoder.jp/contests/typical90/tasks/typical90_u\"\n\n# include <bits/stdc++.h>\n\
    using namespace std;\n\nstruct strongly_connected_components {\nprivate:\n   \
    \ int v;\n    vector<vector<int>> g, rg;\n    vector<int> vs;\n    vector<bool>\
    \ used;\n\n    int groups = 0;\n\n    void dfs(int cur){\n        used[cur] =\
    \ true;\n        for(auto to : g[cur]){\n            if(not used[to])dfs(to);\n\
    \        }\n        vs.push_back(cur);\n    }\n\n    void rdfs(int cur, int k){\n\
    \        used[cur] = true;\n        group[cur] = k;\n        for(auto to : rg[cur]){\n\
    \            if(not used[to])rdfs(to, k);\n        }\n    }\n\n    void scc(){\n\
    \        vs.clear();\n        groups = 0;\n        for(int i = 0;i < v;i++){\n\
    \            if(not used[i])dfs(i);\n        }\n        used.assign(v, false);\n\
    \        for(int i = (int)vs.size() - 1;i >= 0;i--){\n            if(not used[vs[i]])rdfs(vs[i],\
    \ groups++);\n        }\n    }\npublic:\n    // \u5F37\u9023\u7D50\u6210\u5206\
    \u306E\u30B0\u30EB\u30FC\u30D7\u756A\u53F7\n    vector<int> group;\n\n    strongly_connected_components(vector<vector<int>>\
    \ _g) : g(_g){\n        v = (int)g.size();\n        rg.resize(v);\n        for(int\
    \ i = 0;i < v;i++)for(auto to : g[i])rg[to].push_back(i);\n        used.resize(v,\
    \ false);\n        group.resize(v, 0);\n        scc();\n    }\n};\n"
  code: "# define PROBLEM \"https://atcoder.jp/contests/typical90/tasks/typical90_u\"\
    \n\n# include <bits/stdc++.h>\nusing namespace std;\n\nstruct strongly_connected_components\
    \ {\nprivate:\n    int v;\n    vector<vector<int>> g, rg;\n    vector<int> vs;\n\
    \    vector<bool> used;\n\n    int groups = 0;\n\n    void dfs(int cur){\n   \
    \     used[cur] = true;\n        for(auto to : g[cur]){\n            if(not used[to])dfs(to);\n\
    \        }\n        vs.push_back(cur);\n    }\n\n    void rdfs(int cur, int k){\n\
    \        used[cur] = true;\n        group[cur] = k;\n        for(auto to : rg[cur]){\n\
    \            if(not used[to])rdfs(to, k);\n        }\n    }\n\n    void scc(){\n\
    \        vs.clear();\n        groups = 0;\n        for(int i = 0;i < v;i++){\n\
    \            if(not used[i])dfs(i);\n        }\n        used.assign(v, false);\n\
    \        for(int i = (int)vs.size() - 1;i >= 0;i--){\n            if(not used[vs[i]])rdfs(vs[i],\
    \ groups++);\n        }\n    }\npublic:\n    // \u5F37\u9023\u7D50\u6210\u5206\
    \u306E\u30B0\u30EB\u30FC\u30D7\u756A\u53F7\n    vector<int> group;\n\n    strongly_connected_components(vector<vector<int>>\
    \ _g) : g(_g){\n        v = (int)g.size();\n        rg.resize(v);\n        for(int\
    \ i = 0;i < v;i++)for(auto to : g[i])rg[to].push_back(i);\n        used.resize(v,\
    \ false);\n        group.resize(v, 0);\n        scc();\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/strongly_connected_components.cpp
  requiredBy: []
  timestamp: '2024-05-23 22:55:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/strongly_connected_components.cpp
layout: document
redirect_from:
- /library/graph/strongly_connected_components.cpp
- /library/graph/strongly_connected_components.cpp.html
title: graph/strongly_connected_components.cpp
---
