#include "../template.cpp"

// O(NlogN)
template<typename T>
vector<T> fast_zeta_transform(const vector<T>& f) {
    // Return g(s):
    // s.t. g(s) = \sum_{s \subset t} f(t)
    int n = f.size();
    vector<T> g = f;
    for (int i = 0; (1 << i) < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!(j >> i & 1)) {
                g[j] += g[j | (1<<i)];
            }
        }
    }
    return g;
}

// O(NloglogN)
template<typename T>
vector<T> fast_zeta_transform_prime(const vector<T>& f) {
    // Return g(d):
    // s.t. g(d) = \sum_{d | n} f(n)
    int n = f.size();
    vector<T> g = f;
    vector<bool> sieve(n, true);
    for (int p = 2; p < n; ++p) {
        if (!sieve[p]) continue;
        for (int i = (n - 1) / p; i > 0; --i) {
            sieve[i * p] = false;
            g[i] += g[i * p];
        }
    }
    return g;
}
