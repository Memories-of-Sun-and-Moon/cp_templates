---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/hash_map.hpp
    title: "\u30CF\u30C3\u30B7\u30E5\u30DE\u30C3\u30D7"
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
    PROBLEM: https://judge.yosupo.jp/problem/associative_array
    links:
    - https://judge.yosupo.jp/problem/associative_array
  bundledCode: "#line 1 \"verify/yosupo/associative_array.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/associative_array\"\n\n#line 1 \"template/template.hpp\"\
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
    \ 1 \"data_structure/hash_map.hpp\"\n\ntemplate<typename Key, typename Val, uint32_t\
    \ N, typename HashFunc = std::hash<Key>>\nstruct hash_map {\n\tstatic_assert(__builtin_popcount(N)\
    \ == 1);\n\tKey key[N];\n\tVal val[N];\n\tstd::bitset<N> use;\n\t\n\tstatic constexpr\
    \ uint32_t shift = 64 - __builtin_ctz(N);\n\tstatic constexpr uint64_t r = 11995408973635179863ULL;\n\
    \n\tVal& operator[](const Key & k) noexcept {\n\t\tuint64_t h = HashFunc{}(k);\n\
    \t\tuint32_t hash = (h*r) >> shift;\n\t\twhile(true){\n\t\t\tif(!use[hash]){\n\
    \t\t\t\tkey[hash] = k;\n\t\t\t\tuse[hash] = 1;\n\t\t\t\treturn val[hash];\n\t\t\
    \t}\n\t\t\tif(key[hash] == k)return val[hash];\n\t\t\t(++hash) &= (N-1);\n\t\t\
    }\n\t}\n};\n#line 5 \"verify/yosupo/associative_array.test.cpp\"\n\nvoid mmrz::solve(){\n\
    \tint q;\n\tcin >> q;\n\thash_map<ll, ll, bit(20)> mp;\n\twhile(q--){\n\t\tint\
    \ op;\n\t\tcin >> op;\n\t\tif(op == 0){\n\t\t\tll k, v;\n\t\t\tcin >> k >> v;\n\
    \t\t\tmp[k] = v;\n\t\t}else{\n\t\t\tll k;\n\t\t\tcin >> k;\n\t\t\tcout << mp[k]\
    \ << '\\n';\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\n\n\
    #include \"./../../template/template.hpp\"\n#include \"./../../data_structure/hash_map.hpp\"\
    \n\nvoid mmrz::solve(){\n\tint q;\n\tcin >> q;\n\thash_map<ll, ll, bit(20)> mp;\n\
    \twhile(q--){\n\t\tint op;\n\t\tcin >> op;\n\t\tif(op == 0){\n\t\t\tll k, v;\n\
    \t\t\tcin >> k >> v;\n\t\t\tmp[k] = v;\n\t\t}else{\n\t\t\tll k;\n\t\t\tcin >>\
    \ k;\n\t\t\tcout << mp[k] << '\\n';\n\t\t}\n\t}\n}\n"
  dependsOn:
  - template/template.hpp
  - data_structure/hash_map.hpp
  isVerificationFile: true
  path: verify/yosupo/associative_array.test.cpp
  requiredBy: []
  timestamp: '2025-06-30 19:47:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/associative_array.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/associative_array.test.cpp
- /verify/verify/yosupo/associative_array.test.cpp.html
title: verify/yosupo/associative_array.test.cpp
---
