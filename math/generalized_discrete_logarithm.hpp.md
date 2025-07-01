---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo/generalized_discrete_logarithm.test.cpp
    title: verify/yosupo/generalized_discrete_logarithm.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/generalized_discrete_logarithm.hpp\"\n\n#include<unordered_set>\n\
    \ntemplate<typename T>\nT generalized_discrete_logarithm(T x, T y, auto f, int\
    \ n, auto f_m, int m){\n\tif(x == y){\n\t\treturn 0;\n\t}\n\n\tstd::unordered_set<T>\
    \ baby_steps;\n\tT fy = y;\n\tfor(int i = 0;i < m;i++){\n\t\tbaby_steps.insert(fy);\n\
    \t\tfy = f(fy);\n\t}\n\n\tT fx = x;\n\tbool is_first_loop = true;\n\tfor(int i\
    \ = 0;i <= n;i += m){\n\t\tT next_val = f_m(fx);\n\t\tif(baby_steps.contains(next_val)){\n\
    \t\t\tfor(int j = i+1;j <= i+m;j++){\n\t\t\t\tfx = f(fx);\n\t\t\t\tif(fx == y){\n\
    \t\t\t\t\treturn (j <= n ? j : -1);\n\t\t\t\t}\n\t\t\t}\n\t\t\tif(is_first_loop){\n\
    \t\t\t\tis_first_loop = false;\n\t\t\t}else{\n\t\t\t\treturn -1;\n\t\t\t}\n\t\t\
    }\n\t\tfx = next_val;\n\t}\n\treturn -1;\n}\n"
  code: "#pragma once\n\n#include<unordered_set>\n\ntemplate<typename T>\nT generalized_discrete_logarithm(T\
    \ x, T y, auto f, int n, auto f_m, int m){\n\tif(x == y){\n\t\treturn 0;\n\t}\n\
    \n\tstd::unordered_set<T> baby_steps;\n\tT fy = y;\n\tfor(int i = 0;i < m;i++){\n\
    \t\tbaby_steps.insert(fy);\n\t\tfy = f(fy);\n\t}\n\n\tT fx = x;\n\tbool is_first_loop\
    \ = true;\n\tfor(int i = 0;i <= n;i += m){\n\t\tT next_val = f_m(fx);\n\t\tif(baby_steps.contains(next_val)){\n\
    \t\t\tfor(int j = i+1;j <= i+m;j++){\n\t\t\t\tfx = f(fx);\n\t\t\t\tif(fx == y){\n\
    \t\t\t\t\treturn (j <= n ? j : -1);\n\t\t\t\t}\n\t\t\t}\n\t\t\tif(is_first_loop){\n\
    \t\t\t\tis_first_loop = false;\n\t\t\t}else{\n\t\t\t\treturn -1;\n\t\t\t}\n\t\t\
    }\n\t\tfx = next_val;\n\t}\n\treturn -1;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/generalized_discrete_logarithm.hpp
  requiredBy: []
  timestamp: '2025-07-01 03:22:56+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo/generalized_discrete_logarithm.test.cpp
documentation_of: math/generalized_discrete_logarithm.hpp
layout: document
title: generalized_discrete_logarithm
---

# generalized_discrete_logarithm

## 使い方

``template<typename T> generalized_discrete_logarithm(T x, T y, auto f, int n, auto f_m, int m)`` : $f^n(x) = y$ を満たす $n$ 以下の自然数 $k$ が存在するかどうかを判定し、存在するならその最小値を返す（存在しない場合は $-1$ が返る）。適切な $m$ の設定で$O(\sqrt{N})$

ただし、
- $f$ の計算は $\Theta(T)$ 時間かかるとする。
- ある自然数 $m$ ($\sqrt{N}$ 程度が好ましい) について、$f^m(x)$ も $\Theta(T)$ 時間で求められるとする。

## 参考

[250225_離散対数問題](https://acompany-ac.notion.site/250225_-1a4269d8558680a8bcbef0b561d04a41)
