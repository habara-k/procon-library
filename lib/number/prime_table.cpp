#include "../template.cpp"

// O(nloglogn)
vector<bool> prime_table(int n) {
    n = max(n, 1);
    vector<bool> prime(n+1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (!prime[i]) continue;
        for (int j = 2 * i; j <= n; j += i) {
            prime[j] = false;
        }
    }
    return prime;
}
