---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://zenn.dev/reputeless/books/standard-cpp-for-competitive-programming/viewer/lis
  bundledCode: "#line 1 \"LIS.cpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n\
    \n// thx https://zenn.dev/reputeless/books/standard-cpp-for-competitive-programming/viewer/lis\n\
    \ntemplate <bool is_strict, class T> int LIS(const vector<T>& v){\n    vector<T>\
    \ dp;\n\n    auto it = dp.begin();\n\n    for(auto elem : v){\n        if constexpr\
    \ (is_strict){\n            it = lower_bound(dp.begin(), dp.end(), elem);\n  \
    \      }else{\n            it = upper_bound(dp.begin(), dp.end(), elem);\n   \
    \     }\n        if(it == dp.end()){\n            dp.push_back(elem);\n      \
    \  }else{\n            *it = elem;\n        }\n    }\n\n    return int(dp.size());\n\
    }\n\nint main(){\n\n    vector<int> v = {1, 3, 4, 4 ,5, 8, 3};\n\n    // true:\
    \ \u72ED\u7FA9\u5358\u8ABF\u5897\u52A0\n    cout << LIS<true>(v) << endl;\n  \
    \  // false: \u5E83\u7FA9\u5358\u8ABF\u5897\u52A0\n    cout << LIS<false>(v) <<\
    \ endl;\n\n}\n"
  code: "#include<bits/stdc++.h>\nusing namespace std;\n\n// thx https://zenn.dev/reputeless/books/standard-cpp-for-competitive-programming/viewer/lis\n\
    \ntemplate <bool is_strict, class T> int LIS(const vector<T>& v){\n    vector<T>\
    \ dp;\n\n    auto it = dp.begin();\n\n    for(auto elem : v){\n        if constexpr\
    \ (is_strict){\n            it = lower_bound(dp.begin(), dp.end(), elem);\n  \
    \      }else{\n            it = upper_bound(dp.begin(), dp.end(), elem);\n   \
    \     }\n        if(it == dp.end()){\n            dp.push_back(elem);\n      \
    \  }else{\n            *it = elem;\n        }\n    }\n\n    return int(dp.size());\n\
    }\n\nint main(){\n\n    vector<int> v = {1, 3, 4, 4 ,5, 8, 3};\n\n    // true:\
    \ \u72ED\u7FA9\u5358\u8ABF\u5897\u52A0\n    cout << LIS<true>(v) << endl;\n  \
    \  // false: \u5E83\u7FA9\u5358\u8ABF\u5897\u52A0\n    cout << LIS<false>(v) <<\
    \ endl;\n\n}"
  dependsOn: []
  isVerificationFile: false
  path: LIS.cpp
  requiredBy: []
  timestamp: '2023-11-18 18:41:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: LIS.cpp
layout: document
redirect_from:
- /library/LIS.cpp
- /library/LIS.cpp.html
title: LIS.cpp
---
