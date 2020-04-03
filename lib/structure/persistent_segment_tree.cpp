#include "../template.cpp"

template<typename M>
struct PersistentSegmentTree {
    struct Node {
        Node *l, *r;
        M data;
        Node() : l(nullptr), r(nullptr) {}
    };

    const function<M(M,M)> f;
    const M e;
    const int sz;

    PersistentSegmentTree(const function<M(M,M)>& f, const M& e, int sz) :
        f(f), e(e), sz(sz) {}

    Node* _new(const M& data) {
        auto t = new Node();
        t->data = data;
        return t;
    }

    Node* _new(Node* l, Node* r) {
        auto t = new Node();
        t->l = l, t->r = r, t->data = f(l->data, r->data);
        return t;
    }

    Node* _build(int l, int r) {
        assert(l < r);
        if (l+1 == r) return _new(e);
        return _new(_build(l, (l+r)>>1), _build((l+r)>>1, r));
    }

    Node* build() {
        return _build(0, sz);
    }

    template<typename UpdateQuery>
    Node* _update(Node* t, const UpdateQuery& q, int pos, int l, int r) {
        if (pos == l && pos+1 == r) return _new(q(t->data));
        if (r <= pos || pos < l) return t;
        return _new(_update(t->l, q, pos, l, (l+r)>>1),
                    _update(t->r, q, pos, (l+r)>>1, r));
    }

    template<typename UpdateQuery>
    Node* update(Node* root, const UpdateQuery& q, int pos) {
        return _update(root, q, pos, 0, sz);
    }

    M _query(Node* t, int a, int b, int l, int r) {
        if (r <= a || b <= l) return e;
        if (a <= l && r <= b) return t->data;
        return f(_query(t->l, a, b, l, (l+r)>>1),
                 _query(t->r, a, b, (l+r)>>1, r));
    }

    M query(Node* root, int a, int b) {
        // return f[a,b)
        return _query(root, a, b, 0, sz);
    }

};
