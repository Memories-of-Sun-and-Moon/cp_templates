---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/id/1642.test.cpp
    title: verify/aoj/id/1642.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/enumerate_divisors.hpp\"\n\n#include<algorithm>\n#include<vector>\n\
    \ntemplate<typename T>\nstd::vector<T> enumerate_divisors(T n) {\n\tstd::vector<T>\
    \ ret = {1};\n\n\tlong long mul = -1;\n\tlong long pre = -1;\n\tint size_before\
    \ = 1;\n\n\tfor(auto p : factor(n)){\n\t\tmul = (p == pre ? mul*p : p);\n\t\t\
    int sz = (p == pre ? size_before : std::ssize(ret));\n\t\tfor(int i = 0;i < sz;i++){\n\
    \t\t\tret.emplace_back(ret[i] * mul);\n\t\t}\n\t\tpre = p;\n\t\tsize_before =\
    \ sz;\n\t}\n\tstd::sort(ret.begin(), ret.end());\n\treturn ret;\n}\n"
  code: "#pragma once\n\n#include<algorithm>\n#include<vector>\n\ntemplate<typename\
    \ T>\nstd::vector<T> enumerate_divisors(T n) {\n\tstd::vector<T> ret = {1};\n\n\
    \tlong long mul = -1;\n\tlong long pre = -1;\n\tint size_before = 1;\n\n\tfor(auto\
    \ p : factor(n)){\n\t\tmul = (p == pre ? mul*p : p);\n\t\tint sz = (p == pre ?\
    \ size_before : std::ssize(ret));\n\t\tfor(int i = 0;i < sz;i++){\n\t\t\tret.emplace_back(ret[i]\
    \ * mul);\n\t\t}\n\t\tpre = p;\n\t\tsize_before = sz;\n\t}\n\tstd::sort(ret.begin(),\
    \ ret.end());\n\treturn ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/enumerate_divisors.hpp
  requiredBy: []
  timestamp: '2025-07-01 22:36:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/id/1642.test.cpp
documentation_of: math/enumerate_divisors.hpp
layout: document
title: "\u7D04\u6570\u5217\u6319"
---

# 約数列挙

## 使い方

- ``vector<T> enumerate_divisors(T n)`` : $n$ の約数を昇順に列挙したものを返す。素因数分解の計算量を $O(\alpha)$ として、 $O(\alpha + \log(n))$
