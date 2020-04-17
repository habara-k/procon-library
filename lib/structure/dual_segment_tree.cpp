#include "../template.cpp"

template<typename OM>
struct DualSegmentTree {
    int sz;
    vector<OM> lazy;
    const function<OM(OM,OM)> h;
    const OM oe;
    // h: 作用素をマージする関数
    // oe: 作用素の単位元

    DualSegmentTree(
            int n,
            const function<OM(OM,OM)>& h,
            const OM& oe
            ) : h(h), oe(oe) {
        sz = 1;
        while (sz < n) sz <<= 1;
        lazy.assign(2*sz, oe);
    }

    void set(int i, const OM& x) {
        lazy.at(i + sz) = x;
    }

    OM merge(const OM& a, const OM& b) {
        if (a == oe) return b;
        if (b == oe) return a;
        return h(a, b);
    }

    void propagate(int k, int len) {
        if (lazy[k] == oe) return;
        if (k < sz) {
            lazy[2*k  ] = merge(lazy[2*k  ], lazy[k]);
            lazy[2*k+1] = merge(lazy[2*k+1], lazy[k]);
            lazy[k] = oe;
        }
    }

    void _update(int a, int b, const OM& x, int k, int l, int r) {
        propagate(k, r - l);
        if (r <= a or b <= l) return;
        else if (a <= l and r <= b) {
            lazy[k] = merge(lazy[k], x);
            propagate(k, r - l);
        } else {
            _update(a, b, x, 2*k,   l, (l+r)/2);
            _update(a, b, x, 2*k+1, (l+r)/2, r);
        }
    }

    void update(int a, int b, const OM& x) {
        // update [a, b) with x.
        _update(a, b, x, 1, 0, sz);
    }

    OM _query(int i, int k, int l, int r) {
        if (l+1 == r) return lazy[l + sz];
        propagate(k, r - l);
        int m = (l+r)/2;
        if (i < m) return _query(i, 2*k,   l, m);
        else       return _query(i, 2*k+1, m, r);
    }

    OM operator[](int i) {
        return _query(i, 1, 0, sz);
    }

    friend ostream& operator<<(ostream& os, const DualSegmentTree& s) {
        os << "[";
        for (int i = 0; i < s.sz; ++i) {
            if (i) os << " ";
            os << s[i];
        }
        return os << "]";
    }
};
