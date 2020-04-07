#include "../template.cpp"

// O(sqrt(n))
bool is_prime(int64_t n) {
    assert(n > 0);
    if (n == 1) return false;
    for (int64_t i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}