#include "./trie.cpp"

template<int char_size, int margin>
struct AhoCorasick {
    Trie<char_size + 1, margin> trie;
    const int FAIL = char_size;

    AhoCorasick() : trie() {}

    void add(const string& s, int id = 0) {
        trie.add(s, id);
    }

    using Node = typename Trie<char_size + 1, margin>::Node;

    void build() {
        queue<Node*> que;
        for (int i = 0; i < char_size; ++i) {
            if (trie.root->next[i]) {
                que.push(trie.root->next[i]);
                trie.root->next[i]->next[FAIL] = trie.root;
            } else {
                trie.root->next[i] = trie.root;
            }
        }
        while (!que.empty()) {
            Node* now = que.front(); que.pop();
            for (int i = 0; i < char_size; ++i) {
                if (now->next[i] == nullptr) continue;
                Node* fail = now->next[FAIL];
                while (fail->next[i] == nullptr) {
                    fail = fail->next[FAIL];
                }
                now->next[i]->next[FAIL] = fail->next[i];
                auto &u = now->next[i]->accept;
                auto &v = fail->next[i]->accept;
                vector<int> accept;
                set_union(u.begin(), u.end(), v.begin(), v.end(),
                        back_inserter(accept));
                u = accept;
                que.push(now->next[i]);
            }
        }
    }

    map<int,int> match(const string& str) {
        map<int,int> ret;
        Node* now = trie.root;
        for (char c : str) {
            while (now->next[c - margin] == nullptr) now = now->next[FAIL];
            now = now->next[c - margin];
            for (int id : now->accept) ++ret[id];
        }
        return ret;
    }

    friend ostream& operator<<(ostream& os, const AhoCorasick& a) {
        return os << a.trie;
    }
};
