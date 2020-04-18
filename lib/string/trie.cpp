#include "../template.cpp"

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
