#include "../template.cpp"

template<typename T>
struct BIT {
    // BIT<T> bit(n);
    //
    // bit.add(i,x) for i in [0,n)
    //   bit[i] += x;
    //
    // bit.sum(i) for i in [0,n)
    //   return bit[0] + ... + bit[i]
    vector<T> data;
    BIT(int n) : data(n+1) {}

    void add(int i, T x) {
        for (++i; i < data.size(); i += i & -i) data[i] += x;
    }

    T sum(int i) {
        T s = 0;
        for (++i; i > 0; i -= i & -i) s += data[i];
        return s;
    }
};
