---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/grl/5_C.test.cpp
    title: verify/aoj/grl/5_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/lowest_common_ancestor.hpp\"\n\nstruct lowest_common_ancestor\
    \ {\nprivate:\n\tint n;\n\tint root;\n\tvector<vector<int>>par;\npublic:\n\tvector<int>depth;\n\
    \n\tlowest_common_ancestor(vector<vector<int>>& g, int Root) : n((int)g.size())\
    \ {\n\t\tdepth.resize(n);\n\t\tpar.resize(n);\n\t\tfor (int i = 0; i < n; i++)par[i].resize(31);\n\
    \t\troot = Root;\n\n\t\tauto dfs = [&](auto f, int v, int p, int d) -> void {\n\
    \t\t\tpar[v][0] = p;\n\t\t\tdepth[v] = d;\n\t\t\tfor(size_t i = 0;i < g[v].size();i++){\n\
    \t\t\t\tif(g[v][i] == p)continue;\n\t\t\t\tf(f, g[v][i], v, d+1);\n\t\t\t}\n\t\
    \t};\n\n\t\tdfs(dfs, root, -1, 0);\n\t\t\n\t\tfor (int i = 0; i < 30; i++) {\n\
    \t\t\tfor (int j = 0; j < n; j++) {\n\t\t\t\tif (par[j][i] == -1)par[j][i + 1]\
    \ = -1;\n\t\t\t\telse par[j][i + 1] = par[par[j][i]][i];\n\t\t\t}\n\t\t}\n\t}\n\
    \n\tint get(int u, int v) {\n\t\tif (depth[u] > depth[v])swap(u, v);\n\t\tfor\
    \ (int i = 30; i >= 0; i--) {\n\t\t\tif (((depth[v] - depth[u]) >> i) & 1) {\n\
    \t\t\t\tv = par[v][i];\n\t\t\t}\n\t\t}\n\t\tif (u == v)return u;\n\n\t\tfor (int\
    \ i = 30; i >= 0; i--) {\n\t\t\tif (par[u][i] != par[v][i]) {\n\t\t\t\tu = par[u][i];\n\
    \t\t\t\tv = par[v][i];\n\t\t\t}\n\t\t}\n\t\treturn par[u][0];\n\t}\n};\n"
  code: "\nstruct lowest_common_ancestor {\nprivate:\n\tint n;\n\tint root;\n\tvector<vector<int>>par;\n\
    public:\n\tvector<int>depth;\n\n\tlowest_common_ancestor(vector<vector<int>>&\
    \ g, int Root) : n((int)g.size()) {\n\t\tdepth.resize(n);\n\t\tpar.resize(n);\n\
    \t\tfor (int i = 0; i < n; i++)par[i].resize(31);\n\t\troot = Root;\n\n\t\tauto\
    \ dfs = [&](auto f, int v, int p, int d) -> void {\n\t\t\tpar[v][0] = p;\n\t\t\
    \tdepth[v] = d;\n\t\t\tfor(size_t i = 0;i < g[v].size();i++){\n\t\t\t\tif(g[v][i]\
    \ == p)continue;\n\t\t\t\tf(f, g[v][i], v, d+1);\n\t\t\t}\n\t\t};\n\n\t\tdfs(dfs,\
    \ root, -1, 0);\n\t\t\n\t\tfor (int i = 0; i < 30; i++) {\n\t\t\tfor (int j =\
    \ 0; j < n; j++) {\n\t\t\t\tif (par[j][i] == -1)par[j][i + 1] = -1;\n\t\t\t\t\
    else par[j][i + 1] = par[par[j][i]][i];\n\t\t\t}\n\t\t}\n\t}\n\n\tint get(int\
    \ u, int v) {\n\t\tif (depth[u] > depth[v])swap(u, v);\n\t\tfor (int i = 30; i\
    \ >= 0; i--) {\n\t\t\tif (((depth[v] - depth[u]) >> i) & 1) {\n\t\t\t\tv = par[v][i];\n\
    \t\t\t}\n\t\t}\n\t\tif (u == v)return u;\n\n\t\tfor (int i = 30; i >= 0; i--)\
    \ {\n\t\t\tif (par[u][i] != par[v][i]) {\n\t\t\t\tu = par[u][i];\n\t\t\t\tv =\
    \ par[v][i];\n\t\t\t}\n\t\t}\n\t\treturn par[u][0];\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/lowest_common_ancestor.hpp
  requiredBy: []
  timestamp: '2024-09-28 02:39:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/grl/5_C.test.cpp
documentation_of: graph/lowest_common_ancestor.hpp
layout: document
title: Lowest Common Ancestor
---

# Lowest Common Ancestor

## 使い方

``lowest_common_ancestor(vector<vector<int>> g, int root)`` : $root$ を 根とする木の LCA を求めるためのコンストラクタ。 $O(N \log N)$
``get(int u, int v)`` : 頂点 $u, v$ の $LCA$ を求める。 $O(\log N)$