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
  bundledCode: "#line 1 \"template/bint.hpp\"\nostream& operator<<(ostream& os, __int128_t\
    \ value) {\n\tif (value == 0) return os << '0';\n\tbool neg = false;\n\tif (value\
    \ < 0) {\n\t\tneg = true;\n\t\tvalue = -value;\n\t}\n\tstring s;\n\twhile (value\
    \ > 0) {\n\t\ts += '0' + value % 10;\n\t\tvalue /= 10;\n\t}\n\tif (neg) s += '-';\n\
    \treverse(s.begin(), s.end());\n\treturn os << s;\n}\nistream& operator>>(istream&\
    \ is, __int128_t& value) {\n\tstring s;\n\tis >> s;\n\tvalue = 0;\n\tbool neg\
    \ = false;\n\tsize_t i = 0;\n\tif (s[0] == '-') {\n\t\tneg = true;\n\t\ti = 1;\n\
    \t}\n\tfor (; i < s.size(); ++i) {\n\t\tvalue = value * 10 + (s[i] - '0');\n\t\
    }\n\tif (neg) value = -value;\n\treturn is;\n}\nusing bint = __int128_t;\n"
  code: "ostream& operator<<(ostream& os, __int128_t value) {\n\tif (value == 0) return\
    \ os << '0';\n\tbool neg = false;\n\tif (value < 0) {\n\t\tneg = true;\n\t\tvalue\
    \ = -value;\n\t}\n\tstring s;\n\twhile (value > 0) {\n\t\ts += '0' + value % 10;\n\
    \t\tvalue /= 10;\n\t}\n\tif (neg) s += '-';\n\treverse(s.begin(), s.end());\n\t\
    return os << s;\n}\nistream& operator>>(istream& is, __int128_t& value) {\n\t\
    string s;\n\tis >> s;\n\tvalue = 0;\n\tbool neg = false;\n\tsize_t i = 0;\n\t\
    if (s[0] == '-') {\n\t\tneg = true;\n\t\ti = 1;\n\t}\n\tfor (; i < s.size(); ++i)\
    \ {\n\t\tvalue = value * 10 + (s[i] - '0');\n\t}\n\tif (neg) value = -value;\n\
    \treturn is;\n}\nusing bint = __int128_t;\n"
  dependsOn: []
  isVerificationFile: false
  path: template/bint.hpp
  requiredBy: []
  timestamp: '2025-06-09 11:27:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/bint.hpp
layout: document
redirect_from:
- /library/template/bint.hpp
- /library/template/bint.hpp.html
title: template/bint.hpp
---
