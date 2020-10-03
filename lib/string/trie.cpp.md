---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lib/string/aho_corasick.cpp
    title: lib/string/aho_corasick.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/string/aho_corasick/aho_corasick.test.cpp
    title: test/string/aho_corasick/aho_corasick.test.cpp
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
    \ 1e-9;\n// }}}\n\n\n#line 2 \"lib/string/trie.cpp\"\n\ntemplate<int char_size,\
    \ int margin>\nstruct Trie {\n    struct Node {\n        vector<int> next, accept;\n\
    \        Node() : next(char_size, -1) {}\n    };\n\n    vector<Node> nodes;\n\
    \    int root;\n    Trie() : root(0) { nodes.push_back(Node()); }\n\n    inline\
    \ Node operator[](int k) const { return nodes[k]; }\n    inline Node& operator[](int\
    \ k) { return nodes[k]; }\n\n    void add(const string& s, int id = 0) {\n   \
    \     int now = root;\n        for (char c : s) {\n            if (nodes[now].next[c\
    \ - margin] == -1) {\n                nodes[now].next[c - margin] = nodes.size();\n\
    \                nodes.push_back(Node());\n            }\n            now = nodes[now].next[c\
    \ - margin];\n        }\n        nodes[now].accept.push_back(id);\n    }\n\n \
    \   friend ostream& operator<<(ostream& os, const Trie& trie) {\n        function<void(int)>\
    \ dfs = [&](int now) {\n            os << \"{\";\n            bool a = 0;\n  \
    \          for (int i = 0; i < char_size; ++i) {\n                int nxt = trie[now].next[i];\n\
    \                if (nxt != -1) {\n                    if (a) os << \", \"; a\
    \ = 1;\n                    os << (char)(i + margin) << \": \";\n            \
    \        dfs(nxt);\n                }\n            }\n            os << \"}\"\
    ;\n        };\n        dfs(trie.root);\n        return os;\n    }\n\n};\n"
  code: "#include \"../template.cpp\"\n\ntemplate<int char_size, int margin>\nstruct\
    \ Trie {\n    struct Node {\n        vector<int> next, accept;\n        Node()\
    \ : next(char_size, -1) {}\n    };\n\n    vector<Node> nodes;\n    int root;\n\
    \    Trie() : root(0) { nodes.push_back(Node()); }\n\n    inline Node operator[](int\
    \ k) const { return nodes[k]; }\n    inline Node& operator[](int k) { return nodes[k];\
    \ }\n\n    void add(const string& s, int id = 0) {\n        int now = root;\n\
    \        for (char c : s) {\n            if (nodes[now].next[c - margin] == -1)\
    \ {\n                nodes[now].next[c - margin] = nodes.size();\n           \
    \     nodes.push_back(Node());\n            }\n            now = nodes[now].next[c\
    \ - margin];\n        }\n        nodes[now].accept.push_back(id);\n    }\n\n \
    \   friend ostream& operator<<(ostream& os, const Trie& trie) {\n        function<void(int)>\
    \ dfs = [&](int now) {\n            os << \"{\";\n            bool a = 0;\n  \
    \          for (int i = 0; i < char_size; ++i) {\n                int nxt = trie[now].next[i];\n\
    \                if (nxt != -1) {\n                    if (a) os << \", \"; a\
    \ = 1;\n                    os << (char)(i + margin) << \": \";\n            \
    \        dfs(nxt);\n                }\n            }\n            os << \"}\"\
    ;\n        };\n        dfs(trie.root);\n        return os;\n    }\n\n};\n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/string/trie.cpp
  requiredBy:
  - lib/string/aho_corasick.cpp
  timestamp: '2020-04-20 18:48:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/string/aho_corasick/aho_corasick.test.cpp
documentation_of: lib/string/trie.cpp
layout: document
redirect_from:
- /library/lib/string/trie.cpp
- /library/lib/string/trie.cpp.html
title: lib/string/trie.cpp
---
