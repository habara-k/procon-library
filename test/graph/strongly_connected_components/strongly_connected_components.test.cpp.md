---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/strongly_connected_components.cpp
    title: lib/graph/strongly_connected_components.cpp
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_C
  bundledCode: "#line 1 \"test/graph/strongly_connected_components/strongly_connected_components.test.cpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_C\"\
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
    \ 1e-9;\n// }}}\n\n\n#line 2 \"lib/graph/strongly_connected_components.cpp\"\n\
    \nstruct StronglyConnectedComponents {\n    int n;\n    vector<vector<int>> g,\
    \ rg, graph;\n    vector<int> ord, used, comp;\n\n    StronglyConnectedComponents(const\
    \ vector<vector<int>>& g) :\n            n(g.size()), g(g), rg(n), used(n), comp(n,\
    \ -1)\n    {\n        for (int i = 0; i < n; ++i) {\n            for (int to :\
    \ g[i]) {\n                rg[to].push_back(i);\n            }\n        }\n  \
    \  }\n\n    void build() {\n        for (int i = 0; i < n; ++i) dfs(i);\n    \
    \    reverse(ord.begin(), ord.end());\n        int ptr = 0;\n        for (int\
    \ i : ord) if (comp[i] == -1) rdfs(i, ptr), ptr++;\n\n        graph.resize(ptr);\n\
    \        for (int i = 0; i < n; ++i) {\n            for (int to : g[i]) {\n  \
    \              int x = comp[i], y = comp[to];\n                if (x == y) continue;\n\
    \                graph[x].push_back(y);\n            }\n        }\n        for\
    \ (auto& v : graph) {\n            sort(v.begin(), v.end());\n            v.erase(unique(v.begin(),\
    \ v.end()), v.end());\n        }\n    }\n\nprivate:\n    void dfs(int idx) {\n\
    \        if (used[idx]) return;\n        used[idx] = true;\n        for (int to\
    \ : g[idx]) dfs(to);\n        ord.push_back(idx);\n    }\n\n    void rdfs(int\
    \ idx, int cnt) {\n        if (comp[idx] != -1) return;\n        comp[idx] = cnt;\n\
    \        for (int to : rg[idx]) rdfs(to, cnt);\n    }\n};\n\n#line 4 \"test/graph/strongly_connected_components/strongly_connected_components.test.cpp\"\
    \n\nint main() {\n    int V, E, Q;\n    cin >> V >> E;\n    vector<vector<int>>\
    \ G(V);\n    for (int i = 0; i < E; ++i) {\n        int a, b; cin >> a >> b;\n\
    \        G[a].push_back(b);\n    }\n\n    StronglyConnectedComponents scc(G);\n\
    \    scc.build();\n\n    cin >> Q;\n    while (Q--) {\n        int a, b;\n   \
    \     cin >> a >> b;\n        cout << (scc.comp[a] == scc.comp[b] ? \"1\" : \"\
    0\") << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_C\"\
    \n\n#include \"../../../lib/graph/strongly_connected_components.cpp\"\n\nint main()\
    \ {\n    int V, E, Q;\n    cin >> V >> E;\n    vector<vector<int>> G(V);\n   \
    \ for (int i = 0; i < E; ++i) {\n        int a, b; cin >> a >> b;\n        G[a].push_back(b);\n\
    \    }\n\n    StronglyConnectedComponents scc(G);\n    scc.build();\n\n    cin\
    \ >> Q;\n    while (Q--) {\n        int a, b;\n        cin >> a >> b;\n      \
    \  cout << (scc.comp[a] == scc.comp[b] ? \"1\" : \"0\") << endl;\n    }\n}\n"
  dependsOn:
  - lib/graph/strongly_connected_components.cpp
  - lib/template.cpp
  isVerificationFile: true
  path: test/graph/strongly_connected_components/strongly_connected_components.test.cpp
  requiredBy: []
  timestamp: '2020-05-23 16:27:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/strongly_connected_components/strongly_connected_components.test.cpp
layout: document
redirect_from:
- /verify/test/graph/strongly_connected_components/strongly_connected_components.test.cpp
- /verify/test/graph/strongly_connected_components/strongly_connected_components.test.cpp.html
title: test/graph/strongly_connected_components/strongly_connected_components.test.cpp
---
