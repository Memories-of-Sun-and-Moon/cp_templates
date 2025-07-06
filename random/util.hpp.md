---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"random/util.hpp\"\n\n#include<cstdint>\n#include<numeric>\n\
    \n/*\n# rng \u306E\u5B9A\u7FA9\nxorshift32 rng;\n\n# \u6574\u6570\u306E\u4E00\u69D8\
    \u5206\u5E03 [a, b]\nstd::uniform_int_distribution<T> uid(a, b);\nT random_number\
    \ = uid(rng);\n\n# \u5B9F\u6570\u306E\u4E00\u69D8\u5206\u5E03 [a, b)\nstd::uniform_real_distribution<T>\
    \ uid(a, b);\nT random_number = uid(rng);\n\n# \u5E73\u5747 \u03BC, \u6A19\u6E96\
    \u504F\u5DEE \u03C3 \u306E\u6B63\u898F\u5206\u5E03\nstd::normal_distribution<T>\
    \ nd(\u03BC, \u03C3)\nT random_number = nd(rng);\n\n# n \u8A66\u884C\u4E2D p \u306E\
    \u78BA\u7387\u3067\u6210\u529F\u3059\u308B\u4E8C\u9805\u5206\u5E03\u306E\u6210\
    \u529F\u3057\u305F\u56DE\u6570(\u6574\u6570)\nstd::binomial_distribution<T> bd(n,\
    \ p);\nT random_number = bd(rng);\n*/\nstruct xorshift32 {\nprivate:\n\tuint32_t\
    \ state;\npublic:\n\txorshift32(uint32_t seed = 33122) : state(seed) {}\n\n\t\
    static constexpr uint32_t min() { return 0; }\n\tstatic constexpr uint32_t max()\
    \ { return std::numeric_limits<uint32_t>::max(); }\n\n\tuint32_t operator()()\
    \ {\n\t\tstate ^= state << 13;\n\t\tstate ^= state >> 17;\n\t\tstate ^= state\
    \ << 5;\n\t\treturn state;\n\t}\n};\n\n/*\n# rng \u306E\u5B9A\u7FA9\nxorshift32\
    \ rng;\n\n# \u6574\u6570\u306E\u4E00\u69D8\u5206\u5E03 [a, b]\nstd::uniform_int_distribution<T>\
    \ uid(a, b);\nT random_number = uid(rng);\n\n# \u5B9F\u6570\u306E\u4E00\u69D8\u5206\
    \u5E03 [a, b)\nstd::uniform_real_distribution<T> uid(a, b);\nT random_number =\
    \ uid(rng);\n\n# \u5E73\u5747 \u03BC, \u6A19\u6E96\u504F\u5DEE \u03C3 \u306E\u6B63\
    \u898F\u5206\u5E03\nstd::normal_distribution<T> nd(\u03BC, \u03C3)\nT random_number\
    \ = nd(rng);\n\n# n \u8A66\u884C\u4E2D p \u306E\u78BA\u7387\u3067\u6210\u529F\u3059\
    \u308B\u4E8C\u9805\u5206\u5E03\u306E\u6210\u529F\u3057\u305F\u56DE\u6570(\u6574\
    \u6570)\nstd::binomial_distribution<T> bd(n, p);\nT random_number = bd(rng);\n\
    */\nstruct xorshift64 {\nprivate:\n\tuint64_t state;\npublic:\n\txorshift64(uint64_t\
    \ seed = 33122) : state(seed) {}\n\n\tstatic constexpr uint64_t min() { return\
    \ 0; }\n\tstatic constexpr uint64_t max() { return std::numeric_limits<uint64_t>::max();\
    \ }\n\n\tuint64_t operator()() {\n\t\tstate ^= state << 13;\n\t\tstate ^= state\
    \ >> 7;\n\t\tstate ^= state << 17;\n\t\treturn state;\n\t}\n};\n"
  code: "#pragma once\n\n#include<cstdint>\n#include<numeric>\n\n/*\n# rng \u306E\u5B9A\
    \u7FA9\nxorshift32 rng;\n\n# \u6574\u6570\u306E\u4E00\u69D8\u5206\u5E03 [a, b]\n\
    std::uniform_int_distribution<T> uid(a, b);\nT random_number = uid(rng);\n\n#\
    \ \u5B9F\u6570\u306E\u4E00\u69D8\u5206\u5E03 [a, b)\nstd::uniform_real_distribution<T>\
    \ uid(a, b);\nT random_number = uid(rng);\n\n# \u5E73\u5747 \u03BC, \u6A19\u6E96\
    \u504F\u5DEE \u03C3 \u306E\u6B63\u898F\u5206\u5E03\nstd::normal_distribution<T>\
    \ nd(\u03BC, \u03C3)\nT random_number = nd(rng);\n\n# n \u8A66\u884C\u4E2D p \u306E\
    \u78BA\u7387\u3067\u6210\u529F\u3059\u308B\u4E8C\u9805\u5206\u5E03\u306E\u6210\
    \u529F\u3057\u305F\u56DE\u6570(\u6574\u6570)\nstd::binomial_distribution<T> bd(n,\
    \ p);\nT random_number = bd(rng);\n*/\nstruct xorshift32 {\nprivate:\n\tuint32_t\
    \ state;\npublic:\n\txorshift32(uint32_t seed = 33122) : state(seed) {}\n\n\t\
    static constexpr uint32_t min() { return 0; }\n\tstatic constexpr uint32_t max()\
    \ { return std::numeric_limits<uint32_t>::max(); }\n\n\tuint32_t operator()()\
    \ {\n\t\tstate ^= state << 13;\n\t\tstate ^= state >> 17;\n\t\tstate ^= state\
    \ << 5;\n\t\treturn state;\n\t}\n};\n\n/*\n# rng \u306E\u5B9A\u7FA9\nxorshift32\
    \ rng;\n\n# \u6574\u6570\u306E\u4E00\u69D8\u5206\u5E03 [a, b]\nstd::uniform_int_distribution<T>\
    \ uid(a, b);\nT random_number = uid(rng);\n\n# \u5B9F\u6570\u306E\u4E00\u69D8\u5206\
    \u5E03 [a, b)\nstd::uniform_real_distribution<T> uid(a, b);\nT random_number =\
    \ uid(rng);\n\n# \u5E73\u5747 \u03BC, \u6A19\u6E96\u504F\u5DEE \u03C3 \u306E\u6B63\
    \u898F\u5206\u5E03\nstd::normal_distribution<T> nd(\u03BC, \u03C3)\nT random_number\
    \ = nd(rng);\n\n# n \u8A66\u884C\u4E2D p \u306E\u78BA\u7387\u3067\u6210\u529F\u3059\
    \u308B\u4E8C\u9805\u5206\u5E03\u306E\u6210\u529F\u3057\u305F\u56DE\u6570(\u6574\
    \u6570)\nstd::binomial_distribution<T> bd(n, p);\nT random_number = bd(rng);\n\
    */\nstruct xorshift64 {\nprivate:\n\tuint64_t state;\npublic:\n\txorshift64(uint64_t\
    \ seed = 33122) : state(seed) {}\n\n\tstatic constexpr uint64_t min() { return\
    \ 0; }\n\tstatic constexpr uint64_t max() { return std::numeric_limits<uint64_t>::max();\
    \ }\n\n\tuint64_t operator()() {\n\t\tstate ^= state << 13;\n\t\tstate ^= state\
    \ >> 7;\n\t\tstate ^= state << 17;\n\t\treturn state;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: random/util.hpp
  requiredBy: []
  timestamp: '2025-07-06 18:08:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: random/util.hpp
layout: document
redirect_from:
- /library/random/util.hpp
- /library/random/util.hpp.html
title: random/util.hpp
---
