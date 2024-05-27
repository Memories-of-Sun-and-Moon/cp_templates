---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/nCr%mod(combination).cpp
    title: math/nCr%mod(combination).cpp
  - icon: ':warning:'
    path: math/power.cpp
    title: math/power.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://noshi91.hatenablog.com/entry/2019/03/31/174006
  bundledCode: "#line 1 \"math/modint.cpp\"\n# include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n//thx https://noshi91.hatenablog.com/entry/2019/03/31/174006\n\ntemplate\
    \ <std::uint_fast64_t Modulus> class modint {\n\tusing u64 = std::uint_fast64_t;\n\
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
    \      return os;\n    }\n};\n\n\n//using mint = modint<998244353>;\n//using mint\
    \ = modint<1000000007>;\n\n\n// ---- \u4F9D\u5B58\u3057\u3066\u3044\u308B\u30E9\
    \u30A4\u30D6\u30E9\u30EA\n// nCr%mod(combination).cpp\n"
  code: "# include <bits/stdc++.h>\nusing namespace std;\n\n//thx https://noshi91.hatenablog.com/entry/2019/03/31/174006\n\
    \ntemplate <std::uint_fast64_t Modulus> class modint {\n\tusing u64 = std::uint_fast64_t;\n\
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
    \      return os;\n    }\n};\n\n\n//using mint = modint<998244353>;\n//using mint\
    \ = modint<1000000007>;\n\n\n// ---- \u4F9D\u5B58\u3057\u3066\u3044\u308B\u30E9\
    \u30A4\u30D6\u30E9\u30EA\n// nCr%mod(combination).cpp"
  dependsOn: []
  isVerificationFile: false
  path: math/modint.cpp
  requiredBy:
  - math/power.cpp
  - math/nCr%mod(combination).cpp
  timestamp: '2024-05-28 05:46:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/modint.cpp
layout: document
redirect_from:
- /library/math/modint.cpp
- /library/math/modint.cpp.html
title: math/modint.cpp
---
