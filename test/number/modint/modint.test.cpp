#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_B"

#include "../../../lib/number/modint.cpp"

int main() {
    ll n, k;
    cin >> n >> k;

    if (n > k) {
        cout << 0 << endl;
        return 0;
    }

    using Int = modint1000000007;
    Int ans = 1;
    for (ll i = 0; i < n; ++i) {
        ans *= (k - i);
    }
    cout << ans << endl;
}
