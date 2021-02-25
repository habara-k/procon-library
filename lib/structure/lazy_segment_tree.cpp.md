---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/structure/lazy_segment_tree/rmq_raq.test.cpp
    title: test/structure/lazy_segment_tree/rmq_raq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/structure/lazy_segment_tree/rmq_ruq.test.cpp
    title: test/structure/lazy_segment_tree/rmq_ruq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/structure/lazy_segment_tree/rsq_raq.test.cpp
    title: test/structure/lazy_segment_tree/rsq_raq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/structure/lazy_segment_tree/rsq_ruq.test.cpp
    title: test/structure/lazy_segment_tree/rsq_ruq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/hld/hld.test.cpp
    title: test/tree/hld/hld.test.cpp
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
    \ cost(cost) {}\n};\n\n\n#line 2 \"lib/structure/lazy_segment_tree.cpp\"\n\ntemplate<typename\
    \ M, typename OM = M>\nstruct LazySegmentTree {\n\n    LazySegmentTree(\n    \
    \        int n,\n            const function<M(M,M)>& f,\n            const function<M(M,OM,int)>&\
    \ g,\n            const function<OM(OM,OM)>& h,\n            const M& e, const\
    \ OM& oe\n            ) : n(n), f(f), g(g), h(h), e(e), oe(oe) {\n        sz =\
    \ 1;\n        while (sz < n) sz <<= 1;\n        data.assign(2*sz, e);\n      \
    \  lazy.assign(2*sz, oe);\n    }\n\n    void build(const vector<M>& v) {\n   \
    \     assert(v.size() <= n);\n        for (int i = 0; i < v.size(); ++i) {\n \
    \           data[i + sz] = v[i];\n        }\n        for (int i = sz-1; i > 0;\
    \ --i) {\n            data[i] = f(data[2*i], data[2*i+1]);\n        }\n    }\n\
    \n    void update(int a, int b, const OM& x) {\n        // update [a, b) with\
    \ x.\n        update(a, b, x, 1, 0, sz);\n    }\n\n\n    M query(int a, int b)\
    \ {\n        // return f[a, b).\n        return query(a, b, 1, 0, sz);\n    }\n\
    \n    M operator[](int i) {\n        return query(i, i+1);\n    }\n\n    friend\
    \ ostream& operator<<(ostream& os, LazySegmentTree& s) {\n        os << \"[\"\
    ;\n        for (int i = 0; i < s.n; ++i) {\n            if (i) os << \" \";\n\
    \            os << s[i];\n        }\n        return os << \"]\";\n    }\n\nprivate:\n\
    \n    int n, sz;\n    vector<M> data;\n    vector<OM> lazy;\n    const function<M(M,M)>\
    \ f;\n    const function<M(M,OM,int)> g;\n    const function<OM(OM,OM)> h;\n \
    \   const M e;\n    const OM oe;\n    // f: \u4E8C\u3064\u306E\u533A\u9593\u306E\
    \u8981\u7D20\u3092\u30DE\u30FC\u30B8\u3059\u308B\u95A2\u6570\n    // g: \u8981\
    \u7D20\u3068\u4F5C\u7528\u7D20\u3092\u30DE\u30FC\u30B8\u3059\u308B\u4E8C\u9805\
    \u6F14\u7B97. \u7B2C\u4E09\u5F15\u6570\u306F\u533A\u9593\u5E45\n    // h: \u4F5C\
    \u7528\u7D20\u3092\u30DE\u30FC\u30B8\u3059\u308B\u95A2\u6570\n    // e: \u30E2\
    \u30CE\u30A4\u30C9\u306E\u5358\u4F4D\u5143\n    // oe: \u4F5C\u7528\u7D20\u306E\
    \u5358\u4F4D\u5143\n\n    void propagate(int k, int len) {\n        if (lazy[k]\
    \ == oe) return;\n        if (k < sz) {\n            lazy[2*k  ] = h(lazy[2*k\
    \  ], lazy[k]);\n            lazy[2*k+1] = h(lazy[2*k+1], lazy[k]);\n        }\n\
    \        data[k] = g(data[k], lazy[k], len);\n        lazy[k] = oe;\n    }\n\n\
    \    void update(int a, int b, const OM& x, int k, int l, int r) {\n        propagate(k,\
    \ r - l);\n        if (r <= a or b <= l) return;\n        else if (a <= l and\
    \ r <= b) {\n            lazy[k] = h(lazy[k], x);\n            propagate(k, r\
    \ - l);\n        } else {\n            update(a, b, x, 2*k,   l, (l+r)/2);\n \
    \           update(a, b, x, 2*k+1, (l+r)/2, r);\n            data[k] = f(data[2*k],\
    \ data[2*k+1]);\n        }\n    }\n\n    M query(int a, int b, int k, int l, int\
    \ r) {\n        propagate(k, r - l);\n        if (r <= a or b <= l) return e;\n\
    \        else if (a <= l and r <= b) return data[k];\n        else return f(\n\
    \                query(a, b, 2*k,   l, (l+r)/2),\n                query(a, b,\
    \ 2*k+1, (l+r)/2, r));\n    }\n};\n"
  code: "#include \"../template.cpp\"\n\ntemplate<typename M, typename OM = M>\nstruct\
    \ LazySegmentTree {\n\n    LazySegmentTree(\n            int n,\n            const\
    \ function<M(M,M)>& f,\n            const function<M(M,OM,int)>& g,\n        \
    \    const function<OM(OM,OM)>& h,\n            const M& e, const OM& oe\n   \
    \         ) : n(n), f(f), g(g), h(h), e(e), oe(oe) {\n        sz = 1;\n      \
    \  while (sz < n) sz <<= 1;\n        data.assign(2*sz, e);\n        lazy.assign(2*sz,\
    \ oe);\n    }\n\n    void build(const vector<M>& v) {\n        assert(v.size()\
    \ <= n);\n        for (int i = 0; i < v.size(); ++i) {\n            data[i + sz]\
    \ = v[i];\n        }\n        for (int i = sz-1; i > 0; --i) {\n            data[i]\
    \ = f(data[2*i], data[2*i+1]);\n        }\n    }\n\n    void update(int a, int\
    \ b, const OM& x) {\n        // update [a, b) with x.\n        update(a, b, x,\
    \ 1, 0, sz);\n    }\n\n\n    M query(int a, int b) {\n        // return f[a, b).\n\
    \        return query(a, b, 1, 0, sz);\n    }\n\n    M operator[](int i) {\n \
    \       return query(i, i+1);\n    }\n\n    friend ostream& operator<<(ostream&\
    \ os, LazySegmentTree& s) {\n        os << \"[\";\n        for (int i = 0; i <\
    \ s.n; ++i) {\n            if (i) os << \" \";\n            os << s[i];\n    \
    \    }\n        return os << \"]\";\n    }\n\nprivate:\n\n    int n, sz;\n   \
    \ vector<M> data;\n    vector<OM> lazy;\n    const function<M(M,M)> f;\n    const\
    \ function<M(M,OM,int)> g;\n    const function<OM(OM,OM)> h;\n    const M e;\n\
    \    const OM oe;\n    // f: \u4E8C\u3064\u306E\u533A\u9593\u306E\u8981\u7D20\u3092\
    \u30DE\u30FC\u30B8\u3059\u308B\u95A2\u6570\n    // g: \u8981\u7D20\u3068\u4F5C\
    \u7528\u7D20\u3092\u30DE\u30FC\u30B8\u3059\u308B\u4E8C\u9805\u6F14\u7B97. \u7B2C\
    \u4E09\u5F15\u6570\u306F\u533A\u9593\u5E45\n    // h: \u4F5C\u7528\u7D20\u3092\
    \u30DE\u30FC\u30B8\u3059\u308B\u95A2\u6570\n    // e: \u30E2\u30CE\u30A4\u30C9\
    \u306E\u5358\u4F4D\u5143\n    // oe: \u4F5C\u7528\u7D20\u306E\u5358\u4F4D\u5143\
    \n\n    void propagate(int k, int len) {\n        if (lazy[k] == oe) return;\n\
    \        if (k < sz) {\n            lazy[2*k  ] = h(lazy[2*k  ], lazy[k]);\n \
    \           lazy[2*k+1] = h(lazy[2*k+1], lazy[k]);\n        }\n        data[k]\
    \ = g(data[k], lazy[k], len);\n        lazy[k] = oe;\n    }\n\n    void update(int\
    \ a, int b, const OM& x, int k, int l, int r) {\n        propagate(k, r - l);\n\
    \        if (r <= a or b <= l) return;\n        else if (a <= l and r <= b) {\n\
    \            lazy[k] = h(lazy[k], x);\n            propagate(k, r - l);\n    \
    \    } else {\n            update(a, b, x, 2*k,   l, (l+r)/2);\n            update(a,\
    \ b, x, 2*k+1, (l+r)/2, r);\n            data[k] = f(data[2*k], data[2*k+1]);\n\
    \        }\n    }\n\n    M query(int a, int b, int k, int l, int r) {\n      \
    \  propagate(k, r - l);\n        if (r <= a or b <= l) return e;\n        else\
    \ if (a <= l and r <= b) return data[k];\n        else return f(\n           \
    \     query(a, b, 2*k,   l, (l+r)/2),\n                query(a, b, 2*k+1, (l+r)/2,\
    \ r));\n    }\n};\n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/structure/lazy_segment_tree.cpp
  requiredBy: []
  timestamp: '2021-02-25 17:59:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/structure/lazy_segment_tree/rsq_raq.test.cpp
  - test/structure/lazy_segment_tree/rmq_raq.test.cpp
  - test/structure/lazy_segment_tree/rsq_ruq.test.cpp
  - test/structure/lazy_segment_tree/rmq_ruq.test.cpp
  - test/tree/hld/hld.test.cpp
documentation_of: lib/structure/lazy_segment_tree.cpp
layout: document
redirect_from:
- /library/lib/structure/lazy_segment_tree.cpp
- /library/lib/structure/lazy_segment_tree.cpp.html
title: lib/structure/lazy_segment_tree.cpp
---
