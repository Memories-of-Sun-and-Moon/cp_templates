---
title: 疑似乱数(xorshift)
documentation_of: ./../../ramdom/util.hpp
---

# 疑似乱数(xorshift)

## 使い方

- ``xorshift32()`` :  32 bit 空間上の xorshift
- ``xorshift64()`` :  64 bit 空間上の xorshift

[std::random](https://cpprefjp.github.io/reference/random.html) と組み合わせて使用することができ、そうすると様々な分布が取れる

何をもって verify したとするかは不明。

## 参考

AHC 等、適当に乱数が分布されてればいい場合であれば、あらかじめ 10^6 個程度生成しておいて、それを使いまわすと高速に機能する。
