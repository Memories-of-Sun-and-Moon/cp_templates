---
data:
  _extendedDependsOn:
  - icon: ':question:'
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
    \      return os;\n    }\n};\n#line 3 \"math/combination.hpp\"\n\nconstexpr int\
    \ max_combination = 1010101;\ntemplate<typename T>\nstruct binomial {\n\n\tvector<T>\
    \ fact, inv_fact;\n\n\tbinomial(){\n\t\tfact.resize(max_combination);\n\t\tinv_fact.resize(max_combination);\n\
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
  timestamp: '2024-06-04 23:47:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/combination.hpp
layout: document
title: "2\u9805\u4FC2\u6570mod"
---

# 2項係数mod

## 使い方

``binomial<T> bin`` : 2項係数mod $M$ (型は ``T``) のコンストラクタを呼ぶ。2項係数で扱う値の上限を $K = 1010101$ としており、型 ``T`` における $1!, 2!, ..., K!$ 及びそれらの逆元の計算に比例した計算量がかかる。

``bin.nCr(n, r)`` : $_nC_r \pmod{M}$ を返す。

## 概要

## Verify

[AtCoder](https://atcoder.jp/contests/abc066/tasks/arc077_b)
