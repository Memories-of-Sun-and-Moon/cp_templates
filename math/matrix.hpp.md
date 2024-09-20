---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/matrix.hpp\"\n\ntemplate<typename T>\nstruct matrix\
    \ {\n\tvector<vector<T>> mat;\n\n\tmatrix(size_t r, size_t c) {\n\t\tmat.resize(r);\n\
    \t\tfor(size_t i = 0;i < r;i++){\n\t\t\tmat[i].resize(c);\n\t\t}\n\t}\n\n\tmatrix(vector<vector<T>>\
    \ _mat) : mat(_mat){}\n\n\tvector<T>& operator[](int i) {\n\t\treturn mat[i];\n\
    \t}\n\tconst vector<T>& operator[](int i) const {\n\t\treturn mat[i];\n\t}\n\n\
    \tconstexpr matrix operator+(const matrix rhs) const {\n\t\treturn matrix(*this)\
    \ += rhs;\n\t}\n\tconstexpr matrix operator-(const matrix rhs) const {\n\t\treturn\
    \ matrix(*this) += rhs;\n\t}\n\tconstexpr matrix operator*(const T rhs) const\
    \ {\n\t\treturn matrix(*this) *= rhs;\n\t}\n\tconstexpr matrix operator*(const\
    \ matrix rhs) const {\n\t\treturn matrix(*this) *= rhs;\n\t}\n\tconstexpr matrix\
    \ operator+=(const matrix rhs) const {\n\t\tassert((*this).size() == rhs.size()\
    \ && (*this)[0].size() == rhs[0].size());\n\t\tfor(size_t i = 0;i < (*this).size();i++){\n\
    \t\t\tfor(size_t j = 0;j < (*this)[0].size();j++){\n\t\t\t\tmat += rhs[i][j];\n\
    \t\t\t}\n\t\t}\n\t\treturn *this;\n\t}\n\tconstexpr matrix operator-=(const matrix\
    \ rhs) const {\n\t\tfor(size_t i = 0;i < (*this).size();i++){\n\t\t\tfor(size_t\
    \ j = 0;j < (*this)[0].size();j++){\n\t\t\t\tmat -= rhs[i][j];\n\t\t\t}\n\t\t\
    }\n\t\treturn *this;\n\t}\n\n\tconstexpr matrix operator*=(const T rhs) const\
    \ {\n\t\tfor(size_t i = 0;i < (*this).size();i++){\n\t\t\tfor(size_t j = 0;j <\
    \ (*this)[0].size();j++){\n\t\t\t\t(*this)[i][j] *= rhs;\n\t\t\t}\n\t\t}\n\t\t\
    return *this;\n\t}\n\tconstexpr matrix operator*=(const matrix rhs) {\n\t\tassert((*this)[0].size()\
    \ == rhs.mat.size());\n\t\tmatrix c((*this).mat.size(), rhs[0].size());\n\t\t\
    for(size_t i = 0;i < (*this).mat.size();i++){\n\t\t\tfor(size_t k = 0;k < rhs.mat.size();k++){\n\
    \t\t\t\tfor(size_t j = 0;j < rhs[0].size();j++){\n\t\t\t\t\tc[i][j] += (*this)[i][k]*rhs[k][j];\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn (*this) = c;\n\t}\t\n\t\n\tmatrix power(ll\
    \ k) {\n\t\tassert(mat.size() == mat[0].size());\n\t\tmatrix<T> b(mat.size(),\
    \ mat[0].size());\n\t\tfor(size_t i = 0;i < b.mat.size();i++){\n\t\t\tb[i][i]\
    \ = 1;\n\t\t}\n\n\t\twhile(k){\n\t\t\tif(k & 1){\n\t\t\t\tb *= (*this);\n\t\t\t\
    }\n\t\t\t(*this) *= (*this);\n\t\t\tk >>= 1;\n\t\t}\n\t\treturn b;\n\t}\n};\n"
  code: "\ntemplate<typename T>\nstruct matrix {\n\tvector<vector<T>> mat;\n\n\tmatrix(size_t\
    \ r, size_t c) {\n\t\tmat.resize(r);\n\t\tfor(size_t i = 0;i < r;i++){\n\t\t\t\
    mat[i].resize(c);\n\t\t}\n\t}\n\n\tmatrix(vector<vector<T>> _mat) : mat(_mat){}\n\
    \n\tvector<T>& operator[](int i) {\n\t\treturn mat[i];\n\t}\n\tconst vector<T>&\
    \ operator[](int i) const {\n\t\treturn mat[i];\n\t}\n\n\tconstexpr matrix operator+(const\
    \ matrix rhs) const {\n\t\treturn matrix(*this) += rhs;\n\t}\n\tconstexpr matrix\
    \ operator-(const matrix rhs) const {\n\t\treturn matrix(*this) += rhs;\n\t}\n\
    \tconstexpr matrix operator*(const T rhs) const {\n\t\treturn matrix(*this) *=\
    \ rhs;\n\t}\n\tconstexpr matrix operator*(const matrix rhs) const {\n\t\treturn\
    \ matrix(*this) *= rhs;\n\t}\n\tconstexpr matrix operator+=(const matrix rhs)\
    \ const {\n\t\tassert((*this).size() == rhs.size() && (*this)[0].size() == rhs[0].size());\n\
    \t\tfor(size_t i = 0;i < (*this).size();i++){\n\t\t\tfor(size_t j = 0;j < (*this)[0].size();j++){\n\
    \t\t\t\tmat += rhs[i][j];\n\t\t\t}\n\t\t}\n\t\treturn *this;\n\t}\n\tconstexpr\
    \ matrix operator-=(const matrix rhs) const {\n\t\tfor(size_t i = 0;i < (*this).size();i++){\n\
    \t\t\tfor(size_t j = 0;j < (*this)[0].size();j++){\n\t\t\t\tmat -= rhs[i][j];\n\
    \t\t\t}\n\t\t}\n\t\treturn *this;\n\t}\n\n\tconstexpr matrix operator*=(const\
    \ T rhs) const {\n\t\tfor(size_t i = 0;i < (*this).size();i++){\n\t\t\tfor(size_t\
    \ j = 0;j < (*this)[0].size();j++){\n\t\t\t\t(*this)[i][j] *= rhs;\n\t\t\t}\n\t\
    \t}\n\t\treturn *this;\n\t}\n\tconstexpr matrix operator*=(const matrix rhs) {\n\
    \t\tassert((*this)[0].size() == rhs.mat.size());\n\t\tmatrix c((*this).mat.size(),\
    \ rhs[0].size());\n\t\tfor(size_t i = 0;i < (*this).mat.size();i++){\n\t\t\tfor(size_t\
    \ k = 0;k < rhs.mat.size();k++){\n\t\t\t\tfor(size_t j = 0;j < rhs[0].size();j++){\n\
    \t\t\t\t\tc[i][j] += (*this)[i][k]*rhs[k][j];\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\t\
    return (*this) = c;\n\t}\t\n\t\n\tmatrix power(ll k) {\n\t\tassert(mat.size()\
    \ == mat[0].size());\n\t\tmatrix<T> b(mat.size(), mat[0].size());\n\t\tfor(size_t\
    \ i = 0;i < b.mat.size();i++){\n\t\t\tb[i][i] = 1;\n\t\t}\n\n\t\twhile(k){\n\t\
    \t\tif(k & 1){\n\t\t\t\tb *= (*this);\n\t\t\t}\n\t\t\t(*this) *= (*this);\n\t\t\
    \tk >>= 1;\n\t\t}\n\t\treturn b;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/matrix.hpp
  requiredBy: []
  timestamp: '2024-09-21 01:18:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/matrix.hpp
layout: document
title: "\u884C\u5217\u30E9\u30A4\u30D6\u30E9\u30EA"
---

# 行列ライブラリ

## 使い方

- ``+ - *`` はそのまま扱うことができる
- ``power(ll k)`` 累乗が定義できるとき、 $k$ 乗を計算する
