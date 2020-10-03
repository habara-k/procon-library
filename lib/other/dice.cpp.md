---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/other/dice/dice.test.cpp
    title: test/other/dice/dice.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/template.cpp\"\n\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n// type {{{\nusing ll = long long;\nusing ull = unsigned long\
    \ long;\nusing ld = long double;\nusing P = pair<int,int>;\nusing vi = vector<int>;\n\
    using vll = vector<ll>;\nusing vvi = vector<vector<int>>;\nusing vvll = vector<vector<ll>>;\n\
    // }}}\n\n\n// macro {{{\n#define REP(i,n) for (int i=0; i<(n); ++i)\n#define\
    \ RREP(i,n) for (int i=(int)(n)-1; i>=0; --i)\n#define FOR(i,a,n) for (int i=(a);\
    \ i<(n); ++i)\n#define RFOR(i,a,n) for (int i=(int)(n)-1; i>=(a); --i)\n\n#define\
    \ SZ(x) ((int)(x).size())\n#define all(x) begin(x),end(x)\n// }}}\n\n\n// debug\
    \ {{{\n#define dump(x) cerr<<#x<<\" = \"<<(x)<<endl\n#define debug(x) cerr<<#x<<\"\
    \ = \"<<(x)<<\" (L\"<<__LINE__<<\")\"<< endl;\n\ntemplate<typename T>\nostream&\
    \ operator<<(ostream& os, const vector<T>& v) {\n    os << \"[\";\n    REP (i,\
    \ SZ(v)) {\n        if (i) os << \", \";\n        os << v[i];\n    }\n    return\
    \ os << \"]\";\n}\n\ntemplate<typename T, typename U>\nostream& operator<<(ostream&\
    \ os, const pair<T, U>& p) {\n    return os << \"(\" << p.first << \" \" << p.second\
    \ << \")\";\n}\n// }}}\n\n\n// chmax, chmin {{{\ntemplate<class T>\nbool chmax(T&\
    \ a, const T& b) {\n    if (a < b) { a = b; return true; }\n    return false;\n\
    }\ntemplate<class T>\nbool chmin(T& a, const T& b) {\n    if (b < a) { a = b;\
    \ return true; }\n    return false;\n}\n// }}}\n\n\n// constants {{{\n#define\
    \ inf(T) (numeric_limits<T>::max() / 2)\nconst ll MOD = 1e9+7;\nconst ld EPS =\
    \ 1e-9;\n// }}}\n\n\n#line 2 \"lib/other/dice.cpp\"\n\nstruct Dice {\n    int\
    \ U, D, L, R, F, B;\n    Dice(int U, int D, int L, int R, int F, int B) :\n  \
    \      U(U), D(D), L(L), R(R), F(F), B(B) {}\n\n    void rollU() {\n        int\
    \ buff = F;\n        F = R; R = B; B = L; L = buff;\n    }\n    void rollD() {\n\
    \        int buff = F;\n        F = L; L = B; B = R; R = buff;\n    }\n    void\
    \ rollF() {\n        int buff = U;\n        U = L; L = D; D = R; R = buff;\n \
    \   }\n    void rollB() {\n        int buff = U;\n        U = R; R = D; D = L;\
    \ L = buff;\n    }\n    void rollR() {\n        int buff = U;\n        U = F;\
    \ F = D; D = B; B = buff;\n    }\n    void rollL() {\n        int buff = U;\n\
    \        U = B; B = D; D = F; F = buff;\n    }\n};\n"
  code: "#include \"../template.cpp\"\n\nstruct Dice {\n    int U, D, L, R, F, B;\n\
    \    Dice(int U, int D, int L, int R, int F, int B) :\n        U(U), D(D), L(L),\
    \ R(R), F(F), B(B) {}\n\n    void rollU() {\n        int buff = F;\n        F\
    \ = R; R = B; B = L; L = buff;\n    }\n    void rollD() {\n        int buff =\
    \ F;\n        F = L; L = B; B = R; R = buff;\n    }\n    void rollF() {\n    \
    \    int buff = U;\n        U = L; L = D; D = R; R = buff;\n    }\n    void rollB()\
    \ {\n        int buff = U;\n        U = R; R = D; D = L; L = buff;\n    }\n  \
    \  void rollR() {\n        int buff = U;\n        U = F; F = D; D = B; B = buff;\n\
    \    }\n    void rollL() {\n        int buff = U;\n        U = B; B = D; D = F;\
    \ F = buff;\n    }\n};\n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/other/dice.cpp
  requiredBy: []
  timestamp: '2020-04-20 18:48:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/other/dice/dice.test.cpp
documentation_of: lib/other/dice.cpp
layout: document
redirect_from:
- /library/lib/other/dice.cpp
- /library/lib/other/dice.cpp.html
title: lib/other/dice.cpp
---
