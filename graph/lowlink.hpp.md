---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/grl/3_A.test.cpp
    title: verify/aoj/grl/3_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj/grl/3_B.test.cpp
    title: verify/aoj/grl/3_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/lowlink.hpp\"\n\nclass lowlink{\n\tvector<vector<int>>\
    \ g;\n\tvector<int> order, low;\n\tvector<bool> __is_articulation;\n\n\tvoid dfs(int\
    \ cur, int pre, int &time){\n\t\tint count_child = 0;\n\t\tlow[cur] = order[cur]\
    \ = time++;\n\t\tfor(int to : g[cur]){\n\t\t\tif(to == pre)continue;\n\t\t\tif(order[to]\
    \ == -1){\n\t\t\t\tdfs(to, cur, time);\n\t\t\t\tcount_child++;\n\t\t\t\tif(pre\
    \ != -1){\n\t\t\t\t\tif(not __is_articulation[cur]) __is_articulation[cur] = (low[to]\
    \ >= order[cur]);\n\t\t\t\t}\n\t\t\t\tlow[cur] = min(low[cur], low[to]);\n\t\t\
    \t}else{\n\t\t\t\tlow[cur] = min(low[cur], order[to]);\n\t\t\t}\n\t\t}\n\t\tif(pre\
    \ == -1){\n\t\t\t__is_articulation[cur] = (count_child >= 2);\n\t\t}\n\t}\n\n\
    public:\n\n\tlowlink(const vector<vector<int>> &_g) : g(_g), order(g.size(), -1),\
    \ low(g.size()), __is_articulation(g.size(), false){\n\t\tint time = 0;\n\t\t\
    for(int v = 0;v < (int)g.size();v++){\n\t\t\tif(order[v] == -1){\n\t\t\t\tdfs(v,\
    \ -1, time);\n\t\t\t}\n\t\t}\n\t}\n\n\tbool is_bridge(int u, int v) const {\n\t\
    \tif(order[u] > order[v]){\n\t\t\tswap(u, v);\n\t\t}\n\t\treturn order[u] < low[v];\n\
    \t}\n\n\tbool is_articulation(int v) const {\n\t\treturn __is_articulation[v];\n\
    \t}\n};\n"
  code: "\nclass lowlink{\n\tvector<vector<int>> g;\n\tvector<int> order, low;\n\t\
    vector<bool> __is_articulation;\n\n\tvoid dfs(int cur, int pre, int &time){\n\t\
    \tint count_child = 0;\n\t\tlow[cur] = order[cur] = time++;\n\t\tfor(int to :\
    \ g[cur]){\n\t\t\tif(to == pre)continue;\n\t\t\tif(order[to] == -1){\n\t\t\t\t\
    dfs(to, cur, time);\n\t\t\t\tcount_child++;\n\t\t\t\tif(pre != -1){\n\t\t\t\t\t\
    if(not __is_articulation[cur]) __is_articulation[cur] = (low[to] >= order[cur]);\n\
    \t\t\t\t}\n\t\t\t\tlow[cur] = min(low[cur], low[to]);\n\t\t\t}else{\n\t\t\t\t\
    low[cur] = min(low[cur], order[to]);\n\t\t\t}\n\t\t}\n\t\tif(pre == -1){\n\t\t\
    \t__is_articulation[cur] = (count_child >= 2);\n\t\t}\n\t}\n\npublic:\n\n\tlowlink(const\
    \ vector<vector<int>> &_g) : g(_g), order(g.size(), -1), low(g.size()), __is_articulation(g.size(),\
    \ false){\n\t\tint time = 0;\n\t\tfor(int v = 0;v < (int)g.size();v++){\n\t\t\t\
    if(order[v] == -1){\n\t\t\t\tdfs(v, -1, time);\n\t\t\t}\n\t\t}\n\t}\n\n\tbool\
    \ is_bridge(int u, int v) const {\n\t\tif(order[u] > order[v]){\n\t\t\tswap(u,\
    \ v);\n\t\t}\n\t\treturn order[u] < low[v];\n\t}\n\n\tbool is_articulation(int\
    \ v) const {\n\t\treturn __is_articulation[v];\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/lowlink.hpp
  requiredBy: []
  timestamp: '2024-10-15 13:22:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/grl/3_A.test.cpp
  - verify/aoj/grl/3_B.test.cpp
documentation_of: graph/lowlink.hpp
layout: document
title: "lowlink\u3092\u7528\u3044\u305F\u6A4B\u30FB\u95A2\u7BC0\u70B9\u306E\u691C\u51FA"
---

# lowlinkを用いた橋・関節点の検出

## 使い方

- ``lowlink(vector<vector<int>> g)`` : グラフ $G$ に関する lowlink を求めるコンストラクタ。 $O(N)$
- ``is_bridge(int u, int v)`` : 辺 $(u, v)$ が橋かどうかを返す。 $O(1)$
- ``is_articulation(int v)`` : 頂点 $v$ が関節点かどうかを返す。 $O(1)$
