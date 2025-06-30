---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/alds1/14_B.test.cpp
    title: verify/aoj/alds1/14_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/rolling_hash.hpp\"\n\n#include<string>\n#include<vector>\n\
    \nstruct rolling_hash {\n\tusing ull = unsigned long long;\n\n\tconst ull MASK30\
    \ = (1UL << 30) - 1;\n\tconst ull MASK31 = (1UL << 31) - 1;\n\tconst ull MOD =\
    \ (1UL << 61) - 1;\n\tconst ull MASK61 = MOD;\n\tconst ull POSITIVIZER = MOD *\
    \ ((1UL << 3) - 1);\n\n\tstd::string s;\n\tint n;\n\tconst ull bs = 23948798;\n\
    \n\tstd::vector<ull> base_pow;\n\tstd::vector<ull> prefix_hash;\n\n\trolling_hash(std::string\
    \ _s){\n\t\ts = _s;\n\t\tn = int(s.size());\n\t\tbase_pow.resize(n + 1);\n\t\t\
    base_pow[0] = 1;\n\t\tfor(int i = 0;i < n;i++){\n\t\t\tbase_pow[i + 1] = calcmod(mul(base_pow[i],\
    \ bs));\n\t\t}\t\n\n\t\tprefix_hash.resize(n + 1, 0LL);\n\t\tfor(int i = 0;i <\
    \ n;i++){\n\t\t\tprefix_hash[i + 1] = calcmod(mul(prefix_hash[i], bs) + s[i]);\t\
    \n\t\t}\n\t}\n\n\tull slice(int begin, int length){\n\t\treturn calcmod(prefix_hash[begin\
    \ + length] + POSITIVIZER - mul(prefix_hash[begin], base_pow[length]));\n\t}\n\
    \n\t//a * b % mod (2^{61} - 1)\n\tull mul(ull a, ull b){\n\t\tull au = a >> 31;\n\
    \t\tull ad = a & MASK31;\n\t\tull bu = b >> 31;\n\t\tull bd = b & MASK31;\n\t\t\
    ull mid = ad * bu + au * bd;\n\t\tull midu = mid >> 30;\n\t\tull midd = mid &\
    \ MASK30;\n\t\treturn calcmod(au * bu * 2 + midu + (midd << 31) + ad * bd);\n\t\
    }\n\n\t// mod(2^{61} - 1)\n\tull calcmod(ull x){\n\t\tull xu = x >> 61;\n\t\t\
    ull xd = x & MASK61;\n\t\tull res = xu + xd;\n\t\tif (res >= MOD) res -= MOD;\n\
    \t\treturn res;\n\t}\n};\n"
  code: "\n#include<string>\n#include<vector>\n\nstruct rolling_hash {\n\tusing ull\
    \ = unsigned long long;\n\n\tconst ull MASK30 = (1UL << 30) - 1;\n\tconst ull\
    \ MASK31 = (1UL << 31) - 1;\n\tconst ull MOD = (1UL << 61) - 1;\n\tconst ull MASK61\
    \ = MOD;\n\tconst ull POSITIVIZER = MOD * ((1UL << 3) - 1);\n\n\tstd::string s;\n\
    \tint n;\n\tconst ull bs = 23948798;\n\n\tstd::vector<ull> base_pow;\n\tstd::vector<ull>\
    \ prefix_hash;\n\n\trolling_hash(std::string _s){\n\t\ts = _s;\n\t\tn = int(s.size());\n\
    \t\tbase_pow.resize(n + 1);\n\t\tbase_pow[0] = 1;\n\t\tfor(int i = 0;i < n;i++){\n\
    \t\t\tbase_pow[i + 1] = calcmod(mul(base_pow[i], bs));\n\t\t}\t\n\n\t\tprefix_hash.resize(n\
    \ + 1, 0LL);\n\t\tfor(int i = 0;i < n;i++){\n\t\t\tprefix_hash[i + 1] = calcmod(mul(prefix_hash[i],\
    \ bs) + s[i]);\t\n\t\t}\n\t}\n\n\tull slice(int begin, int length){\n\t\treturn\
    \ calcmod(prefix_hash[begin + length] + POSITIVIZER - mul(prefix_hash[begin],\
    \ base_pow[length]));\n\t}\n\n\t//a * b % mod (2^{61} - 1)\n\tull mul(ull a, ull\
    \ b){\n\t\tull au = a >> 31;\n\t\tull ad = a & MASK31;\n\t\tull bu = b >> 31;\n\
    \t\tull bd = b & MASK31;\n\t\tull mid = ad * bu + au * bd;\n\t\tull midu = mid\
    \ >> 30;\n\t\tull midd = mid & MASK30;\n\t\treturn calcmod(au * bu * 2 + midu\
    \ + (midd << 31) + ad * bd);\n\t}\n\n\t// mod(2^{61} - 1)\n\tull calcmod(ull x){\n\
    \t\tull xu = x >> 61;\n\t\tull xd = x & MASK61;\n\t\tull res = xu + xd;\n\t\t\
    if (res >= MOD) res -= MOD;\n\t\treturn res;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: string/rolling_hash.hpp
  requiredBy: []
  timestamp: '2025-07-01 01:51:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/alds1/14_B.test.cpp
documentation_of: string/rolling_hash.hpp
layout: document
title: "\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5"
---

# ローリングハッシュ

## 使い方

添え字は **0-indexed** であることに注意。

- ``rolling_hash(string s)`` : $s$ のハッシュ値の前計算を行う $O(\lvert s \rvert)$
- ``ull slice(int begin, int length)`` : $s$ の $begin$ 文字目から $length$ 文字のハッシュを返す。

## 概要

[参考](https://qiita.com/keymoon/items/11fac5627672a6d6a9f6)

MOD $2^{61}-1$ を採用している。MOD をランダムにしていないため、文字列の統合等をしなくとも、文字長が同じであれば一致判定を行うことができる。
