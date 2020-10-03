---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/number/combination.cpp
    title: lib/number/combination.cpp
  - icon: ':heavy_check_mark:'
    path: lib/number/modint.cpp
    title: lib/number/modint.cpp
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_B
  bundledCode: "#line 1 \"test/number/combination/combination.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_B\"\
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
    \    }\n};\n#line 1 \"lib/number/combination.cpp\"\n\n\n#line 4 \"lib/number/combination.cpp\"\
    \n\ntemplate<typename Field>\nstruct Combination {\n    int _n = 1;\n    vector<Field>\
    \ _fact{1}, _rfact{1}, _inv{0};\n\n    void extend(int n) {\n        _fact.resize(n);\n\
    \        _rfact.resize(n);\n        _inv.resize(n);\n        for (int i = _n;\
    \ i < n; ++i) _fact[i] = _fact[i - 1] * i;\n        _rfact[n - 1] = 1 / _fact[n\
    \ - 1];\n        for (int i = n - 1; i > _n; --i) _rfact[i - 1] = _rfact[i] *\
    \ i;\n        for (int i = _n; i < n; ++i) _inv[i] = _rfact[i] * _fact[i - 1];\n\
    \        _n = n;\n    }\n\n    Field fact(int k) {\n        if (_n <= k) extend(k\
    \ + 1);\n        return _fact.at(k);\n    }\n\n    Field rfact(int k) {\n    \
    \    if (_n <= k) extend(k + 1);\n        return _rfact.at(k);\n    }\n\n    Field\
    \ inv(int k) {\n        assert(k != 0);\n        if (_n <= k) extend(k + 1);\n\
    \        return _inv.at(k);\n    }\n\n    Field P(int n, int r) {\n        if\
    \ (r < 0 or n < r) return 0;\n        return fact(n) * rfact(n - r);\n    }\n\n\
    \    Field C(int n, int r) {\n        if (r < 0 or n < r) return 0;\n        return\
    \ fact(n) * rfact(r) * rfact(n - r);\n    }\n\n    Field H(int n, int r) {\n \
    \       return (n == 0 and r == 0) ? 1 : C(n + r - 1, r);\n    }\n};\n\n#line\
    \ 5 \"test/number/combination/combination.test.cpp\"\n\nint main() {\n    int64_t\
    \ n, k;\n    cin >> n >> k;\n\n    if (n > k) {\n        cout << 0 << endl;\n\
    \        return 0;\n    }\n\n    using Int = modint<MOD>;\n    Combination<Int>\
    \ comb;\n\n    cout << comb.C(k, n) * comb.fact(n) << endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_B\"\
    \n\n#include \"../../../lib/number/modint.cpp\"\n#include \"../../../lib/number/combination.cpp\"\
    \n\nint main() {\n    int64_t n, k;\n    cin >> n >> k;\n\n    if (n > k) {\n\
    \        cout << 0 << endl;\n        return 0;\n    }\n\n    using Int = modint<MOD>;\n\
    \    Combination<Int> comb;\n\n    cout << comb.C(k, n) * comb.fact(n) << endl;\n\
    }\n"
  dependsOn:
  - lib/number/modint.cpp
  - lib/template.cpp
  - lib/number/combination.cpp
  isVerificationFile: true
  path: test/number/combination/combination.test.cpp
  requiredBy: []
  timestamp: '2020-10-03 18:08:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/number/combination/combination.test.cpp
layout: document
redirect_from:
- /verify/test/number/combination/combination.test.cpp
- /verify/test/number/combination/combination.test.cpp.html
title: test/number/combination/combination.test.cpp
---
