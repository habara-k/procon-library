#include "../template.cpp"

struct Permutation {
    vector<int> perm;
    Permutation() {}
    Permutation(int sz) : perm(sz) {
        iota(perm.begin(), perm.end(), 0);
    }
    Permutation(initializer_list<int> init) : perm(init.begin(), init.end()) {}
    size_t size() const {
        return (perm.size());
    }
    inline int operator [](int k) const {
        return (perm.at(k));
    }
    inline int& operator [](int k) {
        return (perm.at(k));
    }
    Permutation& operator*=(const Permutation& rhs) {
        assert(size() == rhs.size());
        Permutation tmp(size());
        for (int i = 0; i < size(); ++i) {
            tmp[i] = perm[rhs[i]];
        }
        perm.swap(tmp.perm);
        return (*this);
    }
    const Permutation operator*(const Permutation& rhs) const {
        return (Permutation(*this) *= rhs);
    }
    Permutation pow(int64_t k) {
        Permutation ret(size()), tmp = *this;
        while (k) {
            if (k & 1) ret *= tmp;
            tmp *= tmp; k >>= 1;
        }
        return (ret);
    }
};
