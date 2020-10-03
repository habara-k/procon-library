---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lib/graph/dijkstra.cpp
    title: lib/graph/dijkstra.cpp
  - icon: ':heavy_check_mark:'
    path: lib/graph/kruskal.cpp
    title: lib/graph/kruskal.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/dijkstra/dijkstra.test.cpp
    title: test/graph/dijkstra/dijkstra.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/dijkstra/dijkstra.test.cpp
    title: test/graph/dijkstra/dijkstra.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/kruskal/kruskal.test.cpp
    title: test/graph/kruskal/kruskal.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/kruskal/kruskal.test.cpp
    title: test/graph/kruskal/kruskal.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/re_rooting/re_rooting.test.cpp
    title: test/graph/re_rooting/re_rooting.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/graph/edge.cpp\"\n\n\n#line 1 \"lib/template.cpp\"\n\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n// type {{{\nusing ll =\
    \ long long;\nusing ull = unsigned long long;\nusing ld = long double;\nusing\
    \ P = pair<int,int>;\nusing vi = vector<int>;\nusing vll = vector<ll>;\nusing\
    \ vvi = vector<vector<int>>;\nusing vvll = vector<vector<ll>>;\n// }}}\n\n\n//\
    \ macro {{{\n#define REP(i,n) for (int i=0; i<(n); ++i)\n#define RREP(i,n) for\
    \ (int i=(int)(n)-1; i>=0; --i)\n#define FOR(i,a,n) for (int i=(a); i<(n); ++i)\n\
    #define RFOR(i,a,n) for (int i=(int)(n)-1; i>=(a); --i)\n\n#define SZ(x) ((int)(x).size())\n\
    #define all(x) begin(x),end(x)\n// }}}\n\n\n// debug {{{\n#define dump(x) cerr<<#x<<\"\
    \ = \"<<(x)<<endl\n#define debug(x) cerr<<#x<<\" = \"<<(x)<<\" (L\"<<__LINE__<<\"\
    )\"<< endl;\n\ntemplate<typename T>\nostream& operator<<(ostream& os, const vector<T>&\
    \ v) {\n    os << \"[\";\n    REP (i, SZ(v)) {\n        if (i) os << \", \";\n\
    \        os << v[i];\n    }\n    return os << \"]\";\n}\n\ntemplate<typename T,\
    \ typename U>\nostream& operator<<(ostream& os, const pair<T, U>& p) {\n    return\
    \ os << \"(\" << p.first << \" \" << p.second << \")\";\n}\n// }}}\n\n\n// chmax,\
    \ chmin {{{\ntemplate<class T>\nbool chmax(T& a, const T& b) {\n    if (a < b)\
    \ { a = b; return true; }\n    return false;\n}\ntemplate<class T>\nbool chmin(T&\
    \ a, const T& b) {\n    if (b < a) { a = b; return true; }\n    return false;\n\
    }\n// }}}\n\n\n// constants {{{\n#define inf(T) (numeric_limits<T>::max() / 2)\n\
    const ll MOD = 1e9+7;\nconst ld EPS = 1e-9;\n// }}}\n\n\n#line 4 \"lib/graph/edge.cpp\"\
    \n\ntemplate<typename T>\nstruct edge {\n    int src, to;\n    T cost;\n\n   \
    \ friend ostream& operator<<(ostream& os, const edge& e) {\n        return os\
    \ << \"(\" << e.src << \"->\" << e.to << \":\" << e.cost << \")\";\n    }\n};\n\
    \ntemplate<typename T>\nusing Graph = vector<vector<edge<T>>>;\n\n\n"
  code: "#ifndef EDGE\n#define EDGE\n#include \"../template.cpp\"\n\ntemplate<typename\
    \ T>\nstruct edge {\n    int src, to;\n    T cost;\n\n    friend ostream& operator<<(ostream&\
    \ os, const edge& e) {\n        return os << \"(\" << e.src << \"->\" << e.to\
    \ << \":\" << e.cost << \")\";\n    }\n};\n\ntemplate<typename T>\nusing Graph\
    \ = vector<vector<edge<T>>>;\n\n#endif\n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/graph/edge.cpp
  requiredBy:
  - lib/graph/kruskal.cpp
  - lib/graph/dijkstra.cpp
  timestamp: '2020-06-26 12:56:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/dijkstra/dijkstra.test.cpp
  - test/graph/dijkstra/dijkstra.test.cpp
  - test/graph/kruskal/kruskal.test.cpp
  - test/graph/kruskal/kruskal.test.cpp
  - test/graph/re_rooting/re_rooting.test.cpp
documentation_of: lib/graph/edge.cpp
layout: document
redirect_from:
- /library/lib/graph/edge.cpp
- /library/lib/graph/edge.cpp.html
title: lib/graph/edge.cpp
---
