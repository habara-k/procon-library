---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/structure/dual_segment_tree/ruq.test.cpp
    title: test/structure/dual_segment_tree/ruq.test.cpp
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
    \ cost(cost) {}\n};\n\n\n#line 2 \"lib/structure/dual_segment_tree.cpp\"\n\ntemplate<typename\
    \ OM>\nstruct DualSegmentTree {\n    int n, sz;\n    vector<OM> lazy;\n    const\
    \ function<OM(OM,OM)> h;\n    const OM oe;\n    // h: \u4F5C\u7528\u7D20\u3092\
    \u30DE\u30FC\u30B8\u3059\u308B\u95A2\u6570\n    // oe: \u4F5C\u7528\u7D20\u306E\
    \u5358\u4F4D\u5143\n\n    DualSegmentTree(\n            int n,\n            const\
    \ function<OM(OM,OM)>& h,\n            const OM& oe\n            ) : n(n), h(h),\
    \ oe(oe) {\n        sz = 1;\n        while (sz < n) sz <<= 1;\n        lazy.assign(2*sz,\
    \ oe);\n    }\n\n    void set(int i, const OM& x) {\n        lazy.at(i + sz) =\
    \ x;\n    }\n\n    OM merge(const OM& a, const OM& b) const {\n        if (a ==\
    \ oe) return b;\n        if (b == oe) return a;\n        return h(a, b);\n   \
    \ }\n\n    void propagate(int k, int len) {\n        if (lazy[k] == oe) return;\n\
    \        if (k < sz) {\n            lazy[2*k  ] = merge(lazy[2*k  ], lazy[k]);\n\
    \            lazy[2*k+1] = merge(lazy[2*k+1], lazy[k]);\n            lazy[k] =\
    \ oe;\n        }\n    }\n\n    void _update(int a, int b, const OM& x, int k,\
    \ int l, int r) {\n        propagate(k, r - l);\n        if (r <= a or b <= l)\
    \ return;\n        else if (a <= l and r <= b) {\n            lazy[k] = merge(lazy[k],\
    \ x);\n            propagate(k, r - l);\n        } else {\n            _update(a,\
    \ b, x, 2*k,   l, (l+r)/2);\n            _update(a, b, x, 2*k+1, (l+r)/2, r);\n\
    \        }\n    }\n\n    void update(int a, int b, const OM& x) {\n        //\
    \ update [a, b) with x.\n        _update(a, b, x, 1, 0, sz);\n    }\n\n    OM\
    \ _query(int i, int k, int l, int r) {\n        if (l+1 == r) return lazy[l +\
    \ sz];\n        propagate(k, r - l);\n        int m = (l+r)/2;\n        if (i\
    \ < m) return _query(i, 2*k,   l, m);\n        else       return _query(i, 2*k+1,\
    \ m, r);\n    }\n\n    OM operator[](int i) {\n        return _query(i, 1, 0,\
    \ sz);\n    }\n\n    friend ostream& operator<<(ostream& os, DualSegmentTree&\
    \ s) {\n        os << \"[\";\n        for (int i = 0; i < s.n; ++i) {\n      \
    \      if (i) os << \" \";\n            os << s[i];\n        }\n        return\
    \ os << \"]\";\n    }\n};\n"
  code: "#include \"../template.cpp\"\n\ntemplate<typename OM>\nstruct DualSegmentTree\
    \ {\n    int n, sz;\n    vector<OM> lazy;\n    const function<OM(OM,OM)> h;\n\
    \    const OM oe;\n    // h: \u4F5C\u7528\u7D20\u3092\u30DE\u30FC\u30B8\u3059\u308B\
    \u95A2\u6570\n    // oe: \u4F5C\u7528\u7D20\u306E\u5358\u4F4D\u5143\n\n    DualSegmentTree(\n\
    \            int n,\n            const function<OM(OM,OM)>& h,\n            const\
    \ OM& oe\n            ) : n(n), h(h), oe(oe) {\n        sz = 1;\n        while\
    \ (sz < n) sz <<= 1;\n        lazy.assign(2*sz, oe);\n    }\n\n    void set(int\
    \ i, const OM& x) {\n        lazy.at(i + sz) = x;\n    }\n\n    OM merge(const\
    \ OM& a, const OM& b) const {\n        if (a == oe) return b;\n        if (b ==\
    \ oe) return a;\n        return h(a, b);\n    }\n\n    void propagate(int k, int\
    \ len) {\n        if (lazy[k] == oe) return;\n        if (k < sz) {\n        \
    \    lazy[2*k  ] = merge(lazy[2*k  ], lazy[k]);\n            lazy[2*k+1] = merge(lazy[2*k+1],\
    \ lazy[k]);\n            lazy[k] = oe;\n        }\n    }\n\n    void _update(int\
    \ a, int b, const OM& x, int k, int l, int r) {\n        propagate(k, r - l);\n\
    \        if (r <= a or b <= l) return;\n        else if (a <= l and r <= b) {\n\
    \            lazy[k] = merge(lazy[k], x);\n            propagate(k, r - l);\n\
    \        } else {\n            _update(a, b, x, 2*k,   l, (l+r)/2);\n        \
    \    _update(a, b, x, 2*k+1, (l+r)/2, r);\n        }\n    }\n\n    void update(int\
    \ a, int b, const OM& x) {\n        // update [a, b) with x.\n        _update(a,\
    \ b, x, 1, 0, sz);\n    }\n\n    OM _query(int i, int k, int l, int r) {\n   \
    \     if (l+1 == r) return lazy[l + sz];\n        propagate(k, r - l);\n     \
    \   int m = (l+r)/2;\n        if (i < m) return _query(i, 2*k,   l, m);\n    \
    \    else       return _query(i, 2*k+1, m, r);\n    }\n\n    OM operator[](int\
    \ i) {\n        return _query(i, 1, 0, sz);\n    }\n\n    friend ostream& operator<<(ostream&\
    \ os, DualSegmentTree& s) {\n        os << \"[\";\n        for (int i = 0; i <\
    \ s.n; ++i) {\n            if (i) os << \" \";\n            os << s[i];\n    \
    \    }\n        return os << \"]\";\n    }\n};\n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/structure/dual_segment_tree.cpp
  requiredBy: []
  timestamp: '2021-02-25 17:59:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/structure/dual_segment_tree/ruq.test.cpp
documentation_of: lib/structure/dual_segment_tree.cpp
layout: document
redirect_from:
- /library/lib/structure/dual_segment_tree.cpp
- /library/lib/structure/dual_segment_tree.cpp.html
title: lib/structure/dual_segment_tree.cpp
---
