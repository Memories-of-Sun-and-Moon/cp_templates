---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo/set_xor_min.test.cpp
    title: verify/yosupo/set_xor_min.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/binary_trie.hpp\"\n\n#include<cassert>\n\
    #include<utility>\n#include<vector>\n\ntemplate<typename T, int MAX_LOG=31, typename\
    \ D=int>\nstruct binary_trie {\n\tstruct Node {\n\t\tNode *nxt[2];\n\t\tD exist;\n\
    \t\tstd::vector<int> accept;\n\n\t\tNode() : nxt{nullptr, nullptr}, exist(0) {}\n\
    \t};\n\n\tNode *root;\n\n\texplicit binary_trie() : root(new Node()) {}\n\texplicit\
    \ binary_trie(Node *_root) : root(_root) {}\n\n\t~binary_trie() { clear(root);\
    \ }\n\n\tvoid add(const T &bit, int idx=-1, D delta=1, T xor_val=0) {\n\t\troot\
    \ = add(root, bit, idx, MAX_LOG, delta, xor_val);\n\t}\n\n\tvoid erase(const T\
    \ &bit, T xor_val=0) {\n\t\tadd(bit, -1, -1, xor_val);\n\t}\n\n\tNode *find(const\
    \ T &bit, T xor_val=0) {\n\t\treturn find(root, bit, MAX_LOG, xor_val);\n\t}\n\
    \n\tD count(const T &bit, T xor_val=0) {\n\t\tauto node = find(bit, xor_val);\n\
    \t\treturn (node ? node->exist : 0);\n\t}\n\n\tstd::pair<T, Node *> min_element(T\
    \ xor_val=0) {\n\t\tassert(root->exist > 0);\n\t\treturn kth_element(0, xor_val);\n\
    \t}\n\n\tstd::pair<T, Node *> max_element(T xor_val=0) {\n\t\tassert(root->exist\
    \ > 0);\n\t\treturn kth_element(root->exist - 1, xor_val);\n\t}\n\n\tstd::pair<T,\
    \ Node *> kth_element(D k, T xor_val=0) {\n\t\tassert(0 <= k && k < root->exist);\n\
    \t\treturn kth_element(root, k, MAX_LOG, xor_val);\n\t}\n\n\t// [0, bit)\n\tD\
    \ count_less(const T &bit, T xor_val=0) {\n\t\treturn count_less(root, bit, MAX_LOG,\
    \ xor_val);\n\t}\nprivate:\n\tvirtual Node *clone(Node *t) { return t; }\n\n\t\
    Node *add(Node *t, T bit, int idx, int depth, D x, T xor_val, bool need=true)\
    \ {\n\t\tif(need) clone(t);\n\t\tif(depth == -1){\n\t\t\tt->exist += x;\n\t\t\t\
    if(idx >= 0) t->accept.emplace_back(idx);\n\t\t}else{\n\t\t\tbool f = (xor_val\
    \ >> depth) & 1;\n\t\t\tauto &to = t->nxt[f ^ ((bit >> depth) & 1)];\n\t\t\tif(not\
    \ to) to = new Node(), need = false;\n\t\t\tto = add(to, bit, idx, depth-1, x,\
    \ xor_val, need);\n\t\t\tt->exist += x;\n\t\t}\n\t\treturn t;\n\t}\n\t\n\tNode\
    \ *find(Node *t, T bit, int depth, T xor_val) {\n\t\tif(depth == -1) {\n\t\t\t\
    return t;\n\t\t}else{\n\t\t\tbool f = (xor_val >> depth) & 1;\n\t\t\tauto &to\
    \ = t->nxt[f ^ ((bit >> depth) & 1)];\n\t\t\treturn (to ? find(to, bit, depth-1,\
    \ xor_val) : nullptr);\n\t\t}\n\t}\n\t\n\tstd::pair<T, Node *> kth_element(Node\
    \ *t, D k, int depth, T xor_val) {\n\t\tif(depth == -1) {\n\t\t\treturn {0, t};\n\
    \t\t}else{\n\t\t\tbool f = (xor_val >> depth) & 1;\n\t\t\tif((t->nxt[f] ? t->nxt[f]->exist\
    \ : 0) <= k) {\n\t\t\t\tauto ret = kth_element(t->nxt[f^1], k-(t->nxt[f] ? t->nxt[f]->exist\
    \ : 0), depth-1, xor_val);\n\t\t\t\tret.first |= T(1) << depth;\n\t\t\t\treturn\
    \ ret;\n\t\t\t}else{\n\t\t\t\treturn kth_element(t->nxt[f], k, depth-1, xor_val);\n\
    \t\t\t}\n\t\t}\n\t}\n\t\n\tD count_less(Node *t, const T &bit, int depth, T xor_val)\
    \ {\n\t\tif(depth == -1)return 0;\n\t\tD ret = 0;\n\t\tbool f = (xor_val >> depth)\
    \ & 1;\n\t\tif((bit >> depth & 1) and t->nxt[f])ret += t->nxt[f]->exist;\n\t\t\
    if(t->nxt[f^(bit >> depth & 1)]){\n\t\t\tret += count_less(t->nxt[f^(bit >> depth\
    \ & 1)], bit, depth-1, xor_val);\n\t\t}\n\t\treturn ret;\n\t}\n\n\tvoid clear(Node\
    \ *t) {\n\t\tif (!t) return;\n\t\tclear(t->nxt[0]);\n\t\tclear(t->nxt[1]);\n\t\
    \tdelete t;\n\t}\n};\n"
  code: "#pragma once\n\n#include<cassert>\n#include<utility>\n#include<vector>\n\n\
    template<typename T, int MAX_LOG=31, typename D=int>\nstruct binary_trie {\n\t\
    struct Node {\n\t\tNode *nxt[2];\n\t\tD exist;\n\t\tstd::vector<int> accept;\n\
    \n\t\tNode() : nxt{nullptr, nullptr}, exist(0) {}\n\t};\n\n\tNode *root;\n\n\t\
    explicit binary_trie() : root(new Node()) {}\n\texplicit binary_trie(Node *_root)\
    \ : root(_root) {}\n\n\t~binary_trie() { clear(root); }\n\n\tvoid add(const T\
    \ &bit, int idx=-1, D delta=1, T xor_val=0) {\n\t\troot = add(root, bit, idx,\
    \ MAX_LOG, delta, xor_val);\n\t}\n\n\tvoid erase(const T &bit, T xor_val=0) {\n\
    \t\tadd(bit, -1, -1, xor_val);\n\t}\n\n\tNode *find(const T &bit, T xor_val=0)\
    \ {\n\t\treturn find(root, bit, MAX_LOG, xor_val);\n\t}\n\n\tD count(const T &bit,\
    \ T xor_val=0) {\n\t\tauto node = find(bit, xor_val);\n\t\treturn (node ? node->exist\
    \ : 0);\n\t}\n\n\tstd::pair<T, Node *> min_element(T xor_val=0) {\n\t\tassert(root->exist\
    \ > 0);\n\t\treturn kth_element(0, xor_val);\n\t}\n\n\tstd::pair<T, Node *> max_element(T\
    \ xor_val=0) {\n\t\tassert(root->exist > 0);\n\t\treturn kth_element(root->exist\
    \ - 1, xor_val);\n\t}\n\n\tstd::pair<T, Node *> kth_element(D k, T xor_val=0)\
    \ {\n\t\tassert(0 <= k && k < root->exist);\n\t\treturn kth_element(root, k, MAX_LOG,\
    \ xor_val);\n\t}\n\n\t// [0, bit)\n\tD count_less(const T &bit, T xor_val=0) {\n\
    \t\treturn count_less(root, bit, MAX_LOG, xor_val);\n\t}\nprivate:\n\tvirtual\
    \ Node *clone(Node *t) { return t; }\n\n\tNode *add(Node *t, T bit, int idx, int\
    \ depth, D x, T xor_val, bool need=true) {\n\t\tif(need) clone(t);\n\t\tif(depth\
    \ == -1){\n\t\t\tt->exist += x;\n\t\t\tif(idx >= 0) t->accept.emplace_back(idx);\n\
    \t\t}else{\n\t\t\tbool f = (xor_val >> depth) & 1;\n\t\t\tauto &to = t->nxt[f\
    \ ^ ((bit >> depth) & 1)];\n\t\t\tif(not to) to = new Node(), need = false;\n\t\
    \t\tto = add(to, bit, idx, depth-1, x, xor_val, need);\n\t\t\tt->exist += x;\n\
    \t\t}\n\t\treturn t;\n\t}\n\t\n\tNode *find(Node *t, T bit, int depth, T xor_val)\
    \ {\n\t\tif(depth == -1) {\n\t\t\treturn t;\n\t\t}else{\n\t\t\tbool f = (xor_val\
    \ >> depth) & 1;\n\t\t\tauto &to = t->nxt[f ^ ((bit >> depth) & 1)];\n\t\t\treturn\
    \ (to ? find(to, bit, depth-1, xor_val) : nullptr);\n\t\t}\n\t}\n\t\n\tstd::pair<T,\
    \ Node *> kth_element(Node *t, D k, int depth, T xor_val) {\n\t\tif(depth == -1)\
    \ {\n\t\t\treturn {0, t};\n\t\t}else{\n\t\t\tbool f = (xor_val >> depth) & 1;\n\
    \t\t\tif((t->nxt[f] ? t->nxt[f]->exist : 0) <= k) {\n\t\t\t\tauto ret = kth_element(t->nxt[f^1],\
    \ k-(t->nxt[f] ? t->nxt[f]->exist : 0), depth-1, xor_val);\n\t\t\t\tret.first\
    \ |= T(1) << depth;\n\t\t\t\treturn ret;\n\t\t\t}else{\n\t\t\t\treturn kth_element(t->nxt[f],\
    \ k, depth-1, xor_val);\n\t\t\t}\n\t\t}\n\t}\n\t\n\tD count_less(Node *t, const\
    \ T &bit, int depth, T xor_val) {\n\t\tif(depth == -1)return 0;\n\t\tD ret = 0;\n\
    \t\tbool f = (xor_val >> depth) & 1;\n\t\tif((bit >> depth & 1) and t->nxt[f])ret\
    \ += t->nxt[f]->exist;\n\t\tif(t->nxt[f^(bit >> depth & 1)]){\n\t\t\tret += count_less(t->nxt[f^(bit\
    \ >> depth & 1)], bit, depth-1, xor_val);\n\t\t}\n\t\treturn ret;\n\t}\n\n\tvoid\
    \ clear(Node *t) {\n\t\tif (!t) return;\n\t\tclear(t->nxt[0]);\n\t\tclear(t->nxt[1]);\n\
    \t\tdelete t;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/binary_trie.hpp
  requiredBy: []
  timestamp: '2025-07-01 03:22:56+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo/set_xor_min.test.cpp
documentation_of: data_structure/binary_trie.hpp
layout: document
title: Binary Trie
---

# Binary Trie

整数をビット列とみなして、 Trie 木のように管理するデータ構造。

整数集合と、XOR 演算につよい。

[参考](https://ei1333.github.io/library/structure/trie/binary-trie.hpp)
