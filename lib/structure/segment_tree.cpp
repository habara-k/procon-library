#include "../template.cpp"

template<typename M>
struct SegmentTree {
    int sz;
    vector<M> data;
    const function<M(M,M)> f;
    const M e;

    SegmentTree(
            int n,
            const function<M(M,M)>& f,
            const M& e
            ) : f(f), e(e) {
        sz = 1;
        while (sz < n) sz <<= 1;
        data.assign(2*sz, e);
    }

    template<typename UpdateQuery>
    void update(int k, const UpdateQuery& q) {
        k += sz;
        data[k] = q(data[k]);
        while (k >>= 1) {
            data[k] = f(data[2*k], data[2*k+1]);
        }
    }

    M _query(int a, int b, int k, int l, int r) {
        if (r <= a or b <= l) return e;
        if (a <= l and r <= b) return data[k];
        return f(_query(a,b,2*k,  l,(l+r)/2),
                 _query(a,b,2*k+1,(l+r)/2,r));
    }

    M query(int a, int b) {
        // return f[a,b)
        return _query(a, b, 1, 0, sz);
    }

    M operator[](int i) {
        return data.at(i + sz);
    }

    friend ostream& operator<<(ostream& os, const SegmentTree& s) {
        os << "[";
        for (int i = 0; i < s.sz; ++i) {
            if (i) os << " ";
            os << s[i];
        }
        return os << "]";
    }
};
