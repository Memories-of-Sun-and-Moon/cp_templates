---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/union_find.hpp
    title: Union-Find
  - icon: ':heavy_check_mark:'
    path: graph/lowlink.hpp
    title: "lowlink\u3092\u7528\u3044\u305F\u6A4B\u30FB\u95A2\u7BC0\u70B9\u306E\u691C\
      \u51FA"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/two_edge_connected_components.test.cpp
    title: verify/yosupo/two_edge_connected_components.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/two_edge_connected_components.hpp\"\n\n#line 2 \"\
    data_structure/union_find.hpp\"\n\n#include<cassert>\n#include<vector>\n\nstruct\
    \ union_find {\n\tstd::vector<int> v;\n\tint g_size;\n\tint n;\n\n\tunion_find(size_t\
    \ size) : v(size, -1), g_size(size), n(size) {}\n\n\tint root(int x){\n\t\tassert(x\
    \ < n);\n\t\treturn (v[x] < 0 ? x : v[x] = root(v[x]));\n\t}\n\n\tbool is_root(int\
    \ x){\n\t\tassert(x < n);\n\t\treturn root(x) == x;\n\t}\n\n\tbool unite(int x,\
    \ int y){\n\t\tassert(x < n && y < n);\n\t\tx = root(x);\n\t\ty = root(y);\n\t\
    \tif(x != y){\n\t\t\tif(v[x] > v[y])std::swap(x, y);\n\t\t\tv[x] += v[y];\n\t\t\
    \tv[y] = x;\n\t\t\tg_size--;\n\t\t\treturn true;\n\t\t}\n\t\treturn false;\n\t\
    }\n\n\tbool is_same(int x,int y){\n\t\tassert(x < n && y < n);\n\t\treturn root(x)\
    \ == root(y);\n\t}\n\n\tint get_size(int x){\n\t\tassert(x < n);\n\t\tx = root(x);\n\
    \t\treturn -v[x];\n\t}\n\n\tint groups_size(){\n\t\treturn g_size;\n\t}\n\n\t\
    std::vector<std::vector<int>> groups(){\n\t\tstd::vector<std::vector<int>> member(n);\n\
    \t\tfor(int i = 0;i < n;i++){\n\t\t\tmember[root(i)].push_back(i);\n\t\t}\n\n\t\
    \tstd::vector<std::vector<int>> ret;\n\t\tfor(int i = 0;i < n;i++){\n\t\t\tif(member[i].empty())continue;\n\
    \t\t\tret.push_back(member[i]);\n\t\t}\n\t\treturn ret;\n\t}\n};\n#line 2 \"graph/lowlink.hpp\"\
    \n\n#line 4 \"graph/lowlink.hpp\"\n#include<utility>\n\nclass lowlink{\n\tstd::vector<std::vector<int>>\
    \ g;\n\tstd::vector<int> order, low;\n\tstd::vector<bool> __is_articulation;\n\
    \n\tvoid dfs(int cur, int pre, int &time){\n\t\tint count_child = 0;\n\t\tlow[cur]\
    \ = order[cur] = time++;\n\t\tbool first_parent = true;\n\t\tfor(int to : g[cur]){\n\
    \t\t\tif(to == pre && std::exchange(first_parent, false))continue;\n\t\t\tif(order[to]\
    \ == -1){\n\t\t\t\tdfs(to, cur, time);\n\t\t\t\tcount_child++;\n\t\t\t\tif(pre\
    \ != -1){\n\t\t\t\t\tif(not __is_articulation[cur]) __is_articulation[cur] = (low[to]\
    \ >= order[cur]);\n\t\t\t\t}\n\t\t\t\tlow[cur] = std::min(low[cur], low[to]);\n\
    \t\t\t}else{\n\t\t\t\tlow[cur] = std::min(low[cur], order[to]);\n\t\t\t}\n\t\t\
    }\n\t\tif(pre == -1){\n\t\t\t__is_articulation[cur] = (count_child >= 2);\n\t\t\
    }\n\t}\n\npublic:\n\n\tlowlink(const std::vector<std::vector<int>> &_g) : g(_g),\
    \ order(g.size(), -1), low(g.size()), __is_articulation(g.size(), false){\n\t\t\
    int time = 0;\n\t\tfor(int v = 0;v < (int)g.size();v++){\n\t\t\tif(order[v] ==\
    \ -1){\n\t\t\t\tdfs(v, -1, time);\n\t\t\t}\n\t\t}\n\t}\n\n\tbool is_bridge(int\
    \ u, int v) const {\n\t\tif(order[u] > order[v]){\n\t\t\tstd::swap(u, v);\n\t\t\
    }\n\t\treturn order[u] < low[v];\n\t}\n\n\tbool is_articulation(int v) const {\n\
    \t\treturn __is_articulation[v];\n\t}\n};\n#line 5 \"graph/two_edge_connected_components.hpp\"\
    \n\n#line 7 \"graph/two_edge_connected_components.hpp\"\n#include<tuple>\n\nauto\
    \ two_edge_connected_components(std::vector<std::vector<int>> &g){\n\tlowlink\
    \ l(g);\n\tunion_find uf((int)g.size());\n\tfor(int i = 0;i < (int)g.size();i++){\n\
    \t\tfor(int to : g[i]){\n\t\t\tif(not l.is_bridge(i, to)){\n\t\t\t\tuf.unite(i,\
    \ to);\n\t\t\t}\n\t\t}\n\t}\n\n\tstd::vector<std::vector<int>> group = uf.groups();\n\
    \tstd::vector<int> comp((int)g.size());\n\tfor(int i = 0;i < (int)group.size();i++){\n\
    \t\tfor(int v : group[i]){\n\t\t\tcomp[v] = i;\n\t\t}\n\t}\n\n\tstd::vector<std::vector<int>>\
    \ tree((int)group.size());\n\tfor(int i = 0;i < (int)g.size();i++){\n\t\tfor(int\
    \ to : g[i]){\n\t\t\tif(comp[i] != comp[to]){\n\t\t\t\ttree[comp[i]].push_back(comp[to]);\n\
    \t\t\t}\n\t\t}\n\t}\n\n\treturn make_tuple(group, comp, tree);\n}\n"
  code: "#pragma once\n\n#include \"../data_structure/union_find.hpp\"\n#include \"\
    ./lowlink.hpp\"\n\n#include<cassert>\n#include<tuple>\n\nauto two_edge_connected_components(std::vector<std::vector<int>>\
    \ &g){\n\tlowlink l(g);\n\tunion_find uf((int)g.size());\n\tfor(int i = 0;i <\
    \ (int)g.size();i++){\n\t\tfor(int to : g[i]){\n\t\t\tif(not l.is_bridge(i, to)){\n\
    \t\t\t\tuf.unite(i, to);\n\t\t\t}\n\t\t}\n\t}\n\n\tstd::vector<std::vector<int>>\
    \ group = uf.groups();\n\tstd::vector<int> comp((int)g.size());\n\tfor(int i =\
    \ 0;i < (int)group.size();i++){\n\t\tfor(int v : group[i]){\n\t\t\tcomp[v] = i;\n\
    \t\t}\n\t}\n\n\tstd::vector<std::vector<int>> tree((int)group.size());\n\tfor(int\
    \ i = 0;i < (int)g.size();i++){\n\t\tfor(int to : g[i]){\n\t\t\tif(comp[i] !=\
    \ comp[to]){\n\t\t\t\ttree[comp[i]].push_back(comp[to]);\n\t\t\t}\n\t\t}\n\t}\n\
    \n\treturn make_tuple(group, comp, tree);\n}\n"
  dependsOn:
  - data_structure/union_find.hpp
  - graph/lowlink.hpp
  isVerificationFile: false
  path: graph/two_edge_connected_components.hpp
  requiredBy: []
  timestamp: '2025-07-01 03:22:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
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
