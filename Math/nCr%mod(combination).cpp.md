---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Math/modint.cpp
    title: Math/modint.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/nCr%mod(combination).cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 2 \"Math/modint.cpp\"\nusing namespace std;\n\n\
    //thx https://noshi91.hatenablog.com/entry/2019/03/31/174006\n\ntemplate <std::uint_fast64_t\
    \ Modulus> class modint {\n\tusing u64 = std::uint_fast64_t;\npublic:\n\tu64 a;\n\
    \tconstexpr modint(const u64 x = 0) noexcept : a(x % Modulus) {}\n\tconstexpr\
    \ u64 &value() noexcept { return a; }\n\tconstexpr const u64 &value() const noexcept\
    \ { return a; }\n\tconstexpr modint operator+(const modint rhs) const noexcept\
    \ {\n\t\treturn modint(*this) += rhs;\n\t}\n\tconstexpr modint operator-(const\
    \ modint rhs) const noexcept {\n\t\treturn modint(*this) -= rhs;\n\t}\n\tconstexpr\
    \ modint operator*(const modint rhs) const noexcept {\n    \treturn modint(*this)\
    \ *= rhs;\n\t}\n\tconstexpr modint operator/(const modint rhs) const noexcept\
    \ {\n\t\treturn modint(*this) /= rhs;\n\t}\n\tconstexpr modint &operator+=(const\
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
    \u30A4\u30D6\u30E9\u30EA\n// nCr%mod(combination).cpp\n#line 5 \"Math/nCr%mod(combination).cpp\"\
    \n\nusing mint = modint<998244353>;\n//using mint = modint<1000000007>;\n\nconstexpr\
    \ int max_combination = 1010101;\n\nmint fact[max_combination], inv_fact[max_combination];\n\
    \nvoid combination_init(){\n    fact[0] = 1, inv_fact[0] = 1;\n    for(int i =\
    \ 1;i < max_combination;i++){\n        fact[i] = fact[i - 1];\n        fact[i]\
    \ *= i;\n        inv_fact[i] = inv_fact[i - 1];\n        inv_fact[i] /= i;\n \
    \   }\n}\n\nmint nCr(int n, int r){\n    if(fact[0].a == 0)combination_init();\n\
    \n    if(r < 0 || r > n)return 0;\n\n    mint ret = fact[n];\n    ret *= inv_fact[r];\n\
    \    ret *= inv_fact[n - r];\n\n    return ret;\n}\n\n\n// n\u500B\u304B\u3089\
    , (a, b)\u500B\u306E\u7D44\u3092\u4F5C\u308B\u6642\u306E\u5834\u5408\u306E\u6570\
    \nmint sub(int n, int a, int b) {\n    if(a + b > n)return 0;\n    return nCr(n,\
    \ a) * nCr(n - a, b);\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n# include \"modint.cpp\"\
    \n\nusing mint = modint<998244353>;\n//using mint = modint<1000000007>;\n\nconstexpr\
    \ int max_combination = 1010101;\n\nmint fact[max_combination], inv_fact[max_combination];\n\
    \nvoid combination_init(){\n    fact[0] = 1, inv_fact[0] = 1;\n    for(int i =\
    \ 1;i < max_combination;i++){\n        fact[i] = fact[i - 1];\n        fact[i]\
    \ *= i;\n        inv_fact[i] = inv_fact[i - 1];\n        inv_fact[i] /= i;\n \
    \   }\n}\n\nmint nCr(int n, int r){\n    if(fact[0].a == 0)combination_init();\n\
    \n    if(r < 0 || r > n)return 0;\n\n    mint ret = fact[n];\n    ret *= inv_fact[r];\n\
    \    ret *= inv_fact[n - r];\n\n    return ret;\n}\n\n\n// n\u500B\u304B\u3089\
    , (a, b)\u500B\u306E\u7D44\u3092\u4F5C\u308B\u6642\u306E\u5834\u5408\u306E\u6570\
    \nmint sub(int n, int a, int b) {\n    if(a + b > n)return 0;\n    return nCr(n,\
    \ a) * nCr(n - a, b);\n};\n"
  dependsOn:
  - Math/modint.cpp
  isVerificationFile: false
  path: Math/nCr%mod(combination).cpp
  requiredBy: []
  timestamp: '2023-12-09 18:47:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/nCr%mod(combination).cpp
layout: document
redirect_from:
- /library/Math/nCr%mod(combination).cpp
- /library/Math/nCr%mod(combination).cpp.html
title: Math/nCr%mod(combination).cpp
---
