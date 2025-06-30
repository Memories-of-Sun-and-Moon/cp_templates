---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/lazy_segment_tree.hpp
    title: "\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/area_of_union_of_rectangles.test.cpp
    title: verify/yosupo/area_of_union_of_rectangles.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/lazy_segment_tree.hpp\"\n\ntemplate<class\
    \ S, auto op, auto e, class F, auto mapping, auto composition, auto id>\nstruct\
    \ lazy_segment_tree {\nprivate:\n\tint n;\n\tint log;\n\tint size;\n\tstd::vector<S>\
    \ node;\n\tstd::vector<F> lazy;\n\n\tvoid update(int k) { node[k] = op(node[2\
    \ * k], node[2 * k + 1]); }\n\tvoid all_apply(int k, F f) {\n\t\tnode[k] = mapping(f,\
    \ node[k]);\n\t\tif(k < size) lazy[k] = composition(f, lazy[k]);\n\t}\n\tvoid\
    \ push(int k) {\n\t\tall_apply(2*k + 0, lazy[k]);\n\t\tall_apply(2*k + 1, lazy[k]);\n\
    \t\tlazy[k] = id();\n\t}\npublic:\n\tlazy_segment_tree() : lazy_segment_tree(0)\
    \ {}\n\n\tlazy_segment_tree(int _n) : lazy_segment_tree(std::vector<S>(_n, e()))\
    \ {}\n\n\tlazy_segment_tree(const std::vector<S> &v) : n((int)v.size()) {\n\t\t\
    size = 1;\n\t\twhile(size < n) size <<= 1;\n\n\t\tlog = __builtin_ctz(size);\n\
    \n\t\tnode.resize(2*size, e());\n\t\tlazy.resize(size, id());\n\n\t\tfor(int i\
    \ = 0;i < n;i++)node[i + size] = v[i];\n\t\tfor(int i = size-1;i >= 1;i--)node[i]\
    \ = op(node[2*i + 0], node[2*i + 1]);\n\t}\n\n\tvoid set(int x, S val) {\n\t\t\
    assert(0 <= x && x < n);\n\t\tx += size;\n\n\t\tfor(int i = log;i >= 1;i--)push(x\
    \ >> i);\n\t\tnode[x] = val;\n\t\tfor(int i = 1;i <= log;i++)update(x >> i);\n\
    \t}\n\n\tS operator[](int x) {\n\t\tassert(0 <= x && x < n);\n\t\tx += size;\n\
    \n\t\tfor(int i = log;i >= 1;i--)push(x >> i);\n\t\treturn node[x];\n\t}\n\n\t\
    S fold(int l, int r) {\n\t\tassert(0 <= l && l <= r && r <= n);\n\t\tif(l == r)return\
    \ e();\n\n\t\tl += size;\n\t\tr += size;\n\n\t\tfor(int i = log;i >= 1;i--) {\n\
    \t\t\tif(((l >> i) << i) != l)push(l >> i);\n\t\t\tif(((r >> i) << i) != r)push((r-1)\
    \ >> i);\n\t\t}\n\n\t\tS L = e(), R = e();\n\t\tfor(;l < r;l >>= 1, r >>= 1){\n\
    \t\t\tif(l&1)L = op(L, node[l++]);\n\t\t\tif(r&1)R = op(node[--r], R);\n\t\t}\n\
    \t\treturn op(L, R);\n\t}\n\n\tS all_fold() { return node[1]; };\n\n\tvoid apply(int\
    \ x, F f) {\n\t\tassert(0 <= x && x < n);\n\n\t\tx += size;\n\t\tfor(int i = log;i\
    \ >= 1;i--)push(x >> i);\n\t\tnode[x] = mapping(f, node[x]);\n\t\tfor(int i =\
    \ 1;i <= log;i++)update(x >> i);\n\t}\n\n\tvoid apply(int l, int r, F f) {\n\t\
    \tassert(0 <= l && l <= r && r <= n);\n\t\tif(l == r)return;\n\n\t\tl += size;\n\
    \t\tr += size;\n\n\t\tfor(int i = log;i >= 1;i--) {\n\t\t\tif(((l >> i) << i)\
    \ != l)push(l >> i);\n\t\t\tif(((r >> i) << i) != r)push((r-1) >> i);\n\t\t}\n\
    \n\t\t{\n\t\t\tint l2 = l, r2 = r;\n\t\t\twhile (l < r) {\n\t\t\t\tif (l & 1)\
    \ all_apply(l++, f);\n\t\t\t\tif (r & 1) all_apply(--r, f);\n\t\t\t\tl >>= 1;\n\
    \t\t\t\tr >>= 1;\n\t\t\t}\n\t\t\tl = l2;\n\t\t\tr = r2;\n\t\t}\n\n\t\tfor (int\
    \ i = 1; i <= log; i++) {\n\t\t\tif (((l >> i) << i) != l) update(l >> i);\n\t\
    \t\tif (((r >> i) << i) != r) update((r - 1) >> i);\n\t\t}\n\t}\n\n\ttemplate<bool\
    \ (*g)(S)> int max_right(int l) {\n\t\treturn max_right(l, [](S x){ return g(x);\
    \ });\n\t}\n\ttemplate<class G> int max_right(int l, G g) {\n\t\tassert(0 <= l\
    \ && l <= n);\n\t\tassert(g(e()));\n\n\t\tif(l == n)return n;\n\n\t\tl += size;\n\
    \t\tfor(int i = log;i >= 1;i--)push(l >> i);\n\n\t\tS sum = e();\n\t\tdo {\n\t\
    \t\twhile(l%2 == 0)l >>= 1;\n\t\t\tif(not g(op(sum, node[l]))) {\n\t\t\t\twhile(l\
    \ < size) {\n\t\t\t\t\tpush(l);\n\t\t\t\t\tl <<= 1;\n\t\t\t\t\tif(g(op(sum, node[l])))\
    \ {\n\t\t\t\t\t\tsum = op(sum, node[l]);\n\t\t\t\t\t\tl++;\n\t\t\t\t\t}\n\t\t\t\
    \t}\n\t\t\t\treturn l-size;\n\t\t\t}\n\t\t\tsum = op(sum, node[l]);\n\t\t\tl++;\n\
    \t\t}while((l&-l) != l);\n\t\treturn n;\n\t}\n\n\ttemplate <bool (*g)(S)> int\
    \ min_left(int r) {\n\t\treturn min_left(r, [](S x) { return g(x); });\n\t}\n\t\
    template<class G> int min_left(int r, G g) {\n\t\tassert(0 <= r && r <= n);\n\t\
    \tassert(g(e()));\n\n\t\tif(r == 0)return 0;\n\n\t\tr += size;\n\t\tfor(int i\
    \ = log;i >= 1;i--)push((r-1) >> i);\n\n\t\tS sum = e();\n\t\tdo {\n\t\t\tr--;\n\
    \t\t\twhile(r > 1 && (r%2))r >>= 1;\n\t\t\tif(not g(op(node[r], sum))) {\n\t\t\
    \t\twhile(r < size) {\n\t\t\t\t\tpush(r);\n\t\t\t\t\tr = r*2 + 1;\n\t\t\t\t\t\
    if(g(op(node[r], sum))) {\n\t\t\t\t\t\tsum = op(node[r], sum);\n\t\t\t\t\t\tr--;\n\
    \t\t\t\t\t}\n\t\t\t\t}\n\t\t\t\treturn r+1-size;\n\t\t\t}\n\t\t\tsum = op(node[r],\
    \ sum);\n\t\t}while((r&-r) != r);\n\t\treturn 0;\n\t}\n};\n#line 2 \"data_structure/area_of_union_of_rectangles.hpp\"\
    \n\ntemplate<class T>\nstruct area_of_union_rectangles {\nprivate:\n\tstd::vector<T>\
    \ ys;\n\tstd::vector<tuple<T, int, int>>xs;\n\tstd::vector<tuple<T, T, T, T>>\
    \ rectangles;\n\tusing S = pair<int, T>;\n\tusing F = int;\n\tstatic S op(S a,\
    \ S b){\n\t\tif(a.first < b.first)return a;\n\t\tif(a.first > b.first)return b;\n\
    \t\treturn make_pair(a.first, a.second+b.second);\n\t}\n\tstatic S e(){ return\
    \ make_pair(std::numeric_limits<int>::max()/2, 0); }\n\tstatic S mapping(F f,\
    \ S x){ return make_pair(x.first+f, x.second); }\n\tstatic F composition(F f,\
    \ F g){ return f+g; }\n\tstatic F id(){ return 0; }\npublic:\n\n\t// l, d, r,\
    \ u\n\tarea_of_union_rectangles(std::vector<tuple<T, T, T, T>> _rectangles) :\
    \ rectangles(_rectangles) {\n\t\tys.reserve(rectangles.size()+rectangles.size());\n\
    \t\txs.reserve(rectangles.size()+rectangles.size());\n\n\t\tfor(size_t i = 0;i\
    \ < rectangles.size();i++){\n\t\t\tauto &[l, d, r, u] = rectangles[i];\n\t\t\t\
    ys.emplace_back(d);\n\t\t\tys.emplace_back(u);\n\t\t\txs.emplace_back(l, i, 1);\n\
    \t\t\txs.emplace_back(r, i, -1);\n\t\t}\n\n\t\tsort(ys.begin(), ys.end());\n\t\
    \tys.erase(unique(ys.begin(), ys.end()), ys.end());\n\t\tsort(xs.begin(), xs.end());\n\
    \n\t\tmap<T, int> y_compress;\n\t\tfor(size_t i = 0;i < ys.size();i++){\n\t\t\t\
    y_compress[ys[i]] = i;\n\t\t}\n\t\tfor(size_t i = 0;i < rectangles.size();i++){\n\
    \t\t\tauto &[l, d, r, u] = rectangles[i];\n\t\t\tu = y_compress[u];\n\t\t\td =\
    \ y_compress[d];\n\t\t}\n\t};\n\n\ttemplate<typename U>\n\tU solve(){\n\t\tstd::vector<S>\
    \ vs((int)ys.size()-1);\n\t\tfor(size_t i = 0;i+1 < ys.size();i++){\n\t\t\tvs[i]\
    \ = make_pair(0, ys[i+1]-ys[i]);\n\t\t}\n\t\tlazy_segment_tree<S, op, e, F, mapping,\
    \ composition, id> seg(vs);\n\t\t\n\t\tU ret = 0;\n\n\t\tT total = ys.back() -\
    \ ys.front();\n\t\tfor(size_t i = 0;i+1 < xs.size();i++){\n\t\t\tauto &[X, idx,\
    \ delta] = xs[i];\n\t\t\tauto &[l, d, r, u] = rectangles[idx];\n\t\t\tseg.apply(d,\
    \ u, delta);\n\n\t\t\tauto [mn, cnt] = seg.all_fold();\n\n\t\t\tU dy = total -\
    \ (mn == 0 ? cnt : 0);\n\t\t\tU dx = get<0>(xs[i+1]) - X;\n\n\t\t\tret += dy*dx;\n\
    \t\t}\n\n\t\treturn ret;\n\t}\n};\n"
  code: "#include \"./lazy_segment_tree.hpp\"\n\ntemplate<class T>\nstruct area_of_union_rectangles\
    \ {\nprivate:\n\tstd::vector<T> ys;\n\tstd::vector<tuple<T, int, int>>xs;\n\t\
    std::vector<tuple<T, T, T, T>> rectangles;\n\tusing S = pair<int, T>;\n\tusing\
    \ F = int;\n\tstatic S op(S a, S b){\n\t\tif(a.first < b.first)return a;\n\t\t\
    if(a.first > b.first)return b;\n\t\treturn make_pair(a.first, a.second+b.second);\n\
    \t}\n\tstatic S e(){ return make_pair(std::numeric_limits<int>::max()/2, 0); }\n\
    \tstatic S mapping(F f, S x){ return make_pair(x.first+f, x.second); }\n\tstatic\
    \ F composition(F f, F g){ return f+g; }\n\tstatic F id(){ return 0; }\npublic:\n\
    \n\t// l, d, r, u\n\tarea_of_union_rectangles(std::vector<tuple<T, T, T, T>> _rectangles)\
    \ : rectangles(_rectangles) {\n\t\tys.reserve(rectangles.size()+rectangles.size());\n\
    \t\txs.reserve(rectangles.size()+rectangles.size());\n\n\t\tfor(size_t i = 0;i\
    \ < rectangles.size();i++){\n\t\t\tauto &[l, d, r, u] = rectangles[i];\n\t\t\t\
    ys.emplace_back(d);\n\t\t\tys.emplace_back(u);\n\t\t\txs.emplace_back(l, i, 1);\n\
    \t\t\txs.emplace_back(r, i, -1);\n\t\t}\n\n\t\tsort(ys.begin(), ys.end());\n\t\
    \tys.erase(unique(ys.begin(), ys.end()), ys.end());\n\t\tsort(xs.begin(), xs.end());\n\
    \n\t\tmap<T, int> y_compress;\n\t\tfor(size_t i = 0;i < ys.size();i++){\n\t\t\t\
    y_compress[ys[i]] = i;\n\t\t}\n\t\tfor(size_t i = 0;i < rectangles.size();i++){\n\
    \t\t\tauto &[l, d, r, u] = rectangles[i];\n\t\t\tu = y_compress[u];\n\t\t\td =\
    \ y_compress[d];\n\t\t}\n\t};\n\n\ttemplate<typename U>\n\tU solve(){\n\t\tstd::vector<S>\
    \ vs((int)ys.size()-1);\n\t\tfor(size_t i = 0;i+1 < ys.size();i++){\n\t\t\tvs[i]\
    \ = make_pair(0, ys[i+1]-ys[i]);\n\t\t}\n\t\tlazy_segment_tree<S, op, e, F, mapping,\
    \ composition, id> seg(vs);\n\t\t\n\t\tU ret = 0;\n\n\t\tT total = ys.back() -\
    \ ys.front();\n\t\tfor(size_t i = 0;i+1 < xs.size();i++){\n\t\t\tauto &[X, idx,\
    \ delta] = xs[i];\n\t\t\tauto &[l, d, r, u] = rectangles[idx];\n\t\t\tseg.apply(d,\
    \ u, delta);\n\n\t\t\tauto [mn, cnt] = seg.all_fold();\n\n\t\t\tU dy = total -\
    \ (mn == 0 ? cnt : 0);\n\t\t\tU dx = get<0>(xs[i+1]) - X;\n\n\t\t\tret += dy*dx;\n\
    \t\t}\n\n\t\treturn ret;\n\t}\n};\n"
  dependsOn:
  - data_structure/lazy_segment_tree.hpp
  isVerificationFile: false
  path: data_structure/area_of_union_of_rectangles.hpp
  requiredBy: []
  timestamp: '2025-06-30 19:47:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/area_of_union_of_rectangles.test.cpp
documentation_of: data_structure/area_of_union_of_rectangles.hpp
layout: document
title: "area_of_union_of_rectangles(\u9577\u65B9\u5F62\u306E\u548C\u96C6\u5408\u306E\
  \u9762\u7A4D)"
---

# area_of_union_of_rectangles(長方形の和集合の面積)

## 使い方

- 要素数を $N$ とする
- ``area_of_union_of_rectangles<T>(vector<tuple<T, T, T, T> rectangles).solve<T2>()`` : $i$ 番目の長方形を $\{(x, y) : l_i \leq x \leq r_i, d_i \leq y \leq u_i\}$ で表すとき、この和集合の面積を返す。 $O(N \log{N})$

## 説明

$(\text{最小値}, \text{最小値となっている数})$ を持つ遅延セグ木を使って $y$ 座標を走査することによって求めることができる。

走査する際には、重なっている長方形の数が $0$ である部分について数えている。
