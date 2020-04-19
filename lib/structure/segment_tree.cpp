#include "../template.cpp"

template<typename M>
struct SegmentTree {
    int n, sz;
    vector<M> data;
    const function<M(M,M)> f;
    const M e;

    SegmentTree(
            int n,
            const function<M(M,M)>& f,
            const M& e
            ) : n(n), f(f), e(e) {
        sz = 1;
        while (sz < n) sz <<= 1;
        data.assign(2*sz, e);
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

    template<typename UpdateQuery>
    void update(int k, const UpdateQuery& q) {
        k += sz;
        data[k] = q(data[k]);
        while (k >>= 1) {
            data[k] = f(data[2*k], data[2*k+1]);
        }
    }

    M _query(int a, int b, int k, int l, int r) const {
        if (r <= a or b <= l) return e;
        if (a <= l and r <= b) return data[k];
        return f(_query(a,b,2*k,  l,(l+r)/2),
                 _query(a,b,2*k+1,(l+r)/2,r));
    }

    M query(int a, int b) const {
        // return f[a,b)
        return _query(a, b, 1, 0, sz);
    }

    M operator[](int i) const {
        return data.at(i + sz);
    }

    friend ostream& operator<<(ostream& os, const SegmentTree& s) {
        os << "[";
        for (int i = 0; i < s.n; ++i) {
            if (i) os << " ";
            os << s[i];
        }
        return os << "]";
    }
};
