---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
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
    \ cost(cost) {}\n};\n\n\n#line 2 \"lib/graph/topological_sort.cpp\"\n\nvector<int>\
    \ topological_sort(const vector<vector<int>>& G)\n{\n    int n = G.size();\n \
    \   vector<int> num(n), ord;\n    for (int i = 0; i < n; ++i) {\n        for (int\
    \ u : G[i]) ++num[u];\n    }\n    stack<int> st;\n    for (int i = 0; i < n; ++i)\
    \ {\n        if (num[i] == 0) st.push(i);\n    }\n    while (!st.empty()) {\n\
    \        int i = st.top(); st.pop();\n        ord.push_back(i);\n        for (int\
    \ u : G[i]) {\n            --num[u];\n            if (num[u] == 0) st.push(u);\n\
    \        }\n    }\n    return ord;\n}\n"
  code: "#include \"../template.cpp\"\n\nvector<int> topological_sort(const vector<vector<int>>&\
    \ G)\n{\n    int n = G.size();\n    vector<int> num(n), ord;\n    for (int i =\
    \ 0; i < n; ++i) {\n        for (int u : G[i]) ++num[u];\n    }\n    stack<int>\
    \ st;\n    for (int i = 0; i < n; ++i) {\n        if (num[i] == 0) st.push(i);\n\
    \    }\n    while (!st.empty()) {\n        int i = st.top(); st.pop();\n     \
    \   ord.push_back(i);\n        for (int u : G[i]) {\n            --num[u];\n \
    \           if (num[u] == 0) st.push(u);\n        }\n    }\n    return ord;\n\
    }\n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/graph/topological_sort.cpp
  requiredBy: []
  timestamp: '2021-02-25 17:59:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/graph/topological_sort.cpp
layout: document
redirect_from:
- /library/lib/graph/topological_sort.cpp
- /library/lib/graph/topological_sort.cpp.html
title: lib/graph/topological_sort.cpp
---
