#include "../template.cpp"

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
