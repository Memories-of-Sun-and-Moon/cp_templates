---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/lowest_common_ancestor.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nstruct lowest_common_ancestor {\nprivate:\n\tint n;\n\t\
    vector<vector<int>>g;\n\tint root;\n\tvector<int>depth;\n\tvector<vector<int>>par;\n\
    public:\n\n\tvoid dfs(int v, int p, int d) {\n\t\tpar[v][0] = p;\n\t\tdepth[v]\
    \ = d;\n\t\tfor (int i = 0; i<(int)g[v].size(); i++) {\n\t\t\tif (g[v][i] == p)continue;\n\
    \t\t\tdfs(g[v][i], v, d + 1);\n\t\t}\n\t}\n\n\tlowest_common_ancestor(int N, vector<vector<int>>&\
    \ G, int Root) {\n\t\tn = N;\n        g = G;\n\t\tdepth.resize(N);\n\t\tpar.resize(N);\n\
    \t\tfor (int i = 0; i < N; i++)par[i].resize(31);\n\t\troot = Root;\n\t\tdfs(root,\
    \ -1, 0);\n\t\tfor (int i = 0; i < 30; i++) {\n\t\t\tfor (int j = 0; j < N; j++)\
    \ {\n\t\t\t\tif (par[j][i] == -1)par[j][i + 1] = -1;\n\t\t\t\telse par[j][i +\
    \ 1] = par[par[j][i]][i];\n\t\t\t}\n\t\t}\n\t}\n\n\tint get(int u, int v) {\n\t\
    \tif (depth[u] > depth[v])swap(u, v);\n\t\tfor (int i = 30; i >= 0; i--) {\n\t\
    \t\tif (((depth[v] - depth[u]) >> i) & 1) {\n\t\t\t\tv = par[v][i];\n\t\t\t}\n\
    \t\t}\n\t\tif (u == v)return u;\n\n\t\tfor (int i = 30; i >= 0; i--) {\n\t\t\t\
    if (par[u][i] != par[v][i]) {\n\t\t\t\tu = par[u][i];\n\t\t\t\tv = par[v][i];\n\
    \t\t\t}\n\t\t}\n\t\treturn par[u][0];\n\t}\n};\n\nint main(){\n    int n;\n  \
    \  vector<vector<int>> g(n);\n    lowest_common_ancestor lca(n, g, 0);\n\n   \
    \ cout << lca.get(2, 3) << endl;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\nstruct lowest_common_ancestor\
    \ {\nprivate:\n\tint n;\n\tvector<vector<int>>g;\n\tint root;\n\tvector<int>depth;\n\
    \tvector<vector<int>>par;\npublic:\n\n\tvoid dfs(int v, int p, int d) {\n\t\t\
    par[v][0] = p;\n\t\tdepth[v] = d;\n\t\tfor (int i = 0; i<(int)g[v].size(); i++)\
    \ {\n\t\t\tif (g[v][i] == p)continue;\n\t\t\tdfs(g[v][i], v, d + 1);\n\t\t}\n\t\
    }\n\n\tlowest_common_ancestor(int N, vector<vector<int>>& G, int Root) {\n\t\t\
    n = N;\n        g = G;\n\t\tdepth.resize(N);\n\t\tpar.resize(N);\n\t\tfor (int\
    \ i = 0; i < N; i++)par[i].resize(31);\n\t\troot = Root;\n\t\tdfs(root, -1, 0);\n\
    \t\tfor (int i = 0; i < 30; i++) {\n\t\t\tfor (int j = 0; j < N; j++) {\n\t\t\t\
    \tif (par[j][i] == -1)par[j][i + 1] = -1;\n\t\t\t\telse par[j][i + 1] = par[par[j][i]][i];\n\
    \t\t\t}\n\t\t}\n\t}\n\n\tint get(int u, int v) {\n\t\tif (depth[u] > depth[v])swap(u,\
    \ v);\n\t\tfor (int i = 30; i >= 0; i--) {\n\t\t\tif (((depth[v] - depth[u]) >>\
    \ i) & 1) {\n\t\t\t\tv = par[v][i];\n\t\t\t}\n\t\t}\n\t\tif (u == v)return u;\n\
    \n\t\tfor (int i = 30; i >= 0; i--) {\n\t\t\tif (par[u][i] != par[v][i]) {\n\t\
    \t\t\tu = par[u][i];\n\t\t\t\tv = par[v][i];\n\t\t\t}\n\t\t}\n\t\treturn par[u][0];\n\
    \t}\n};\n\nint main(){\n    int n;\n    vector<vector<int>> g(n);\n    lowest_common_ancestor\
    \ lca(n, g, 0);\n\n    cout << lca.get(2, 3) << endl;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/lowest_common_ancestor.cpp
  requiredBy: []
  timestamp: '2024-05-23 22:55:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/lowest_common_ancestor.cpp
layout: document
redirect_from:
- /library/graph/lowest_common_ancestor.cpp
- /library/graph/lowest_common_ancestor.cpp.html
title: graph/lowest_common_ancestor.cpp
---
