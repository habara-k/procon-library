#include "../template.cpp"

template<typename M, typename OM = M>
struct LazySegmentTree {
    int sz;
    vector<M> data;
    vector<OM> lazy;
    const M e;
    const OM oe;
    const function<M(M,M)> f;
    const function<M(M,OM,int)> g;
    const function<OM(OM,OM)> h;
    // f: 二つの区間の要素をマージする関数
    // g: 要素と作用素をマージする二項演算. 第三引数は区間幅
    // h: 作用素をマージする関数
    // e: モノイドの単位元
    // oe: 作用素の単位元

    LazySegmentTree(
            int n, const M& e, const OM& oe,
            const function<M(M,M)>& f,
            const function<M(M,OM,int)>& g,
            const function<OM(OM,OM)>& h
            ) : e(e), oe(oe), f(f), g(g), h(h) {
        sz = 1;
        while (sz < n) sz <<= 1;
        data.assign(2*sz, e);
        lazy.assign(2*sz, oe);
    }

    void set(int i, const M &x) {
        data[i + sz] = x;
    }

    void build() {
        for(int i = sz-1; i > 0; --i) {
            data[i] = f(data[2*i], data[2*i+1]);
        }
    }

    void propagate(int k, int len) {
        if (lazy[k] == oe) return;
        if (k < sz) {
            lazy[2*k  ] = h(lazy[2*k  ], lazy[k]);
            lazy[2*k+1] = h(lazy[2*k+1], lazy[k]);
        }
        data[k] = g(data[k], lazy[k], len);
        lazy[k] = oe;
    }

    void _update(int a, int b, const OM &x, int k, int l, int r) {
        propagate(k, r - l);
        if (r <= a || b <= l) return;
        else if (a <= l && r <= b) {
            lazy[k] = h(lazy[k], x);
            propagate(k, r - l);
        } else {
            _update(a, b, x, 2*k,   l, (l+r)/2);
            _update(a, b, x, 2*k+1, (l+r)/2, r);
            data[k] = f(data[2*k], data[2*k+1]);
        }
    }

    void update(int a, int b, const OM &x) {
        // update [a, b) with x.
        _update(a, b, x, 1, 0, sz);
    }

    M _query(int a, int b, int k, int l, int r) {
        propagate(k, r - l);
        if (r <= a || b <= l) return e;
        else if (a <= l && r <= b) return data[k];
        else return f(
                _query(a, b, 2*k,   l, (l+r)/2),
                _query(a, b, 2*k+1, (l+r)/2, r));
    }

    M query(int a, int b) {
        // return f[a, b).
        return _query(a, b, 1, 0, sz);
    }
};
