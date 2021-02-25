#include "../template.cpp"

template<int mod>
class modint {
    int x;

public:
    modint(ll x = 0) : x(x < 0 ? (mod - (-x) % mod) % mod : x % mod) {}

    int val() const { return x; }
    const modint operator-() const { return x ? mod - x : 0; }
    const modint inv() const {
        int a = x, b = mod, u = 1, v = 0, t;
        while (b) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        assert(a == 1);
        assert(b == 0);
        return u;
    }

    modint& operator+=(const modint& rhs) {
        if ((x += rhs.x) >= mod) x -= mod;
        return *this;
    }
    modint& operator-=(const modint& rhs) {
        return *this += -rhs;
    }
    modint& operator*=(const modint& rhs) {
        x = ((ll)x * rhs.x) % mod;
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

    const modint pow(ll n) const {
        modint ret = 1, tmp = *this;
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
        ll tmp; is >> tmp; a = tmp;
        return is;
    }
};

using modint998244353 = modint<998244353>;
using modint1000000007 = modint<1000000007>;

