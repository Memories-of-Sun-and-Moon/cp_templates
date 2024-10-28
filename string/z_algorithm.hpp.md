---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: verify/yosupo/zalgorithm.cpp
    title: verify/yosupo/zalgorithm.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/z_algorithm.hpp\"\n\nvector<int> z_algorithm(const\
    \ string &s){\n\tvector<int> z(s.size());\n\tz[0] = (int)z.size();\n\tint i =\
    \ 1, j = 0;\n\twhile(i < (int)z.size()){\n\t\twhile(i+j < (int)s.size() && s[j]\
    \ == s[i+j])j++;\n\t\tz[i] = j;\n\t\t\n\t\tif(j == 0){\n\t\t\ti++;\n\t\t\tcontinue;\n\
    \t\t}\n\t\t\n\t\tint k = 1;\n\t\twhile(k < j && k + z[k] < j){\n\t\t\tz[i+k] =\
    \ z[k];\n\t\t\tk++;\n\t\t}\n\t\ti += k;\n\t\tj -= k;\n\t}\n\treturn z;\n}\n"
  code: "\nvector<int> z_algorithm(const string &s){\n\tvector<int> z(s.size());\n\
    \tz[0] = (int)z.size();\n\tint i = 1, j = 0;\n\twhile(i < (int)z.size()){\n\t\t\
    while(i+j < (int)s.size() && s[j] == s[i+j])j++;\n\t\tz[i] = j;\n\t\t\n\t\tif(j\
    \ == 0){\n\t\t\ti++;\n\t\t\tcontinue;\n\t\t}\n\t\t\n\t\tint k = 1;\n\t\twhile(k\
    \ < j && k + z[k] < j){\n\t\t\tz[i+k] = z[k];\n\t\t\tk++;\n\t\t}\n\t\ti += k;\n\
    \t\tj -= k;\n\t}\n\treturn z;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: string/z_algorithm.hpp
  requiredBy:
  - verify/yosupo/zalgorithm.cpp
  timestamp: '2024-10-29 02:59:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/z_algorithm.hpp
layout: document
title: Z Algorithm
---

# Z Algorithm

## 使い方

- ``vector<int> z_algorithm(string s)`` : 文字列 $S$ のと、 $S$ の $i$ 文字目以降の部分文字列との高さ配列を構築する $(O\lvert S\rvert)$

## 概要

[参考](https://qiita.com/hotman78/items/b8986a23b8fdfe25c9fb#z-algorithm)
