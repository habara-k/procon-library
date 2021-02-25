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
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/template.cpp\"\n\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n#define REP(i,n) for (int i=0; i<(n); ++i)\n#define ALL(x)\
    \ begin(x),end(x)\n#define DUMP(x) cerr<<#x<<\" = \"<<(x)<<endl\n\nstruct fast_ios\
    \ {\n    fast_ios() {\n        std::cin.tie(nullptr);\n        ios::sync_with_stdio(false);\n\
    \        cout << fixed << setprecision(20);\n    };\n} fast_ios_;\n\nusing ll\
    \ = long long;\n\ntemplate<class T>\nbool chmin(T &a, T b) {\n    if (a > b) {\
    \ a = b; return true; }\n    return false;\n}\ntemplate<class T>\nbool chmax(T\
    \ &a, T b) {\n    if (a < b) { a = b; return true; }\n    return false;\n}\n\n\
    template<class T>\nostream &operator<<(ostream &os, const vector<T> &v);\ntemplate<class\
    \ T, class U>\nostream &operator<<(ostream &os, const pair<T, U> &p);\ntemplate<class\
    \ T, class U>\nostream &operator<<(ostream &os, const map<T, U> &mp);\n\ntemplate<class\
    \ T>\nostream &operator<<(ostream &os, const vector<T> &v) {\n    os << '[';\n\
    \    REP(i, v.size()) {\n        if (i) os << ',';\n        os << v[i];\n    }\n\
    \    return os << ']';\n}\n\ntemplate<class T, class U>\nostream &operator<<(ostream\
    \ &os, const pair<T, U> &p) {\n    return os << '(' << p.first << ' ' << p.second\
    \ << ')';\n}\n\ntemplate<class T, class U>\nostream &operator<<(ostream &os, const\
    \ map<T, U> &mp) {\n    os << '{';\n    for (const auto &p : mp) {\n        os\
    \ << p << endl;\n    }\n    return os << '}';\n}\n\nconst int INF = numeric_limits<int>::max();\n\
    const ll LINF = numeric_limits<ll>::max();\n\ntemplate<class T>\nstruct edge {\n\
    \    int from, to; T cost;\n    edge(int to, T cost) :\n        from(-1), to(to),\
    \ cost(cost) {}\n    edge(int from, int to, T cost) :\n        from(from), to(to),\
    \ cost(cost) {}\n};\n\n\n#line 2 \"lib/other/dice.cpp\"\n\nstruct Dice {\n   \
    \ int U, D, L, R, F, B;\n    Dice(int U, int D, int L, int R, int F, int B) :\n\
    \        U(U), D(D), L(L), R(R), F(F), B(B) {}\n\n    void rollU() {\n       \
    \ int buff = F;\n        F = R; R = B; B = L; L = buff;\n    }\n    void rollD()\
    \ {\n        int buff = F;\n        F = L; L = B; B = R; R = buff;\n    }\n  \
    \  void rollF() {\n        int buff = U;\n        U = L; L = D; D = R; R = buff;\n\
    \    }\n    void rollB() {\n        int buff = U;\n        U = R; R = D; D = L;\
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
  timestamp: '2021-02-25 17:59:51+09:00'
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
