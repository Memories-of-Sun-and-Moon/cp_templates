---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/strongly_connected_components.hpp
    title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/id/3205.test.cpp
    title: verify/aoj/id/3205.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/two_sat.test.cpp
    title: verify/yosupo/two_sat.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yukicoder/274.test.cpp
    title: verify/yukicoder/274.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/two_sat.hpp\"\n\n#line 2 \"graph/strongly_connected_components.hpp\"\
    \n\n#include<vector>\n\nstruct scc_graph {\n\tint n;\n\tint k;\n\tstd::vector<std::vector<int>>\
    \ g;\n\tstd::vector<std::vector<int>> rg;\n\tstd::vector<bool> used;\n\tstd::vector<int>\
    \ cmp;\n\tstd::vector<int> vs;\n\n\tscc_graph(int _n) : n(_n), k(0), g(n), rg(n),\
    \ used(n), cmp(n) {}\n\n\tvoid add_edge(int a, int b) {\n\t\tg[a].push_back(b);\n\
    \t\trg[b].push_back(a);\n\t}\n\n\tvoid dfs(int v){\n\t\tused[v] = true;\n\t\t\
    for(auto to : g[v]){\n\t\t\tif(not used[to])dfs(to);\n\t\t}\n\t\tvs.push_back(v);\n\
    \t}\n\n\tvoid rdfs(int v, int col){\n\t\tused[v] = true;\n\t\tcmp[v] = col;\n\t\
    \tfor(auto to : rg[v]){\n\t\t\tif(not used[to])rdfs(to, col);\n\t\t}\n\t}\n\n\t\
    std::vector<std::vector<int>> scc() {\n\t\tfor(int i = 0;i < n;i++){\n\t\t\tif(not\
    \ used[i])dfs(i);\n\t\t}\n\t\tfor(int i = 0;i < n;i++){\n\t\t\tused[i] = false;\n\
    \t\t}\n\t\tfor(auto i = vs.rbegin();i != vs.rend();i++){\n\t\t\tif(not used[*i])rdfs(*i,\
    \ k++);\n\t\t}\n\t\tstd::vector<std::vector<int>> ret(k);\n\t\tfor(int i = 0;i\
    \ < n;i++){\n\t\t\tret[cmp[i]].push_back(i);\n\t\t}\n\t\treturn ret;\n\t}\n};\n\
    #line 4 \"graph/two_sat.hpp\"\n\nstruct two_sat {\n\tint n;\n\tscc_graph g;\n\n\
    \ttwo_sat(int _n) : n(_n), g(scc_graph(2*n)) {}\n\n\t// (i = f1) || (j = f2)\n\
    \tvoid add_clause(int i, bool f1, int j, bool f2){\n\t\tg.add_edge((i << 1) ^\
    \ !f1, (j << 1) ^ f2);\n\t\tg.add_edge((j << 1) ^ !f2, (i << 1) ^ f1);\n\t}\n\n\
    \t// (i = f1) -> (j = f2) <=> (1 = !f1) || (j = f2)\n\tvoid add_if(int i, bool\
    \ f1, int j, bool f2){\n\t\tadd_clause(i, !f1, j, f2);\n\t}\n\n\t// i\n\tvoid\
    \ set_true(int i){\n\t\tadd_clause(i, true, i, true);\n\t}\n\n\t// !i\n\tvoid\
    \ set_false(int i){\n\t\tadd_clause(i, false, i, false);\n\t}\n\n\tstd::vector<bool>\
    \ solve(){\n\t\tstd::vector<std::vector<int>> scc = g.scc();\n\t\tstd::vector<int>\
    \ c(2*n);\n\t\tfor(int i = 0;i < (int)scc.size();i++){\n\t\t\tfor(auto v : scc[i]){\n\
    \t\t\t\tc[v] = i;\n\t\t\t}\n\t\t}\n\t\tstd::vector<bool> res(n);\n\t\tfor(int\
    \ i = 0;i < n;i++){\n\t\t\tif(c[i << 1] == c[i << 1 | 1])return std::vector<bool>();\n\
    \t\t\tres[i] = (c[i << 1] < c[i << 1 | 1]);\n\t\t}\n\t\treturn res;\n\t}\n};\n"
  code: "#pragma once\n\n#include \"./strongly_connected_components.hpp\"\n\nstruct\
    \ two_sat {\n\tint n;\n\tscc_graph g;\n\n\ttwo_sat(int _n) : n(_n), g(scc_graph(2*n))\
    \ {}\n\n\t// (i = f1) || (j = f2)\n\tvoid add_clause(int i, bool f1, int j, bool\
    \ f2){\n\t\tg.add_edge((i << 1) ^ !f1, (j << 1) ^ f2);\n\t\tg.add_edge((j << 1)\
    \ ^ !f2, (i << 1) ^ f1);\n\t}\n\n\t// (i = f1) -> (j = f2) <=> (1 = !f1) || (j\
    \ = f2)\n\tvoid add_if(int i, bool f1, int j, bool f2){\n\t\tadd_clause(i, !f1,\
    \ j, f2);\n\t}\n\n\t// i\n\tvoid set_true(int i){\n\t\tadd_clause(i, true, i,\
    \ true);\n\t}\n\n\t// !i\n\tvoid set_false(int i){\n\t\tadd_clause(i, false, i,\
    \ false);\n\t}\n\n\tstd::vector<bool> solve(){\n\t\tstd::vector<std::vector<int>>\
    \ scc = g.scc();\n\t\tstd::vector<int> c(2*n);\n\t\tfor(int i = 0;i < (int)scc.size();i++){\n\
    \t\t\tfor(auto v : scc[i]){\n\t\t\t\tc[v] = i;\n\t\t\t}\n\t\t}\n\t\tstd::vector<bool>\
    \ res(n);\n\t\tfor(int i = 0;i < n;i++){\n\t\t\tif(c[i << 1] == c[i << 1 | 1])return\
    \ std::vector<bool>();\n\t\t\tres[i] = (c[i << 1] < c[i << 1 | 1]);\n\t\t}\n\t\
    \treturn res;\n\t}\n};\n"
  dependsOn:
  - graph/strongly_connected_components.hpp
  isVerificationFile: false
  path: graph/two_sat.hpp
  requiredBy: []
  timestamp: '2025-07-01 03:22:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yukicoder/274.test.cpp
  - verify/yosupo/two_sat.test.cpp
  - verify/aoj/id/3205.test.cpp
documentation_of: graph/two_sat.hpp
layout: document
title: 2-SAT
---

# 2-SAT

## 使い方

- ``two_sat(n)`` : コンストラクタ。$n$ は変数の数を表す
- ``void add_clause(int i, int f1, int j, int f2)`` : 句を追加する
- ``void add_clause(int i, int f1, int j, int f2)`` : 句を追加する
- ``void add_true(int i)`` : 句を追加する
- ``void add_false(int i)`` : 句を追加する
- ``vector<bool> solve()`` : 与えられた $n$ 変数 $m$ 句が充足可能か調べる。充足可能であった場合、真偽の割り当て例を $1$ つ返す。不可能な場合、空の配列を返す。 $O(N+M)$

## 概要

論理式の対応を有向グラフとみて、矛盾がないかをチェックする。チェックに強連結成分分解を行う部分がネックとなり、$O(N+M)$ となる。
