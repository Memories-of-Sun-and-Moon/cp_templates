---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/combination.hpp
    title: "2\u9805\u4FC2\u6570mod"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo/convolution_mod.test.cpp
    title: verify/yosupo/convolution_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yukicoder/2219.test.cpp
    title: verify/yukicoder/2219.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/modint.hpp\"\n\ntemplate <std::uint_fast64_t Modulus>\
    \ class modint {\n\tusing u64 = std::uint_fast64_t;\npublic:\n\tu64 a;\n\tconstexpr\
    \ modint(const u64 x = 0) noexcept : a(x % Modulus) {}\n\tconstexpr u64 &value()\
    \ noexcept { return a; }\n\tconstexpr const u64 &value() const noexcept { return\
    \ a; }\n\tconstexpr modint operator+(const modint rhs) const noexcept {\n\t\t\
    return modint(*this) += rhs;\n\t}\n\tconstexpr modint operator-(const modint rhs)\
    \ const noexcept {\n\t\treturn modint(*this) -= rhs;\n\t}\n\tconstexpr modint\
    \ operator*(const modint rhs) const noexcept {\n    \treturn modint(*this) *=\
    \ rhs;\n\t}\n\tconstexpr modint operator/(const modint rhs) const noexcept {\n\
    \t\treturn modint(*this) /= rhs;\n\t}\n\tconstexpr modint &operator+=(const modint\
    \ rhs) noexcept {\n\t\ta += rhs.a;\n\t\tif (a >= Modulus) {\n\t\t\ta -= Modulus;\n\
    \t\t}\n    \treturn *this;\n\t}\n\tconstexpr modint &operator-=(const modint rhs)\
    \ noexcept {\n\t\tif (a < rhs.a) {\n\t\t\ta += Modulus;\n\t\t}\n\t\ta -= rhs.a;\n\
    \t\treturn *this;\n\t}\n\tconstexpr modint &operator*=(const modint rhs) noexcept\
    \ {\n    \ta = a * rhs.a % Modulus;\n    \treturn *this;\n\t}\n\tconstexpr modint\
    \ &operator/=(modint rhs) noexcept {\n\t\tu64 exp = Modulus - 2;\n\t\twhile (exp)\
    \ {\n\t\t\tif (exp % 2) {\n\t\t\t\t*this *= rhs;\n\t\t\t}\n\t\t\trhs *= rhs;\n\
    \t\t\texp /= 2;\n\t\t}\n    \treturn *this;\n\t}\n\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const modint& rhs) {\n        os << rhs.a;\n        return os;\n    }\n\
    };\n"
  code: "\ntemplate <std::uint_fast64_t Modulus> class modint {\n\tusing u64 = std::uint_fast64_t;\n\
    public:\n\tu64 a;\n\tconstexpr modint(const u64 x = 0) noexcept : a(x % Modulus)\
    \ {}\n\tconstexpr u64 &value() noexcept { return a; }\n\tconstexpr const u64 &value()\
    \ const noexcept { return a; }\n\tconstexpr modint operator+(const modint rhs)\
    \ const noexcept {\n\t\treturn modint(*this) += rhs;\n\t}\n\tconstexpr modint\
    \ operator-(const modint rhs) const noexcept {\n\t\treturn modint(*this) -= rhs;\n\
    \t}\n\tconstexpr modint operator*(const modint rhs) const noexcept {\n    \treturn\
    \ modint(*this) *= rhs;\n\t}\n\tconstexpr modint operator/(const modint rhs) const\
    \ noexcept {\n\t\treturn modint(*this) /= rhs;\n\t}\n\tconstexpr modint &operator+=(const\
    \ modint rhs) noexcept {\n\t\ta += rhs.a;\n\t\tif (a >= Modulus) {\n\t\t\ta -=\
    \ Modulus;\n\t\t}\n    \treturn *this;\n\t}\n\tconstexpr modint &operator-=(const\
    \ modint rhs) noexcept {\n\t\tif (a < rhs.a) {\n\t\t\ta += Modulus;\n\t\t}\n\t\
    \ta -= rhs.a;\n\t\treturn *this;\n\t}\n\tconstexpr modint &operator*=(const modint\
    \ rhs) noexcept {\n    \ta = a * rhs.a % Modulus;\n    \treturn *this;\n\t}\n\t\
    constexpr modint &operator/=(modint rhs) noexcept {\n\t\tu64 exp = Modulus - 2;\n\
    \t\twhile (exp) {\n\t\t\tif (exp % 2) {\n\t\t\t\t*this *= rhs;\n\t\t\t}\n\t\t\t\
    rhs *= rhs;\n\t\t\texp /= 2;\n\t\t}\n    \treturn *this;\n\t}\n\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const modint& rhs) {\n        os << rhs.a;\n  \
    \      return os;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/modint.hpp
  requiredBy:
  - math/combination.hpp
  timestamp: '2024-06-04 18:16:03+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/yukicoder/2219.test.cpp
  - verify/yosupo/convolution_mod.test.cpp
documentation_of: math/modint.hpp
layout: document
title: modint
---

# modint

## 使い方

$p$ を法として

- ``modint<p> x`` : modint型の x を定義する

大体の演算をサポートしている

## 概要

[noshiさんの実装](https://noshi91.hatenablog.com/entry/2019/03/31/174006)を大いに参考にしている
