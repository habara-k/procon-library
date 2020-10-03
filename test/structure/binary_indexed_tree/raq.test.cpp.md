---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/structure/binary_indexed_tree.cpp
    title: lib/structure/binary_indexed_tree.cpp
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E
  bundledCode: "#line 1 \"test/structure/binary_indexed_tree/raq.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E\"\
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
    \ 1e-9;\n// }}}\n\n\n#line 2 \"lib/structure/binary_indexed_tree.cpp\"\n\ntemplate<typename\
    \ T>\nstruct BIT {\n    vector<T> data;\n    int sz;\n    BIT(int sz) : sz(sz),\
    \ data(sz+1) {}\n\n    void add(int i, T x) {\n        // v[i] += x;\n       \
    \ assert(0 <= i and i < sz);\n        for (++i; i < data.size(); i += i & -i)\
    \ data[i] += x;\n    }\n\n    T sum(int i) const {\n        // return v[0] + v[1]\
    \ + ... + v[i]\n        if (i < 0) return 0;\n        assert(i < sz);\n      \
    \  T s = 0;\n        for (++i; i > 0; i -= i & -i) s += data[i];\n        return\
    \ s;\n    }\n\n    friend ostream& operator<<(ostream& os, const BIT& b) {\n \
    \       os << \"[\";\n        for (int i = 0; i < b.sz; ++i) {\n            if\
    \ (i) os << \" \";\n            os << b.sum(i) - b.sum(i-1);\n        }\n    \
    \    return os << \"]\";\n    }\n};\n#line 4 \"test/structure/binary_indexed_tree/raq.test.cpp\"\
    \n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    BIT<int> bit(N+1);\n\
    \    while (Q--) {\n        int q; cin >> q;\n        if (q == 0) {\n        \
    \    int s, t, X;\n            cin >> s >> t >> X; --s, --t;\n            bit.add(s,\
    \ X);\n            bit.add(t+1, -X);\n        } else {\n            int i; cin\
    \ >> i; --i;\n            cout << bit.sum(i) << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E\"\
    \n\n#include \"../../../lib/structure/binary_indexed_tree.cpp\"\n\nint main()\
    \ {\n    int N, Q;\n    cin >> N >> Q;\n    BIT<int> bit(N+1);\n    while (Q--)\
    \ {\n        int q; cin >> q;\n        if (q == 0) {\n            int s, t, X;\n\
    \            cin >> s >> t >> X; --s, --t;\n            bit.add(s, X);\n     \
    \       bit.add(t+1, -X);\n        } else {\n            int i; cin >> i; --i;\n\
    \            cout << bit.sum(i) << endl;\n        }\n    }\n}\n"
  dependsOn:
  - lib/structure/binary_indexed_tree.cpp
  - lib/template.cpp
  isVerificationFile: true
  path: test/structure/binary_indexed_tree/raq.test.cpp
  requiredBy: []
  timestamp: '2020-04-20 18:48:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/structure/binary_indexed_tree/raq.test.cpp
layout: document
redirect_from:
- /verify/test/structure/binary_indexed_tree/raq.test.cpp
- /verify/test/structure/binary_indexed_tree/raq.test.cpp.html
title: test/structure/binary_indexed_tree/raq.test.cpp
---
