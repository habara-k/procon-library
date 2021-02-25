---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/string/aho_corasick.cpp
    title: lib/string/aho_corasick.cpp
  - icon: ':heavy_check_mark:'
    path: lib/string/trie.cpp
    title: lib/string/trie.cpp
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2212
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2212
  bundledCode: "#line 1 \"test/string/aho_corasick/aho_corasick.test.cpp\"\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2212\"\n\n\
    #line 1 \"lib/template.cpp\"\n\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
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
    ;\n        };\n        dfs(trie.root);\n        return os;\n    }\n\n};\n#line\
    \ 2 \"lib/string/aho_corasick.cpp\"\n\ntemplate<int char_size, int margin>\nstruct\
    \ AhoCorasick {\n    Trie<char_size + 1, margin> trie;\n    const int FAIL = char_size;\n\
    \n    AhoCorasick() : trie() {}\n\n    using Node = typename Trie<char_size +\
    \ 1, margin>::Node;\n\n    inline Node operator[](int k) const { return trie[k];\
    \ }\n    inline Node& operator[](int k) { return trie[k]; }\n\n    void add(const\
    \ string& s, int id = 0) {\n        trie.add(s, id);\n    }\n\n    void build()\
    \ {\n        queue<int> que;\n        for (int i = 0; i < char_size; ++i) {\n\
    \            if (trie[trie.root].next[i] == -1) {\n                trie[trie.root].next[i]\
    \ = trie.root;\n            } else {\n                que.push(trie[trie.root].next[i]);\n\
    \                trie[trie[trie.root].next[i]].next[FAIL] = trie.root;\n     \
    \       }\n        }\n        while (!que.empty()) {\n            int now = que.front();\
    \ que.pop();\n            for (int i = 0; i < char_size; ++i) {\n            \
    \    if (trie[now].next[i] == -1) continue;\n                int fail = trie[now].next[FAIL];\n\
    \                while (trie[fail].next[i] == -1) {\n                    fail\
    \ = trie[fail].next[FAIL];\n                }\n                trie[trie[now].next[i]].next[FAIL]\
    \ = trie[fail].next[i];\n                auto &u = trie[trie[now].next[i]].accept;\n\
    \                auto &v = trie[trie[fail].next[i]].accept;\n                vector<int>\
    \ accept;\n                set_union(u.begin(), u.end(), v.begin(), v.end(),\n\
    \                        back_inserter(accept));\n                u = accept;\n\
    \                que.push(trie[now].next[i]);\n            }\n        }\n    }\n\
    \n    map<int,int> match(const string& str) const {\n        map<int,int> ret;\n\
    \        int now = trie.root;\n        for (char c : str) {\n            while\
    \ (trie[now].next[c - margin] == -1) now = trie[now].next[FAIL];\n           \
    \ now = trie[now].next[c - margin];\n            for (int id : trie[now].accept)\
    \ ++ret[id];\n        }\n        return ret;\n    }\n\n    friend ostream& operator<<(ostream&\
    \ os, const AhoCorasick& aho) {\n        const int n = aho.trie.nodes.size();\n\
    \        vector<bool> used(n);\n        function<void(int)> dfs = [&](int now)\
    \ {\n            used[now] = true;\n            os << \"{\" << now << \" \" <<\
    \ \"#:\" << aho[now].next[aho.FAIL];\n            for (int i = 0; i < char_size;\
    \ ++i) {\n                int nxt = aho[now].next[i];\n                if (nxt\
    \ != -1) {\n                    os << \", \" << (char)(i + margin) << \":\";\n\
    \                    if (!used[nxt]) dfs(nxt);\n                    else os <<\
    \ nxt;\n                }\n            }\n\n            os << \"}\";\n       \
    \ };\n        dfs(aho.trie.root);\n        return os;\n    }\n};\n#line 4 \"test/string/aho_corasick/aho_corasick.test.cpp\"\
    \n\nint main() {\n    map<char,int> dy, dx;\n    dy['U'] = -1, dy['R'] = 0, dy['D']\
    \ = 1, dy['L'] = 0;\n    dx['U'] = 0, dx['R'] = 1, dx['D'] = 0, dx['L'] = -1;\n\
    \n    while (true) {\n        int n, m; cin >> n >> m;\n        if (n == 0) break;\n\
    \        vector<string> board(n);\n        int si, sj;\n        for (int i = 0;\
    \ i < n; ++i) {\n            cin >> board[i];\n            for (int j = 0; j <\
    \ m; ++j) {\n                if (board[i][j] == 'S') {\n                    si\
    \ = i, sj = j;\n                }\n            }\n        }\n\n        AhoCorasick<26,'A'>\
    \ aho;\n        int P; cin >> P;\n        for (int i = 0; i < P; ++i) {\n    \
    \        string p; cin >> p;\n            aho.add(p, i);\n        }\n        aho.build();\n\
    \n        using Node = int;\n\n        queue<tuple<int,int,int,Node>> que;\n \
    \       que.emplace(si, sj, 0, aho.trie.root);\n        map<tuple<int,int,Node>,bool>\
    \ used;\n        used[make_tuple(si, sj, aho.trie.root)] = true;\n\n        int\
    \ ans = -1;\n\n        while (!que.empty()) {\n            int i, j, d; Node now;\n\
    \            tie(i, j, d, now) = que.front(); que.pop();\n            if (board[i][j]\
    \ == 'G') {\n                ans = d;\n                break;\n            }\n\
    \            for (char dir : { 'U', 'R', 'D', 'L' }) {\n                Node tmp\
    \ = now;\n                int y = i + dy[dir], x = j + dx[dir];\n            \
    \    if (y < 0 or n <= y or x < 0 or m <= x or\n                        board[y][x]\
    \ == '#') continue;\n\n                while (aho[tmp].next[dir - 'A'] == -1)\
    \ {\n                    tmp = aho[tmp].next[aho.FAIL];\n                }\n \
    \               tmp = aho[tmp].next[dir - 'A'];\n                if (aho[tmp].accept.size())\
    \ {\n                    continue;\n                }\n                if (!used[make_tuple(y,\
    \ x, tmp)]) {\n                    used[make_tuple(y, x, tmp)] = true;\n     \
    \               que.emplace(y, x, d + 1, tmp);\n                }\n          \
    \  }\n        }\n\n        cout << ans << endl;\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2212\"\
    \n\n#include \"../../../lib/string/aho_corasick.cpp\"\n\nint main() {\n    map<char,int>\
    \ dy, dx;\n    dy['U'] = -1, dy['R'] = 0, dy['D'] = 1, dy['L'] = 0;\n    dx['U']\
    \ = 0, dx['R'] = 1, dx['D'] = 0, dx['L'] = -1;\n\n    while (true) {\n       \
    \ int n, m; cin >> n >> m;\n        if (n == 0) break;\n        vector<string>\
    \ board(n);\n        int si, sj;\n        for (int i = 0; i < n; ++i) {\n    \
    \        cin >> board[i];\n            for (int j = 0; j < m; ++j) {\n       \
    \         if (board[i][j] == 'S') {\n                    si = i, sj = j;\n   \
    \             }\n            }\n        }\n\n        AhoCorasick<26,'A'> aho;\n\
    \        int P; cin >> P;\n        for (int i = 0; i < P; ++i) {\n           \
    \ string p; cin >> p;\n            aho.add(p, i);\n        }\n        aho.build();\n\
    \n        using Node = int;\n\n        queue<tuple<int,int,int,Node>> que;\n \
    \       que.emplace(si, sj, 0, aho.trie.root);\n        map<tuple<int,int,Node>,bool>\
    \ used;\n        used[make_tuple(si, sj, aho.trie.root)] = true;\n\n        int\
    \ ans = -1;\n\n        while (!que.empty()) {\n            int i, j, d; Node now;\n\
    \            tie(i, j, d, now) = que.front(); que.pop();\n            if (board[i][j]\
    \ == 'G') {\n                ans = d;\n                break;\n            }\n\
    \            for (char dir : { 'U', 'R', 'D', 'L' }) {\n                Node tmp\
    \ = now;\n                int y = i + dy[dir], x = j + dx[dir];\n            \
    \    if (y < 0 or n <= y or x < 0 or m <= x or\n                        board[y][x]\
    \ == '#') continue;\n\n                while (aho[tmp].next[dir - 'A'] == -1)\
    \ {\n                    tmp = aho[tmp].next[aho.FAIL];\n                }\n \
    \               tmp = aho[tmp].next[dir - 'A'];\n                if (aho[tmp].accept.size())\
    \ {\n                    continue;\n                }\n                if (!used[make_tuple(y,\
    \ x, tmp)]) {\n                    used[make_tuple(y, x, tmp)] = true;\n     \
    \               que.emplace(y, x, d + 1, tmp);\n                }\n          \
    \  }\n        }\n\n        cout << ans << endl;\n    }\n    return 0;\n}\n"
  dependsOn:
  - lib/string/aho_corasick.cpp
  - lib/string/trie.cpp
  - lib/template.cpp
  isVerificationFile: true
  path: test/string/aho_corasick/aho_corasick.test.cpp
  requiredBy: []
  timestamp: '2021-02-25 17:59:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/string/aho_corasick/aho_corasick.test.cpp
layout: document
redirect_from:
- /verify/test/string/aho_corasick/aho_corasick.test.cpp
- /verify/test/string/aho_corasick/aho_corasick.test.cpp.html
title: test/string/aho_corasick/aho_corasick.test.cpp
---
