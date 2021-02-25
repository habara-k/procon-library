#include "../template.cpp"

template<typename T>
struct fenwick_tree {
    vector<T> data;
    int sz;
    fenwick_tree(int sz) : sz(sz), data(sz+1) {}

    void add(int i, T x) {
        // a[i] += x;
        assert(0 <= i and i < sz);
        for (++i; i <= sz; i += i & -i) data[i] += x;
    }

    T sum(int i) const {
        // return a[0] + ... + a[i-1]
        assert(0 <= i and i <= sz);
        T s = 0;
        for (; i > 0; i -= i & -i) s += data[i];
        return s;
    }

    T sum(int l, int r) const {
        // return a[l] + ... + a[r-1]
        return sum(r) - sum(l);
    }

    friend ostream& operator<<(ostream& os, const fenwick_tree& a) {
        os << "[";
        for (int i = 0; i < a.sz; ++i) {
            if (i) os << " ";
            os << a.sum(i, i+1);
        }
        return os << "]";
    }
};
