---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/re_rooting/re_rooting.test.cpp
    title: test/graph/re_rooting/re_rooting.test.cpp
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
    \ 1e-9;\n// }}}\n\n\n#line 2 \"lib/graph/re_rooting.cpp\"\n\ntemplate<typename\
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
  path: lib/graph/re_rooting.cpp
  requiredBy: []
  timestamp: '2020-04-20 20:05:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/re_rooting/re_rooting.test.cpp
documentation_of: lib/graph/re_rooting.cpp
layout: document
redirect_from:
- /library/lib/graph/re_rooting.cpp
- /library/lib/graph/re_rooting.cpp.html
title: lib/graph/re_rooting.cpp
---
