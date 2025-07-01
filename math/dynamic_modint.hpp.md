---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yukicoder/3187.test.cpp
    title: verify/yukicoder/3187.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/dynamic_modint.hpp\"\n\n#include<cstdint>\n#include<iostream>\n\
    \nclass dynamic_modint {\n\tusing u64 = std::uint_fast64_t;\n\tstatic u64 Modulus;\n\
    public:\n\tu64 a;\n\tstatic void set_mod(u64 m) { Modulus = m; }\n\n\tu64 &value()\
    \ { return a; }\n\tdynamic_modint(u64 x = 0) : a(x % Modulus) {}\n\tdynamic_modint\
    \ operator+(const dynamic_modint rhs) const {\n\t\treturn dynamic_modint(*this)\
    \ += rhs;\n\t}\n\tdynamic_modint operator-(const dynamic_modint rhs) const {\n\
    \t\treturn dynamic_modint(*this) -= rhs;\n\t}\n\tdynamic_modint operator*(const\
    \ dynamic_modint rhs) const {\n\t\treturn dynamic_modint(*this) *= rhs;\n\t}\n\
    \tdynamic_modint operator/(const dynamic_modint rhs) const {\n\t\treturn dynamic_modint(*this)\
    \ /= rhs;\n\t}\n\tdynamic_modint &operator+=(const dynamic_modint rhs) {\n\t\t\
    a += rhs.a;\n\t\tif (a >= Modulus) {\n\t\t\ta -= Modulus;\n\t\t}\n\t\treturn *this;\n\
    \t}\n\tdynamic_modint &operator-=(const dynamic_modint rhs) {\n\t\tif (a < rhs.a)\
    \ {\n\t\t\ta += Modulus;\n\t\t}\n\t\ta -= rhs.a;\n\t\treturn *this;\n\t}\n\tdynamic_modint\
    \ &operator*=(const dynamic_modint rhs) {\n\t\ta = a * rhs.a % Modulus;\n\t\t\
    return *this;\n\t}\n\tdynamic_modint &operator/=(dynamic_modint rhs) {\n\t\tu64\
    \ exp = Modulus - 2;\n\t\twhile (exp) {\n\t\t\tif (exp % 2) {\n\t\t\t\t*this *=\
    \ rhs;\n\t\t\t}\n\t\t\trhs *= rhs;\n\t\t\texp /= 2;\n\t\t}\n\t\treturn *this;\n\
    \t}\n\n\tfriend std::ostream& operator<<(std::ostream& os, const dynamic_modint&\
    \ rhs) {\n\t\tos << rhs.a;\n\t\treturn os;\n\t}\n};\n\ninline dynamic_modint::u64\
    \ dynamic_modint::Modulus = 1;\n"
  code: "#pragma once\n\n#include<cstdint>\n#include<iostream>\n\nclass dynamic_modint\
    \ {\n\tusing u64 = std::uint_fast64_t;\n\tstatic u64 Modulus;\npublic:\n\tu64\
    \ a;\n\tstatic void set_mod(u64 m) { Modulus = m; }\n\n\tu64 &value() { return\
    \ a; }\n\tdynamic_modint(u64 x = 0) : a(x % Modulus) {}\n\tdynamic_modint operator+(const\
    \ dynamic_modint rhs) const {\n\t\treturn dynamic_modint(*this) += rhs;\n\t}\n\
    \tdynamic_modint operator-(const dynamic_modint rhs) const {\n\t\treturn dynamic_modint(*this)\
    \ -= rhs;\n\t}\n\tdynamic_modint operator*(const dynamic_modint rhs) const {\n\
    \t\treturn dynamic_modint(*this) *= rhs;\n\t}\n\tdynamic_modint operator/(const\
    \ dynamic_modint rhs) const {\n\t\treturn dynamic_modint(*this) /= rhs;\n\t}\n\
    \tdynamic_modint &operator+=(const dynamic_modint rhs) {\n\t\ta += rhs.a;\n\t\t\
    if (a >= Modulus) {\n\t\t\ta -= Modulus;\n\t\t}\n\t\treturn *this;\n\t}\n\tdynamic_modint\
    \ &operator-=(const dynamic_modint rhs) {\n\t\tif (a < rhs.a) {\n\t\t\ta += Modulus;\n\
    \t\t}\n\t\ta -= rhs.a;\n\t\treturn *this;\n\t}\n\tdynamic_modint &operator*=(const\
    \ dynamic_modint rhs) {\n\t\ta = a * rhs.a % Modulus;\n\t\treturn *this;\n\t}\n\
    \tdynamic_modint &operator/=(dynamic_modint rhs) {\n\t\tu64 exp = Modulus - 2;\n\
    \t\twhile (exp) {\n\t\t\tif (exp % 2) {\n\t\t\t\t*this *= rhs;\n\t\t\t}\n\t\t\t\
    rhs *= rhs;\n\t\t\texp /= 2;\n\t\t}\n\t\treturn *this;\n\t}\n\n\tfriend std::ostream&\
    \ operator<<(std::ostream& os, const dynamic_modint& rhs) {\n\t\tos << rhs.a;\n\
    \t\treturn os;\n\t}\n};\n\ninline dynamic_modint::u64 dynamic_modint::Modulus\
    \ = 1;\n"
  dependsOn: []
  isVerificationFile: false
  path: math/dynamic_modint.hpp
  requiredBy: []
  timestamp: '2025-07-01 03:22:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yukicoder/3187.test.cpp
documentation_of: math/dynamic_modint.hpp
layout: document
title: "\u4EFB\u610F modint \u578B"
---

# 任意 modint 型

## 使い方

``dynamic_modint::set_mod(u64 p)`` : $p$ を法とする modint 型を定義する

後は modint と同じ

大体の演算をサポートしている

## 概要

[noshiさんの実装](https://noshi91.hatenablog.com/entry/2019/03/31/174006)を大いに参考にしている
