---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/tree/re_rooting/re_rooting.test.cpp
    title: test/tree/re_rooting/re_rooting.test.cpp
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
    \ cost(cost) {}\n};\n\n\n#line 2 \"lib/tree/re_rooting.cpp\"\n\ntemplate<typename\
    \ Data, typename T>\nstruct ReRooting {\n\n    struct edge {\n        int to,\
    \ rev;\n        Data data;\n    };\n\n    using F1 = function<T(T, T)>;\n    using\
    \ F2 = function<T(T, Data)>;\n\n    vector<vector<edge>> g;\n    vector<vector<T>>\
    \ ldp, rdp;\n    vector<int> lptr, rptr;\n    const F1 f1;\n    const F2 f2;\n\
    \    const T init;\n\n    ReRooting(int n, const F1 &f1, const F2 &f2, const T\
    \ &init) :\n        g(n), ldp(n), rdp(n), lptr(n), rptr(n), f1(f1), f2(f2), init(init)\
    \ {}\n\n    void add_edge(int u, int v, const Data &d) {\n        g[u].emplace_back((edge){v,\
    \ (int)g[v].size(), d});\n        g[v].emplace_back((edge){u, (int)g[u].size()-1,\
    \ d});\n    }\n\n    T dfs(int idx, int par) {\n\n        while (lptr[idx] !=\
    \ par and lptr[idx] < g[idx].size()) {\n            auto &e = g[idx][lptr[idx]];\n\
    \            ldp[idx][lptr[idx]+1] = f1(\n                    ldp[idx][lptr[idx]],\n\
    \                    f2(dfs(e.to, e.rev), e.data));\n            ++lptr[idx];\n\
    \        }\n        while (rptr[idx] != par and rptr[idx] >= 0) {\n          \
    \  auto &e = g[idx][rptr[idx]];\n            rdp[idx][rptr[idx]] = f1(\n     \
    \               rdp[idx][rptr[idx]+1],\n                    f2(dfs(e.to, e.rev),\
    \ e.data));\n            --rptr[idx];\n        }\n        if (par < 0) return\
    \ rdp[idx][0];\n        return f1(ldp[idx][par], rdp[idx][par+1]);\n    }\n\n\
    \    vector<T> solve() {\n        for (int i = 0; i < g.size(); ++i) {\n     \
    \       ldp[i].assign(g[i].size()+1, init);\n            rdp[i].assign(g[i].size()+1,\
    \ init);\n            lptr[i] = 0;\n            rptr[i] = (int)g[i].size()-1;\n\
    \        }\n        vector<T> ret(g.size());\n        for (int i = 0; i < g.size();\
    \ ++i) {\n            ret[i] = dfs(i, -1);\n        }\n        return ret;\n \
    \   }\n};\n"
  code: "#include \"../template.cpp\"\n\ntemplate<typename Data, typename T>\nstruct\
    \ ReRooting {\n\n    struct edge {\n        int to, rev;\n        Data data;\n\
    \    };\n\n    using F1 = function<T(T, T)>;\n    using F2 = function<T(T, Data)>;\n\
    \n    vector<vector<edge>> g;\n    vector<vector<T>> ldp, rdp;\n    vector<int>\
    \ lptr, rptr;\n    const F1 f1;\n    const F2 f2;\n    const T init;\n\n    ReRooting(int\
    \ n, const F1 &f1, const F2 &f2, const T &init) :\n        g(n), ldp(n), rdp(n),\
    \ lptr(n), rptr(n), f1(f1), f2(f2), init(init) {}\n\n    void add_edge(int u,\
    \ int v, const Data &d) {\n        g[u].emplace_back((edge){v, (int)g[v].size(),\
    \ d});\n        g[v].emplace_back((edge){u, (int)g[u].size()-1, d});\n    }\n\n\
    \    T dfs(int idx, int par) {\n\n        while (lptr[idx] != par and lptr[idx]\
    \ < g[idx].size()) {\n            auto &e = g[idx][lptr[idx]];\n            ldp[idx][lptr[idx]+1]\
    \ = f1(\n                    ldp[idx][lptr[idx]],\n                    f2(dfs(e.to,\
    \ e.rev), e.data));\n            ++lptr[idx];\n        }\n        while (rptr[idx]\
    \ != par and rptr[idx] >= 0) {\n            auto &e = g[idx][rptr[idx]];\n   \
    \         rdp[idx][rptr[idx]] = f1(\n                    rdp[idx][rptr[idx]+1],\n\
    \                    f2(dfs(e.to, e.rev), e.data));\n            --rptr[idx];\n\
    \        }\n        if (par < 0) return rdp[idx][0];\n        return f1(ldp[idx][par],\
    \ rdp[idx][par+1]);\n    }\n\n    vector<T> solve() {\n        for (int i = 0;\
    \ i < g.size(); ++i) {\n            ldp[i].assign(g[i].size()+1, init);\n    \
    \        rdp[i].assign(g[i].size()+1, init);\n            lptr[i] = 0;\n     \
    \       rptr[i] = (int)g[i].size()-1;\n        }\n        vector<T> ret(g.size());\n\
    \        for (int i = 0; i < g.size(); ++i) {\n            ret[i] = dfs(i, -1);\n\
    \        }\n        return ret;\n    }\n};\n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/tree/re_rooting.cpp
  requiredBy: []
  timestamp: '2021-02-25 17:59:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/tree/re_rooting/re_rooting.test.cpp
documentation_of: lib/tree/re_rooting.cpp
layout: document
redirect_from:
- /library/lib/tree/re_rooting.cpp
- /library/lib/tree/re_rooting.cpp.html
title: lib/tree/re_rooting.cpp
---