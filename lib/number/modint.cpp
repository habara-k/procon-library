#include "../template.cpp"

template<int64_t mod>
class modint {
    using LL = int64_t;
    LL x;

public:
    modint(LL x=0) : x(((x % mod) + mod) % mod) {}

    const modint operator-() const { return (-x + mod) % mod; }
    const modint inv() const { return pow(mod-2); }

    modint& operator+=(const modint& rhs) {
        (x += rhs.x) %= mod;
        return *this;
    }
    modint& operator-=(const modint& rhs) {
        return *this += -rhs;
    }
    modint& operator*=(const modint& rhs) {
        (x *= rhs.x) %= mod;
        return *this;
    }
    modint& operator/=(const modint& rhs) {
        return *this *= rhs.inv();
    }

    friend const modint operator+(modint lhs, const modint& rhs) {
        return lhs += rhs;
    }
    friend const modint operator-(modint lhs, const modint& rhs) {
        return lhs -= rhs;
    }
    friend const modint operator*(modint lhs, const modint& rhs) {
        return lhs *= rhs;
    }
    friend const modint operator/(modint lhs, const modint& rhs) {
        return lhs /= rhs;
    }

    const modint pow(LL n) const {
        modint ret = 1, tmp = x;
        while (n) {
            if (n & 1) ret *= tmp;
            tmp *= tmp; n >>= 1;
        }
        return ret;
    }

    friend bool operator==(const modint& lhs, const modint& rhs) {
        return lhs.x == rhs.x;
    }
    friend bool operator!=(const modint& lhs, const modint& rhs) {
        return !(lhs == rhs);
    }

    friend ostream& operator<<(ostream& os, const modint& a) {
        return os << a.x;
    }

    friend istream& operator>>(istream& is, modint& a) {
        return is >> a.x;
    }
};
