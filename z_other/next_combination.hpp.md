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
  bundledCode: "#line 1 \"z_other/next_combination.hpp\"\n\n// https://qiita.com/mdstoy/items/39104b686540c5f1dc6c\n\
    template <typename T> bool next_combination(const T first, const T last, int k)\
    \ {\n    const T subset = first + k;\n    // empty container | k = 0 | k == n\
    \ \n    if (first == last || first == subset || last == subset) {\n        return\
    \ false;\n    }\n    T src = subset;\n    while (first != src) {\n        src--;\n\
    \        if (*src < *(last - 1)) {\n            T dest = subset;\n           \
    \ while (*src >= *dest) {\n                dest++;\n            }\n          \
    \  iter_swap(src, dest);\n            rotate(src + 1, dest + 1, last);\n     \
    \       rotate(subset, subset + (last - dest) - 1, last);\n            return\
    \ true;\n        }\n    }\n    // restore\n    rotate(first, subset, last);\n\
    \    return false;\n}\n\n"
  code: "\n// https://qiita.com/mdstoy/items/39104b686540c5f1dc6c\ntemplate <typename\
    \ T> bool next_combination(const T first, const T last, int k) {\n    const T\
    \ subset = first + k;\n    // empty container | k = 0 | k == n \n    if (first\
    \ == last || first == subset || last == subset) {\n        return false;\n   \
    \ }\n    T src = subset;\n    while (first != src) {\n        src--;\n       \
    \ if (*src < *(last - 1)) {\n            T dest = subset;\n            while (*src\
    \ >= *dest) {\n                dest++;\n            }\n            iter_swap(src,\
    \ dest);\n            rotate(src + 1, dest + 1, last);\n            rotate(subset,\
    \ subset + (last - dest) - 1, last);\n            return true;\n        }\n  \
    \  }\n    // restore\n    rotate(first, subset, last);\n    return false;\n}\n\
    \n"
  dependsOn: []
  isVerificationFile: false
  path: z_other/next_combination.hpp
  requiredBy: []
  timestamp: '2024-10-03 17:27:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: z_other/next_combination.hpp
layout: document
title: next_combination
---

# next_combination 

## 使い方

``next_combination(T first, T last, int k)`` : イテレータの $[first, last)$ 間の上位 $k$ 個について、 $nCk$ の全ての組み合わせを順に返す。 

