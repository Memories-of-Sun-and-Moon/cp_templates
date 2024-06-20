---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/id/2828.test.cpp
    title: verify/aoj/id/2828.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/lc/assignment.test.cpp
    title: verify/lc/assignment.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/assignment.test.cpp
    title: verify/yosupo/assignment.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/hungarian.hpp\"\n\ntemplate<bool is_min, typename\
    \ T>\nvector<int> hungarian(vector<vector<T>> a) {\n\tconstexpr T infty = numeric_limits<T>::max()/2;\n\
    \tint n = (int)a.size();\n\t\n\tif(not is_min){\n\t\tfor(int i = 0;i < n;i++){\n\
    \t\t\tfor(int j = 0; j < n;j++){\n\t\t\t\ta[i][j] *= -1;\n\t\t\t}\n\t\t}\n\t}\n\
    \n\tvector<int> p(n);\n\tiota(p.begin(), p.end(), 0);\n\n\tvector<T> h = {0};\n\
    \th.reserve(n);\n\tfor(int i = 1;i < n;i++){\n\t\th.push_back(0);\n\t\tvector<T>\
    \ d(i+1, infty);\n\t\tvector<int> pre(i+1, -1);\n\t\tvector<bool> used(i+1, false);\n\
    \n\t\td[i] = 0;\n\t\tpre[i] = i;\n\n\t\tfor(int _ = 0;_ <= i;_++){\n\t\t\tT min_d\
    \ = infty;\n\t\t\tint v = -1;\n\t\t\tfor(int j = 0;j <= i;j++){\n\t\t\t\tif(not\
    \ used[j] && min_d > d[j]-h[j]){\n\t\t\t\t\tmin_d = d[j]-h[j];\n\t\t\t\t\tv =\
    \ j;\n\t\t\t\t}\n\t\t\t}\n\t\t\t\t\n\t\t\tused[v] = true;\n\n\t\t\tfor(int j =\
    \ 0;j <= i;j++){\n\t\t\t\tif(not used[j] || j == i){\n\t\t\t\t\tT nd = d[v] -\
    \ a[v][p[v]] + a[j][p[v]];\n\t\t\t\t\tif(d[j] > nd){\n\t\t\t\t\t\td[j] = nd;\n\
    \t\t\t\t\t\tpre[j] = v;\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\n\t\tint cur\
    \ = i;\n\t\twhile(pre[cur] != i){\n\t\t\tswap(p[cur], p[pre[cur]]);\n\t\t\tcur\
    \ = pre[cur];\n\t\t}\n\t\th = d;\n\t}\n\treturn p;\n}\n"
  code: "\ntemplate<bool is_min, typename T>\nvector<int> hungarian(vector<vector<T>>\
    \ a) {\n\tconstexpr T infty = numeric_limits<T>::max()/2;\n\tint n = (int)a.size();\n\
    \t\n\tif(not is_min){\n\t\tfor(int i = 0;i < n;i++){\n\t\t\tfor(int j = 0; j <\
    \ n;j++){\n\t\t\t\ta[i][j] *= -1;\n\t\t\t}\n\t\t}\n\t}\n\n\tvector<int> p(n);\n\
    \tiota(p.begin(), p.end(), 0);\n\n\tvector<T> h = {0};\n\th.reserve(n);\n\tfor(int\
    \ i = 1;i < n;i++){\n\t\th.push_back(0);\n\t\tvector<T> d(i+1, infty);\n\t\tvector<int>\
    \ pre(i+1, -1);\n\t\tvector<bool> used(i+1, false);\n\n\t\td[i] = 0;\n\t\tpre[i]\
    \ = i;\n\n\t\tfor(int _ = 0;_ <= i;_++){\n\t\t\tT min_d = infty;\n\t\t\tint v\
    \ = -1;\n\t\t\tfor(int j = 0;j <= i;j++){\n\t\t\t\tif(not used[j] && min_d > d[j]-h[j]){\n\
    \t\t\t\t\tmin_d = d[j]-h[j];\n\t\t\t\t\tv = j;\n\t\t\t\t}\n\t\t\t}\n\t\t\t\t\n\
    \t\t\tused[v] = true;\n\n\t\t\tfor(int j = 0;j <= i;j++){\n\t\t\t\tif(not used[j]\
    \ || j == i){\n\t\t\t\t\tT nd = d[v] - a[v][p[v]] + a[j][p[v]];\n\t\t\t\t\tif(d[j]\
    \ > nd){\n\t\t\t\t\t\td[j] = nd;\n\t\t\t\t\t\tpre[j] = v;\n\t\t\t\t\t}\n\t\t\t\
    \t}\n\t\t\t}\n\t\t}\n\n\t\tint cur = i;\n\t\twhile(pre[cur] != i){\n\t\t\tswap(p[cur],\
    \ p[pre[cur]]);\n\t\t\tcur = pre[cur];\n\t\t}\n\t\th = d;\n\t}\n\treturn p;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/hungarian.hpp
  requiredBy: []
  timestamp: '2024-06-04 08:02:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/lc/assignment.test.cpp
  - verify/aoj/id/2828.test.cpp
  - verify/yosupo/assignment.test.cpp
documentation_of: graph/hungarian.hpp
layout: document
title: "\u5272\u5F53\u554F\u984C\uFF08\u30CF\u30F3\u30AC\u30EA\u30A2\u30F3\u6CD5\uFF09"
---

# ハンガリアン法

## 使い方

行が人、列が仕事を表す $N$ 行 $N$ 列の行列を用意する。（割り当てがない場合は、$A_{i, j} = 0$ としてよい）

- ``vector<int> hungarian<bool is_min, typename T>(vector<vector<T>> A)`` : 割当問題における
  - ``is_min`` が ``true`` の時 : 最小重み最大マッチングの割り当てを返す $O(N^3)$
  - ``is_min`` が ``false`` の時 : 最大重み最大マッチングの割り当てを返す $O(N^3)$

## メモ

割当問題をハンガリアン法で解く。

- 最小重み最大マッチングを、最小費用流で解けることを理解するのが前提
- $i$ からスタートする増加路を考える
- 二部グラフの最大マッチングの形のグラフになっていることを活用して、（ダイクストラ法などのグラフアルゴリズムを使うことなく）ポテンシャルの計算をするのが肝っぽい
