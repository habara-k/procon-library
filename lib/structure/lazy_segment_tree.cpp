#include "../template.cpp"

template<typename M, typename OM = M>
struct LazySegmentTree {

    LazySegmentTree(
            int n,
            const function<M(M,M)>& f,
            const function<M(M,OM,int)>& g,
            const function<OM(OM,OM)>& h,
            const M& e, const OM& oe
            ) : n(n), f(f), g(g), h(h), e(e), oe(oe) {
        sz = 1;
        while (sz < n) sz <<= 1;
        data.assign(2*sz, e);
        lazy.assign(2*sz, oe);
    }

    void build(const vector<M>& v) {
        assert(v.size() <= n);
        for (int i = 0; i < v.size(); ++i) {
            data[i + sz] = v[i];
        }
        for (int i = sz-1; i > 0; --i) {
            data[i] = f(data[2*i], data[2*i+1]);
        }
    }

    void update(int a, int b, const OM& x) {
        // update [a, b) with x.
        update(a, b, x, 1, 0, sz);
    }


    M query(int a, int b) {
        // return f[a, b).
        return query(a, b, 1, 0, sz);
    }

    M operator[](int i) {
        return query(i, i+1);
    }

    friend ostream& operator<<(ostream& os, LazySegmentTree& s) {
        os << "[";
        for (int i = 0; i < s.n; ++i) {
            if (i) os << " ";
            os << s[i];
        }
        return os << "]";
    }

private:

    int n, sz;
    vector<M> data;
    vector<OM> lazy;
    const function<M(M,M)> f;
    const function<M(M,OM,int)> g;
    const function<OM(OM,OM)> h;
    const M e;
    const OM oe;
    // f: 二つの区間の要素をマージする関数
    // g: 要素と作用素をマージする二項演算. 第三引数は区間幅
    // h: 作用素をマージする関数
    // e: モノイドの単位元
    // oe: 作用素の単位元

    void propagate(int k, int len) {
        if (lazy[k] == oe) return;
        if (k < sz) {
            lazy[2*k  ] = h(lazy[2*k  ], lazy[k]);
            lazy[2*k+1] = h(lazy[2*k+1], lazy[k]);
        }
        data[k] = g(data[k], lazy[k], len);
        lazy[k] = oe;
    }

    void update(int a, int b, const OM& x, int k, int l, int r) {
        propagate(k, r - l);
        if (r <= a or b <= l) return;
        else if (a <= l and r <= b) {
            lazy[k] = h(lazy[k], x);
            propagate(k, r - l);
        } else {
            update(a, b, x, 2*k,   l, (l+r)/2);
            update(a, b, x, 2*k+1, (l+r)/2, r);
            data[k] = f(data[2*k], data[2*k+1]);
        }
    }

    M query(int a, int b, int k, int l, int r) {
        propagate(k, r - l);
        if (r <= a or b <= l) return e;
        else if (a <= l and r <= b) return data[k];
        else return f(
                query(a, b, 2*k,   l, (l+r)/2),
                query(a, b, 2*k+1, (l+r)/2, r));
    }
};
