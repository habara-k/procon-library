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
    \ 1e-9;\n// }}}\n\n\n#line 2 \"lib/number/prime_factorize.cpp\"\n\n// O(sqrt(n))\n\
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
  timestamp: '2020-04-20 18:48:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/number/prime_factorize/prime_factorize.test.cpp
layout: document
redirect_from:
- /verify/test/number/prime_factorize/prime_factorize.test.cpp
- /verify/test/number/prime_factorize/prime_factorize.test.cpp.html
title: test/number/prime_factorize/prime_factorize.test.cpp
---
