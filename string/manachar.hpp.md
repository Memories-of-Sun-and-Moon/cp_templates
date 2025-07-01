---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo/enumerate_palindromes.test.cpp
    title: verify/yosupo/enumerate_palindromes.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/manachar.hpp\"\n\n#include<string>\n#include<vector>\n\
    \nstd::vector<int> manachar(std::string _s){\n\tstd::string t = \"\";\n\tint n\
    \ = (int)_s.size();\n\tfor(int i = 0;i < n;i++){\n\t\tif(i)t += '#';\n\t\tt +=\
    \ _s[i];\n\t}\n\tn = (int)t.size();\n\tint i = 0, j = 0;\n\tstd::vector<int> r(n);\n\
    \twhile(i < n){\n\t\twhile(i-j >= 0 && i+j < n && t[i-j] == t[i+j]) j++;\n\t\t\
    r[i] = j;\n\t\tint k = 1;\n\t\twhile(i-k >= 0 && k+r[i-k] < j) r[i+k] = r[i-k],\
    \ k++;\n\t\ti += k, j -= k;\n\t}\n\tfor(int k = 0;k < n;k++){\n\t\tif(k&1)r[k]\
    \ >>= 1;\n\t\telse r[k] = (r[k]+1) >> 1;\n\t}\n\treturn r;\n}\n\n/*\nint i = 0,\
    \ j = 0;\nwhile (i < S.size()) {\n  while (i-j >= 0 && i+j < S.size() && S[i-j]\
    \ == S[i+j]) ++j;\n  R[i] = j;\n  int k = 1;\n  while (i-k >= 0 && k+R[i-k] <\
    \ j) R[i+k] = R[i-k], ++k;\n  i += k; j -= k;\n}\n*/\n"
  code: "#pragma once\n\n#include<string>\n#include<vector>\n\nstd::vector<int> manachar(std::string\
    \ _s){\n\tstd::string t = \"\";\n\tint n = (int)_s.size();\n\tfor(int i = 0;i\
    \ < n;i++){\n\t\tif(i)t += '#';\n\t\tt += _s[i];\n\t}\n\tn = (int)t.size();\n\t\
    int i = 0, j = 0;\n\tstd::vector<int> r(n);\n\twhile(i < n){\n\t\twhile(i-j >=\
    \ 0 && i+j < n && t[i-j] == t[i+j]) j++;\n\t\tr[i] = j;\n\t\tint k = 1;\n\t\t\
    while(i-k >= 0 && k+r[i-k] < j) r[i+k] = r[i-k], k++;\n\t\ti += k, j -= k;\n\t\
    }\n\tfor(int k = 0;k < n;k++){\n\t\tif(k&1)r[k] >>= 1;\n\t\telse r[k] = (r[k]+1)\
    \ >> 1;\n\t}\n\treturn r;\n}\n\n/*\nint i = 0, j = 0;\nwhile (i < S.size()) {\n\
    \  while (i-j >= 0 && i+j < S.size() && S[i-j] == S[i+j]) ++j;\n  R[i] = j;\n\
    \  int k = 1;\n  while (i-k >= 0 && k+R[i-k] < j) R[i+k] = R[i-k], ++k;\n  i +=\
    \ k; j -= k;\n}\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: string/manachar.hpp
  requiredBy: []
  timestamp: '2025-07-01 03:22:56+09:00'
  verificationStatus: LIBRARY_ALL_WA
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
