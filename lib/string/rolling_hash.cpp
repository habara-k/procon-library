#include "../template.cpp"

struct RollingHash {
    using uint = uint64_t;
    vector<uint> hash, pow;
    static const uint MASK30 = (1LL<<30)-1,
                      MASK31 = (1LL<<31)-1,
                      MASK61 = (1LL<<61)-1;

    template<typename S>
    RollingHash(const S& s, uint base) {
        int n = s.size();
        hash.assign(n+1, 0);
        pow.assign(n+1, 1);
        for (int i = 0; i < n; ++i) {
            hash[i+1] = _mod(_mul(hash[i], base) + s[i]);
            pow[i+1] = _mul(pow[i], base);
        }
    }

    uint get(int l, int r) const {
        return _mod(hash[r] + MASK61 - _mul(hash[l], pow[r - l]));
    }

    static uint _mul(uint a, uint b) {
        uint au = a >> 31, ad = a & MASK31,
             bu = b >> 31, bd = b & MASK31;
        uint m = au * bd + ad * bu;
        uint mu = m >> 30, md = m & MASK30;

        return _mod(au*bu*2 + mu + (md<<31) + ad*bd);
    }
    static uint _mod(uint x) {
        uint xu = x >> 61, xd = x & MASK61;
        uint ret = xu + xd;
        if (ret >= MASK61) ret -= MASK61;
        return ret;
    }
    static uint gen_base() {
        mt19937 random{random_device{}()};
        uniform_int_distribution<uint> dist(2, MASK61-2);
        return dist(random);
    }
};
