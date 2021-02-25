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
    \ cost(cost) {}\n};\n\n\n#line 2 \"lib/number/partition.cpp\"\n\n// \u5206\u5272\
    \u6570\n// Partition(k, n) := \u533A\u5225\u3067\u304D\u306A\u3044n \u500B\u306E\
    \u30DC\u30FC\u30EB\u3092\n//                    \u533A\u5225\u3067\u304D\u306A\
    \u3044k \u500B\u306E\u7BB1\u306B\u5165\u308C\u308B\u5834\u5408\u306E\u6570\ntemplate<typename\
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
  timestamp: '2021-02-25 17:59:51+09:00'
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
