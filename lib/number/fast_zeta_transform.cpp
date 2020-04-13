#include "../template.cpp"

// O(NlogN)
template<typename T>
vector<T> fast_zeta_transform_1(const vector<T>& f) {
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

// O(NlogN)
template<typename T>
vector<T> fast_zeta_transform_2(const vector<T>& f) {
    // Return g(s):
    // s.t. g(s) = \sum_{t \subset s} f(t)
    int n = f.size();
    vector<T> g = f;
    for (int i = 0; (1 << i) < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j >> i & 1) {
                g[j] += g[j & ~(1<<i)];
            }
        }
    }
    return g;
}

// O(NloglogN)
template<typename T>
vector<T> fast_zeta_transform_prime_1(const vector<T>& f) {
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

// O(NloglogN)
template<typename T>
vector<T> fast_zeta_transform_prime_2(const vector<T>& f) {
    // Return g(n):
    // s.t. g(n) = \sum_{d | n} f(d)
    int n = f.size();
    vector<T> g = f;
    vector<bool> sieve(n, true);
    for (int p = 2; p < n; ++p) {
        if (!sieve[p]) continue;
        for (int i = 1; i * p < n; ++i) {
            sieve[i * p] = false;
            g[i * p] += g[i];
        }
    }
    return g;
}

