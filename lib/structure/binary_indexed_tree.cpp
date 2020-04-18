#include "../template.cpp"

template<typename T>
struct BIT {
    vector<T> data;
    int sz;
    BIT(int sz) : sz(sz), data(sz+1) {}

    void add(int i, T x) {
        // v[i] += x;
        assert(0 <= i and i < sz);
        for (++i; i < data.size(); i += i & -i) data[i] += x;
    }

    T sum(int i) const {
        // return v[0] + v[1] + ... + v[i]
        if (i < 0) return 0;
        assert(i < sz);
        T s = 0;
        for (++i; i > 0; i -= i & -i) s += data[i];
        return s;
    }

    friend ostream& operator<<(ostream& os, const BIT& b) {
        os << "[";
        for (int i = 0; i < b.sz; ++i) {
            if (i) os << " ";
            os << b.sum(i) - b.sum(i-1);
        }
        return os << "]";
    }
};
