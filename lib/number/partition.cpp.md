---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/number/partition/partition1.test.cpp
    title: test/number/partition/partition1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/number/partition/partition2.test.cpp
    title: test/number/partition/partition2.test.cpp
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
    \ 1e-9;\n// }}}\n\n\n#line 2 \"lib/number/partition.cpp\"\n\n// \u5206\u5272\u6570\
    \n// Partition(k, n) := \u533A\u5225\u3067\u304D\u306A\u3044n \u500B\u306E\u30DC\
    \u30FC\u30EB\u3092\n//                    \u533A\u5225\u3067\u304D\u306A\u3044\
    k \u500B\u306E\u7BB1\u306B\u5165\u308C\u308B\u5834\u5408\u306E\u6570\ntemplate<typename\
    \ Ring>\nRing Partition(int k, int n) {\n    vector<vector<Ring>> part(k+1, vector<Ring>(n+1));\n\
    \    part[0][0] = 1;\n    for (int i = 1; i <= k; ++i) {\n        for (int j =\
    \ 0; j <= n; ++j) {\n            if (j-i >= 0) {\n                part[i][j] =\
    \ part[i-1][j] + part[i][j-i];\n            } else {\n                part[i][j]\
    \ = part[i-1][j];\n            }\n        }\n    }\n    return part[k][n];\n}\n"
  code: "#include \"../template.cpp\"\n\n// \u5206\u5272\u6570\n// Partition(k, n)\
    \ := \u533A\u5225\u3067\u304D\u306A\u3044n \u500B\u306E\u30DC\u30FC\u30EB\u3092\
    \n//                    \u533A\u5225\u3067\u304D\u306A\u3044k \u500B\u306E\u7BB1\
    \u306B\u5165\u308C\u308B\u5834\u5408\u306E\u6570\ntemplate<typename Ring>\nRing\
    \ Partition(int k, int n) {\n    vector<vector<Ring>> part(k+1, vector<Ring>(n+1));\n\
    \    part[0][0] = 1;\n    for (int i = 1; i <= k; ++i) {\n        for (int j =\
    \ 0; j <= n; ++j) {\n            if (j-i >= 0) {\n                part[i][j] =\
    \ part[i-1][j] + part[i][j-i];\n            } else {\n                part[i][j]\
    \ = part[i-1][j];\n            }\n        }\n    }\n    return part[k][n];\n}\n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/number/partition.cpp
  requiredBy: []
  timestamp: '2020-04-20 18:48:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/number/partition/partition2.test.cpp
  - test/number/partition/partition1.test.cpp
documentation_of: lib/number/partition.cpp
layout: document
redirect_from:
- /library/lib/number/partition.cpp
- /library/lib/number/partition.cpp.html
title: lib/number/partition.cpp
---
