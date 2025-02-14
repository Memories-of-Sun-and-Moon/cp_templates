---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/union_find.hpp
    title: Union-Find
  - icon: ':question:'
    path: graph/lowlink.hpp
    title: "lowlink\u3092\u7528\u3044\u305F\u6A4B\u30FB\u95A2\u7BC0\u70B9\u306E\u691C\
      \u51FA"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo/two_edge_connected_components.test.cpp
    title: verify/yosupo/two_edge_connected_components.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/two_edge_connected_components.hpp\"\n\n#line 1 \"\
    data_structure/union_find.hpp\"\n\nstruct union_find {\n\tvector<int> v;\n\tint\
    \ g_size;\n\tint n;\n\n\tunion_find(size_t size) : v(size, -1), g_size(size),\
    \ n(size) {}\n\n\tint root(int x){\n\t\tassert(x < n);\n\t\treturn (v[x] < 0 ?\
    \ x : v[x] = root(v[x]));\n\t}\n\n\tbool is_root(int x){\n\t\tassert(x < n);\n\
    \t\treturn root(x) == x;\n\t}\n\n\tbool unite(int x, int y){\n\t\tassert(x < n\
    \ && y < n);\n\t\tx = root(x);\n\t\ty = root(y);\n\t\tif(x != y){\n\t\t\tif(v[x]\
    \ > v[y])swap(x, y);\n\t\t\tv[x] += v[y];\n\t\t\tv[y] = x;\n\t\t\tg_size--;\n\t\
    \t\treturn true;\n\t\t}\n\t\treturn false;\n\t}\n\n\tbool is_same(int x,int y){\n\
    \t\tassert(x < n && y < n);\n\t\treturn root(x) == root(y);\n\t}\n\n\tint get_size(int\
    \ x){\n\t\tassert(x < n);\n\t\tx = root(x);\n\t\treturn -v[x];\n\t}\n\n\tint groups_size(){\n\
    \t\treturn g_size;\n\t}\n\n\tvector<vector<int>> groups(){\n\t\tvector<vector<int>>\
    \ member(n);\n\t\tfor(int i = 0;i < n;i++){\n\t\t\tmember[root(i)].push_back(i);\n\
    \t\t}\n\n\t\tvector<vector<int>> ret;\n\t\tfor(int i = 0;i < n;i++){\n\t\t\tif(member[i].empty())continue;\n\
    \t\t\tret.push_back(member[i]);\n\t\t}\n\t\treturn ret;\n\t}\n};\n#line 1 \"graph/lowlink.hpp\"\
    \n\nclass lowlink{\n\tvector<vector<int>> g;\n\tvector<int> order, low;\n\tvector<bool>\
    \ __is_articulation;\n\n\tvoid dfs(int cur, int pre, int &time){\n\t\tint count_child\
    \ = 0;\n\t\tlow[cur] = order[cur] = time++;\n\t\tbool first_parent = true;\n\t\
    \tfor(int to : g[cur]){\n\t\t\tif(to == pre && exchange(first_parent, false))continue;\n\
    \t\t\tif(order[to] == -1){\n\t\t\t\tdfs(to, cur, time);\n\t\t\t\tcount_child++;\n\
    \t\t\t\tif(pre != -1){\n\t\t\t\t\tif(not __is_articulation[cur]) __is_articulation[cur]\
    \ = (low[to] >= order[cur]);\n\t\t\t\t}\n\t\t\t\tlow[cur] = min(low[cur], low[to]);\n\
    \t\t\t}else{\n\t\t\t\tlow[cur] = min(low[cur], order[to]);\n\t\t\t}\n\t\t}\n\t\
    \tif(pre == -1){\n\t\t\t__is_articulation[cur] = (count_child >= 2);\n\t\t}\n\t\
    }\n\npublic:\n\n\tlowlink(const vector<vector<int>> &_g) : g(_g), order(g.size(),\
    \ -1), low(g.size()), __is_articulation(g.size(), false){\n\t\tint time = 0;\n\
    \t\tfor(int v = 0;v < (int)g.size();v++){\n\t\t\tif(order[v] == -1){\n\t\t\t\t\
    dfs(v, -1, time);\n\t\t\t}\n\t\t}\n\t}\n\n\tbool is_bridge(int u, int v) const\
    \ {\n\t\tif(order[u] > order[v]){\n\t\t\tswap(u, v);\n\t\t}\n\t\treturn order[u]\
    \ < low[v];\n\t}\n\n\tbool is_articulation(int v) const {\n\t\treturn __is_articulation[v];\n\
    \t}\n};\n#line 4 \"graph/two_edge_connected_components.hpp\"\n\nauto two_edge_connected_components(vector<vector<int>>\
    \ &g){\n    lowlink l(g);\n    union_find uf((int)g.size());\n    for(int i =\
    \ 0;i < (int)g.size();i++){\n        for(int to : g[i]){\n            if(not l.is_bridge(i,\
    \ to)){\n                uf.unite(i, to);\n            }\n        }\n    }\n\n\
    \    vector<vector<int>> group = uf.groups();\n    vector<int> comp((int)g.size());\n\
    \    for(int i = 0;i < (int)group.size();i++){\n        for(int v : group[i]){\n\
    \            comp[v] = i;\n        }\n    }\n\n    vector<vector<int>> tree((int)group.size());\n\
    \    for(int i = 0;i < (int)g.size();i++){\n        for(int to : g[i]){\n    \
    \        if(comp[i] != comp[to]){\n                tree[comp[i]].push_back(comp[to]);\n\
    \            }\n        }\n    }\n\n    return make_tuple(group, comp, tree);\n\
    }\n"
  code: "\n#include \"../data_structure/union_find.hpp\"\n#include \"./lowlink.hpp\"\
    \n\nauto two_edge_connected_components(vector<vector<int>> &g){\n    lowlink l(g);\n\
    \    union_find uf((int)g.size());\n    for(int i = 0;i < (int)g.size();i++){\n\
    \        for(int to : g[i]){\n            if(not l.is_bridge(i, to)){\n      \
    \          uf.unite(i, to);\n            }\n        }\n    }\n\n    vector<vector<int>>\
    \ group = uf.groups();\n    vector<int> comp((int)g.size());\n    for(int i =\
    \ 0;i < (int)group.size();i++){\n        for(int v : group[i]){\n            comp[v]\
    \ = i;\n        }\n    }\n\n    vector<vector<int>> tree((int)group.size());\n\
    \    for(int i = 0;i < (int)g.size();i++){\n        for(int to : g[i]){\n    \
    \        if(comp[i] != comp[to]){\n                tree[comp[i]].push_back(comp[to]);\n\
    \            }\n        }\n    }\n\n    return make_tuple(group, comp, tree);\n\
    }\n"
  dependsOn:
  - data_structure/union_find.hpp
  - graph/lowlink.hpp
  isVerificationFile: false
  path: graph/two_edge_connected_components.hpp
  requiredBy: []
  timestamp: '2024-10-15 14:47:57+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo/two_edge_connected_components.test.cpp
documentation_of: graph/two_edge_connected_components.hpp
layout: document
title: "\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3"
---

# 二重辺連結成分分解

## 使い方

``tuple(vector<vector<int>>, vector<int>, vector<vector<int>>) two_edge_connected_components(vector<vector<int>> g)`` 
$G$ の二重辺連結成分分解をした

- 圧縮された頂点のグループ
- 各頂点が圧縮された後の集合
- 二重辺連結成分分解をしたグラフ

を返す。
