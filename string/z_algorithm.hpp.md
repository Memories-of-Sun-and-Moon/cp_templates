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
    \ string &s){\n    vector<int> z(s.size());\n    z[0] = (int)z.size();\n    int\
    \ i = 1, j = 0;\n    while(i < (int)z.size()){\n        while(i+j < (int)s.size()\
    \ && s[j] == s[i+j])j++;\n        z[i] = j;\n        \n        if(j == 0){\n \
    \           i++;\n            continue;\n        }\n        \n        int k =\
    \ 1;\n        while(k < j && k + z[k] < j){\n            z[i+k] = z[k];\n    \
    \        k++;\n        }\n        i += k;\n        j -= k;\n    }\n    return\
    \ z;\n}\n"
  code: "\nvector<int> z_algorithm(const string &s){\n    vector<int> z(s.size());\n\
    \    z[0] = (int)z.size();\n    int i = 1, j = 0;\n    while(i < (int)z.size()){\n\
    \        while(i+j < (int)s.size() && s[j] == s[i+j])j++;\n        z[i] = j;\n\
    \        \n        if(j == 0){\n            i++;\n            continue;\n    \
    \    }\n        \n        int k = 1;\n        while(k < j && k + z[k] < j){\n\
    \            z[i+k] = z[k];\n            k++;\n        }\n        i += k;\n  \
    \      j -= k;\n    }\n    return z;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: string/z_algorithm.hpp
  requiredBy:
  - verify/yosupo/zalgorithm.cpp
  timestamp: '2024-06-20 13:02:36+09:00'
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
