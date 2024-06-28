---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/power.hpp
    title: math/power.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo/convolution_mod.test.cpp
    title: verify/yosupo/convolution_mod.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/formal_power_series.hpp\"\n\ntemplate<typename mint998>\n\
    struct formal_power_series : vector<mint998> {\n\tusing vector<mint998>::vector;\n\
    \tusing FPS = formal_power_series;\n\n\tFPS &operator+=(const FPS &r){\n\t\tif(r.size()\
    \ > this->size()){\n\t\t\tthis->resize(r.size());\n\t\t}\n\t\tfor(size_t i = 0;i\
    \ < r.size();i++){\n\t\t\t(*this)[i] += r[i];\n\t\t}\n\t\treturn *this;\n\t}\n\
    \n\tFPS &operator+=(const mint998 &v){\n\t\tif(this->empty())this->resize(1);\n\
    \t\t(*this)[0] += v;\n\t\treturn *this;\n\t}\n\n\tFPS &operator-=(const FPS &r){\n\
    \t\tif(r.size() > this->size()){\n\t\t\tthis->resize(r.size());\n\t\t}\n\t\tfor(size_t\
    \ i = 0;i < r.size();i++){\n\t\t\t(*this)[i] -= r[i];\n\t\t}\n\t\treturn *this;\n\
    \t}\n\n\tFPS &operator-=(const mint998 &v){\n\t\tif(this->empty())this->resize(1);\n\
    \t\t(*this)[0] -= v;\n\t\treturn *this;\n\t}\n\n\tFPS &operator*=(const FPS &g){\n\
    \t\tsize_t N = std::bit_ceil(this->size() + g.size() - 1);\n\n\t\tvector<mint998>\
    \ F(N, 0), G(N, 0);\n\n\t\tfor (size_t i = 0; i < this->size(); i++){\n\t\t\t\
    F[i] = (*this)[i];\n\t\t}\n\t\tfor (size_t i = 0; i < g.size(); i++){\n\t\t\t\
    G[i] = g[i];\n\t\t}\n\n\t\tDFT(F);\n\t\tDFT(G);\n\n\t\tvector<mint998> FG(N);\n\
    \t\tfor (size_t i = 0; i < N; i++){\n\t\t\tFG[i] = F[i] * G[i];\n\t\t}\n\t\tIDFT(FG);\n\
    \n\t\tFPS fg(this->size() + g.size() - 1);\n\t\tfor (size_t i = 0; i < fg.size();\
    \ i++){\n\t\t\tfg[i] = FG[i];\n\t\t}\n\t\treturn *this = fg;\n\t}\n\n\tFPS &operator*=(const\
    \ mint998 &v){\n\t\tfor(size_t k = 0;k < this->size();k++){\n\t\t\t(*this)[k]\
    \ *= v;\n\t\t\treturn *this;\n\t\t}\n\t}\n\n\tFPS operator+(const FPS &r) const\
    \ { return FPS(*this) += r; }\n\tFPS operator+(const mint998 &v) const { return\
    \ FPS(*this) += v; }\n\tFPS operator-(const FPS &r) const { return FPS(*this)\
    \ -= r; }\n\tFPS operator-(const mint998 &v) const { return FPS(*this) -= v; }\n\
    \tFPS operator*(const FPS &r) const { return FPS(*this) *= r; }\n\tFPS operator*(const\
    \ mint998 &v) const { return FPS(*this) *= v; }\n\tFPS operator-() const {\n\t\
    \tFPS ret(this->size());\n\t\tfor(size_t i = 0;i < this->size();i++){\n\t\t\t\
    ret[i] = -(*this)[i];\n\t\t}\n\t\treturn ret;\n\t}\n\n\tvoid shrink(){\n\t\twhile(this->size()\
    \ && this->back() == mint998(0))this->pop_back();\n\t}\n\n\tmint998 eval(mint998\
    \ x) const {\n\t\tmint998 r = 0, w = 1;\n\t\tfor(auto &v : *this){\n\t\t\tr +=\
    \ w*v;\n\t\t\tw *= x;\n\t\t}\n\t\treturn r;\n\t}\n};\n\n#line 1 \"math/power.hpp\"\
    \n\ntemplate<typename mint>\nmint power(mint n, long long k) {\n\tmint ret = 1;\n\
    \twhile(k > 0) {\n\t\tif(k & 1)ret *= n;\n\t\tn = n*n;\n\t\tk >>= 1;\n\t}\n\t\
    return ret;\n}\n#line 103 \"math/formal_power_series.hpp\"\n\nvector<vector<mint998>>\
    \ zeta_table;\n\nmint998 zeta(size_t n, int i){\n\ti += n;\n\ti %= n;\n\tif(zeta_table.empty()){\n\
    \t\tzeta_table.resize(24);\n\t\tmint998 r = power<mint998>(3,119);\n\t\tfor(int\
    \ j = 23;j >= 0;j--){\n\t\t\tzeta_table[j].resize(1);\n\t\t\tzeta_table[j][0]\
    \ = r;\n\t\t\tr *= r;\n\t\t}\n\t}\n\tint N_2 = __builtin_ctz(n);\n\tif(zeta_table[N_2].size()\
    \ == 1){\n\t\tmint998 r = zeta_table[N_2][0];\n\t\tzeta_table[N_2][0] = 1;\n\t\
    \tzeta_table[N_2].resize(n);\n\t\tfor(size_t j = 1;j < n;j++){\n\t\t\tzeta_table[N_2][j]\
    \ = r * zeta_table[N_2][j-1];\n\t\t\tif(j == n-1){\n\t\t\t\tassert((zeta_table[N_2][j]\
    \ * r).a == 1);\n\t\t\t}\n\t\t}\n\t}\n\treturn zeta_table[N_2][i];\n}\n\nvoid\
    \ DFT(vector<mint998> &f, bool inverse = false){\n\tsize_t N = f.size();\n\tif(N\
    \ == 1)return;\n\n\tsize_t n = N >> 1;\n\n\tvector<mint998> f0(n), f1(n);\n\t\
    for (size_t i = 0; i < n; i++){\n\t\tf0[i] = f[2 * i];\n\t\tf1[i] = f[2 * i +\
    \ 1];\n\t}\n\n\tDFT(f0, inverse);\n\tDFT(f1, inverse);\n\n\tfor (size_t i = 0;\
    \ i < n; i++){\n\t\tf[i] = f0[i] + (inverse ? zeta(N, -i) : zeta(N, i)) * f1[i];\n\
    \t\tf[n + i] = f0[i] + (inverse ? zeta(N, -n - i) : zeta(N, n + i)) * f1[i];\n\
    \t}\n}\n\nvoid IDFT(vector<mint998> &f){\n\tDFT(f, true);\n\tsize_t N = f.size();\n\
    \tfor (mint998 &a : f){\n\t\ta /= N;\n\t}\n}\n"
  code: "\ntemplate<typename mint998>\nstruct formal_power_series : vector<mint998>\
    \ {\n\tusing vector<mint998>::vector;\n\tusing FPS = formal_power_series;\n\n\t\
    FPS &operator+=(const FPS &r){\n\t\tif(r.size() > this->size()){\n\t\t\tthis->resize(r.size());\n\
    \t\t}\n\t\tfor(size_t i = 0;i < r.size();i++){\n\t\t\t(*this)[i] += r[i];\n\t\t\
    }\n\t\treturn *this;\n\t}\n\n\tFPS &operator+=(const mint998 &v){\n\t\tif(this->empty())this->resize(1);\n\
    \t\t(*this)[0] += v;\n\t\treturn *this;\n\t}\n\n\tFPS &operator-=(const FPS &r){\n\
    \t\tif(r.size() > this->size()){\n\t\t\tthis->resize(r.size());\n\t\t}\n\t\tfor(size_t\
    \ i = 0;i < r.size();i++){\n\t\t\t(*this)[i] -= r[i];\n\t\t}\n\t\treturn *this;\n\
    \t}\n\n\tFPS &operator-=(const mint998 &v){\n\t\tif(this->empty())this->resize(1);\n\
    \t\t(*this)[0] -= v;\n\t\treturn *this;\n\t}\n\n\tFPS &operator*=(const FPS &g){\n\
    \t\tsize_t N = std::bit_ceil(this->size() + g.size() - 1);\n\n\t\tvector<mint998>\
    \ F(N, 0), G(N, 0);\n\n\t\tfor (size_t i = 0; i < this->size(); i++){\n\t\t\t\
    F[i] = (*this)[i];\n\t\t}\n\t\tfor (size_t i = 0; i < g.size(); i++){\n\t\t\t\
    G[i] = g[i];\n\t\t}\n\n\t\tDFT(F);\n\t\tDFT(G);\n\n\t\tvector<mint998> FG(N);\n\
    \t\tfor (size_t i = 0; i < N; i++){\n\t\t\tFG[i] = F[i] * G[i];\n\t\t}\n\t\tIDFT(FG);\n\
    \n\t\tFPS fg(this->size() + g.size() - 1);\n\t\tfor (size_t i = 0; i < fg.size();\
    \ i++){\n\t\t\tfg[i] = FG[i];\n\t\t}\n\t\treturn *this = fg;\n\t}\n\n\tFPS &operator*=(const\
    \ mint998 &v){\n\t\tfor(size_t k = 0;k < this->size();k++){\n\t\t\t(*this)[k]\
    \ *= v;\n\t\t\treturn *this;\n\t\t}\n\t}\n\n\tFPS operator+(const FPS &r) const\
    \ { return FPS(*this) += r; }\n\tFPS operator+(const mint998 &v) const { return\
    \ FPS(*this) += v; }\n\tFPS operator-(const FPS &r) const { return FPS(*this)\
    \ -= r; }\n\tFPS operator-(const mint998 &v) const { return FPS(*this) -= v; }\n\
    \tFPS operator*(const FPS &r) const { return FPS(*this) *= r; }\n\tFPS operator*(const\
    \ mint998 &v) const { return FPS(*this) *= v; }\n\tFPS operator-() const {\n\t\
    \tFPS ret(this->size());\n\t\tfor(size_t i = 0;i < this->size();i++){\n\t\t\t\
    ret[i] = -(*this)[i];\n\t\t}\n\t\treturn ret;\n\t}\n\n\tvoid shrink(){\n\t\twhile(this->size()\
    \ && this->back() == mint998(0))this->pop_back();\n\t}\n\n\tmint998 eval(mint998\
    \ x) const {\n\t\tmint998 r = 0, w = 1;\n\t\tfor(auto &v : *this){\n\t\t\tr +=\
    \ w*v;\n\t\t\tw *= x;\n\t\t}\n\t\treturn r;\n\t}\n};\n\n#include \"./power.hpp\"\
    \n\nvector<vector<mint998>> zeta_table;\n\nmint998 zeta(size_t n, int i){\n\t\
    i += n;\n\ti %= n;\n\tif(zeta_table.empty()){\n\t\tzeta_table.resize(24);\n\t\t\
    mint998 r = power<mint998>(3,119);\n\t\tfor(int j = 23;j >= 0;j--){\n\t\t\tzeta_table[j].resize(1);\n\
    \t\t\tzeta_table[j][0] = r;\n\t\t\tr *= r;\n\t\t}\n\t}\n\tint N_2 = __builtin_ctz(n);\n\
    \tif(zeta_table[N_2].size() == 1){\n\t\tmint998 r = zeta_table[N_2][0];\n\t\t\
    zeta_table[N_2][0] = 1;\n\t\tzeta_table[N_2].resize(n);\n\t\tfor(size_t j = 1;j\
    \ < n;j++){\n\t\t\tzeta_table[N_2][j] = r * zeta_table[N_2][j-1];\n\t\t\tif(j\
    \ == n-1){\n\t\t\t\tassert((zeta_table[N_2][j] * r).a == 1);\n\t\t\t}\n\t\t}\n\
    \t}\n\treturn zeta_table[N_2][i];\n}\n\nvoid DFT(vector<mint998> &f, bool inverse\
    \ = false){\n\tsize_t N = f.size();\n\tif(N == 1)return;\n\n\tsize_t n = N >>\
    \ 1;\n\n\tvector<mint998> f0(n), f1(n);\n\tfor (size_t i = 0; i < n; i++){\n\t\
    \tf0[i] = f[2 * i];\n\t\tf1[i] = f[2 * i + 1];\n\t}\n\n\tDFT(f0, inverse);\n\t\
    DFT(f1, inverse);\n\n\tfor (size_t i = 0; i < n; i++){\n\t\tf[i] = f0[i] + (inverse\
    \ ? zeta(N, -i) : zeta(N, i)) * f1[i];\n\t\tf[n + i] = f0[i] + (inverse ? zeta(N,\
    \ -n - i) : zeta(N, n + i)) * f1[i];\n\t}\n}\n\nvoid IDFT(vector<mint998> &f){\n\
    \tDFT(f, true);\n\tsize_t N = f.size();\n\tfor (mint998 &a : f){\n\t\ta /= N;\n\
    \t}\n}\n"
  dependsOn:
  - math/power.hpp
  isVerificationFile: false
  path: math/formal_power_series.hpp
  requiredBy: []
  timestamp: '2024-06-29 00:45:01+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo/convolution_mod.test.cpp
documentation_of: math/formal_power_series.hpp
layout: document
title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\u30A4\u30D6\u30E9\u30EA"
---

**未検証パート多め**

**mod998にしか対応していないため、定義する際は mint998 を定義すること**

# 形式的冪級数ライブラリ

## 使い方

各係数はvectorの要領で定義することができる。

- 加算
- 減算
- 乗算

に対応。
