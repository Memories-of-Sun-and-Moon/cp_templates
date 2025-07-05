---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/binary_trie.hpp
    title: Binary Trie
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/set_xor_min
    links:
    - https://judge.yosupo.jp/problem/set_xor_min
  bundledCode: "#line 1 \"verify/yosupo/set_xor_min.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/set_xor_min\"\n\n#line 1 \"template/template.hpp\"\
    \n# include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\nusing\
    \ ull = unsigned long long;\nconst double pi = acos(-1);\ntemplate<class T>constexpr\
    \ T inf() { return ::std::numeric_limits<T>::max(); }\ntemplate<class T>constexpr\
    \ T hinf() { return inf<T>() / 2; }\ntemplate <typename T_char>T_char TL(T_char\
    \ cX) { return tolower(cX); }\ntemplate <typename T_char>T_char TU(T_char cX)\
    \ { return toupper(cX); }\ntemplate<class T> bool chmin(T& a,T b) { if(a > b){a\
    \ = b; return true;} return false; }\ntemplate<class T> bool chmax(T& a,T b) {\
    \ if(a < b){a = b; return true;} return false; }\nint popcnt(unsigned long long\
    \ n) { int cnt = 0; for (int i = 0; i < 64; i++)if ((n >> i) & 1)cnt++; return\
    \ cnt; }\nint d_sum(ll n) { int ret = 0; while (n > 0) { ret += n % 10; n /= 10;\
    \ }return ret; }\nint d_cnt(ll n) { int ret = 0; while (n > 0) { ret++; n /= 10;\
    \ }return ret; }\nll gcd(ll a, ll b) { if (b == 0)return a; return gcd(b, a%b);\
    \ };\nll lcm(ll a, ll b) { ll g = gcd(a, b); return a / g*b; };\nll MOD(ll x,\
    \ ll m){return (x%m+m)%m; }\nll FLOOR(ll x, ll m) {ll r = (x%m+m)%m; return (x-r)/m;\
    \ }\ntemplate<class T> using dijk = priority_queue<T, vector<T>, greater<T>>;\n\
    # define all(qpqpq)           (qpqpq).begin(),(qpqpq).end()\n# define UNIQUE(wpwpw)\
    \        (wpwpw).erase(unique(all((wpwpw))),(wpwpw).end())\n# define LOWER(epepe)\
    \         transform(all((epepe)),(epepe).begin(),TL<char>)\n# define UPPER(rprpr)\
    \         transform(all((rprpr)),(rprpr).begin(),TU<char>)\n# define rep(i,upupu)\
    \         for(ll i = 0, i##_len = (upupu);(i) < (i##_len);(i)++)\n# define reps(i,opopo)\
    \        for(ll i = 1, i##_len = (opopo);(i) <= (i##_len);(i)++)\n# define len(x)\
    \                ((ll)(x).size())\n# define bit(n)               (1LL << (n))\n\
    # define pb push_back\n# define eb emplace_back\n# define exists(c, e)       \
    \  ((c).find(e) != (c).end())\n\nstruct INIT{\n\tINIT(){\n\t\tstd::ios::sync_with_stdio(false);\n\
    \t\tstd::cin.tie(0);\n\t\tcout << fixed << setprecision(20);\n\t}\n}INIT;\n\n\
    namespace mmrz {\n\tvoid solve();\n}\n\nint main(){\n\tmmrz::solve();\n}\n#line\
    \ 2 \"data_structure/binary_trie.hpp\"\n\n#line 6 \"data_structure/binary_trie.hpp\"\
    \n\ntemplate<typename T, int MAX_LOG=31, typename D=int>\nstruct binary_trie {\n\
    \tstruct Node {\n\t\tNode *nxt[2];\n\t\tD exist;\n\t\tstd::vector<int> accept;\n\
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
    \t\tdelete t;\n\t}\n};\n#line 5 \"verify/yosupo/set_xor_min.test.cpp\"\n\nusing\
    \ namespace mmrz;\n\nvoid mmrz::solve(){\n\tint q;\n\tcin >> q;\n\tbinary_trie<int,\
    \ 29> trie;\n\twhile(q--){\n\t\tint op, x;\n\t\tcin >> op >> x;\n\t\tif(op ==\
    \ 0){\n\t\t\tif(trie.count(x) == 0)trie.add(x);\n\t\t}else if(op == 1){\n\t\t\t\
    if(trie.count(x) != 0)trie.erase(x);\n\t\t}else{\n\t\t\tcout << trie.min_element(x).first\
    \ << '\\n';\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\n\n#include\
    \ \"./../../template/template.hpp\"\n#include \"./../../data_structure/binary_trie.hpp\"\
    \n\nusing namespace mmrz;\n\nvoid mmrz::solve(){\n\tint q;\n\tcin >> q;\n\tbinary_trie<int,\
    \ 29> trie;\n\twhile(q--){\n\t\tint op, x;\n\t\tcin >> op >> x;\n\t\tif(op ==\
    \ 0){\n\t\t\tif(trie.count(x) == 0)trie.add(x);\n\t\t}else if(op == 1){\n\t\t\t\
    if(trie.count(x) != 0)trie.erase(x);\n\t\t}else{\n\t\t\tcout << trie.min_element(x).first\
    \ << '\\n';\n\t\t}\n\t}\n}\n"
  dependsOn:
  - template/template.hpp
  - data_structure/binary_trie.hpp
  isVerificationFile: true
  path: verify/yosupo/set_xor_min.test.cpp
  requiredBy: []
  timestamp: '2025-07-01 03:22:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/set_xor_min.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/set_xor_min.test.cpp
- /verify/verify/yosupo/set_xor_min.test.cpp.html
title: verify/yosupo/set_xor_min.test.cpp
---
