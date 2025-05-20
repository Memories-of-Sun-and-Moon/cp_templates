---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/modint.hpp
    title: modint
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/combination.hpp\"\n\n#line 1 \"math/modint.hpp\"\n\n\
    template <std::uint_fast64_t Modulus> class modint {\n\tusing u64 = std::uint_fast64_t;\n\
    public:\n\tu64 a;\n\tconstexpr modint(const u64 x = 0) noexcept : a(x % Modulus)\
    \ {}\n\tconstexpr u64 &value() noexcept { return a; }\n\tconstexpr const u64 &value()\
    \ const noexcept { return a; }\n\tconstexpr modint operator+(const modint rhs)\
    \ const noexcept {\n\t\treturn modint(*this) += rhs;\n\t}\n\tconstexpr modint\
    \ operator-(const modint rhs) const noexcept {\n\t\treturn modint(*this) -= rhs;\n\
    \t}\n\tconstexpr modint operator*(const modint rhs) const noexcept {\n\t\treturn\
    \ modint(*this) *= rhs;\n\t}\n\tconstexpr modint operator/(const modint rhs) const\
    \ noexcept {\n\t\treturn modint(*this) /= rhs;\n\t}\n\tconstexpr modint &operator+=(const\
    \ modint rhs) noexcept {\n\t\ta += rhs.a;\n\t\tif (a >= Modulus) {\n\t\t\ta -=\
    \ Modulus;\n\t\t}\n\t\treturn *this;\n\t}\n\tconstexpr modint &operator-=(const\
    \ modint rhs) noexcept {\n\t\tif (a < rhs.a) {\n\t\t\ta += Modulus;\n\t\t}\n\t\
    \ta -= rhs.a;\n\t\treturn *this;\n\t}\n\tconstexpr modint &operator*=(const modint\
    \ rhs) noexcept {\n\t\ta = a * rhs.a % Modulus;\n\t\treturn *this;\n\t}\n\tconstexpr\
    \ modint &operator/=(modint rhs) noexcept {\n\t\tu64 exp = Modulus - 2;\n\t\t\
    while (exp) {\n\t\t\tif (exp % 2) {\n\t\t\t\t*this *= rhs;\n\t\t\t}\n\t\t\trhs\
    \ *= rhs;\n\t\t\texp /= 2;\n\t\t}\n\t\treturn *this;\n\t}\n\n\tfriend std::ostream&\
    \ operator<<(std::ostream& os, const modint& rhs) {\n\t\tos << rhs.a;\n\t\treturn\
    \ os;\n\t}\n};\n#line 3 \"math/combination.hpp\"\n\nconstexpr int max_combination\
    \ = 1010101;\ntemplate<typename T>\nstruct binomial {\n\n\tvector<T> fact, inv_fact;\n\
    \n\tbinomial(){\n\t\tfact.resize(max_combination);\n\t\tinv_fact.resize(max_combination);\n\
    \t\tfact[0] = 1, inv_fact[0] = 1;\n\t\tfor(int i = 1;i < max_combination;i++){\n\
    \t\t\tfact[i] = fact[i - 1];\n\t\t\tfact[i] *= i;\n\t\t\tinv_fact[i] = inv_fact[i\
    \ - 1];\n\t\t\tinv_fact[i] /= i;\n\t\t}\n\t}\n\n\tT nCr(int n, int r){\n\t\tif(r\
    \ < 0 || r > n)return 0;\n\n\t\tmodint ret = fact[n];\n\t\tret *= inv_fact[r];\n\
    \t\tret *= inv_fact[n - r];\n\n\t\treturn ret;\n\t}\n};\n"
  code: "\n#include \"modint.hpp\"\n\nconstexpr int max_combination = 1010101;\ntemplate<typename\
    \ T>\nstruct binomial {\n\n\tvector<T> fact, inv_fact;\n\n\tbinomial(){\n\t\t\
    fact.resize(max_combination);\n\t\tinv_fact.resize(max_combination);\n\t\tfact[0]\
    \ = 1, inv_fact[0] = 1;\n\t\tfor(int i = 1;i < max_combination;i++){\n\t\t\tfact[i]\
    \ = fact[i - 1];\n\t\t\tfact[i] *= i;\n\t\t\tinv_fact[i] = inv_fact[i - 1];\n\t\
    \t\tinv_fact[i] /= i;\n\t\t}\n\t}\n\n\tT nCr(int n, int r){\n\t\tif(r < 0 || r\
    \ > n)return 0;\n\n\t\tmodint ret = fact[n];\n\t\tret *= inv_fact[r];\n\t\tret\
    \ *= inv_fact[n - r];\n\n\t\treturn ret;\n\t}\n};\n"
  dependsOn:
  - math/modint.hpp
  isVerificationFile: false
  path: math/combination.hpp
  requiredBy: []
  timestamp: '2024-09-21 01:01:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/combination.hpp
layout: document
title: binary_gcd
---

# binary_gcd

## 使い方

``binary_gcd(ll a, ll b)`` : $\text{gcd}(a, b)$ を返す。$O(\log{a+b})$ 程度

## 概要

除算が遅いため、それを回避するためにビットシフトに限定した GCD 計算アルゴリズム
