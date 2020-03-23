#include "../template.cpp"

template<typename T>
vector<T> fast_mobius_transform_1(const vector<T>& g)
{
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
template<typename T>
vector<T> fast_mobius_transform_2(const vector<T>& g)
{
    // Return f(s):
    // s.t. g(s) = \sum_{t \subset s} f(t)
    // ( e.g. f(s) = \sum_{t \subset s} (-1)^|t-s| * g(t) )
    int n = g.size();
    vector<T> f = g;
    for (int i = 0; (1 << i) < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j >> i & 1) {
                f[j] -= f[j & ~(1<<i)];
            }
        }
    }
    return f;
}
