---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/heavy_light_decomposition/heavy_light_decomposition.test.cpp
    title: test/graph/heavy_light_decomposition/heavy_light_decomposition.test.cpp
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
    \ 1e-9;\n// }}}\n\n\n#line 2 \"lib/structure/lazy_segment_tree.cpp\"\n\ntemplate<typename\
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
  timestamp: '2020-05-22 14:56:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/structure/lazy_segment_tree/rmq_ruq.test.cpp
  - test/structure/lazy_segment_tree/rsq_ruq.test.cpp
  - test/structure/lazy_segment_tree/rmq_raq.test.cpp
  - test/structure/lazy_segment_tree/rsq_raq.test.cpp
  - test/graph/heavy_light_decomposition/heavy_light_decomposition.test.cpp
documentation_of: lib/structure/lazy_segment_tree.cpp
layout: document
redirect_from:
- /library/lib/structure/lazy_segment_tree.cpp
- /library/lib/structure/lazy_segment_tree.cpp.html
title: lib/structure/lazy_segment_tree.cpp
---
