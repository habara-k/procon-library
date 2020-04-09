#include "../template.cpp"

// O(sqrt(n))
int64_t euler_phi(int64_t n) {
    int64_t ret = n;
    for (int64_t i = 2; i * i <= n; ++i) {
        if (n % i != 0) continue;
        ret -= ret / i;
        while (n % i == 0) n /= i;
    }
    if (n > 1) ret -= ret / n;
    return ret;
}
