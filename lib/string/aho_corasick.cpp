#include "./trie.cpp"

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
