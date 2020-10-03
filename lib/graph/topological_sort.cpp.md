---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
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
    \ 1e-9;\n// }}}\n\n\n#line 2 \"lib/graph/topological_sort.cpp\"\n\nvector<int>\
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
  timestamp: '2020-04-20 20:05:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/graph/topological_sort.cpp
layout: document
redirect_from:
- /library/lib/graph/topological_sort.cpp
- /library/lib/graph/topological_sort.cpp.html
title: lib/graph/topological_sort.cpp
---
