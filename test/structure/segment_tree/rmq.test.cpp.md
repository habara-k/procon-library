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
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
  bundledCode: "#line 1 \"test/structure/segment_tree/rmq.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A\"\n\n#line\
    \ 1 \"lib/template.cpp\"\n\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \n// type {{{\nusing ll = long long;\nusing ull = unsigned long long;\nusing ld\
    \ = long double;\nusing P = pair<int,int>;\nusing vi = vector<int>;\nusing vll\
    \ = vector<ll>;\nusing vvi = vector<vector<int>>;\nusing vvll = vector<vector<ll>>;\n\
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
    \ 1e-9;\n// }}}\n\n\n#line 2 \"lib/structure/segment_tree.cpp\"\n\ntemplate<typename\
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
    ]\";\n    }\n};\n#line 4 \"test/structure/segment_tree/rmq.test.cpp\"\n\nint main()\
    \ {\n    int N, Q;\n    cin >> N >> Q;\n    SegmentTree<int> tr(\n           \
    \ N,\n            [&](int a, int b){ return min(a, b); },\n            numeric_limits<int>::max());\n\
    \    while (Q--) {\n        int T, X, Y;\n        cin >> T >> X >> Y;\n      \
    \  if (T == 0) tr.update(X, [&](int x){ return Y; });\n        else printf(\"\
    %d\\n\", tr.query(X, Y + 1));\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A\"\
    \n\n#include \"../../../lib/structure/segment_tree.cpp\"\n\nint main() {\n   \
    \ int N, Q;\n    cin >> N >> Q;\n    SegmentTree<int> tr(\n            N,\n  \
    \          [&](int a, int b){ return min(a, b); },\n            numeric_limits<int>::max());\n\
    \    while (Q--) {\n        int T, X, Y;\n        cin >> T >> X >> Y;\n      \
    \  if (T == 0) tr.update(X, [&](int x){ return Y; });\n        else printf(\"\
    %d\\n\", tr.query(X, Y + 1));\n    }\n}\n"
  dependsOn:
  - lib/structure/segment_tree.cpp
  - lib/template.cpp
  isVerificationFile: true
  path: test/structure/segment_tree/rmq.test.cpp
  requiredBy: []
  timestamp: '2020-07-19 03:06:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/structure/segment_tree/rmq.test.cpp
layout: document
redirect_from:
- /verify/test/structure/segment_tree/rmq.test.cpp
- /verify/test/structure/segment_tree/rmq.test.cpp.html
title: test/structure/segment_tree/rmq.test.cpp
---
