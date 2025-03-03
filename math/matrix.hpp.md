---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/itp1/7_d.test.cpp
    title: verify/aoj/itp1/7_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yukicoder/3044.test.cpp
    title: verify/yukicoder/3044.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/matrix.hpp\"\n\ntemplate<typename T>\nstruct matrix\
    \ {\n\tvector<vector<T>> a;\n\n\tmatrix(){}\n\tmatrix(int n, int m) : a(n, vector<T>(m,\
    \ 0)){}\n\tmatrix(int n) : a(n, vector<T>(n, 0)){}\n\n\tsize_t height() const\
    \ {return a.size(); }\n\tsize_t width() const {return a[0].size(); }\n\n\tconst\
    \ vector<T> &operator[](int k) const {return a.at(k); }\n\tvector<T> &operator[](int\
    \ k) {return a.at(k); }\n\n\tstatic matrix I(size_t n){\n\t\tmatrix mat(n);\n\t\
    \tfor(size_t i = 0;i < n;i++){\n\t\t\tmat[i][i] = 1;\n\t\t}\n\t\treturn mat;\n\
    \t}\n\n\tmatrix &operator+=(const matrix &b){\n\t\tsize_t n = height(), m = width();\n\
    \t\tassert(n == b.height() && m == b.width());\n\t\tfor(size_t i = 0;i < n;i++){\n\
    \t\t\tfor(size_t j = 0;j < m;j++){\n\t\t\t\t(*this)[i][j] += b[i][j];\n\t\t\t\
    }\n\t\t}\n\t\treturn *this;\n\t}\n\n\tmatrix &operator-=(const matrix &b){\n\t\
    \tsize_t n = height(), m = width();\n\t\tassert(n == b.height() && m == b.width());\n\
    \t\tfor(size_t i = 0;i < n;i++){\n\t\t\tfor(size_t j = 0;j < m;j++){\n\t\t\t\t\
    (*this)[i][j] -= b[i][j];\n\t\t\t}\n\t\t}\n\t\treturn *this;\n\t}\n\n\tmatrix\
    \ &operator*=(const matrix &b){\n\t\tsize_t n = height(), m = b.width(), p = width();\n\
    \t\tassert(p == b.height());\n\t\tmatrix c(n, m);\n\t\tfor(size_t i = 0;i < n;i++){\n\
    \t\t\tfor(size_t k = 0;k < p;k++){\n\t\t\t\tfor(size_t j = 0;j < m;j++){\n\t\t\
    \t\t\tc[i][j] += (*this)[i][k] * b[k][j];\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\ta.swap(c.a);\n\
    \t\treturn *this;\n\t}\n\n\tmatrix &operator*=(const T &x){\n\t\tsize_t n = height(),\
    \ m = width();\n\t\tfor(int i = 0;i < n;i++){\n\t\t\tfor(int j = 0;j < m;j++){\n\
    \t\t\t\t(*this)[i][j] *= x;\n\t\t\t}\n\t\t}\n\t\treturn *this;\n\t}\n\n\tmatrix\
    \ operator+(const matrix &b) const {return matrix(*this) += b; }\n\tmatrix operator-(const\
    \ matrix &b) const {return matrix(*this) -= b; }\n\tmatrix operator*(const matrix\
    \ &b) const {return matrix(*this) *= b; }\n\tmatrix operator*(const T &x) const\
    \ {return matrix(*this) *= x; }\n};\n\ntemplate<typename T>\nmatrix<T> matrix_power(matrix<T>\
    \ a, long long k){\n\tassert(a.height() == a.width());\n\tmatrix<T> ret = matrix<T>::I(a.height());\n\
    \twhile(k > 0){\n\t\tif(k & 1)ret *= a;\n\t\ta = a*a;\n\t\tk >>= 1;\n\t}\n\treturn\
    \ ret;\n}\n"
  code: "\ntemplate<typename T>\nstruct matrix {\n\tvector<vector<T>> a;\n\n\tmatrix(){}\n\
    \tmatrix(int n, int m) : a(n, vector<T>(m, 0)){}\n\tmatrix(int n) : a(n, vector<T>(n,\
    \ 0)){}\n\n\tsize_t height() const {return a.size(); }\n\tsize_t width() const\
    \ {return a[0].size(); }\n\n\tconst vector<T> &operator[](int k) const {return\
    \ a.at(k); }\n\tvector<T> &operator[](int k) {return a.at(k); }\n\n\tstatic matrix\
    \ I(size_t n){\n\t\tmatrix mat(n);\n\t\tfor(size_t i = 0;i < n;i++){\n\t\t\tmat[i][i]\
    \ = 1;\n\t\t}\n\t\treturn mat;\n\t}\n\n\tmatrix &operator+=(const matrix &b){\n\
    \t\tsize_t n = height(), m = width();\n\t\tassert(n == b.height() && m == b.width());\n\
    \t\tfor(size_t i = 0;i < n;i++){\n\t\t\tfor(size_t j = 0;j < m;j++){\n\t\t\t\t\
    (*this)[i][j] += b[i][j];\n\t\t\t}\n\t\t}\n\t\treturn *this;\n\t}\n\n\tmatrix\
    \ &operator-=(const matrix &b){\n\t\tsize_t n = height(), m = width();\n\t\tassert(n\
    \ == b.height() && m == b.width());\n\t\tfor(size_t i = 0;i < n;i++){\n\t\t\t\
    for(size_t j = 0;j < m;j++){\n\t\t\t\t(*this)[i][j] -= b[i][j];\n\t\t\t}\n\t\t\
    }\n\t\treturn *this;\n\t}\n\n\tmatrix &operator*=(const matrix &b){\n\t\tsize_t\
    \ n = height(), m = b.width(), p = width();\n\t\tassert(p == b.height());\n\t\t\
    matrix c(n, m);\n\t\tfor(size_t i = 0;i < n;i++){\n\t\t\tfor(size_t k = 0;k <\
    \ p;k++){\n\t\t\t\tfor(size_t j = 0;j < m;j++){\n\t\t\t\t\tc[i][j] += (*this)[i][k]\
    \ * b[k][j];\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\ta.swap(c.a);\n\t\treturn *this;\n\
    \t}\n\n\tmatrix &operator*=(const T &x){\n\t\tsize_t n = height(), m = width();\n\
    \t\tfor(int i = 0;i < n;i++){\n\t\t\tfor(int j = 0;j < m;j++){\n\t\t\t\t(*this)[i][j]\
    \ *= x;\n\t\t\t}\n\t\t}\n\t\treturn *this;\n\t}\n\n\tmatrix operator+(const matrix\
    \ &b) const {return matrix(*this) += b; }\n\tmatrix operator-(const matrix &b)\
    \ const {return matrix(*this) -= b; }\n\tmatrix operator*(const matrix &b) const\
    \ {return matrix(*this) *= b; }\n\tmatrix operator*(const T &x) const {return\
    \ matrix(*this) *= x; }\n};\n\ntemplate<typename T>\nmatrix<T> matrix_power(matrix<T>\
    \ a, long long k){\n\tassert(a.height() == a.width());\n\tmatrix<T> ret = matrix<T>::I(a.height());\n\
    \twhile(k > 0){\n\t\tif(k & 1)ret *= a;\n\t\ta = a*a;\n\t\tk >>= 1;\n\t}\n\treturn\
    \ ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/matrix.hpp
  requiredBy: []
  timestamp: '2025-03-04 06:01:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/itp1/7_d.test.cpp
  - verify/yukicoder/3044.test.cpp
documentation_of: math/matrix.hpp
layout: document
title: "\u884C\u5217\u30E9\u30A4\u30D6\u30E9\u30EA"
---

# 行列ライブラリ

## 使い方

- ``+ - *`` はそのまま扱うことができる
- ``matrix_power(matrix<T> mat, ll k)`` 累乗が定義できるとき、 $mat$ の $k$ 乗を計算する
