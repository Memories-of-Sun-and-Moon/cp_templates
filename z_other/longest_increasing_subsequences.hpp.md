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
  bundledCode: "#line 1 \"z_other/longest_increasing_subsequences.hpp\"\ntemplate\
    \ <bool is_strict, class T>\nint longest_increasing_subsequences(const vector<T>&\
    \ v){\n    vector<T> dp;\n\n    auto it = dp.begin();\n\n    for(auto elem : v){\n\
    \        if constexpr (is_strict){\n            it = lower_bound(dp.begin(), dp.end(),\
    \ elem);\n        }else{\n            it = upper_bound(dp.begin(), dp.end(), elem);\n\
    \        }\n        if(it == dp.end()){\n            dp.push_back(elem);\n   \
    \     }else{\n            *it = elem;\n        }\n    }\n\n    return int(dp.size());\n\
    }\n\n"
  code: "template <bool is_strict, class T>\nint longest_increasing_subsequences(const\
    \ vector<T>& v){\n    vector<T> dp;\n\n    auto it = dp.begin();\n\n    for(auto\
    \ elem : v){\n        if constexpr (is_strict){\n            it = lower_bound(dp.begin(),\
    \ dp.end(), elem);\n        }else{\n            it = upper_bound(dp.begin(), dp.end(),\
    \ elem);\n        }\n        if(it == dp.end()){\n            dp.push_back(elem);\n\
    \        }else{\n            *it = elem;\n        }\n    }\n\n    return int(dp.size());\n\
    }\n\n"
  dependsOn: []
  isVerificationFile: false
  path: z_other/longest_increasing_subsequences.hpp
  requiredBy: []
  timestamp: '2024-07-01 17:44:46+09:00'
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
