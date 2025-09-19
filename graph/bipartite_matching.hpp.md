---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/dinic.hpp
    title: "\u6700\u5927\u6D41(Dinic)"
  _extendedRequiredBy:
  - icon: ':warning:'
    path: verify/yosupo/bipertitematching.cpp
    title: verify/yosupo/bipertitematching.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/bipartite_matching.hpp\"\n\n#line 2 \"graph/dinic.hpp\"\
    \n\n#include<numeric>\n#include<queue>\n#include<vector>\n\ntemplate<typename\
    \ T>\nstruct dinic {\n\n\tstruct edge{\n\t\tint to;\n\t\tT cap;\n\t\tT rev;\n\t\
    \tT init_cap;\n\t};\n\t\t\n\tint n;\n\tstd::vector<std::vector<edge>> G;\n\tstd::vector<int>\
    \ level;\n\tstd::vector<int> iter;\n\n\tstd::vector<int> from_idx, to_idx;\n\t\
    int edge_idx;\n\n\tdinic(int _v) : n(_v), G(n), level(n), iter(n), edge_idx(0)\
    \ {}\n\n\tint add_edge(int from, int to, T cap){\n\t\tG[from].push_back((edge){to,\
    \ cap, (T)G[to].size(), cap});\n\t\tG[to].push_back((edge){from, 0, (T)(G[from].size()\
    \ - 1), 0});\n\t\tfrom_idx.emplace_back(from);\n\t\tto_idx.emplace_back((int)G[from].size()-1);\n\
    \t\t\n\t\treturn edge_idx++;\n\t}\n\n\tvoid bfs(int s){\n\t\tfor(int i = 0;i <\
    \ n;i++)level[i] = -1;\n\t\tstd::queue<int> que;\n\t\tlevel[s] = 0;\n\t\tque.push(s);\n\
    \t\twhile(!que.empty()){\n\t\t\tint v = que.front();\n\t\t\tque.pop();\n\t\t\t\
    for(int i = 0;i < (int)G[v].size();i++){\n\t\t\t\tedge &e = G[v][i];\n\t\t\t\t\
    if(e.cap > 0 && level[e.to] < 0){\n\t\t\t\t\tlevel[e.to] = level[v] + 1;\n\t\t\
    \t\t\tque.push(e.to);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\n\tT dfs(int v, int t,\
    \ T f){\n\t\tif(v == t)return f;\n\t\tfor(int &i = iter[v];i < (int)G[v].size();i++){\n\
    \t\t\tedge &e = G[v][i];\n\t\t\tif(e.cap > 0 && level[v] < level[e.to]){\n\t\t\
    \t\tT d = dfs(e.to, t, min(f, e.cap));\n\t\t\t\tif(d > 0){\n\t\t\t\t\te.cap -=\
    \ d;\n\t\t\t\t\tG[e.to][e.rev].cap += d;\n\t\t\t\t\treturn d;\n\t\t\t\t}\n\t\t\
    \t}\n\t\t}\n\t\treturn 0;\n\t}\n\n\tT calc(int s, int t){\n\t\tT flow = 0;\n\t\
    \tfor(;;){\n\t\t\tbfs(s);\n\t\t\tif(level[t] < 0)return flow;\n\t\t\tfor(int i\
    \ = 0;i < n;i++)iter[i] = 0;\n\t\t\tT f;\n\t\t\twhile((f = dfs(s, t, std::numeric_limits<T>::max()))\
    \ > 0) {\n\t\t\t\tflow += f;\n\t\t\t}\n\t\t}\n\t}\n\n\tT get_flow(int idx){\n\t\
    \treturn G[from_idx[idx]][to_idx[idx]].init_cap - G[from_idx[idx]][to_idx[idx]].cap;\n\
    \t}\n};\n#line 4 \"graph/bipartite_matching.hpp\"\n\n#line 6 \"graph/bipartite_matching.hpp\"\
    \n#include<ranges>\n\nvector<pair<int, int>> bipartite_matching(const int &l,\
    \ const int &r, const vector<pair<int, int>> &es) {\n\n\tdinic<int> matching(l+r+2);\n\
    \tconst int S = l+r+0;\n\tconst int T = l+r+1;\n\n\tfor(int i = 0;i < l;i++)matching.add_edge(S,\
    \ i, 1);\n\tfor(int i = 0;i < r;i++)matching.add_edge(l+i, T, 1);\n\tfor(auto\
    \ [u, v] : es){\n\t\tmatching.add_edge(u, l+v, 1);\n\t}\n\n\tmatching.calc(S,\
    \ T);\n\n\tstd::vector<pair<int, int>> ret;\n\t\n\t// C++23\n\t// for(auto [idx,\
    \ edge] : es | std::views::enumerate) {\n\tfor(int idx = 0;idx < ssize(es);idx++){\n\
    \t\tauto &edge = es[idx];\n\t\tif(matching.get_flow(l+r+idx) == 1){\n\t\t\tret.emplace_back(edge);\n\
    \t\t}\n\t}\n\n\treturn ret;\n}\n"
  code: "#pragma once\n\n#include \"./dinic.hpp\"\n\n#include<vector>\n#include<ranges>\n\
    \nvector<pair<int, int>> bipartite_matching(const int &l, const int &r, const\
    \ vector<pair<int, int>> &es) {\n\n\tdinic<int> matching(l+r+2);\n\tconst int\
    \ S = l+r+0;\n\tconst int T = l+r+1;\n\n\tfor(int i = 0;i < l;i++)matching.add_edge(S,\
    \ i, 1);\n\tfor(int i = 0;i < r;i++)matching.add_edge(l+i, T, 1);\n\tfor(auto\
    \ [u, v] : es){\n\t\tmatching.add_edge(u, l+v, 1);\n\t}\n\n\tmatching.calc(S,\
    \ T);\n\n\tstd::vector<pair<int, int>> ret;\n\t\n\t// C++23\n\t// for(auto [idx,\
    \ edge] : es | std::views::enumerate) {\n\tfor(int idx = 0;idx < ssize(es);idx++){\n\
    \t\tauto &edge = es[idx];\n\t\tif(matching.get_flow(l+r+idx) == 1){\n\t\t\tret.emplace_back(edge);\n\
    \t\t}\n\t}\n\n\treturn ret;\n}\n"
  dependsOn:
  - graph/dinic.hpp
  isVerificationFile: false
  path: graph/bipartite_matching.hpp
  requiredBy:
  - verify/yosupo/bipertitematching.cpp
  timestamp: '2025-09-19 19:07:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/bipartite_matching.hpp
layout: document
title: "\u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0"
---

# 二部グラフの最大マッチング

## 使い方

- ``vector<pair<int, int>> bipartite_matching(vector<vector<int>> &g)`` : 二部グラフ $G$ の最大マッチングを表す組を返す $O(E \sqrt{V})$
