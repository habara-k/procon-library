---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/number/prime_factorize.cpp
    title: lib/number/prime_factorize.cpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A
  bundledCode: "#line 1 \"test/number/prime_factorize/prime_factorize.test.cpp\"\n\
    #define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A\"\
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
    \ cost(cost) {}\n};\n\n\n#line 2 \"lib/number/prime_factorize.cpp\"\n\n// O(sqrt(n))\n\
    map<int64_t, int> prime_factorize(int64_t n) {\n    map<int64_t, int> ret;\n \
    \   for (int64_t i = 2; i * i <= n; ++i) {\n        while (n % i == 0) {\n   \
    \         ret[i]++;\n            n /= i;\n        }\n    }\n    if (n != 1) ret[n]\
    \ = 1;\n    return ret;\n}\n#line 4 \"test/number/prime_factorize/prime_factorize.test.cpp\"\
    \n\nint main() {\n    int n; cin >> n;\n\n    map<int64_t, int> fact = prime_factorize(n);\n\
    \n    cout << n << \":\";\n\n    for (auto tp : fact) {\n        for (int i =\
    \ 0; i < tp.second; ++i) {\n            cout << \" \" << tp.first;\n        }\n\
    \    }\n    cout << endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A\"\
    \n\n#include \"../../../lib/number/prime_factorize.cpp\"\n\nint main() {\n   \
    \ int n; cin >> n;\n\n    map<int64_t, int> fact = prime_factorize(n);\n\n   \
    \ cout << n << \":\";\n\n    for (auto tp : fact) {\n        for (int i = 0; i\
    \ < tp.second; ++i) {\n            cout << \" \" << tp.first;\n        }\n   \
    \ }\n    cout << endl;\n}\n"
  dependsOn:
  - lib/number/prime_factorize.cpp
  - lib/template.cpp
  isVerificationFile: true
  path: test/number/prime_factorize/prime_factorize.test.cpp
  requiredBy: []
  timestamp: '2021-02-25 17:59:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/number/prime_factorize/prime_factorize.test.cpp
layout: document
redirect_from:
- /verify/test/number/prime_factorize/prime_factorize.test.cpp
- /verify/test/number/prime_factorize/prime_factorize.test.cpp.html
title: test/number/prime_factorize/prime_factorize.test.cpp
---
