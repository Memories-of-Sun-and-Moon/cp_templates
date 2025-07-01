---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://qiita.com/mdstoy/items/39104b686540c5f1dc6c
  bundledCode: "#line 2 \"z_other/next_combination.hpp\"\n\n#include<algorithm>\n\
    #include<iterator>\n\n// https://qiita.com/mdstoy/items/39104b686540c5f1dc6c\n\
    template <typename T> bool next_combination(const T first, const T last, int k)\
    \ {\n\tconst T subset = first + k;\n\t// empty container | k = 0 | k == n \n\t\
    if (first == last || first == subset || last == subset) {\n\t\treturn false;\n\
    \t}\n\tT src = subset;\n\twhile (first != src) {\n\t\tsrc--;\n\t\tif (*src < *(last\
    \ - 1)) {\n\t\t\tT dest = subset;\n\t\t\twhile (*src >= *dest) {\n\t\t\t\tdest++;\n\
    \t\t\t}\n\t\t\titer_swap(src, dest);\n\t\t\trotate(src + 1, dest + 1, last);\n\
    \t\t\trotate(subset, subset + (last - dest) - 1, last);\n\t\t\treturn true;\n\t\
    \t}\n\t}\n\t// restore\n\trotate(first, subset, last);\n\treturn false;\n}\n\n"
  code: "#pragma once\n\n#include<algorithm>\n#include<iterator>\n\n// https://qiita.com/mdstoy/items/39104b686540c5f1dc6c\n\
    template <typename T> bool next_combination(const T first, const T last, int k)\
    \ {\n\tconst T subset = first + k;\n\t// empty container | k = 0 | k == n \n\t\
    if (first == last || first == subset || last == subset) {\n\t\treturn false;\n\
    \t}\n\tT src = subset;\n\twhile (first != src) {\n\t\tsrc--;\n\t\tif (*src < *(last\
    \ - 1)) {\n\t\t\tT dest = subset;\n\t\t\twhile (*src >= *dest) {\n\t\t\t\tdest++;\n\
    \t\t\t}\n\t\t\titer_swap(src, dest);\n\t\t\trotate(src + 1, dest + 1, last);\n\
    \t\t\trotate(subset, subset + (last - dest) - 1, last);\n\t\t\treturn true;\n\t\
    \t}\n\t}\n\t// restore\n\trotate(first, subset, last);\n\treturn false;\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: z_other/next_combination.hpp
  requiredBy: []
  timestamp: '2025-07-01 03:22:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: z_other/next_combination.hpp
layout: document
title: next_combination
---

# next_combination 

## 使い方

``next_combination(T first, T last, int k)`` : イテレータの $[first, last)$ 間の上位 $k$ 個について、 $nCk$ の全ての組み合わせを順に返す。 

