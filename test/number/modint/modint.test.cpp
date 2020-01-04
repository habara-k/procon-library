#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_B"

#include "../../../lib/number/modint.cpp"

int main() {
    LL n, k;
    cin >> n >> k;

    if (n > k) {
        cout << 0 << endl;
        return 0;
    }

    using Int = modint<MOD>;
    Int ans = 1;
    for (LL i = 0; i < n; ++i) {
        ans *= (k - i);
    }
    cout << ans << endl;
}
