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
  code: "import datetime\nimport pathlib\nimport subprocess\n\ndef main(name: str):\n\
    \    pathlib.Path('archive').mkdir(exist_ok=True)\n\n    t_delta = datetime.timedelta(hours=9)\n\
    \    JST = datetime.timezone(t_delta, 'JST')\n    now = datetime.datetime.now(JST)\n\
    \    name = str(f'{now:%m%d%H%M}') + str(name)\n\n    pathlib.Path(name).mkdir()\n\
    \    \n    subprocess.run(['mv', '-v', 'out', f'{name}' + '/out'])\n    subprocess.run(['mv',\
    \ '-v', f'{name}', 'archive/' + f'{name}'])\n    subprocess.run(['mv', 'score.txt',\
    \ 'archive/' + f'{name}' + '/score.txt'])\n    subprocess.run(['cp', 'AHCXXX.cpp',\
    \ 'archive/' + f'{name}' + '/source.cpp'])\n"
  dependsOn: []
  isVerificationFile: false
  path: Marathon_Match_Tools/analysis_tools/archive.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Marathon_Match_Tools/analysis_tools/archive.py
layout: document
redirect_from:
- /library/Marathon_Match_Tools/analysis_tools/archive.py
- /library/Marathon_Match_Tools/analysis_tools/archive.py.html
title: Marathon_Match_Tools/analysis_tools/archive.py
---
