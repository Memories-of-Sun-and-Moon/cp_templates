---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/associative_array.test.cpp
    title: verify/yosupo/associative_array.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yukicoder/8016.test.cpp
    title: verify/yukicoder/8016.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/hash_map.hpp\"\n\n#include<bitset>\n#include<cstdint>\n\
    \ntemplate<typename Key, typename Val, uint32_t N, typename HashFunc = std::hash<Key>>\n\
    struct hash_map {\n\tstatic_assert(__builtin_popcount(N) == 1);\n\tKey key[N];\n\
    \tVal val[N];\n\tstd::bitset<N> use;\n\t\n\tstatic constexpr uint32_t shift =\
    \ 64 - __builtin_ctz(N);\n\tstatic constexpr uint64_t r = 11995408973635179863ULL;\n\
    \n\tVal& operator[](const Key & k) noexcept {\n\t\tuint64_t h = HashFunc{}(k);\n\
    \t\tuint32_t hash = (h*r) >> shift;\n\t\twhile(true){\n\t\t\tif(!use[hash]){\n\
    \t\t\t\tkey[hash] = k;\n\t\t\t\tuse[hash] = 1;\n\t\t\t\treturn val[hash];\n\t\t\
    \t}\n\t\t\tif(key[hash] == k)return val[hash];\n\t\t\t(++hash) &= (N-1);\n\t\t\
    }\n\t}\n};\n"
  code: "#pragma once\n\n#include<bitset>\n#include<cstdint>\n\ntemplate<typename\
    \ Key, typename Val, uint32_t N, typename HashFunc = std::hash<Key>>\nstruct hash_map\
    \ {\n\tstatic_assert(__builtin_popcount(N) == 1);\n\tKey key[N];\n\tVal val[N];\n\
    \tstd::bitset<N> use;\n\t\n\tstatic constexpr uint32_t shift = 64 - __builtin_ctz(N);\n\
    \tstatic constexpr uint64_t r = 11995408973635179863ULL;\n\n\tVal& operator[](const\
    \ Key & k) noexcept {\n\t\tuint64_t h = HashFunc{}(k);\n\t\tuint32_t hash = (h*r)\
    \ >> shift;\n\t\twhile(true){\n\t\t\tif(!use[hash]){\n\t\t\t\tkey[hash] = k;\n\
    \t\t\t\tuse[hash] = 1;\n\t\t\t\treturn val[hash];\n\t\t\t}\n\t\t\tif(key[hash]\
    \ == k)return val[hash];\n\t\t\t(++hash) &= (N-1);\n\t\t}\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/hash_map.hpp
  requiredBy: []
  timestamp: '2025-07-01 03:22:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/associative_array.test.cpp
  - verify/yukicoder/8016.test.cpp
documentation_of: data_structure/hash_map.hpp
layout: document
title: "\u30CF\u30C3\u30B7\u30E5\u30DE\u30C3\u30D7"
---

# ハッシュマップ

## 使い方

``hash_map<Key, Val, N, HashFunc>`` : $N$ 程度の種類を格納できるハッシュマップを用意。
1. $N$ は格納予定の量の $2$ 倍程度とするとよさそう
2. ハッシュ関数が無い型を使うときは HashFunc を定義する

## 概要

``unordered_map`` の代用
