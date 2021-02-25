---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/other/dice.cpp
    title: lib/other/dice.cpp
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1181
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1181
  bundledCode: "#line 1 \"test/other/dice/dice.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1181\"\
    \n\n#line 1 \"lib/template.cpp\"\n\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#define REP(i,n) for (int i=0; i<(n); ++i)\n#define ALL(x) begin(x),end(x)\n\
    #define DUMP(x) cerr<<#x<<\" = \"<<(x)<<endl\n\nstruct fast_ios {\n    fast_ios()\
    \ {\n        std::cin.tie(nullptr);\n        ios::sync_with_stdio(false);\n  \
    \      cout << fixed << setprecision(20);\n    };\n} fast_ios_;\n\nusing ll =\
    \ long long;\n\ntemplate<class T>\nbool chmin(T &a, T b) {\n    if (a > b) { a\
    \ = b; return true; }\n    return false;\n}\ntemplate<class T>\nbool chmax(T &a,\
    \ T b) {\n    if (a < b) { a = b; return true; }\n    return false;\n}\n\ntemplate<class\
    \ T>\nostream &operator<<(ostream &os, const vector<T> &v);\ntemplate<class T,\
    \ class U>\nostream &operator<<(ostream &os, const pair<T, U> &p);\ntemplate<class\
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
    \        U = B; B = D; D = F; F = buff;\n    }\n};\n#line 4 \"test/other/dice/dice.test.cpp\"\
    \n\nint main()\n{\n    while (true) {\n        int n; cin >> n;\n        if (n\
    \ == 0) break;\n\n        vector<vector<int>> h(2*n+1, vector<int>(2*n+1));\n\
    \        vector<vector<int>> v(2*n+1, vector<int>(2*n+1));\n\n        for (int\
    \ k = 0; k < n; ++k) {\n            int t, f; cin >> t >> f;\n            Dice\
    \ dice(1,6,2,5,3,4);\n            if (dice.U != t) dice.rollR();\n           \
    \ if (dice.U != t) dice.rollR();\n            if (dice.U != t) dice.rollR();\n\
    \            if (dice.U != t) dice.rollF();\n            if (dice.U != t) dice.rollF();\n\
    \            if (dice.U != t) dice.rollF();\n            if (dice.F != f) dice.rollU();\n\
    \            if (dice.F != f) dice.rollU();\n            if (dice.F != f) dice.rollU();\n\
    \            assert(dice.F == f and dice.U == t);\n\n            for (int i =\
    \ n, j = n;;) {\n                if (dice.L == 6 and h[i+1][j] < h[i][j]) {\n\
    \                    dice.rollB();\n                    ++i;\n               \
    \ }\n                else if (dice.R == 6 and h[i-1][j] < h[i][j]) {\n       \
    \             dice.rollF();\n                    --i;\n                }\n   \
    \             else if (dice.F == 6 and h[i][j+1] < h[i][j]) {\n              \
    \      dice.rollL();\n                    ++j;\n                }\n          \
    \      else if (dice.B == 6 and h[i][j-1] < h[i][j]) {\n                    dice.rollR();\n\
    \                    --j;\n                }\n                else if (dice.L\
    \ == 5 and h[i+1][j] < h[i][j]) {\n                    dice.rollB();\n       \
    \             ++i;\n                }\n                else if (dice.R == 5 and\
    \ h[i-1][j] < h[i][j]) {\n                    dice.rollF();\n                \
    \    --i;\n                }\n                else if (dice.F == 5 and h[i][j+1]\
    \ < h[i][j]) {\n                    dice.rollL();\n                    ++j;\n\
    \                }\n                else if (dice.B == 5 and h[i][j-1] < h[i][j])\
    \ {\n                    dice.rollR();\n                    --j;\n           \
    \     }\n                else if (dice.L == 4 and h[i+1][j] < h[i][j]) {\n   \
    \                 dice.rollB();\n                    ++i;\n                }\n\
    \                else if (dice.R == 4 and h[i-1][j] < h[i][j]) {\n           \
    \         dice.rollF();\n                    --i;\n                }\n       \
    \         else if (dice.F == 4 and h[i][j+1] < h[i][j]) {\n                  \
    \  dice.rollL();\n                    ++j;\n                }\n              \
    \  else if (dice.B == 4 and h[i][j-1] < h[i][j]) {\n                    dice.rollR();\n\
    \                    --j;\n                }\n                else {\n       \
    \             ++h[i][j];\n                    v[i][j] = dice.U;\n            \
    \        break;\n                }\n            }\n\n        }\n        vector<int>\
    \ cnt(6);\n        for (int i = 0; i <= 2*n; ++i) {\n            for (int j =\
    \ 0; j <= 2*n; ++j) {\n                if (v[i][j]) ++cnt[v[i][j]-1];\n      \
    \      }\n        }\n\n        for (int i = 0; i < 6; ++i) {\n            if (i)\
    \ cout << \" \";\n            cout << cnt[i];\n        }\n        cout << endl;\n\
    \    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1181\"\
    \n\n#include \"../../../lib/other/dice.cpp\"\n\nint main()\n{\n    while (true)\
    \ {\n        int n; cin >> n;\n        if (n == 0) break;\n\n        vector<vector<int>>\
    \ h(2*n+1, vector<int>(2*n+1));\n        vector<vector<int>> v(2*n+1, vector<int>(2*n+1));\n\
    \n        for (int k = 0; k < n; ++k) {\n            int t, f; cin >> t >> f;\n\
    \            Dice dice(1,6,2,5,3,4);\n            if (dice.U != t) dice.rollR();\n\
    \            if (dice.U != t) dice.rollR();\n            if (dice.U != t) dice.rollR();\n\
    \            if (dice.U != t) dice.rollF();\n            if (dice.U != t) dice.rollF();\n\
    \            if (dice.U != t) dice.rollF();\n            if (dice.F != f) dice.rollU();\n\
    \            if (dice.F != f) dice.rollU();\n            if (dice.F != f) dice.rollU();\n\
    \            assert(dice.F == f and dice.U == t);\n\n            for (int i =\
    \ n, j = n;;) {\n                if (dice.L == 6 and h[i+1][j] < h[i][j]) {\n\
    \                    dice.rollB();\n                    ++i;\n               \
    \ }\n                else if (dice.R == 6 and h[i-1][j] < h[i][j]) {\n       \
    \             dice.rollF();\n                    --i;\n                }\n   \
    \             else if (dice.F == 6 and h[i][j+1] < h[i][j]) {\n              \
    \      dice.rollL();\n                    ++j;\n                }\n          \
    \      else if (dice.B == 6 and h[i][j-1] < h[i][j]) {\n                    dice.rollR();\n\
    \                    --j;\n                }\n                else if (dice.L\
    \ == 5 and h[i+1][j] < h[i][j]) {\n                    dice.rollB();\n       \
    \             ++i;\n                }\n                else if (dice.R == 5 and\
    \ h[i-1][j] < h[i][j]) {\n                    dice.rollF();\n                \
    \    --i;\n                }\n                else if (dice.F == 5 and h[i][j+1]\
    \ < h[i][j]) {\n                    dice.rollL();\n                    ++j;\n\
    \                }\n                else if (dice.B == 5 and h[i][j-1] < h[i][j])\
    \ {\n                    dice.rollR();\n                    --j;\n           \
    \     }\n                else if (dice.L == 4 and h[i+1][j] < h[i][j]) {\n   \
    \                 dice.rollB();\n                    ++i;\n                }\n\
    \                else if (dice.R == 4 and h[i-1][j] < h[i][j]) {\n           \
    \         dice.rollF();\n                    --i;\n                }\n       \
    \         else if (dice.F == 4 and h[i][j+1] < h[i][j]) {\n                  \
    \  dice.rollL();\n                    ++j;\n                }\n              \
    \  else if (dice.B == 4 and h[i][j-1] < h[i][j]) {\n                    dice.rollR();\n\
    \                    --j;\n                }\n                else {\n       \
    \             ++h[i][j];\n                    v[i][j] = dice.U;\n            \
    \        break;\n                }\n            }\n\n        }\n        vector<int>\
    \ cnt(6);\n        for (int i = 0; i <= 2*n; ++i) {\n            for (int j =\
    \ 0; j <= 2*n; ++j) {\n                if (v[i][j]) ++cnt[v[i][j]-1];\n      \
    \      }\n        }\n\n        for (int i = 0; i < 6; ++i) {\n            if (i)\
    \ cout << \" \";\n            cout << cnt[i];\n        }\n        cout << endl;\n\
    \    }\n\n    return 0;\n}\n"
  dependsOn:
  - lib/other/dice.cpp
  - lib/template.cpp
  isVerificationFile: true
  path: test/other/dice/dice.test.cpp
  requiredBy: []
  timestamp: '2021-02-25 17:59:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/other/dice/dice.test.cpp
layout: document
redirect_from:
- /verify/test/other/dice/dice.test.cpp
- /verify/test/other/dice/dice.test.cpp.html
title: test/other/dice/dice.test.cpp
---
