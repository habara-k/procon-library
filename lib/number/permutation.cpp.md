---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/number/permutation/permutation.test.cpp
    title: test/number/permutation/permutation.test.cpp
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
    \ 1e-9;\n// }}}\n\n\n#line 2 \"lib/number/permutation.cpp\"\n\nstruct Permutation\
    \ {\n    vector<int> perm;\n    Permutation() {}\n    Permutation(int sz) : perm(sz)\
    \ {\n        iota(perm.begin(), perm.end(), 0);\n    }\n    Permutation(initializer_list<int>\
    \ init) : perm(init.begin(), init.end()) {}\n    size_t size() const {\n     \
    \   return (perm.size());\n    }\n    inline int operator [](int k) const {\n\
    \        return (perm.at(k));\n    }\n    inline int& operator [](int k) {\n \
    \       return (perm.at(k));\n    }\n    Permutation& operator*=(const Permutation&\
    \ rhs) {\n        assert(size() == rhs.size());\n        Permutation tmp(size());\n\
    \        for (int i = 0; i < size(); ++i) {\n            tmp[i] = perm[rhs[i]];\n\
    \        }\n        perm.swap(tmp.perm);\n        return (*this);\n    }\n   \
    \ const Permutation operator*(const Permutation& rhs) const {\n        return\
    \ (Permutation(*this) *= rhs);\n    }\n    Permutation pow(int64_t k) {\n    \
    \    Permutation ret(size()), tmp = *this;\n        while (k) {\n            if\
    \ (k & 1) ret *= tmp;\n            tmp *= tmp; k >>= 1;\n        }\n        return\
    \ (ret);\n    }\n};\n"
  code: "#include \"../template.cpp\"\n\nstruct Permutation {\n    vector<int> perm;\n\
    \    Permutation() {}\n    Permutation(int sz) : perm(sz) {\n        iota(perm.begin(),\
    \ perm.end(), 0);\n    }\n    Permutation(initializer_list<int> init) : perm(init.begin(),\
    \ init.end()) {}\n    size_t size() const {\n        return (perm.size());\n \
    \   }\n    inline int operator [](int k) const {\n        return (perm.at(k));\n\
    \    }\n    inline int& operator [](int k) {\n        return (perm.at(k));\n \
    \   }\n    Permutation& operator*=(const Permutation& rhs) {\n        assert(size()\
    \ == rhs.size());\n        Permutation tmp(size());\n        for (int i = 0; i\
    \ < size(); ++i) {\n            tmp[i] = perm[rhs[i]];\n        }\n        perm.swap(tmp.perm);\n\
    \        return (*this);\n    }\n    const Permutation operator*(const Permutation&\
    \ rhs) const {\n        return (Permutation(*this) *= rhs);\n    }\n    Permutation\
    \ pow(int64_t k) {\n        Permutation ret(size()), tmp = *this;\n        while\
    \ (k) {\n            if (k & 1) ret *= tmp;\n            tmp *= tmp; k >>= 1;\n\
    \        }\n        return (ret);\n    }\n};\n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/number/permutation.cpp
  requiredBy: []
  timestamp: '2020-04-20 18:48:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/number/permutation/permutation.test.cpp
documentation_of: lib/number/permutation.cpp
layout: document
redirect_from:
- /library/lib/number/permutation.cpp
- /library/lib/number/permutation.cpp.html
title: lib/number/permutation.cpp
---
