---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../assets/css/copy-button.css" />


# :heavy_check_mark: test/string/aho_corasick/aho_corasick.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#0af9586de21ee7fea49aa629a8bd3e9a">test/string/aho_corasick</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/string/aho_corasick/aho_corasick.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-20 18:48:42+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2212">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2212</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/lib/string/aho_corasick.cpp.html">lib/string/aho_corasick.cpp</a>
* :heavy_check_mark: <a href="../../../../library/lib/string/trie.cpp.html">lib/string/trie.cpp</a>
* :heavy_check_mark: <a href="../../../../library/lib/template.cpp.html">lib/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2212"

#include "../../../lib/string/aho_corasick.cpp"

int main() {
    map<char,int> dy, dx;
    dy['U'] = -1, dy['R'] = 0, dy['D'] = 1, dy['L'] = 0;
    dx['U'] = 0, dx['R'] = 1, dx['D'] = 0, dx['L'] = -1;

    while (true) {
        int n, m; cin >> n >> m;
        if (n == 0) break;
        vector<string> board(n);
        int si, sj;
        for (int i = 0; i < n; ++i) {
            cin >> board[i];
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 'S') {
                    si = i, sj = j;
                }
            }
        }

        AhoCorasick<26,'A'> aho;
        int P; cin >> P;
        for (int i = 0; i < P; ++i) {
            string p; cin >> p;
            aho.add(p, i);
        }
        aho.build();

        using Node = int;

        queue<tuple<int,int,int,Node>> que;
        que.emplace(si, sj, 0, aho.trie.root);
        map<tuple<int,int,Node>,bool> used;
        used[make_tuple(si, sj, aho.trie.root)] = true;

        int ans = -1;

        while (!que.empty()) {
            int i, j, d; Node now;
            tie(i, j, d, now) = que.front(); que.pop();
            if (board[i][j] == 'G') {
                ans = d;
                break;
            }
            for (char dir : { 'U', 'R', 'D', 'L' }) {
                Node tmp = now;
                int y = i + dy[dir], x = j + dx[dir];
                if (y < 0 or n <= y or x < 0 or m <= x or
                        board[y][x] == '#') continue;

                while (aho[tmp].next[dir - 'A'] == -1) {
                    tmp = aho[tmp].next[aho.FAIL];
                }
                tmp = aho[tmp].next[dir - 'A'];
                if (aho[tmp].accept.size()) {
                    continue;
                }
                if (!used[make_tuple(y, x, tmp)]) {
                    used[make_tuple(y, x, tmp)] = true;
                    que.emplace(y, x, d + 1, tmp);
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/string/aho_corasick/aho_corasick.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2212"

#line 1 "lib/template.cpp"


#include <bits/stdc++.h>
using namespace std;

// type {{{
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using P = pair<int,int>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
// }}}


// macro {{{
#define REP(i,n) for (int i=0; i<(n); ++i)
#define RREP(i,n) for (int i=(int)(n)-1; i>=0; --i)
#define FOR(i,a,n) for (int i=(a); i<(n); ++i)
#define RFOR(i,a,n) for (int i=(int)(n)-1; i>=(a); --i)

#define SZ(x) ((int)(x).size())
#define all(x) begin(x),end(x)
// }}}


// debug {{{
#define dump(x) cerr<<#x<<" = "<<(x)<<endl
#define debug(x) cerr<<#x<<" = "<<(x)<<" (L"<<__LINE__<<")"<< endl;

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "[";
    REP (i, SZ(v)) {
        if (i) os << ", ";
        os << v[i];
    }
    return os << "]";
}

template<typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    return os << "(" << p.first << " " << p.second << ")";
}
// }}}


// chmax, chmin {{{
template<class T>
bool chmax(T& a, const T& b) {
    if (a < b) { a = b; return true; }
    return false;
}
template<class T>
bool chmin(T& a, const T& b) {
    if (b < a) { a = b; return true; }
    return false;
}
// }}}


// constants {{{
#define inf(T) (numeric_limits<T>::max() / 2)
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
// }}}


#line 2 "lib/string/trie.cpp"

template<int char_size, int margin>
struct Trie {
    struct Node {
        vector<int> next, accept;
        Node() : next(char_size, -1) {}
    };

    vector<Node> nodes;
    int root;
    Trie() : root(0) { nodes.push_back(Node()); }

    inline Node operator[](int k) const { return nodes[k]; }
    inline Node& operator[](int k) { return nodes[k]; }

    void add(const string& s, int id = 0) {
        int now = root;
        for (char c : s) {
            if (nodes[now].next[c - margin] == -1) {
                nodes[now].next[c - margin] = nodes.size();
                nodes.push_back(Node());
            }
            now = nodes[now].next[c - margin];
        }
        nodes[now].accept.push_back(id);
    }

    friend ostream& operator<<(ostream& os, const Trie& trie) {
        function<void(int)> dfs = [&](int now) {
            os << "{";
            bool a = 0;
            for (int i = 0; i < char_size; ++i) {
                int nxt = trie[now].next[i];
                if (nxt != -1) {
                    if (a) os << ", "; a = 1;
                    os << (char)(i + margin) << ": ";
                    dfs(nxt);
                }
            }
            os << "}";
        };
        dfs(trie.root);
        return os;
    }

};
#line 2 "lib/string/aho_corasick.cpp"

template<int char_size, int margin>
struct AhoCorasick {
    Trie<char_size + 1, margin> trie;
    const int FAIL = char_size;

    AhoCorasick() : trie() {}

    using Node = typename Trie<char_size + 1, margin>::Node;

    inline Node operator[](int k) const { return trie[k]; }
    inline Node& operator[](int k) { return trie[k]; }

    void add(const string& s, int id = 0) {
        trie.add(s, id);
    }

    void build() {
        queue<int> que;
        for (int i = 0; i < char_size; ++i) {
            if (trie[trie.root].next[i] == -1) {
                trie[trie.root].next[i] = trie.root;
            } else {
                que.push(trie[trie.root].next[i]);
                trie[trie[trie.root].next[i]].next[FAIL] = trie.root;
            }
        }
        while (!que.empty()) {
            int now = que.front(); que.pop();
            for (int i = 0; i < char_size; ++i) {
                if (trie[now].next[i] == -1) continue;
                int fail = trie[now].next[FAIL];
                while (trie[fail].next[i] == -1) {
                    fail = trie[fail].next[FAIL];
                }
                trie[trie[now].next[i]].next[FAIL] = trie[fail].next[i];
                auto &u = trie[trie[now].next[i]].accept;
                auto &v = trie[trie[fail].next[i]].accept;
                vector<int> accept;
                set_union(u.begin(), u.end(), v.begin(), v.end(),
                        back_inserter(accept));
                u = accept;
                que.push(trie[now].next[i]);
            }
        }
    }

    map<int,int> match(const string& str) const {
        map<int,int> ret;
        int now = trie.root;
        for (char c : str) {
            while (trie[now].next[c - margin] == -1) now = trie[now].next[FAIL];
            now = trie[now].next[c - margin];
            for (int id : trie[now].accept) ++ret[id];
        }
        return ret;
    }

    friend ostream& operator<<(ostream& os, const AhoCorasick& aho) {
        const int n = aho.trie.nodes.size();
        vector<bool> used(n);
        function<void(int)> dfs = [&](int now) {
            used[now] = true;
            os << "{" << now << " " << "#:" << aho[now].next[aho.FAIL];
            for (int i = 0; i < char_size; ++i) {
                int nxt = aho[now].next[i];
                if (nxt != -1) {
                    os << ", " << (char)(i + margin) << ":";
                    if (!used[nxt]) dfs(nxt);
                    else os << nxt;
                }
            }

            os << "}";
        };
        dfs(aho.trie.root);
        return os;
    }
};
#line 4 "test/string/aho_corasick/aho_corasick.test.cpp"

int main() {
    map<char,int> dy, dx;
    dy['U'] = -1, dy['R'] = 0, dy['D'] = 1, dy['L'] = 0;
    dx['U'] = 0, dx['R'] = 1, dx['D'] = 0, dx['L'] = -1;

    while (true) {
        int n, m; cin >> n >> m;
        if (n == 0) break;
        vector<string> board(n);
        int si, sj;
        for (int i = 0; i < n; ++i) {
            cin >> board[i];
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 'S') {
                    si = i, sj = j;
                }
            }
        }

        AhoCorasick<26,'A'> aho;
        int P; cin >> P;
        for (int i = 0; i < P; ++i) {
            string p; cin >> p;
            aho.add(p, i);
        }
        aho.build();

        using Node = int;

        queue<tuple<int,int,int,Node>> que;
        que.emplace(si, sj, 0, aho.trie.root);
        map<tuple<int,int,Node>,bool> used;
        used[make_tuple(si, sj, aho.trie.root)] = true;

        int ans = -1;

        while (!que.empty()) {
            int i, j, d; Node now;
            tie(i, j, d, now) = que.front(); que.pop();
            if (board[i][j] == 'G') {
                ans = d;
                break;
            }
            for (char dir : { 'U', 'R', 'D', 'L' }) {
                Node tmp = now;
                int y = i + dy[dir], x = j + dx[dir];
                if (y < 0 or n <= y or x < 0 or m <= x or
                        board[y][x] == '#') continue;

                while (aho[tmp].next[dir - 'A'] == -1) {
                    tmp = aho[tmp].next[aho.FAIL];
                }
                tmp = aho[tmp].next[dir - 'A'];
                if (aho[tmp].accept.size()) {
                    continue;
                }
                if (!used[make_tuple(y, x, tmp)]) {
                    used[make_tuple(y, x, tmp)] = true;
                    que.emplace(y, x, d + 1, tmp);
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

