---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: string/suffix_array.hpp
    title: Suffix Array
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/number_of_substrings
    links:
    - https://judge.yosupo.jp/problem/number_of_substrings
  bundledCode: "#line 1 \"verify/yosupo/number_of_substrings.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/number_of_substrings\"\n\n#line 1 \"template/template.hpp\"\
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
    \ 2 \"string/suffix_array.hpp\"\n\n#line 5 \"string/suffix_array.hpp\"\n\ntemplate\
    \ <typename T> struct suffix_array {\n\tT s;\n\tstd::vector<int> sa;\n\tstd::vector<int>\
    \ rank;\n\tstd::vector<int> lcp;\n\n\tsuffix_array(const T &str, bool gen_lcp\
    \ = true) : s(str) {\n\t\tint n = (int)s.size();\n\t\tsa.resize(n+1);\n\t\tstd::iota(sa.begin(),\
    \ sa.end(), 0);\n\t\trank.assign(n+1, -1);\n\t\tfor(int i = 0;i < n;i++){\n\t\t\
    \trank[i] = s[i];\n\t\t}\n\t\tstd::vector<int> tmp(n+1);\n\t\tint k;\n\t\tauto\
    \ comp_sa = [&](int i, int j) -> bool {\n\t\t\tif(rank[i] != rank[j])return rank[i]\
    \ < rank[j];\n\t\t\tint ri = i + k <= n ? rank[i+k] : -1;\n\t\t\tint rj = j +\
    \ k <= n ? rank[j+k] : -1;\n\t\t\treturn ri < rj;\n\t\t};\n\t\tfor(k = 1;k <=\
    \ n;k *= 2){\n\t\t\tsort(sa.begin(), sa.end(), comp_sa);\n\t\t\ttmp[sa[0]] = 0;\n\
    \t\t\tfor(int i = 1;i <= n;i++){\n\t\t\t\ttmp[sa[i]] = tmp[sa[i-1]] + (comp_sa(sa[i-1],\
    \ sa[i]) ? 1 : 0);\n\t\t\t}\n\t\t\trank = tmp;\n\t\t}\n\n\t\tif(not gen_lcp)return;\n\
    \n\t\tlcp.assign(n, 0);\n\t\tint h = 0;\n\t\tfor(int i = 0;i < n;i++){\n\t\t\t\
    int j = sa[rank[i]-1];\n\t\t\tif(h)h--;\n\t\t\tfor(;j+h < n and i+h < n;h++){\n\
    \t\t\t\tif(s[j+h] != s[i+h])break;\n\t\t\t}\n\t\t\tlcp[rank[i]-1] = h;\n\t\t}\n\
    \t}\n};\n#line 5 \"verify/yosupo/number_of_substrings.test.cpp\"\n\nvoid mmrz::solve(){\n\
    \tstring s;\n\tcin >> s;\n\tsuffix_array sa(s, true);\n\tll ans = len(s)*(len(s)+1)/2;\n\
    \tans -= accumulate(all(sa.lcp), 0LL);\n\tcout << ans << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/number_of_substrings\"\n\
    \n#include \"./../../template/template.hpp\"\n#include \"./../../string/suffix_array.hpp\"\
    \n\nvoid mmrz::solve(){\n\tstring s;\n\tcin >> s;\n\tsuffix_array sa(s, true);\n\
    \tll ans = len(s)*(len(s)+1)/2;\n\tans -= accumulate(all(sa.lcp), 0LL);\n\tcout\
    \ << ans << '\\n';\n}\n"
  dependsOn:
  - template/template.hpp
  - string/suffix_array.hpp
  isVerificationFile: true
  path: verify/yosupo/number_of_substrings.test.cpp
  requiredBy: []
  timestamp: '2025-07-01 03:22:56+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo/number_of_substrings.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/number_of_substrings.test.cpp
- /verify/verify/yosupo/number_of_substrings.test.cpp.html
title: verify/yosupo/number_of_substrings.test.cpp
---
