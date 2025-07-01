---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/dpl/1_D.test.cpp
    title: verify/aoj/dpl/1_D.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"z_other/longest_increasing_subsequences.hpp\"\n\n#include<algorithm>\n\
    #include<vector>\n\ntemplate <bool is_strict, class T>\nint longest_increasing_subsequences(const\
    \ std::vector<T>& v){\n\tstd::vector<T> dp;\n\n\tauto it = dp.begin();\n\n\tfor(auto\
    \ elem : v){\n\t\tif constexpr (is_strict){\n\t\t\tit = std::lower_bound(dp.begin(),\
    \ dp.end(), elem);\n\t\t}else{\n\t\t\tit = std::upper_bound(dp.begin(), dp.end(),\
    \ elem);\n\t\t}\n\t\tif(it == dp.end()){\n\t\t\tdp.push_back(elem);\n\t\t}else{\n\
    \t\t\t*it = elem;\n\t\t}\n\t}\n\n\treturn int(dp.size());\n}\n\n"
  code: "#pragma once\n\n#include<algorithm>\n#include<vector>\n\ntemplate <bool is_strict,\
    \ class T>\nint longest_increasing_subsequences(const std::vector<T>& v){\n\t\
    std::vector<T> dp;\n\n\tauto it = dp.begin();\n\n\tfor(auto elem : v){\n\t\tif\
    \ constexpr (is_strict){\n\t\t\tit = std::lower_bound(dp.begin(), dp.end(), elem);\n\
    \t\t}else{\n\t\t\tit = std::upper_bound(dp.begin(), dp.end(), elem);\n\t\t}\n\t\
    \tif(it == dp.end()){\n\t\t\tdp.push_back(elem);\n\t\t}else{\n\t\t\t*it = elem;\n\
    \t\t}\n\t}\n\n\treturn int(dp.size());\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: z_other/longest_increasing_subsequences.hpp
  requiredBy: []
  timestamp: '2025-07-01 03:22:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/dpl/1_D.test.cpp
documentation_of: z_other/longest_increasing_subsequences.hpp
layout: document
title: LIS
---

# LIS

## 使い方

``longest_increasing_subsequences<bool is_strict, T>(vector<T> v)`` : $v$ の最長増加部分列の長さを返す。

- ``is_strict = true`` の時、狭義単調増加
- ``is_strict = false`` の時、講義単調増加
