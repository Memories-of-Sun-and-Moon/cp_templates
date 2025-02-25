---
title: generalized_discrete_logarithm
documentation_of: ./../../math/generalized_discrete_logarithm.hpp
---

# generalized_discrete_logarithm

## 使い方

``template<typename T> generalized_discrete_logarithm(T x, T y, auto f, int n, auto f_m, int m)`` : $f^n(x) = y$ を満たす $n$ 以下の自然数 $k$ が存在するかどうかを判定し、存在するならその最小値を返す（存在しない場合は $-1$ が返る）。適切な $m$ の設定で$O(\sqrt{N})$

ただし、
- $f$ の計算は $\Theta(T)$ 時間かかるとする。
- ある自然数 $m$ ($\sqrt{N}$ 程度が好ましい) について、$f^m(x)$ も $\Theta(T)$ 時間で求められるとする。

## 参考

[250225_離散対数問題](https://acompany-ac.notion.site/250225_-1a4269d8558680a8bcbef0b561d04a41)
