---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/functional_graph_cycle_enumeration.hpp\"\n\n#include<vector>\n\
    \nstd::vector<std::vector<int>> functional_graph_cycle_enumeration(std::vector<int>\
    \ a){\n\tstd::vector<std::vector<int>> ret;\n\tint n = (int)a.size();\n\tstd::vector\
    \ vis(n, 0);\n\tfor(int i = 0;i < n;i++){\n\t\tif(vis[i] != 0)continue;\n\t\t\
    int cur = i;\n\t\twhile(vis[cur] == 0){\n\t\t\tvis[cur] = 1;\n\t\t\tcur = a[cur];\n\
    \t\t}\n\t\tif(vis[cur] == 1){\n\t\t\tint cnt = 0;\n\t\t\tint u = cur;\n\t\t\t\
    std::vector<int> v;\n\t\t\tdo{\n\t\t\t\tcnt++;\n\t\t\t\tv.emplace_back(u);\n\t\
    \t\t\tu = a[u];\n\t\t\t}while(u != cur);\n\t\t\tret.emplace_back(v);\n\t\t}\n\t\
    \tfor(int v = i;vis[v] != 2;v = a[v]){\n\t\t\tvis[v] = 2;\n\t\t}\n\t}\n\treturn\
    \ ret;\n}\n"
  code: "#pragma once\n\n#include<vector>\n\nstd::vector<std::vector<int>> functional_graph_cycle_enumeration(std::vector<int>\
    \ a){\n\tstd::vector<std::vector<int>> ret;\n\tint n = (int)a.size();\n\tstd::vector\
    \ vis(n, 0);\n\tfor(int i = 0;i < n;i++){\n\t\tif(vis[i] != 0)continue;\n\t\t\
    int cur = i;\n\t\twhile(vis[cur] == 0){\n\t\t\tvis[cur] = 1;\n\t\t\tcur = a[cur];\n\
    \t\t}\n\t\tif(vis[cur] == 1){\n\t\t\tint cnt = 0;\n\t\t\tint u = cur;\n\t\t\t\
    std::vector<int> v;\n\t\t\tdo{\n\t\t\t\tcnt++;\n\t\t\t\tv.emplace_back(u);\n\t\
    \t\t\tu = a[u];\n\t\t\t}while(u != cur);\n\t\t\tret.emplace_back(v);\n\t\t}\n\t\
    \tfor(int v = i;vis[v] != 2;v = a[v]){\n\t\t\tvis[v] = 2;\n\t\t}\n\t}\n\treturn\
    \ ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/functional_graph_cycle_enumeration.hpp
  requiredBy: []
  timestamp: '2025-07-01 03:22:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/functional_graph_cycle_enumeration.hpp
layout: document
redirect_from:
- /library/graph/functional_graph_cycle_enumeration.hpp
- /library/graph/functional_graph_cycle_enumeration.hpp.html
title: graph/functional_graph_cycle_enumeration.hpp
---
