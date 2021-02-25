---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
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
    \ cost(cost) {}\n};\n\n\n#line 2 \"lib/number/fast_mobius_transform.cpp\"\n\n\
    // O(NlogN)\ntemplate<typename T>\nvector<T> fast_mobius_transform(const vector<T>&\
    \ g) {\n    // Return f(s):\n    // s.t. g(s) = \\sum_{s \\subset t} f(t)\n  \
    \  // ( e.g. f(s) = \\sum_{s \\subset t} (-1)^|t-s| * g(t) )\n    int n = g.size();\n\
    \    vector<T> f = g;\n    for (int i = 0; (1 << i) < n; ++i) {\n        for (int\
    \ j = 0; j < n; ++j) {\n            if (!(j >> i & 1)) {\n                f[j]\
    \ -= f[j | (1<<i)];\n            }\n        }\n    }\n    return f;\n}\n\n// O(NloglogN)\n\
    template<typename T>\nvector<T> fast_mobius_transform_prime(const vector<T>& g)\
    \ {\n    // Return f(d):\n    // s.t. g(d) = \\sum_{d | n} f(n)\n    // ( e.g.\
    \ f(d) = \\sum_{d | n} mu(n / d) * g(n) )\n    int n = g.size();\n    vector<T>\
    \ f = g;\n    vector<bool> sieve(n, true);\n    for (int p = 2; p < n; ++p) {\n\
    \        if (!sieve[p]) continue;\n        for (int i = 1; i * p < n; ++i) {\n\
    \            sieve[i * p] = false;\n            f[i] -= f[i * p];\n        }\n\
    \    }\n    return f;\n}\n"
  code: "#include \"../template.cpp\"\n\n// O(NlogN)\ntemplate<typename T>\nvector<T>\
    \ fast_mobius_transform(const vector<T>& g) {\n    // Return f(s):\n    // s.t.\
    \ g(s) = \\sum_{s \\subset t} f(t)\n    // ( e.g. f(s) = \\sum_{s \\subset t}\
    \ (-1)^|t-s| * g(t) )\n    int n = g.size();\n    vector<T> f = g;\n    for (int\
    \ i = 0; (1 << i) < n; ++i) {\n        for (int j = 0; j < n; ++j) {\n       \
    \     if (!(j >> i & 1)) {\n                f[j] -= f[j | (1<<i)];\n         \
    \   }\n        }\n    }\n    return f;\n}\n\n// O(NloglogN)\ntemplate<typename\
    \ T>\nvector<T> fast_mobius_transform_prime(const vector<T>& g) {\n    // Return\
    \ f(d):\n    // s.t. g(d) = \\sum_{d | n} f(n)\n    // ( e.g. f(d) = \\sum_{d\
    \ | n} mu(n / d) * g(n) )\n    int n = g.size();\n    vector<T> f = g;\n    vector<bool>\
    \ sieve(n, true);\n    for (int p = 2; p < n; ++p) {\n        if (!sieve[p]) continue;\n\
    \        for (int i = 1; i * p < n; ++i) {\n            sieve[i * p] = false;\n\
    \            f[i] -= f[i * p];\n        }\n    }\n    return f;\n}\n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/number/fast_mobius_transform.cpp
  requiredBy: []
  timestamp: '2021-02-25 17:59:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/number/fast_mobius_transform.cpp
layout: document
redirect_from:
- /library/lib/number/fast_mobius_transform.cpp
- /library/lib/number/fast_mobius_transform.cpp.html
title: lib/number/fast_mobius_transform.cpp
---
