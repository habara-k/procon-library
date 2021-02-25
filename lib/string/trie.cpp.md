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
    \ cost(cost) {}\n};\n\n\n#line 2 \"lib/string/trie.cpp\"\n\ntemplate<int char_size,\
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
  timestamp: '2021-02-25 17:59:51+09:00'
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
