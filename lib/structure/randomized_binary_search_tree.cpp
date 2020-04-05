#include "../template.cpp"

template<typename M, typename OM = M>
struct RandomizedBinarySearchTree {

    struct Node {
        Node *lch, *rch;
        int sz;
        M data, sum;
        OM lazy;
        Node(const M& data, const OM& lazy) :
            lch(nullptr), rch(nullptr), sz(1),
            data(data), sum(data), lazy(lazy) {}
    };

    const function<M(M,M)> f;
    const function<M(M,OM,int)> g;
    const function<OM(OM,OM)> h;
    const M e;
    const OM oe;
    std::mt19937 rand;
    const int SEED = 0;
    Node* root;

    RandomizedBinarySearchTree(
            const function<M(M,M)>& f,
            const function<M(M,OM,int)>& g,
            const function<OM(OM,OM)>& h,
            const M& e, const OM& oe
            ) : f(f), g(g), h(h), e(e), oe(oe), rand(SEED), root(nullptr) {}

    Node* _build(const vector<M>& v, int l, int r) {
        if (l+1 >= r) return _new(v[l]);
        return merge(_build(v, l, (l+r)>>1),
                     _build(v, (l+r)>>1, r));
    }
    void build(const vector<M>& v) { root = _build(v, 0, v.size()); }

    Node* _build(int l, int r) {
        if (l+1 >= r) return _new(e);
        return merge(_build(l, (l+r)>>1),
                     _build((l+r)>>1, r));
    }
    void build(int size) { root = _build(0, size); }

    inline Node* _new(const M& data) { return new Node(data, oe); }

    inline int size(Node* t) const { return t ? t->sz : 0; }
    inline M sum(Node* t) const { return t ? t->sum : e; }
    inline OM lazy(Node* t) const { return t ? t->lazy : oe; }

    inline Node* modify(Node *t) {
        t->sz = size(t->lch) + size(t->rch) + 1;
        t->sum = f(f(sum(t->lch), t->data), sum(t->rch));
        return t;
    }

    // Lazy Segment Tree
    Node* propagate(Node* t) {
        if (!t) return t;
        if (lazy(t) == oe) return t;
        if (t->lch != nullptr) {
            t->lch->lazy = h(lazy(t->lch), lazy(t));
            t->lch->sum = g(sum(t->lch), lazy(t), size(t->lch));
        }
        if (t->rch != nullptr) {
            t->rch->lazy = h(lazy(t->rch), lazy(t));
            t->rch->sum = g(sum(t->rch), lazy(t), size(t->rch));
        }
        t->data = g(t->data, lazy(t), 1);
        t->lazy = oe;
        return modify(t);
    }

    void update(int a, int b, const OM& lazy) {
        // data[a, b) = g(data[a, b), lazy)
        auto p0 = split(root, a);
        auto p1 = split(p0.second, b-a);
        p1.first->lazy = h(p1.first->lazy, lazy);
        p1.first = propagate(p1.first);
        root = merge(p0.first, merge(p1.first, p1.second));
    }

    M query(int a, int b) {
        // return f[a,b)
        auto p0 = split(root, a);
        auto p1 = split(p0.second, b-a);
        p1.first = propagate(p1.first);
        M ret = sum(p1.first);
        root = merge(p0.first, merge(p1.first, p1.second));
        return ret;
    }


    // Binary Search Tree
    Node* merge(Node *l, Node *r) {
        if (!l) return r;
        if (!r) return l;
        std::uniform_int_distribution<> dist(1,size(l)+size(r));
        if (dist(rand) > size(l)) {
            r = propagate(r);
            r->lch = merge(l, r->lch);
            return modify(r);
        } else {
            l = propagate(l);
            l->rch = merge(l->rch, r);
            return modify(l);
        }
    }

    pair<Node*, Node*> split(Node* t, int k) {
        if (!t) return {t, t};
        t = propagate(t);
        if (k > size(t->lch)) {
            auto p = split(t->rch, k-size(t->lch)-1);
            t->rch = p.first;
            return {modify(t), p.second};
        } else {
            auto p = split(t->lch, k);
            t->lch = p.second;
            return {p.first, modify(t)};
        }
    }

    void insert(int k, const M& data) {
        auto q = _new(data);
        auto p = split(root, k);
        root = merge(merge(p.first, q), p.second);
    }

    M erase(int k) {
        auto p = split(root, k);
        auto q = split(p.second, 1);
        M ret = q.first->data;
        root = merge(p.first, q.second);
        return ret;
    }

    void print(Node* t) {
        if (!t) return;
        if (t->lch) { cout << "("; print(t->lch); cout << ")"; }
        cout << t->data;
        if (t->rch) { cout << "("; print(t->rch); cout << ")"; }
    }
    void print_sum(Node* t) {
        if (!t) return;
        if (t->lch) { cout << "("; print(t->lch); cout << ")"; }
        cout << sum(t);
        if (t->rch) { cout << "("; print(t->rch); cout << ")"; }
    }
    void print_lazy(Node* t) {
        if (!t) return;
        if (t->lch) { cout << "("; print(t->lch); cout << ")"; }
        cout << lazy(t);
        if (t->rch) { cout << "("; print(t->rch); cout << ")"; }
    }

    friend ostream& operator<<(ostream& os, RandomizedBinarySearchTree& tr) {
        os << "data: "; tr.print(tr.root); os << endl;
        os << " sum: "; tr.print_sum(tr.root); os << endl;
        os << "lazy: "; tr.print_lazy(tr.root); os << endl;
        return os;
    }
};
