---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: bits/stdc++.h:\
    \ line -1: no such header\n"
  code: "# include \"bits/stdc++.h\"\nusing namespace std;\n\nstruct measure_time{\n\
    \    using timer_point = chrono::high_resolution_clock::time_point;\n    using\
    \ timer_duration = chrono::high_resolution_clock::duration;\nprivate:\n    timer_point\
    \ clock_start;\n    timer_duration time_length;\n    bool is_stopping;\npublic:\n\
    \n    measure_time() : time_length(std::chrono::high_resolution_clock::duration()),\
    \ is_stopping(false) {}\n\n    inline void start(){\n        clock_start = chrono::high_resolution_clock::now();\n\
    \    }\n\n    inline void stop(){\n        assert(is_stopping == false);\n   \
    \     timer_point lap = chrono::high_resolution_clock::now();\n\n        timer_duration\
    \ d = lap - clock_start;\n\n        time_length += d;\n        is_stopping = true;\n\
    \    }\n\n    inline void resume(){\n        assert(is_stopping == true);\n  \
    \      clock_start = chrono::high_resolution_clock::now();\n        is_stopping\
    \ = false;\n    }\n\n    inline int elapsed(){\n        assert(is_stopping ==\
    \ false);\n        timer_point lap = chrono::high_resolution_clock::now();\n\n\
    \        timer_duration d = lap - clock_start;\n\n        time_length += d;\n\n\
    \        clock_start = chrono::high_resolution_clock::now();\n\n        return\
    \ chrono::duration_cast<chrono::milliseconds>(time_length).count();\n    }\n}timer;"
  dependsOn: []
  isVerificationFile: false
  path: Marathon_Match_Tools/measure_time.cpp
  requiredBy: []
  timestamp: '2023-08-06 18:53:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Marathon_Match_Tools/measure_time.cpp
layout: document
redirect_from:
- /library/Marathon_Match_Tools/measure_time.cpp
- /library/Marathon_Match_Tools/measure_time.cpp.html
title: Marathon_Match_Tools/measure_time.cpp
---
