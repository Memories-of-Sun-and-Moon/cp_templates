---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/dsl/2_F.test.cpp
    title: verify/aoj/dsl/2_F.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/lazy_segment_tree.hpp\"\n\ntemplate<class\
    \ S, auto op, auto e, class F, auto mapping, auto composition, auto id>\nstruct\
    \ lazy_segment_tree {\nprivate:\n\tint n;\n\tint log;\n\tint size;\n\tvector<S>\
    \ node;\n\tvector<F> lazy;\n\n\tvoid update(int k) { node[k] = op(node[2 * k],\
    \ node[2 * k + 1]); }\n\tvoid all_apply(int k, F f) {\n\t\tnode[k] = mapping(f,\
    \ node[k]);\n\t\tif(k < size) lazy[k] = composition(f, lazy[k]);\n\t}\n\tvoid\
    \ push(int k) {\n\t\tall_apply(2*k + 0, lazy[k]);\n\t\tall_apply(2*k + 1, lazy[k]);\n\
    \t\tlazy[k] = id();\n\t}\npublic:\n\tlazy_segment_tree() : lazy_segment_tree(0)\
    \ {}\n\n\tlazy_segment_tree(int _n) : lazy_segment_tree(vector<S>(_n, e())) {}\n\
    \n\tlazy_segment_tree(const vector<S> &v) : n((int)v.size()) {\n\t\tsize = 1;\n\
    \t\twhile(size < n) size <<= 1;\n\n\t\tlog = __builtin_ctz(size);\n\n\t\tnode.resize(2*size,\
    \ e());\n\t\tlazy.resize(size, id());\n\n\t\tfor(int i = 0;i < n;i++)node[i +\
    \ size] = v[i];\n\t\tfor(int i = size-1;i >= 1;i--)node[i] = op(node[2*i + 0],\
    \ node[2*i + 1]);\n\t}\n\n\tvoid set(int x, S val) {\n\t\tassert(0 <= x && x <\
    \ n);\n\t\tx += size;\n\n\t\tfor(int i = log;i >= 1;i--)push(x >> i);\n\t\tnode[x]\
    \ = val;\n\t\tfor(int i = 1;i <= log;i++)update(x >> i);\n\t}\n\n\tS operator[](int\
    \ x) {\n\t\tassert(0 <= x && x < n);\n\t\tx += size;\n\n\t\tfor(int i = log;i\
    \ >= 1;i--)push(x >> i);\n\t\treturn node[x];\n\t}\n\n\tS fold(int l, int r) {\n\
    \t\tassert(0 <= l && l <= r && r <= n);\n\t\tif(l == r)return e();\n\n\t\tl +=\
    \ size;\n\t\tr += size;\n\n\t\tfor(int i = log;i >= 1;i--) {\n\t\t\tif(((l >>\
    \ i) << i) != l)push(l >> i);\n\t\t\tif(((r >> i) << i) != r)push((r-1) >> i);\n\
    \t\t}\n\n\t\tS L = e(), R = e();\n\t\tfor(;l < r;l >>= 1, r >>= 1){\n\t\t\tif(l&1)L\
    \ = op(L, node[l++]);\n\t\t\tif(r&1)R = op(node[--r], R);\n\t\t}\n\t\treturn op(L,\
    \ R);\n\t}\n\n\t// ACL \u306B\u3053\u306E\u5B9F\u88C5\u304C\u3042\u308B\u3093\u3060\
    \u3051\u3069\u5FC3\u914D\uFF1F\n\t//S all_fold() { return node[1]; };\n\n\tvoid\
    \ apply(int x, F f) {\n\t\tassert(0 <= x && x < n);\n\n\t\tx += size;\n\t\tfor(int\
    \ i = log;i >= 1;i--)push(x >> i);\n\t\tnode[x] = mapping(f, node[x]);\n\t\tfor(int\
    \ i = 1;i <= log;i++)update(x >> i);\n\t}\n\n\tvoid apply(int l, int r, F f) {\n\
    \t\tassert(0 <= l && l <= r && r <= n);\n\t\tif(l == r)return;\n\n\t\tl += size;\n\
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
    \ sum);\n\t\t}while((r&-r) != r);\n\t\treturn n;\n\t}\n};\n"
  code: "\ntemplate<class S, auto op, auto e, class F, auto mapping, auto composition,\
    \ auto id>\nstruct lazy_segment_tree {\nprivate:\n\tint n;\n\tint log;\n\tint\
    \ size;\n\tvector<S> node;\n\tvector<F> lazy;\n\n\tvoid update(int k) { node[k]\
    \ = op(node[2 * k], node[2 * k + 1]); }\n\tvoid all_apply(int k, F f) {\n\t\t\
    node[k] = mapping(f, node[k]);\n\t\tif(k < size) lazy[k] = composition(f, lazy[k]);\n\
    \t}\n\tvoid push(int k) {\n\t\tall_apply(2*k + 0, lazy[k]);\n\t\tall_apply(2*k\
    \ + 1, lazy[k]);\n\t\tlazy[k] = id();\n\t}\npublic:\n\tlazy_segment_tree() : lazy_segment_tree(0)\
    \ {}\n\n\tlazy_segment_tree(int _n) : lazy_segment_tree(vector<S>(_n, e())) {}\n\
    \n\tlazy_segment_tree(const vector<S> &v) : n((int)v.size()) {\n\t\tsize = 1;\n\
    \t\twhile(size < n) size <<= 1;\n\n\t\tlog = __builtin_ctz(size);\n\n\t\tnode.resize(2*size,\
    \ e());\n\t\tlazy.resize(size, id());\n\n\t\tfor(int i = 0;i < n;i++)node[i +\
    \ size] = v[i];\n\t\tfor(int i = size-1;i >= 1;i--)node[i] = op(node[2*i + 0],\
    \ node[2*i + 1]);\n\t}\n\n\tvoid set(int x, S val) {\n\t\tassert(0 <= x && x <\
    \ n);\n\t\tx += size;\n\n\t\tfor(int i = log;i >= 1;i--)push(x >> i);\n\t\tnode[x]\
    \ = val;\n\t\tfor(int i = 1;i <= log;i++)update(x >> i);\n\t}\n\n\tS operator[](int\
    \ x) {\n\t\tassert(0 <= x && x < n);\n\t\tx += size;\n\n\t\tfor(int i = log;i\
    \ >= 1;i--)push(x >> i);\n\t\treturn node[x];\n\t}\n\n\tS fold(int l, int r) {\n\
    \t\tassert(0 <= l && l <= r && r <= n);\n\t\tif(l == r)return e();\n\n\t\tl +=\
    \ size;\n\t\tr += size;\n\n\t\tfor(int i = log;i >= 1;i--) {\n\t\t\tif(((l >>\
    \ i) << i) != l)push(l >> i);\n\t\t\tif(((r >> i) << i) != r)push((r-1) >> i);\n\
    \t\t}\n\n\t\tS L = e(), R = e();\n\t\tfor(;l < r;l >>= 1, r >>= 1){\n\t\t\tif(l&1)L\
    \ = op(L, node[l++]);\n\t\t\tif(r&1)R = op(node[--r], R);\n\t\t}\n\t\treturn op(L,\
    \ R);\n\t}\n\n\t// ACL \u306B\u3053\u306E\u5B9F\u88C5\u304C\u3042\u308B\u3093\u3060\
    \u3051\u3069\u5FC3\u914D\uFF1F\n\t//S all_fold() { return node[1]; };\n\n\tvoid\
    \ apply(int x, F f) {\n\t\tassert(0 <= x && x < n);\n\n\t\tx += size;\n\t\tfor(int\
    \ i = log;i >= 1;i--)push(x >> i);\n\t\tnode[x] = mapping(f, node[x]);\n\t\tfor(int\
    \ i = 1;i <= log;i++)update(x >> i);\n\t}\n\n\tvoid apply(int l, int r, F f) {\n\
    \t\tassert(0 <= l && l <= r && r <= n);\n\t\tif(l == r)return;\n\n\t\tl += size;\n\
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
    \ sum);\n\t\t}while((r&-r) != r);\n\t\treturn n;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/lazy_segment_tree.hpp
  requiredBy: []
  timestamp: '2024-09-21 17:14:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/dsl/2_F.test.cpp
documentation_of: data_structure/lazy_segment_tree.hpp
layout: document
redirect_from:
- /library/data_structure/lazy_segment_tree.hpp
- /library/data_structure/lazy_segment_tree.hpp.html
title: data_structure/lazy_segment_tree.hpp
---
