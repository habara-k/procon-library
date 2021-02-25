#include "../template.cpp"

template<typename T>
T gcd(T a, T b) {
    if (b == 0) return a;
    return gcd(b % a, a);
}

template<typename T>
T extended_gcd(T a, T b, T& x, T& y) {
    // solve ax + by = gcd(a, b)
    if (b == 0) { x = 1; y = 0; return a; }

    T X, Y;
    T g = extended_gcd(b, a % b, X, Y);
    x = Y; y = X - a/b * Y;
    return g;
}
