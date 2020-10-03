---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lib/number/bell.cpp
    title: lib/number/bell.cpp
  - icon: ':heavy_check_mark:'
    path: lib/number/stirling.cpp
    title: lib/number/stirling.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/number/bell/bell.test.cpp
    title: test/number/bell/bell.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/number/combination/combination.test.cpp
    title: test/number/combination/combination.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/number/stirling/stirling.test.cpp
    title: test/number/stirling/stirling.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/number/combination.cpp\"\n\n\n#line 1 \"lib/template.cpp\"\
    \n\n\n#include <bits/stdc++.h>\nusing namespace std;\n\n// type {{{\nusing ll\
    \ = long long;\nusing ull = unsigned long long;\nusing ld = long double;\nusing\
    \ P = pair<int,int>;\nusing vi = vector<int>;\nusing vll = vector<ll>;\nusing\
    \ vvi = vector<vector<int>>;\nusing vvll = vector<vector<ll>>;\n// }}}\n\n\n//\
    \ macro {{{\n#define REP(i,n) for (int i=0; i<(n); ++i)\n#define RREP(i,n) for\
    \ (int i=(int)(n)-1; i>=0; --i)\n#define FOR(i,a,n) for (int i=(a); i<(n); ++i)\n\
    #define RFOR(i,a,n) for (int i=(int)(n)-1; i>=(a); --i)\n\n#define SZ(x) ((int)(x).size())\n\
    #define all(x) begin(x),end(x)\n// }}}\n\n\n// debug {{{\n#define dump(x) cerr<<#x<<\"\
    \ = \"<<(x)<<endl\n#define debug(x) cerr<<#x<<\" = \"<<(x)<<\" (L\"<<__LINE__<<\"\
    )\"<< endl;\n\ntemplate<typename T>\nostream& operator<<(ostream& os, const vector<T>&\
    \ v) {\n    os << \"[\";\n    REP (i, SZ(v)) {\n        if (i) os << \", \";\n\
    \        os << v[i];\n    }\n    return os << \"]\";\n}\n\ntemplate<typename T,\
    \ typename U>\nostream& operator<<(ostream& os, const pair<T, U>& p) {\n    return\
    \ os << \"(\" << p.first << \" \" << p.second << \")\";\n}\n// }}}\n\n\n// chmax,\
    \ chmin {{{\ntemplate<class T>\nbool chmax(T& a, const T& b) {\n    if (a < b)\
    \ { a = b; return true; }\n    return false;\n}\ntemplate<class T>\nbool chmin(T&\
    \ a, const T& b) {\n    if (b < a) { a = b; return true; }\n    return false;\n\
    }\n// }}}\n\n\n// constants {{{\n#define inf(T) (numeric_limits<T>::max() / 2)\n\
    const ll MOD = 1e9+7;\nconst ld EPS = 1e-9;\n// }}}\n\n\n#line 4 \"lib/number/combination.cpp\"\
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
    \       return (n == 0 and r == 0) ? 1 : C(n + r - 1, r);\n    }\n};\n\n"
  code: "#ifndef COMBINATION\n#define COMBINATION\n#include \"../template.cpp\"\n\n\
    template<typename Field>\nstruct Combination {\n    int _n = 1;\n    vector<Field>\
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
    \       return (n == 0 and r == 0) ? 1 : C(n + r - 1, r);\n    }\n};\n#endif\n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/number/combination.cpp
  requiredBy:
  - lib/number/bell.cpp
  - lib/number/stirling.cpp
  timestamp: '2020-10-03 18:08:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/number/combination/combination.test.cpp
  - test/number/bell/bell.test.cpp
  - test/number/stirling/stirling.test.cpp
documentation_of: lib/number/combination.cpp
layout: document
redirect_from:
- /library/lib/number/combination.cpp
- /library/lib/number/combination.cpp.html
title: lib/number/combination.cpp
---
