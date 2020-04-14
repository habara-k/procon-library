#include "../template.cpp"

// O(NlogN)
template<typename T>
vector<T> fast_mobius_transform(const vector<T>& g) {
    // Return f(s):
    // s.t. g(s) = \sum_{s \subset t} f(t)
    // ( e.g. f(s) = \sum_{s \subset t} (-1)^|t-s| * g(t) )
    int n = g.size();
    vector<T> f = g;
    for (int i = 0; (1 << i) < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!(j >> i & 1)) {
                f[j] -= f[j | (1<<i)];
            }
        }
    }
    return f;
}

// O(NloglogN)
template<typename T>
vector<T> fast_mobius_transform_prime(const vector<T>& g) {
    // Return f(d):
    // s.t. g(d) = \sum_{d | n} f(n)
    // ( e.g. f(d) = \sum_{d | n} mu(n / d) * g(n) )
    int n = g.size();
    vector<T> f = g;
    vector<bool> sieve(n, true);
    for (int p = 2; p < n; ++p) {
        if (!sieve[p]) continue;
        for (int i = 1; i * p < n; ++i) {
            sieve[i * p] = false;
            f[i] -= f[i * p];
        }
    }
    return f;
}
