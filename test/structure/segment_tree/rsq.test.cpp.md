---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/structure/segment_tree.cpp
    title: lib/structure/segment_tree.cpp
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
  bundledCode: "#line 1 \"test/structure/segment_tree/rsq.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B\"\n\n#line\
    \ 1 \"lib/template.cpp\"\n\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \n#define REP(i,n) for (int i=0; i<(n); ++i)\n#define ALL(x) begin(x),end(x)\n\
    #define DUMP(x) cerr<<#x<<\" = \"<<(x)<<endl\n\nstruct fast_ios {\n    fast_ios()\
    \ {\n        std::cin.tie(nullptr);\n        ios::sync_with_stdio(false);\n  \
    \      cout << fixed << setprecision(20);\n    };\n} fast_ios_;\n\nusing ll =\
    \ long long;\n\ntemplate<class T>\nbool chmin(T &a, T b) {\n    if (a > b) { a\
    \ = b; return true; }\n    return false;\n}\ntemplate<class T>\nbool chmax(T &a,\
    \ T b) {\n    if (a < b) { a = b; return true; }\n    return false;\n}\n\ntemplate<class\
    \ T>\nostream &operator<<(ostream &os, const vector<T> &v);\ntemplate<class T,\
    \ class U>\nostream &operator<<(ostream &os, const pair<T, U> &p);\ntemplate<class\
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
    \ cost(cost) {}\n};\n\n\n#line 2 \"lib/structure/segment_tree.cpp\"\n\ntemplate<typename\
    \ M>\nstruct SegmentTree {\n    int n, sz;\n    vector<M> data;\n    const function<M(M,M)>\
    \ f;\n    const M e;\n\n    SegmentTree(\n            int n,\n            const\
    \ function<M(M,M)>& f,\n            const M& e\n            ) : n(n), f(f), e(e)\
    \ {\n        sz = 1;\n        while (sz < n) sz <<= 1;\n        data.assign(2*sz,\
    \ e);\n    }\n\n    void build(const vector<M>& v) {\n        assert(v.size()\
    \ <= n);\n        for (int i = 0; i < v.size(); ++i) {\n            data[i + sz]\
    \ = v[i];\n        }\n        for (int i = sz-1; i > 0; --i) {\n            data[i]\
    \ = f(data[2*i], data[2*i+1]);\n        }\n    }\n\n    template<typename UpdateQuery>\n\
    \    void update(int k, const UpdateQuery& q) {\n        k += sz;\n        data[k]\
    \ = q(data[k]);\n        while (k >>= 1) {\n            data[k] = f(data[2*k],\
    \ data[2*k+1]);\n        }\n    }\n\n    M _query(int a, int b, int k, int l,\
    \ int r) const {\n        if (r <= a or b <= l) return e;\n        if (a <= l\
    \ and r <= b) return data[k];\n        return f(_query(a,b,2*k,  l,(l+r)/2),\n\
    \                 _query(a,b,2*k+1,(l+r)/2,r));\n    }\n\n    M query(int a, int\
    \ b) const {\n        // return f[a,b)\n        return _query(a, b, 1, 0, sz);\n\
    \    }\n\n    M operator[](int i) const {\n        return data.at(i + sz);\n \
    \   }\n\n    friend ostream& operator<<(ostream& os, const SegmentTree& s) {\n\
    \        os << \"[\";\n        for (int i = 0; i < s.n; ++i) {\n            if\
    \ (i) os << \" \";\n            os << s[i];\n        }\n        return os << \"\
    ]\";\n    }\n};\n#line 4 \"test/structure/segment_tree/rsq.test.cpp\"\n\nint main()\
    \ {\n    int N, Q;\n    cin >> N >> Q;\n    SegmentTree<int> tr(\n           \
    \ N, [](int a,int b){ return a+b; }, 0);\n    while (Q--) {\n        int T, X,\
    \ Y;\n        cin >> T >> X >> Y;\n        if (T == 0) tr.update(X-1, [&](int\
    \ a){ return a+Y; });\n        else cout << tr.query(X-1, Y) << endl;\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B\"\
    \n\n#include \"../../../lib/structure/segment_tree.cpp\"\n\nint main() {\n   \
    \ int N, Q;\n    cin >> N >> Q;\n    SegmentTree<int> tr(\n            N, [](int\
    \ a,int b){ return a+b; }, 0);\n    while (Q--) {\n        int T, X, Y;\n    \
    \    cin >> T >> X >> Y;\n        if (T == 0) tr.update(X-1, [&](int a){ return\
    \ a+Y; });\n        else cout << tr.query(X-1, Y) << endl;\n    }\n}\n"
  dependsOn:
  - lib/structure/segment_tree.cpp
  - lib/template.cpp
  isVerificationFile: true
  path: test/structure/segment_tree/rsq.test.cpp
  requiredBy: []
  timestamp: '2021-02-25 17:59:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/structure/segment_tree/rsq.test.cpp
layout: document
redirect_from:
- /verify/test/structure/segment_tree/rsq.test.cpp
- /verify/test/structure/segment_tree/rsq.test.cpp.html
title: test/structure/segment_tree/rsq.test.cpp
---
