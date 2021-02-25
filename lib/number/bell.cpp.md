---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/number/combination.cpp
    title: lib/number/combination.cpp
  - icon: ':heavy_check_mark:'
    path: lib/number/stirling.cpp
    title: lib/number/stirling.cpp
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/number/bell/bell.test.cpp
    title: test/number/bell/bell.test.cpp
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
    \ cost(cost) {}\n};\n\n\n#line 1 \"lib/number/combination.cpp\"\n\n\n#line 4 \"\
    lib/number/combination.cpp\"\n\ntemplate<typename Field>\nstruct Combination {\n\
    \    int _n = 1;\n    vector<Field> _fact{1}, _rfact{1}, _inv{0};\n\n    void\
    \ extend(int n) {\n        _fact.resize(n);\n        _rfact.resize(n);\n     \
    \   _inv.resize(n);\n        for (int i = _n; i < n; ++i) _fact[i] = _fact[i -\
    \ 1] * i;\n        _rfact[n - 1] = 1 / _fact[n - 1];\n        for (int i = n -\
    \ 1; i > _n; --i) _rfact[i - 1] = _rfact[i] * i;\n        for (int i = _n; i <\
    \ n; ++i) _inv[i] = _rfact[i] * _fact[i - 1];\n        _n = n;\n    }\n\n    Field\
    \ fact(int k) {\n        if (_n <= k) extend(k + 1);\n        return _fact.at(k);\n\
    \    }\n\n    Field rfact(int k) {\n        if (_n <= k) extend(k + 1);\n    \
    \    return _rfact.at(k);\n    }\n\n    Field inv(int k) {\n        assert(k !=\
    \ 0);\n        if (_n <= k) extend(k + 1);\n        return _inv.at(k);\n    }\n\
    \n    Field P(int n, int r) {\n        if (r < 0 or n < r) return 0;\n       \
    \ return fact(n) * rfact(n - r);\n    }\n\n    Field C(int n, int r) {\n     \
    \   if (r < 0 or n < r) return 0;\n        return fact(n) * rfact(r) * rfact(n\
    \ - r);\n    }\n\n    Field H(int n, int r) {\n        return (n == 0 and r ==\
    \ 0) ? 1 : C(n + r - 1, r);\n    }\n};\n\n#line 3 \"lib/number/stirling.cpp\"\n\
    \n// \u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570\n// Stirling(n, k) := \u533A\u5225\
    \u3067\u304D\u308Bn \u500B\u306E\u30DC\u30FC\u30EB\u3092\n//                 \
    \  \u533A\u5225\u3067\u304D\u306A\u3044k \u500B\u306E\u7BB1\u306B\u5165\u308C\u308B\
    \u5834\u5408\u306E\u6570\n//                   (\u305F\u3060\u3057\u7A7A\u7BB1\
    \u306FNG)\ntemplate<typename Field>\nField Stirling(int64_t n, int k) {\n    Combination<Field>\
    \ comb;\n\n    Field ret = 0;\n    for (int i = 0; i <= k; ++i) {\n        ret\
    \ += comb.C(k, i) * Field{k-i}.pow(n) * (i & 1 ? -1 : 1);\n    }\n    return ret\
    \ /= comb.fact(k);\n}\n#line 3 \"lib/number/bell.cpp\"\n\n// Bell \u6570\n// Bell(n,\
    \ k) := \u533A\u5225\u3067\u304D\u308Bn \u500B\u306E\u30DC\u30FC\u30EB\u3092,\n\
    //               \u533A\u5225\u3067\u304D\u306A\u3044k \u500B\u306E\u7BB1\u306B\
    \u5165\u308C\u308B\u5834\u5408\u306E\u6570\ntemplate<typename Field>\nField Bell(ll\
    \ n, int k) {\n    Field ret = 0;\n    for (int i = 0; i <= k; ++i) {\n      \
    \  ret += Stirling<Field>(n, i);\n    }\n    return ret;\n}\n"
  code: "#include \"../template.cpp\"\n#include \"stirling.cpp\"\n\n// Bell \u6570\
    \n// Bell(n, k) := \u533A\u5225\u3067\u304D\u308Bn \u500B\u306E\u30DC\u30FC\u30EB\
    \u3092,\n//               \u533A\u5225\u3067\u304D\u306A\u3044k \u500B\u306E\u7BB1\
    \u306B\u5165\u308C\u308B\u5834\u5408\u306E\u6570\ntemplate<typename Field>\nField\
    \ Bell(ll n, int k) {\n    Field ret = 0;\n    for (int i = 0; i <= k; ++i) {\n\
    \        ret += Stirling<Field>(n, i);\n    }\n    return ret;\n}\n"
  dependsOn:
  - lib/template.cpp
  - lib/number/stirling.cpp
  - lib/number/combination.cpp
  isVerificationFile: false
  path: lib/number/bell.cpp
  requiredBy: []
  timestamp: '2021-02-25 17:59:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/number/bell/bell.test.cpp
documentation_of: lib/number/bell.cpp
layout: document
redirect_from:
- /library/lib/number/bell.cpp
- /library/lib/number/bell.cpp.html
title: lib/number/bell.cpp
---
