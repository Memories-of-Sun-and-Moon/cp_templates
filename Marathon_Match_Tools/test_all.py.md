---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "import argparse\n\nfrom analysis_tools import concurrent_executor\nfrom analysis_tools\
    \ import archive\nfrom analysis_tools import score_calclator\n\n# parser\n\nparser\
    \ = argparse.ArgumentParser(description='Analyzer for AHCXXX')\nparser.add_argument('-e',\
    \ default='./AHCXXX', help='\u5B9F\u884C\u30D5\u30A1\u30A4\u30EB\u306E\u9078\u629E\
    ')\nparser.add_argument('-t', default=10, help='\u30C6\u30B9\u30C8\u30B1\u30FC\
    \u30B9\u6570')\nparser.add_argument('-j', default=1, help='\u4E26\u5217\u5B9F\u884C\
    \u6570')\nparser.add_argument('name', help='\u4FDD\u5B58\u3059\u308B\u540D\u524D\
    ')\nargs = parser.parse_args()\n\nargs.t = int(args.t)\nargs.j = int(args.j)\n\
    \nconcurrent_executor.main(max_workers=args.j, testcases=args.t, exe=args.e)\n\
    \nscore_calclator.main(testcases=args.t)\n\narchive.main(name=args.name)"
  dependsOn: []
  isVerificationFile: false
  path: Marathon_Match_Tools/test_all.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Marathon_Match_Tools/test_all.py
layout: document
redirect_from:
- /library/Marathon_Match_Tools/test_all.py
- /library/Marathon_Match_Tools/test_all.py.html
title: Marathon_Match_Tools/test_all.py
---
