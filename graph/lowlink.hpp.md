---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/aoj/grl/3_B.test.cpp
    title: verify/aoj/grl/3_B.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/lowlink.hpp\"\n\nclass lowlink{\n\tvector<vector<int>>\
    \ g;\n\tvector<int> order, low;\n\tvector<bool> is_articulation;\n\n\tvoid dfs(int\
    \ v, int pre, int &time){\n\t\tlow[v] = order[v] = time++;\n\t\tfor(int to : g[v]){\n\
    \t\t\tif(to == pre)continue;\n\t\t\tif(order[to] == -1){\n\t\t\t\tdfs(to, v, time);\n\
    \t\t\t\tlow[v] = min(low[v], low[to]);\n\t\t\t}else{\n\t\t\t\tlow[v] = min(low[v],\
    \ order[to]);\n\t\t\t}\n\t\t}\n\t}\n\npublic:\n\n\tlowlink(const vector<vector<int>>\
    \ &_g) : g(_g), order(g.size(), -1), low(g.size()){\n\t\tint time = 0;\n\t\tfor(int\
    \ v = 0;v < (int)g.size();v++){\n\t\t\tif(order[v] == -1){\n\t\t\t\tdfs(v, -1,\
    \ time);\n\t\t\t}\n\t\t}\n\t\tdebug(order, low);\n\t}\n\n\tbool is_bridge(int\
    \ u, int v) const {\n\t\tif(order[u] > order[v]){\n\t\t\tswap(u, v);\n\t\t}\n\t\
    \treturn order[u] < low[v];\n\t}\n};\n"
  code: "\nclass lowlink{\n\tvector<vector<int>> g;\n\tvector<int> order, low;\n\t\
    vector<bool> is_articulation;\n\n\tvoid dfs(int v, int pre, int &time){\n\t\t\
    low[v] = order[v] = time++;\n\t\tfor(int to : g[v]){\n\t\t\tif(to == pre)continue;\n\
    \t\t\tif(order[to] == -1){\n\t\t\t\tdfs(to, v, time);\n\t\t\t\tlow[v] = min(low[v],\
    \ low[to]);\n\t\t\t}else{\n\t\t\t\tlow[v] = min(low[v], order[to]);\n\t\t\t}\n\
    \t\t}\n\t}\n\npublic:\n\n\tlowlink(const vector<vector<int>> &_g) : g(_g), order(g.size(),\
    \ -1), low(g.size()){\n\t\tint time = 0;\n\t\tfor(int v = 0;v < (int)g.size();v++){\n\
    \t\t\tif(order[v] == -1){\n\t\t\t\tdfs(v, -1, time);\n\t\t\t}\n\t\t}\n\t\tdebug(order,\
    \ low);\n\t}\n\n\tbool is_bridge(int u, int v) const {\n\t\tif(order[u] > order[v]){\n\
    \t\t\tswap(u, v);\n\t\t}\n\t\treturn order[u] < low[v];\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/lowlink.hpp
  requiredBy: []
  timestamp: '2024-10-15 13:00:16+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/aoj/grl/3_B.test.cpp
documentation_of: graph/lowlink.hpp
layout: document
redirect_from:
- /library/graph/lowlink.hpp
- /library/graph/lowlink.hpp.html
title: graph/lowlink.hpp
---
