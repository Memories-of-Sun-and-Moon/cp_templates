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
    - http://www.w3.org/2000/svg\">\n
    - https://ez-net.jp/article/89/CZq0rF1K/mY7SLPft42BO/
    - https://gist.github.com/saharan/9547f3e56bcfb3e355a9d1df4d670fd4
    - https://www.colordic.org/
  bundledCode: "#line 1 \"Marathon_Match_Tools/vis.cpp\"\n// https://gist.github.com/saharan/9547f3e56bcfb3e355a9d1df4d670fd4\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\nclass Graphics {\npublic:\n\t\
    double screenW;\n\tdouble screenH;\n\tostringstream data;\n\n\tdouble sr;\n\t\
    double sg;\n\tdouble sb;\n\tdouble sa;\n\tdouble fr;\n\tdouble fg;\n\tdouble fb;\n\
    \tdouble fa;\n\n\tGraphics() : screenW(1), screenH(1), sr(0), sg(0), sb(0), sa(1),\
    \ fr(1), fg(1), fb(1), fa(1) {\n\t}\n\n\tvoid screen(int width, int height) {\n\
    \t\tscreenW = width;\n\t\tscreenH = height;\n\t}\n\n\tvoid clear() {\n\t\tdata.str(\"\
    \");\n\t\tdata.clear(stringstream::goodbit);\n\t}\n\n\tvoid stroke(double r, double\
    \ g, double b) {\n\t\tstroke(r, g, b, 1.0);\n\t}\n\n\tvoid stroke(double r, double\
    \ g, double b, double a) {\n\t\tsr = r;\n\t\tsg = g;\n\t\tsb = b;\n\t\tsa = a;\n\
    \t}\n\n    //https://ez-net.jp/article/89/CZq0rF1K/mY7SLPft42BO/\n    //https://www.colordic.org/\n\
    \    void stroke(string str) {\n        if(str == \"Red\")sr = 1.0, sg = 0.0,\
    \ sb = 0.0, sa = 1.0;\n        if(str == \"Pink\")sr = 1.0, sg = 0.752, sb = 0.796,\
    \ sa = 1.0;\n        if(str == \"Brown\")sr = 0.647, sg = 0.164, sb = 0.164, sa\
    \ = 1.0;\n        if(str == \"Orange\")sr = 1.000, sg = 0.647, sb = 0.0, sa =\
    \ 1.0;\n        if(str == \"Yellow\")sr = 1.0, sb = 1.0, sg = 0.0, sa = 1.0;\n\
    \        if(str == \"Green\")sr = 0.0, sg = 0.5, sb = 0.0, sa = 1.0;\n       \
    \ if(str == \"Blue\")sr = 0.0, sg = 0.0, sb = 1.0, sa = 1.0;\n        if(str ==\
    \ \"SkyBlue\")sr = 0.529, sg = 0.807, sb = 0.921, sa = 1.0;\n        if(str ==\
    \ \"Purple\")sr = 0.5, sg = 0.5, sb = 0.0, sa = 1.0;\n        if(str == \"Black\"\
    )sr = 0.0, sg = 0.0, sb = 0.0, sa = 1.0;\n        if(str == \"Grey\")sr = 0.5,\
    \ sg = 0.5, sb = 0.5, sa = 1.0;\n        if(str == \"White\")sr = 1.0, sg = 1.0,\
    \ sb = 1.0, sa = 1.0;\n    }\n\n\tvoid noStroke() {\n\t\tstroke(0.0, 0.0, 0.0,\
    \ 0.0);\n\t}\n\n\tvoid fill(double r, double g, double b) {\n\t\tfill(r, g, b,\
    \ 1.0);\n\t}\n\n\tvoid fill(double r, double g, double b, double a) {\n\t\tfr\
    \ = r;\n\t\tfg = g;\n\t\tfb = b;\n\t\tfa = a;\n\t}\n    \n    void fill(string\
    \ str) {\n        if(str == \"Red\")fr = 1.0, fg = 0.0, fb = 0.0, fa = 1.0;\n\
    \        if(str == \"Pink\")fr = 1.0, fg = 0.752, fb = 0.796, fa = 1.0;\n    \
    \    if(str == \"Brown\")fr = 0.647, fg = 0.164, fb = 0.164, fa = 1.0;\n     \
    \   if(str == \"Orange\")fr = 1.000, fg = 0.647, fb = 0.0, fa = 1.0;\n       \
    \ if(str == \"Yellow\")fr = 1.0, fg = 1.0, fb = 0.0, fa = 1.0;\n        if(str\
    \ == \"Green\")fr = 0.0, fg = 0.5, fb = 0.0, fa = 1.0;\n        if(str == \"Blue\"\
    )fr = 0.0, fg = 0.0, fb = 1.0, fa = 1.0;\n        if(str == \"SkyBlue\")fr = 0.529,\
    \ fg = 0.807, fb = 0.921, fa = 1.0;\n        if(str == \"Purple\")fr = 0.5, fg\
    \ = 0.5, fb = 0.0, fa = 1.0;\n        if(str == \"Black\")fr = 0.0, fg = 0.0,\
    \ fb = 0.0, fa = 1.0;\n        if(str == \"Grey\")fr = 0.5, fg = 0.5, fb = 0.5,\
    \ fa = 1.0;\n        if(str == \"White\")fr = 1.0, fg = 1.0, fb = 1.0, fa = 1.0;\n\
    \    }\n    \n\tvoid noFill() {\n\t\tfill(0.0, 0.0, 0.0, 0.0);\n\t}\n\n\tvoid\
    \ line(double x1, double y1, double x2, double y2) {\n\t\tdata << \"<line x1=\\\
    \"\" << x1 << \"\\\" y1=\\\"\" << y1 << \"\\\" x2=\\\"\" << x2 << \"\\\" y2=\\\
    \"\" << y2 << \"\\\" \" << stroke() << \"/>\\n\";\n\t}\n\n\tvoid rect(double x,\
    \ double y, double w, double h) {\n\t\tdata << \"<rect x=\\\"\" << x << \"\\\"\
    \ y=\\\"\" << y << \"\\\" width=\\\"\" << w << \"\\\" height=\\\"\" << h << \"\
    \\\" \" << stroke() << \" \" + fill() << \"/>\\n\";\n\t}\n\n\tvoid text(string\
    \ str, double x, double y, double size = 16) {\n\t\tdata << \"<text text-anchor=\\\
    \"middle\\\" x=\\\"\" << x << \"\\\" y=\\\"\" << y << \"\\\" font-size=\\\"\"\
    \ << size << \"\\\" \" << fill() << \" >\" << str << \"</text>\\n\";\n\t}\n\n\t\
    string dump(string id = \"\", string style = \"\", int widthPx = -1, int heightPx\
    \ = -1) const {\n\t\tostringstream res;\n\t\tres << \"<svg \";\n\t\tif (id !=\
    \ \"\") res << \"id=\\\"\" + id + \"\\\" \";\n\t\tif (style != \"\") res << \"\
    style=\\\"\" + style + \"\\\" \";\n\t\tif (widthPx != -1) res << \"width=\\\"\"\
    \ << widthPx << \"\\\" \";\n\t\tif (heightPx != -1) res << \"height=\\\"\" <<\
    \ heightPx << \"\\\" \";\n\t\tres << \"viewBox=\\\"-1 -1 \" << screenW + 2 <<\
    \ \" \" << screenH + 2 << \"\\\" xmlns=\\\"http://www.w3.org/2000/svg\\\">\\n\"\
    \ << data.str() << \"</svg>\";\n\t\treturn res.str();\n\t}\n\nprivate:\n\tstring\
    \ stroke() const {\n\t\treturn \"stroke=\\\"\" + rgb(sr, sg, sb) + \"\\\" stroke-opacity=\\\
    \"\" + s(sa) + \"\\\"\";\n\t}\n\n\tstring fill() const {\n\t\treturn \"fill=\\\
    \"\" + rgb(fr, fg, fb) + \"\\\" fill-opacity=\\\"\" + s(fa) + \"\\\"\";\n\t}\n\
    \n\tstring rgb(double r, double g, double b) const {\n\t\treturn \"rgb(\" + s(lround(r\
    \ * 255)) + \",\" + s(lround(g * 255)) + \",\" + s(lround(b * 255)) + \")\";\n\
    \t}\n\n\tstring s(double x) const {\n\t\treturn to_string(x);\n\t}\n};\n\nclass\
    \ Movie {\npublic:\n\tvector<string> svgs;\n\n\tMovie() {\n\t}\n\n\tvoid clear()\
    \ {\n\t\tsvgs.clear();\n\t}\n\n\tvoid addFrame(Graphics& g) {\n\t\tsvgs.push_back(g.dump(\"\
    f\" + to_string(svgs.size()), \"display:none;pointer-events:none;user-select:none;\"\
    ));\n\t}\n\n\tstring dumpHtml(int fps) {\n\t\tostringstream res;\n\t\tres << \"\
    <html><body><div id=\\\"text\\\">loading...</div>\" << endl;\n\t\tfor (string&\
    \ svg : svgs) {\n\t\t\tres << svg << endl;\n\t\t}\n\n\t\tres << \"<script>\\nlet\
    \ numFrames = \" << svgs.size() << \", fps = \" << fps << \";\";\n\t\tres << R\"\
    (\n\tlet text = document.getElementById(\"text\");\n\tlet frames = [];\n\tfor\
    \ (let i = 0; i < numFrames; i++) {\n\t\tlet f = document.getElementById(\"f\"\
    \ + i);\n\t\tframes.push(f);\n\t\tf.style.display = \"none\";\n\t}\n\tlet currentFrame\
    \ = 0;\n\tlet playing = true;\n\tsetInterval(() => {\n\t\tif (!playing) return;\n\
    \t\ttext.innerText = (currentFrame + 1) + \" / \" + numFrames;\n\t\tframes[(currentFrame\
    \ - 1 + numFrames) % numFrames].style.display = \"none\";\n\t\tframes[currentFrame].style.display\
    \ = null;\n\t\tcurrentFrame = (currentFrame + 1) % numFrames;\n\t\tif (currentFrame\
    \ == 0) playing = false;\n\t}, 1000 / fps);\n\twindow.onmousedown = e => { if\
    \ (e.button == 0) playing = true; };\n;)\";\n\t\tres << \"</script>\" << endl;\n\
    \t\tres << \"</body></html>\" << endl;\n\t\treturn res.str();\n\t}\nprivate:\n\
    };\n"
  code: "// https://gist.github.com/saharan/9547f3e56bcfb3e355a9d1df4d670fd4\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\nclass Graphics {\npublic:\n\tdouble\
    \ screenW;\n\tdouble screenH;\n\tostringstream data;\n\n\tdouble sr;\n\tdouble\
    \ sg;\n\tdouble sb;\n\tdouble sa;\n\tdouble fr;\n\tdouble fg;\n\tdouble fb;\n\t\
    double fa;\n\n\tGraphics() : screenW(1), screenH(1), sr(0), sg(0), sb(0), sa(1),\
    \ fr(1), fg(1), fb(1), fa(1) {\n\t}\n\n\tvoid screen(int width, int height) {\n\
    \t\tscreenW = width;\n\t\tscreenH = height;\n\t}\n\n\tvoid clear() {\n\t\tdata.str(\"\
    \");\n\t\tdata.clear(stringstream::goodbit);\n\t}\n\n\tvoid stroke(double r, double\
    \ g, double b) {\n\t\tstroke(r, g, b, 1.0);\n\t}\n\n\tvoid stroke(double r, double\
    \ g, double b, double a) {\n\t\tsr = r;\n\t\tsg = g;\n\t\tsb = b;\n\t\tsa = a;\n\
    \t}\n\n    //https://ez-net.jp/article/89/CZq0rF1K/mY7SLPft42BO/\n    //https://www.colordic.org/\n\
    \    void stroke(string str) {\n        if(str == \"Red\")sr = 1.0, sg = 0.0,\
    \ sb = 0.0, sa = 1.0;\n        if(str == \"Pink\")sr = 1.0, sg = 0.752, sb = 0.796,\
    \ sa = 1.0;\n        if(str == \"Brown\")sr = 0.647, sg = 0.164, sb = 0.164, sa\
    \ = 1.0;\n        if(str == \"Orange\")sr = 1.000, sg = 0.647, sb = 0.0, sa =\
    \ 1.0;\n        if(str == \"Yellow\")sr = 1.0, sb = 1.0, sg = 0.0, sa = 1.0;\n\
    \        if(str == \"Green\")sr = 0.0, sg = 0.5, sb = 0.0, sa = 1.0;\n       \
    \ if(str == \"Blue\")sr = 0.0, sg = 0.0, sb = 1.0, sa = 1.0;\n        if(str ==\
    \ \"SkyBlue\")sr = 0.529, sg = 0.807, sb = 0.921, sa = 1.0;\n        if(str ==\
    \ \"Purple\")sr = 0.5, sg = 0.5, sb = 0.0, sa = 1.0;\n        if(str == \"Black\"\
    )sr = 0.0, sg = 0.0, sb = 0.0, sa = 1.0;\n        if(str == \"Grey\")sr = 0.5,\
    \ sg = 0.5, sb = 0.5, sa = 1.0;\n        if(str == \"White\")sr = 1.0, sg = 1.0,\
    \ sb = 1.0, sa = 1.0;\n    }\n\n\tvoid noStroke() {\n\t\tstroke(0.0, 0.0, 0.0,\
    \ 0.0);\n\t}\n\n\tvoid fill(double r, double g, double b) {\n\t\tfill(r, g, b,\
    \ 1.0);\n\t}\n\n\tvoid fill(double r, double g, double b, double a) {\n\t\tfr\
    \ = r;\n\t\tfg = g;\n\t\tfb = b;\n\t\tfa = a;\n\t}\n    \n    void fill(string\
    \ str) {\n        if(str == \"Red\")fr = 1.0, fg = 0.0, fb = 0.0, fa = 1.0;\n\
    \        if(str == \"Pink\")fr = 1.0, fg = 0.752, fb = 0.796, fa = 1.0;\n    \
    \    if(str == \"Brown\")fr = 0.647, fg = 0.164, fb = 0.164, fa = 1.0;\n     \
    \   if(str == \"Orange\")fr = 1.000, fg = 0.647, fb = 0.0, fa = 1.0;\n       \
    \ if(str == \"Yellow\")fr = 1.0, fg = 1.0, fb = 0.0, fa = 1.0;\n        if(str\
    \ == \"Green\")fr = 0.0, fg = 0.5, fb = 0.0, fa = 1.0;\n        if(str == \"Blue\"\
    )fr = 0.0, fg = 0.0, fb = 1.0, fa = 1.0;\n        if(str == \"SkyBlue\")fr = 0.529,\
    \ fg = 0.807, fb = 0.921, fa = 1.0;\n        if(str == \"Purple\")fr = 0.5, fg\
    \ = 0.5, fb = 0.0, fa = 1.0;\n        if(str == \"Black\")fr = 0.0, fg = 0.0,\
    \ fb = 0.0, fa = 1.0;\n        if(str == \"Grey\")fr = 0.5, fg = 0.5, fb = 0.5,\
    \ fa = 1.0;\n        if(str == \"White\")fr = 1.0, fg = 1.0, fb = 1.0, fa = 1.0;\n\
    \    }\n    \n\tvoid noFill() {\n\t\tfill(0.0, 0.0, 0.0, 0.0);\n\t}\n\n\tvoid\
    \ line(double x1, double y1, double x2, double y2) {\n\t\tdata << \"<line x1=\\\
    \"\" << x1 << \"\\\" y1=\\\"\" << y1 << \"\\\" x2=\\\"\" << x2 << \"\\\" y2=\\\
    \"\" << y2 << \"\\\" \" << stroke() << \"/>\\n\";\n\t}\n\n\tvoid rect(double x,\
    \ double y, double w, double h) {\n\t\tdata << \"<rect x=\\\"\" << x << \"\\\"\
    \ y=\\\"\" << y << \"\\\" width=\\\"\" << w << \"\\\" height=\\\"\" << h << \"\
    \\\" \" << stroke() << \" \" + fill() << \"/>\\n\";\n\t}\n\n\tvoid text(string\
    \ str, double x, double y, double size = 16) {\n\t\tdata << \"<text text-anchor=\\\
    \"middle\\\" x=\\\"\" << x << \"\\\" y=\\\"\" << y << \"\\\" font-size=\\\"\"\
    \ << size << \"\\\" \" << fill() << \" >\" << str << \"</text>\\n\";\n\t}\n\n\t\
    string dump(string id = \"\", string style = \"\", int widthPx = -1, int heightPx\
    \ = -1) const {\n\t\tostringstream res;\n\t\tres << \"<svg \";\n\t\tif (id !=\
    \ \"\") res << \"id=\\\"\" + id + \"\\\" \";\n\t\tif (style != \"\") res << \"\
    style=\\\"\" + style + \"\\\" \";\n\t\tif (widthPx != -1) res << \"width=\\\"\"\
    \ << widthPx << \"\\\" \";\n\t\tif (heightPx != -1) res << \"height=\\\"\" <<\
    \ heightPx << \"\\\" \";\n\t\tres << \"viewBox=\\\"-1 -1 \" << screenW + 2 <<\
    \ \" \" << screenH + 2 << \"\\\" xmlns=\\\"http://www.w3.org/2000/svg\\\">\\n\"\
    \ << data.str() << \"</svg>\";\n\t\treturn res.str();\n\t}\n\nprivate:\n\tstring\
    \ stroke() const {\n\t\treturn \"stroke=\\\"\" + rgb(sr, sg, sb) + \"\\\" stroke-opacity=\\\
    \"\" + s(sa) + \"\\\"\";\n\t}\n\n\tstring fill() const {\n\t\treturn \"fill=\\\
    \"\" + rgb(fr, fg, fb) + \"\\\" fill-opacity=\\\"\" + s(fa) + \"\\\"\";\n\t}\n\
    \n\tstring rgb(double r, double g, double b) const {\n\t\treturn \"rgb(\" + s(lround(r\
    \ * 255)) + \",\" + s(lround(g * 255)) + \",\" + s(lround(b * 255)) + \")\";\n\
    \t}\n\n\tstring s(double x) const {\n\t\treturn to_string(x);\n\t}\n};\n\nclass\
    \ Movie {\npublic:\n\tvector<string> svgs;\n\n\tMovie() {\n\t}\n\n\tvoid clear()\
    \ {\n\t\tsvgs.clear();\n\t}\n\n\tvoid addFrame(Graphics& g) {\n\t\tsvgs.push_back(g.dump(\"\
    f\" + to_string(svgs.size()), \"display:none;pointer-events:none;user-select:none;\"\
    ));\n\t}\n\n\tstring dumpHtml(int fps) {\n\t\tostringstream res;\n\t\tres << \"\
    <html><body><div id=\\\"text\\\">loading...</div>\" << endl;\n\t\tfor (string&\
    \ svg : svgs) {\n\t\t\tres << svg << endl;\n\t\t}\n\n\t\tres << \"<script>\\nlet\
    \ numFrames = \" << svgs.size() << \", fps = \" << fps << \";\";\n\t\tres << R\"\
    (\n\tlet text = document.getElementById(\"text\");\n\tlet frames = [];\n\tfor\
    \ (let i = 0; i < numFrames; i++) {\n\t\tlet f = document.getElementById(\"f\"\
    \ + i);\n\t\tframes.push(f);\n\t\tf.style.display = \"none\";\n\t}\n\tlet currentFrame\
    \ = 0;\n\tlet playing = true;\n\tsetInterval(() => {\n\t\tif (!playing) return;\n\
    \t\ttext.innerText = (currentFrame + 1) + \" / \" + numFrames;\n\t\tframes[(currentFrame\
    \ - 1 + numFrames) % numFrames].style.display = \"none\";\n\t\tframes[currentFrame].style.display\
    \ = null;\n\t\tcurrentFrame = (currentFrame + 1) % numFrames;\n\t\tif (currentFrame\
    \ == 0) playing = false;\n\t}, 1000 / fps);\n\twindow.onmousedown = e => { if\
    \ (e.button == 0) playing = true; };\n;)\";\n\t\tres << \"</script>\" << endl;\n\
    \t\tres << \"</body></html>\" << endl;\n\t\treturn res.str();\n\t}\nprivate:\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: Marathon_Match_Tools/vis.cpp
  requiredBy: []
  timestamp: '2023-09-07 18:23:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Marathon_Match_Tools/vis.cpp
layout: document
redirect_from:
- /library/Marathon_Match_Tools/vis.cpp
- /library/Marathon_Match_Tools/vis.cpp.html
title: Marathon_Match_Tools/vis.cpp
---
