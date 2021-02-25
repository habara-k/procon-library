---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/structure/fenwick_tree/raq.test.cpp
    title: test/structure/fenwick_tree/raq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/structure/fenwick_tree/rsq.test.cpp
    title: test/structure/fenwick_tree/rsq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/euler_tour/euler_tour.test.cpp
    title: test/tree/euler_tour/euler_tour.test.cpp
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
    \ cost(cost) {}\n};\n\n\n#line 2 \"lib/structure/fenwick_tree.cpp\"\n\ntemplate<typename\
    \ T>\nstruct fenwick_tree {\n    vector<T> data;\n    int sz;\n    fenwick_tree(int\
    \ sz) : sz(sz), data(sz+1) {}\n\n    void add(int i, T x) {\n        // a[i] +=\
    \ x;\n        assert(0 <= i and i < sz);\n        for (++i; i <= sz; i += i &\
    \ -i) data[i] += x;\n    }\n\n    T sum(int i) const {\n        // return a[0]\
    \ + ... + a[i-1]\n        assert(0 <= i and i <= sz);\n        T s = 0;\n    \
    \    for (; i > 0; i -= i & -i) s += data[i];\n        return s;\n    }\n\n  \
    \  T sum(int l, int r) const {\n        // return a[l] + ... + a[r-1]\n      \
    \  return sum(r) - sum(l);\n    }\n\n    friend ostream& operator<<(ostream& os,\
    \ const fenwick_tree& a) {\n        os << \"[\";\n        for (int i = 0; i <\
    \ a.sz; ++i) {\n            if (i) os << \" \";\n            os << a.sum(i, i+1);\n\
    \        }\n        return os << \"]\";\n    }\n};\n"
  code: "#include \"../template.cpp\"\n\ntemplate<typename T>\nstruct fenwick_tree\
    \ {\n    vector<T> data;\n    int sz;\n    fenwick_tree(int sz) : sz(sz), data(sz+1)\
    \ {}\n\n    void add(int i, T x) {\n        // a[i] += x;\n        assert(0 <=\
    \ i and i < sz);\n        for (++i; i <= sz; i += i & -i) data[i] += x;\n    }\n\
    \n    T sum(int i) const {\n        // return a[0] + ... + a[i-1]\n        assert(0\
    \ <= i and i <= sz);\n        T s = 0;\n        for (; i > 0; i -= i & -i) s +=\
    \ data[i];\n        return s;\n    }\n\n    T sum(int l, int r) const {\n    \
    \    // return a[l] + ... + a[r-1]\n        return sum(r) - sum(l);\n    }\n\n\
    \    friend ostream& operator<<(ostream& os, const fenwick_tree& a) {\n      \
    \  os << \"[\";\n        for (int i = 0; i < a.sz; ++i) {\n            if (i)\
    \ os << \" \";\n            os << a.sum(i, i+1);\n        }\n        return os\
    \ << \"]\";\n    }\n};\n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/structure/fenwick_tree.cpp
  requiredBy: []
  timestamp: '2021-02-25 17:59:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/structure/fenwick_tree/raq.test.cpp
  - test/structure/fenwick_tree/rsq.test.cpp
  - test/tree/euler_tour/euler_tour.test.cpp
documentation_of: lib/structure/fenwick_tree.cpp
layout: document
redirect_from:
- /library/lib/structure/fenwick_tree.cpp
- /library/lib/structure/fenwick_tree.cpp.html
title: lib/structure/fenwick_tree.cpp
---
