#include "../template.cpp"

template<int char_size, int margin>
struct Trie {
    struct Node {
        vector<Node*> next;
        vector<int> accept;
        int depth;
        Node(int depth) : next(char_size, nullptr), depth(depth) {}
        friend ostream& operator<<(ostream& os, const Node* t) {
            os << "{";
            bool a = 0;
            for (int i = 0; i < char_size; ++i) {
                if (t->next[i] == nullptr) continue;
                if (a) os << ", "; a = 1;
                os << (char)(i + margin);
                if (t->next[i]->depth > t->depth) os << ": " << t->next[i];
            }
            return os << "}";
        }
    };

    Node* root;
    Trie() { root = new Node(0); }

    void add(const string& s, int id = 0) {
        Node* now = root;
        for (char c : s) {
            if (now->next[c - margin] == nullptr) {
                now->next[c - margin] = new Node(now->depth + 1);
            }
            now = now->next[c - margin];
        }
        now->accept.push_back(id);
    }

    friend ostream& operator<<(ostream& os, const Trie& t) {
        return os << t.root;
    }
};
