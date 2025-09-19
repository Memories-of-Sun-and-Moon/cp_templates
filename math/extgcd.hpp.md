---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/id/3362.test.cpp
    title: verify/aoj/id/3362.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj/ntl/1_E.test.cpp
    title: verify/aoj/ntl/1_E.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/extgcd.hpp\"\n\ntemplate<typename T>\nT extgcd(T a,\
    \ T b, T &x, T &y){\n\tT d = a;\n\tif(b != 0){\n\t\td = extgcd(b, a%b, y, x);\n\
    \t\ty -= (a/b) * x;\n\t}else{\n\t\tx = 1;\n\t\ty = 0;\n\t}\n\treturn d;\n}\n"
  code: "\ntemplate<typename T>\nT extgcd(T a, T b, T &x, T &y){\n\tT d = a;\n\tif(b\
    \ != 0){\n\t\td = extgcd(b, a%b, y, x);\n\t\ty -= (a/b) * x;\n\t}else{\n\t\tx\
    \ = 1;\n\t\ty = 0;\n\t}\n\treturn d;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/extgcd.hpp
  requiredBy: []
  timestamp: '2025-05-27 00:04:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/ntl/1_E.test.cpp
  - verify/aoj/id/3362.test.cpp
documentation_of: math/extgcd.hpp
layout: document
title: "\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5"
---

# 拡張ユークリッドの互除法

## 使い方

``extgcd(T a, T b, T &x, T &y)`` : $ax + by = \text{gcd}(a, b)$ なる $x, y$ を求める。$O(\log{a+b})$ 程度
