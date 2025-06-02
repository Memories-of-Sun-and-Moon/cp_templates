---
title: stern_brocot_tree
documentation_of: ./../../math/stern_brocot_tree.hpp
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
