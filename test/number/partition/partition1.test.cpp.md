---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/number/modint.cpp
    title: lib/number/modint.cpp
  - icon: ':heavy_check_mark:'
    path: lib/number/partition.cpp
    title: lib/number/partition.cpp
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_J
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_J
  bundledCode: "#line 1 \"test/number/partition/partition1.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_J\"\n\n#line\
    \ 1 \"lib/template.cpp\"\n\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \n// type {{{\nusing ll = long long;\nusing ull = unsigned long long;\nusing ld\
    \ = long double;\nusing P = pair<int,int>;\nusing vi = vector<int>;\nusing vll\
    \ = vector<ll>;\nusing vvi = vector<vector<int>>;\nusing vvll = vector<vector<ll>>;\n\
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
    \ 1e-9;\n// }}}\n\n\n#line 2 \"lib/number/modint.cpp\"\n\ntemplate<int64_t mod>\n\
    class modint {\n    int64_t x;\n\npublic:\n    modint(int64_t x = 0) : x(x < 0\
    \ ? ((x % mod) + mod) % mod : x % mod) {}\n\n    const modint operator-() const\
    \ { return x ? mod - x : 0; }\n\n    modint& operator+=(const modint& rhs) {\n\
    \        if ((x += rhs.x) >= mod) x -= mod;\n        return *this;\n    }\n  \
    \  modint& operator-=(const modint& rhs) {\n        return *this += -rhs;\n  \
    \  }\n    modint& operator*=(const modint& rhs) {\n        (x *= rhs.x) %= mod;\n\
    \        return *this;\n    }\n    modint& operator/=(const modint& rhs) {\n \
    \       return *this *= rhs.pow(mod - 2);\n    }\n\n    friend const modint operator+(modint\
    \ lhs, const modint& rhs) {\n        return lhs += rhs;\n    }\n    friend const\
    \ modint operator-(modint lhs, const modint& rhs) {\n        return lhs -= rhs;\n\
    \    }\n    friend const modint operator*(modint lhs, const modint& rhs) {\n \
    \       return lhs *= rhs;\n    }\n    friend const modint operator/(modint lhs,\
    \ const modint& rhs) {\n        return lhs /= rhs;\n    }\n\n    const modint\
    \ pow(int64_t n) const {\n        modint ret = 1, tmp = *this;\n        while\
    \ (n) {\n            if (n & 1) ret *= tmp;\n            tmp *= tmp; n >>= 1;\n\
    \        }\n        return ret;\n    }\n\n    friend bool operator==(const modint&\
    \ lhs, const modint& rhs) {\n        return lhs.x == rhs.x;\n    }\n    friend\
    \ bool operator!=(const modint& lhs, const modint& rhs) {\n        return !(lhs\
    \ == rhs);\n    }\n\n    friend ostream& operator<<(ostream& os, const modint&\
    \ a) {\n        return os << a.x;\n    }\n    friend istream& operator>>(istream&\
    \ is, modint& a) {\n        int64_t tmp; is >> tmp; a = tmp;\n        return is;\n\
    \    }\n};\n#line 2 \"lib/number/partition.cpp\"\n\n// \u5206\u5272\u6570\n//\
    \ Partition(k, n) := \u533A\u5225\u3067\u304D\u306A\u3044n \u500B\u306E\u30DC\u30FC\
    \u30EB\u3092\n//                    \u533A\u5225\u3067\u304D\u306A\u3044k \u500B\
    \u306E\u7BB1\u306B\u5165\u308C\u308B\u5834\u5408\u306E\u6570\ntemplate<typename\
    \ Ring>\nRing Partition(int k, int n) {\n    vector<vector<Ring>> part(k+1, vector<Ring>(n+1));\n\
    \    part[0][0] = 1;\n    for (int i = 1; i <= k; ++i) {\n        for (int j =\
    \ 0; j <= n; ++j) {\n            if (j-i >= 0) {\n                part[i][j] =\
    \ part[i-1][j] + part[i][j-i];\n            } else {\n                part[i][j]\
    \ = part[i-1][j];\n            }\n        }\n    }\n    return part[k][n];\n}\n\
    #line 5 \"test/number/partition/partition1.test.cpp\"\n\nint main() {\n    int\
    \ n, k; cin >> n >> k;\n\n    using Int = modint<MOD>;\n    cout << Partition<Int>(k,\
    \ n) << endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_J\"\
    \n\n#include \"../../../lib/number/modint.cpp\"\n#include \"../../../lib/number/partition.cpp\"\
    \n\nint main() {\n    int n, k; cin >> n >> k;\n\n    using Int = modint<MOD>;\n\
    \    cout << Partition<Int>(k, n) << endl;\n}\n"
  dependsOn:
  - lib/number/modint.cpp
  - lib/template.cpp
  - lib/number/partition.cpp
  isVerificationFile: true
  path: test/number/partition/partition1.test.cpp
  requiredBy: []
  timestamp: '2020-06-22 23:31:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/number/partition/partition1.test.cpp
layout: document
redirect_from:
- /verify/test/number/partition/partition1.test.cpp
- /verify/test/number/partition/partition1.test.cpp.html
title: test/number/partition/partition1.test.cpp
---
