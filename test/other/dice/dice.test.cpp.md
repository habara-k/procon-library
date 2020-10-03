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
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1181
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1181
  bundledCode: "#line 1 \"test/other/dice/dice.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1181\"\
    \n\n#line 1 \"lib/template.cpp\"\n\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n// type {{{\nusing ll = long long;\nusing ull = unsigned long long;\n\
    using ld = long double;\nusing P = pair<int,int>;\nusing vi = vector<int>;\nusing\
    \ vll = vector<ll>;\nusing vvi = vector<vector<int>>;\nusing vvll = vector<vector<ll>>;\n\
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
  timestamp: '2020-04-20 19:29:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/other/dice/dice.test.cpp
layout: document
redirect_from:
- /verify/test/other/dice/dice.test.cpp
- /verify/test/other/dice/dice.test.cpp.html
title: test/other/dice/dice.test.cpp
---
