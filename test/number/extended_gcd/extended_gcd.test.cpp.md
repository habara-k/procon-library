---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/number/extended_gcd.cpp
    title: lib/number/extended_gcd.cpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E
  bundledCode: "#line 1 \"test/number/extended_gcd/extended_gcd.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E\"\
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
    \ cost(cost) {}\n};\n\n\n#line 2 \"lib/number/extended_gcd.cpp\"\n\ntemplate<typename\
    \ T>\nT gcd(T a, T b) {\n    if (b == 0) return a;\n    return gcd(b, a % b);\n\
    }\n\ntemplate<typename T>\nT extended_gcd(T a, T b, T& x, T& y) {\n    // solve\
    \ ax + by = gcd(a, b)\n    if (b == 0) { x = 1; y = 0; return a; }\n\n    T X,\
    \ Y;\n    T g = extended_gcd(b, a % b, X, Y);\n    x = Y; y = X - a/b * Y;\n \
    \   return g;\n}\n#line 4 \"test/number/extended_gcd/extended_gcd.test.cpp\"\n\
    \nint main() {\n    ll a, b; cin >> a >> b;\n    ll x, y;\n    extended_gcd(a,\
    \ b, x, y);\n    cout << x << \" \" << y << endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E\"\
    \n\n#include \"../../../lib/number/extended_gcd.cpp\"\n\nint main() {\n    ll\
    \ a, b; cin >> a >> b;\n    ll x, y;\n    extended_gcd(a, b, x, y);\n    cout\
    \ << x << \" \" << y << endl;\n}\n"
  dependsOn:
  - lib/number/extended_gcd.cpp
  - lib/template.cpp
  isVerificationFile: true
  path: test/number/extended_gcd/extended_gcd.test.cpp
  requiredBy: []
  timestamp: '2021-02-25 17:59:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/number/extended_gcd/extended_gcd.test.cpp
layout: document
redirect_from:
- /verify/test/number/extended_gcd/extended_gcd.test.cpp
- /verify/test/number/extended_gcd/extended_gcd.test.cpp.html
title: test/number/extended_gcd/extended_gcd.test.cpp
---
