---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/lowest_common_ancestor.cpp
    title: lib/graph/lowest_common_ancestor.cpp
  - icon: ':heavy_check_mark:'
    path: lib/structure/persistent_segment_tree.cpp
    title: lib/structure/persistent_segment_tree.cpp
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2270
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2270
  bundledCode: "#line 1 \"test/structure/persistent_segment_tree/persistent_segment_tree.test.cpp\"\
    \n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2270\"\
    \n\n#line 1 \"lib/template.cpp\"\n\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n// type {{{\nusing ll = long long;\nusing ull = unsigned long long;\n\
    using ld = long double;\nusing P = pair<int,int>;\nusing vi = vector<int>;\nusing\
    \ vll = vector<ll>;\nusing vvi = vector<vector<int>>;\nusing vvll = vector<vector<ll>>;\n\
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
    \ 1e-9;\n// }}}\n\n\n#line 2 \"lib/structure/persistent_segment_tree.cpp\"\n\n\
    template<typename M>\nstruct PersistentSegmentTree {\n    struct Node {\n    \
    \    Node *l, *r;\n        M data;\n        Node() : l(nullptr), r(nullptr) {}\n\
    \    };\n\n    const function<M(M,M)> f;\n    const M e;\n    const int sz;\n\n\
    \    PersistentSegmentTree(const function<M(M,M)>& f, const M& e, int sz) :\n\
    \        f(f), e(e), sz(sz) {}\n\n    Node* _new(const M& data) const {\n    \
    \    auto t = new Node();\n        t->data = data;\n        return t;\n    }\n\
    \n    Node* _new(Node* l, Node* r) const {\n        auto t = new Node();\n   \
    \     t->l = l, t->r = r, t->data = f(l->data, r->data);\n        return t;\n\
    \    }\n\n    Node* _build(int l, int r) const {\n        assert(l < r);\n   \
    \     if (l+1 == r) return _new(e);\n        return _new(_build(l, (l+r)>>1),\
    \ _build((l+r)>>1, r));\n    }\n\n    Node* build() const {\n        return _build(0,\
    \ sz);\n    }\n\n    template<typename UpdateQuery>\n    Node* _update(Node* t,\
    \ const UpdateQuery& q, int pos, int l, int r) const {\n        if (pos == l and\
    \ pos+1 == r) return _new(q(t->data));\n        if (r <= pos or pos < l) return\
    \ t;\n        return _new(_update(t->l, q, pos, l, (l+r)>>1),\n              \
    \      _update(t->r, q, pos, (l+r)>>1, r));\n    }\n\n    template<typename UpdateQuery>\n\
    \    Node* update(Node* root, int pos, const UpdateQuery& q) const {\n       \
    \ return _update(root, q, pos, 0, sz);\n    }\n\n    M _query(Node* t, int a,\
    \ int b, int l, int r) const {\n        if (r <= a or b <= l) return e;\n    \
    \    if (a <= l and r <= b) return t->data;\n        return f(_query(t->l, a,\
    \ b, l, (l+r)>>1),\n                 _query(t->r, a, b, (l+r)>>1, r));\n    }\n\
    \n    M query(Node* root, int a, int b) const {\n        // return f[a,b)\n  \
    \      return _query(root, a, b, 0, sz);\n    }\n\n};\n#line 2 \"lib/graph/lowest_common_ancestor.cpp\"\
    \n\nstruct LCA {\n    int n, log2_n;\n    vector<int> depth;\n    vector<vector<int>>\
    \ par;\n\n    void dfs(const vector<vector<int>>& G, int v, int p, int d) {\n\
    \        depth[v] = d;\n        par[0][v] = p;\n        for (auto to : G[v]) {\n\
    \            if (to != p) dfs(G, to, v, d+1);\n        }\n    }\n\n    LCA(const\
    \ vector<vector<int>>& G, int root=0) :\n            n(G.size()), log2_n(log2(n)),\
    \ depth(n),\n            par(log2_n+1, vector<int>(n,-1)) {\n\n        dfs(G,\
    \ root, -1, 0);\n        for (int k = 0; k < log2_n; ++k) {\n            for (int\
    \ v = 0; v < n; ++v) {\n                if (par[k][v] != -1) {\n             \
    \       par[k+1][v] = par[k][par[k][v]];\n                }\n            }\n \
    \       }\n    }\n\n    int query(int u, int v) const {\n        if (depth[u]\
    \ > depth[v]) swap(u, v);\n\n        // align the depth of u and v\n        for\
    \ (int k = 0; k <= log2_n; ++k) {\n            if ((depth[v] - depth[u]) >> k\
    \ & 1) {\n                v = par[k][v];\n            }\n        }\n        if\
    \ (u == v) return u;\n\n        // go back until u and v's parents do not match\n\
    \        for (int k = log2_n; k >= 0; --k) {\n            if (par[k][u] != par[k][v])\
    \ {\n                u = par[k][u];\n                v = par[k][v];\n        \
    \    }\n        }\n        return par[0][u];\n    }\n};\n#line 5 \"test/structure/persistent_segment_tree/persistent_segment_tree.test.cpp\"\
    \n\nint main()\n{\n    int N, Q;\n    cin >> N >> Q;\n    vector<int> x(N);\n\
    \    for (int i = 0; i < N; ++i) {\n        cin >> x[i];\n    }\n\n    vector<vector<int>>\
    \ G(N);\n    for (int i = 0; i < N-1; ++i) {\n        int a, b; cin >> a >> b;\n\
    \        --a, --b;\n        G[a].push_back(b);\n        G[b].push_back(a);\n \
    \   }\n\n    // compress\n    map<int,int> comp, comp_inv;\n    for (auto X :\
    \ x) comp[X] = -1;\n    int comp_size = 0;\n    for (auto &p : comp) {\n     \
    \   p.second = comp_size++;\n    }\n    for (auto p : comp) {\n        comp_inv[p.second]\
    \ = p.first;\n    }\n\n    // lca\n    auto lca = LCA(G);\n\n    // persistent\
    \ segtree\n    PersistentSegmentTree<int> segt(\n            [](int a,int b){\
    \ return a+b; },\n            0, comp.size());\n\n    map<int,PersistentSegmentTree<int>::Node*>\
    \ root;\n    vector<int> par(N);\n\n    function<void(int,int)> dfs = [&](int\
    \ v, int p) {\n        par[v] = p;\n        root[v] = segt.update(root[p],\n \
    \               comp[x[v]], [](int a){ return a+1; });\n        for (int u : G[v])\
    \ {\n            if (u != p) dfs(u, v);\n        }\n    };\n\n    root[-1] = segt.build();\n\
    \    dfs(0, -1);\n\n    for (int i = 0; i < Q; ++i)\n    {\n        int v, w,\
    \ l; cin >> v >> w >> l; --v, --w;\n\n        // search x s.t. there are more\
    \ than l numbers less than or equal to x\n\n        int u = lca.query(v, w);\n\
    \n        auto check = [&](int m) {\n            int nv = segt.query(root[v],\
    \ 0, m+1),\n                nw = segt.query(root[w], 0, m+1),\n              \
    \  nu = segt.query(root[u], 0, m+1),\n                np = segt.query(root[par[u]],\
    \ 0, m+1);\n\n            return nv + nw - nu - np >= l;\n        };\n\n     \
    \   int ng = -1, ok = comp.size()-1;\n        while (abs(ok - ng) > 1) {\n   \
    \         int mid = (ng + ok) / 2;\n            (check(mid) ? ok : ng) = mid;\n\
    \        }\n\n        cout << comp_inv[ok] << endl;\n    }\n\n    return 0;\n\
    }\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2270\"\
    \n\n#include \"../../../lib/structure/persistent_segment_tree.cpp\"\n#include\
    \ \"../../../lib/graph/lowest_common_ancestor.cpp\"\n\nint main()\n{\n    int\
    \ N, Q;\n    cin >> N >> Q;\n    vector<int> x(N);\n    for (int i = 0; i < N;\
    \ ++i) {\n        cin >> x[i];\n    }\n\n    vector<vector<int>> G(N);\n    for\
    \ (int i = 0; i < N-1; ++i) {\n        int a, b; cin >> a >> b;\n        --a,\
    \ --b;\n        G[a].push_back(b);\n        G[b].push_back(a);\n    }\n\n    //\
    \ compress\n    map<int,int> comp, comp_inv;\n    for (auto X : x) comp[X] = -1;\n\
    \    int comp_size = 0;\n    for (auto &p : comp) {\n        p.second = comp_size++;\n\
    \    }\n    for (auto p : comp) {\n        comp_inv[p.second] = p.first;\n   \
    \ }\n\n    // lca\n    auto lca = LCA(G);\n\n    // persistent segtree\n    PersistentSegmentTree<int>\
    \ segt(\n            [](int a,int b){ return a+b; },\n            0, comp.size());\n\
    \n    map<int,PersistentSegmentTree<int>::Node*> root;\n    vector<int> par(N);\n\
    \n    function<void(int,int)> dfs = [&](int v, int p) {\n        par[v] = p;\n\
    \        root[v] = segt.update(root[p],\n                comp[x[v]], [](int a){\
    \ return a+1; });\n        for (int u : G[v]) {\n            if (u != p) dfs(u,\
    \ v);\n        }\n    };\n\n    root[-1] = segt.build();\n    dfs(0, -1);\n\n\
    \    for (int i = 0; i < Q; ++i)\n    {\n        int v, w, l; cin >> v >> w >>\
    \ l; --v, --w;\n\n        // search x s.t. there are more than l numbers less\
    \ than or equal to x\n\n        int u = lca.query(v, w);\n\n        auto check\
    \ = [&](int m) {\n            int nv = segt.query(root[v], 0, m+1),\n        \
    \        nw = segt.query(root[w], 0, m+1),\n                nu = segt.query(root[u],\
    \ 0, m+1),\n                np = segt.query(root[par[u]], 0, m+1);\n\n       \
    \     return nv + nw - nu - np >= l;\n        };\n\n        int ng = -1, ok =\
    \ comp.size()-1;\n        while (abs(ok - ng) > 1) {\n            int mid = (ng\
    \ + ok) / 2;\n            (check(mid) ? ok : ng) = mid;\n        }\n\n       \
    \ cout << comp_inv[ok] << endl;\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - lib/structure/persistent_segment_tree.cpp
  - lib/template.cpp
  - lib/graph/lowest_common_ancestor.cpp
  - lib/template.cpp
  isVerificationFile: true
  path: test/structure/persistent_segment_tree/persistent_segment_tree.test.cpp
  requiredBy: []
  timestamp: '2020-05-22 14:57:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/structure/persistent_segment_tree/persistent_segment_tree.test.cpp
layout: document
redirect_from:
- /verify/test/structure/persistent_segment_tree/persistent_segment_tree.test.cpp
- /verify/test/structure/persistent_segment_tree/persistent_segment_tree.test.cpp.html
title: test/structure/persistent_segment_tree/persistent_segment_tree.test.cpp
---
