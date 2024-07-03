---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/enumerate_palindromes.test.cpp
    title: verify/yosupo/enumerate_palindromes.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/manachar.hpp\"\n\nvector<int> manachar(string _s){\n\
    \    string t = \"\";\n    int n = (int)_s.size();\n    for(int i = 0;i < n;i++){\n\
    \        if(i)t += '#';\n        t += _s[i];\n    }\n    n = (int)t.size();\n\
    \    int i = 0, j = 0;\n    vector<int> r(n);\n    while(i < n){\n        while(i-j\
    \ >= 0 && i+j < n && t[i-j] == t[i+j]) j++;\n        r[i] = j;\n        int k\
    \ = 1;\n        while(i-k >= 0 && k+r[i-k] < j) r[i+k] = r[i-k], k++;\n      \
    \  i += k, j -= k;\n    }\n    for(int i = 0;i < n;i++){\n        if(i%2)r[i]\
    \ /= 2;\n        else r[i] = (r[i]+1)/2;\n    }\n    return r;\n}\n\n/*\nint i\
    \ = 0, j = 0;\nwhile (i < S.size()) {\n  while (i-j >= 0 && i+j < S.size() &&\
    \ S[i-j] == S[i+j]) ++j;\n  R[i] = j;\n  int k = 1;\n  while (i-k >= 0 && k+R[i-k]\
    \ < j) R[i+k] = R[i-k], ++k;\n  i += k; j -= k;\n}\n*/\n"
  code: "\nvector<int> manachar(string _s){\n    string t = \"\";\n    int n = (int)_s.size();\n\
    \    for(int i = 0;i < n;i++){\n        if(i)t += '#';\n        t += _s[i];\n\
    \    }\n    n = (int)t.size();\n    int i = 0, j = 0;\n    vector<int> r(n);\n\
    \    while(i < n){\n        while(i-j >= 0 && i+j < n && t[i-j] == t[i+j]) j++;\n\
    \        r[i] = j;\n        int k = 1;\n        while(i-k >= 0 && k+r[i-k] < j)\
    \ r[i+k] = r[i-k], k++;\n        i += k, j -= k;\n    }\n    for(int i = 0;i <\
    \ n;i++){\n        if(i%2)r[i] /= 2;\n        else r[i] = (r[i]+1)/2;\n    }\n\
    \    return r;\n}\n\n/*\nint i = 0, j = 0;\nwhile (i < S.size()) {\n  while (i-j\
    \ >= 0 && i+j < S.size() && S[i-j] == S[i+j]) ++j;\n  R[i] = j;\n  int k = 1;\n\
    \  while (i-k >= 0 && k+R[i-k] < j) R[i+k] = R[i-k], ++k;\n  i += k; j -= k;\n\
    }\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: string/manachar.hpp
  requiredBy: []
  timestamp: '2024-07-03 19:31:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/enumerate_palindromes.test.cpp
documentation_of: string/manachar.hpp
layout: document
title: manachar
---

# manachar

## 使い方

**0-indexed** で表す。

- ``vector<int>manachar(string s)`` : 文字列 $S$ の
  - 奇数番目 : $S_{i/2}, S_{i/2+1}$ の間を中心とした回文の半径
  - 偶数番目 : $S_{i/2}$ を中心とした回文の半径（自身を含む）
- を求めた長さ $2n-1$ の配列を返す $O(\lvert S \rvert)$
