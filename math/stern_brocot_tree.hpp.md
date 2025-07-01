---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/stern_brocot_tree.test.cpp
    title: verify/yosupo/stern_brocot_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/stern_brocot_tree.hpp\"\n\n#include<algorithm>\n#include<optional>\n\
    #include<ranges>\n#include<tuple>\n#include<vector>\n\nnamespace sbt{\n\n\ttemplate<class\
    \ T>\n\tstd::tuple<T, T, T, T> child(T p, T q, T r, T s, T d, bool is_left){\n\
    \t\tif(is_left){\n\t\t\tr += d*p;\n\t\t\ts += d*q;\n\t\t}else{\n\t\t\tp += d*r;\n\
    \t\t\tq += d*s;\n\t\t}\n\t\treturn std::make_tuple(p, q, r, s);\n\t}\n\n\ttemplate<class\
    \ T>\n\tstd::tuple<T, T, T, T> parent(T p, T q, T r, T s){\n\t\tif(p == 0 && q\
    \ == 1 && r == 1 && s == 0){\n\t\t\treturn std::make_tuple(0, 0, 0, 0);\n\t\t\
    }\n\t\tif(p < r || q < s){\n\t\t\tr -= p, s -= q;\n\t\t}else{\n\t\t\tp -= r, q\
    \ -= s;\n\t\t}\n\t\treturn std::make_tuple(p, q, r, s);\n\t}\n\n\ttemplate<class\
    \ T>\n\tstd::vector<T> encode_path(T p, T q){\n\t\tstd::vector<T> a;\n\t\tif(p\
    \ < q){\n\t\t\ta.emplace_back(0);\n\t\t\tstd::swap(p, q);\n\t\t}\n\t\twhile(p\
    \ != 1){\n\t\t\ta.emplace_back(p/q);\n\t\t\tp %= q;\n\t\t\tstd::swap(p, q);\n\t\
    \t}\n\t\tif(not a.empty()){\n\t\t\tif(a.back() == 1){\n\t\t\t\ta.pop_back();\n\
    \t\t\t}else{\n\t\t\t\ta.back()--;\n\t\t\t}\n\t\t}\n\t\treturn a;\n\t}\n\n\ttemplate<class\
    \ T>\n\tstd::tuple<T, T, T, T> decode_path(const std::vector<T> &a){\n\t\tT p\
    \ = 0, q = 1, r = 1, s = 0;\n\t\tfor(int i = 0;i < std::ssize(a);i++){\n\t\t\t\
    std::tie(p, q, r, s) = child(p, q, r, s, a[i], i&1);\n\t\t}\n\t\treturn std::make_tuple(p,\
    \ q, r, s);\n\t}\n\n\ttemplate<class T>\n\tstd::tuple<T, T, T, T> lca(T p, T q,\
    \ T r, T s){\n\t\tstd::vector<T> a = encode_path(p, q), b = encode_path(r, s);\n\
    \n\t\tint n = std::min(std::ssize(a), std::ssize(b));\n\n\t\tT P = 0, Q = 1, R\
    \ = 1, S = 0;\n\t\tfor(int i = 0;i < n;i++){\n\t\t\tT c = std::min(a[i], b[i]);\n\
    \t\t\tstd::tie(P, Q, R, S) = child(P, Q, R, S, c, i&1);\n\t\t\tif(a[i] != b[i])break;\n\
    \t\t}\n\t\treturn std::make_tuple(P, Q, R, S);\n\t}\n\n\ttemplate<class T>\n\t\
    std::optional<std::tuple<T, T, T, T>> ancestor(T p, T q, T d){\n\t\tstd::vector<T>\
    \ a = encode_path(p, q);\n\t\tT P = 0, Q = 1, R = 1, S = 0;\n\t\tfor(int i = 0;i\
    \ < std::ssize(a);i++){\n\t\t\tT c = std::min(d, a[i]);\n\t\t\tstd::tie(P, Q,\
    \ R, S) = child(P, Q, R, S, c, i&1);\n\t\t\td -= c;\n\t\t\tif(d == 0)break;\n\t\
    \t}\n\t\tif(d == 0){\n\t\t\treturn std::make_tuple(P, Q, R, S);\n\t\t}\n\t\treturn\
    \ std::nullopt;\n\t}\n\n\ttemplate<class T>\n\tstd::tuple<T, T, T, T> range(T\
    \ p, T q){\n\t\treturn decode_path(encode_path(p, q));\n\t}\n}\n"
  code: "#pragma once\n\n#include<algorithm>\n#include<optional>\n#include<ranges>\n\
    #include<tuple>\n#include<vector>\n\nnamespace sbt{\n\n\ttemplate<class T>\n\t\
    std::tuple<T, T, T, T> child(T p, T q, T r, T s, T d, bool is_left){\n\t\tif(is_left){\n\
    \t\t\tr += d*p;\n\t\t\ts += d*q;\n\t\t}else{\n\t\t\tp += d*r;\n\t\t\tq += d*s;\n\
    \t\t}\n\t\treturn std::make_tuple(p, q, r, s);\n\t}\n\n\ttemplate<class T>\n\t\
    std::tuple<T, T, T, T> parent(T p, T q, T r, T s){\n\t\tif(p == 0 && q == 1 &&\
    \ r == 1 && s == 0){\n\t\t\treturn std::make_tuple(0, 0, 0, 0);\n\t\t}\n\t\tif(p\
    \ < r || q < s){\n\t\t\tr -= p, s -= q;\n\t\t}else{\n\t\t\tp -= r, q -= s;\n\t\
    \t}\n\t\treturn std::make_tuple(p, q, r, s);\n\t}\n\n\ttemplate<class T>\n\tstd::vector<T>\
    \ encode_path(T p, T q){\n\t\tstd::vector<T> a;\n\t\tif(p < q){\n\t\t\ta.emplace_back(0);\n\
    \t\t\tstd::swap(p, q);\n\t\t}\n\t\twhile(p != 1){\n\t\t\ta.emplace_back(p/q);\n\
    \t\t\tp %= q;\n\t\t\tstd::swap(p, q);\n\t\t}\n\t\tif(not a.empty()){\n\t\t\tif(a.back()\
    \ == 1){\n\t\t\t\ta.pop_back();\n\t\t\t}else{\n\t\t\t\ta.back()--;\n\t\t\t}\n\t\
    \t}\n\t\treturn a;\n\t}\n\n\ttemplate<class T>\n\tstd::tuple<T, T, T, T> decode_path(const\
    \ std::vector<T> &a){\n\t\tT p = 0, q = 1, r = 1, s = 0;\n\t\tfor(int i = 0;i\
    \ < std::ssize(a);i++){\n\t\t\tstd::tie(p, q, r, s) = child(p, q, r, s, a[i],\
    \ i&1);\n\t\t}\n\t\treturn std::make_tuple(p, q, r, s);\n\t}\n\n\ttemplate<class\
    \ T>\n\tstd::tuple<T, T, T, T> lca(T p, T q, T r, T s){\n\t\tstd::vector<T> a\
    \ = encode_path(p, q), b = encode_path(r, s);\n\n\t\tint n = std::min(std::ssize(a),\
    \ std::ssize(b));\n\n\t\tT P = 0, Q = 1, R = 1, S = 0;\n\t\tfor(int i = 0;i <\
    \ n;i++){\n\t\t\tT c = std::min(a[i], b[i]);\n\t\t\tstd::tie(P, Q, R, S) = child(P,\
    \ Q, R, S, c, i&1);\n\t\t\tif(a[i] != b[i])break;\n\t\t}\n\t\treturn std::make_tuple(P,\
    \ Q, R, S);\n\t}\n\n\ttemplate<class T>\n\tstd::optional<std::tuple<T, T, T, T>>\
    \ ancestor(T p, T q, T d){\n\t\tstd::vector<T> a = encode_path(p, q);\n\t\tT P\
    \ = 0, Q = 1, R = 1, S = 0;\n\t\tfor(int i = 0;i < std::ssize(a);i++){\n\t\t\t\
    T c = std::min(d, a[i]);\n\t\t\tstd::tie(P, Q, R, S) = child(P, Q, R, S, c, i&1);\n\
    \t\t\td -= c;\n\t\t\tif(d == 0)break;\n\t\t}\n\t\tif(d == 0){\n\t\t\treturn std::make_tuple(P,\
    \ Q, R, S);\n\t\t}\n\t\treturn std::nullopt;\n\t}\n\n\ttemplate<class T>\n\tstd::tuple<T,\
    \ T, T, T> range(T p, T q){\n\t\treturn decode_path(encode_path(p, q));\n\t}\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: math/stern_brocot_tree.hpp
  requiredBy: []
  timestamp: '2025-07-01 03:22:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/stern_brocot_tree.test.cpp
documentation_of: math/stern_brocot_tree.hpp
layout: document
title: stern_brocot_tree
---

# stern_brocot_tree

頂点 $(p, q, r, s)$ は $\frac{p+r}{q+s}$ に対応する

## 使い方

- ``vector<T> sbt::encode_path<T>(a, b)`` : $\frac{a}{b}$ に対応する頂点までのパスを連長圧縮したものを取得。0-indexed で偶数番目が左方向, 奇数番目が右方向への移動を示す。 $O(\log \max(a, b))$
- ``tuple<T, T, T, T> sbt::decode_path<T>(vector<T> path)`` : path に対応する頂点を取得 $O(\log \max(p, q, r, s))$
- ``tuple<T, T, T, T> sbt::lca<T>(T p, T q, T r, T s)`` : $\frac{p}{q}$ と $\frac{r}{s}$ に対応する頂点の LCA を求める。$O(\log \max(p, q, r, s))$
- ``tuple<T, T, T, T> sbt::ancestor(T p, T q, T d)`` : $\frac{p}{q}$ に対応する頂点から $d$ 個祖先の頂点を求める。 $O(\log \max(p, q, r, s))$
- ``tuple<T, T, T, T> sbt::range(T p, T q)`` : $\frac{p}{q}$ に対応する頂点の子孫の下限と上限を求める。$O(\log \max(p, q, r, s))$


[参考](https://miscalc.hatenablog.com/entry/2023/12/22/213007)
