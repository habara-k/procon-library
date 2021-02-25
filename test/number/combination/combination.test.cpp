#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_B"

#include "../../../lib/number/modint.cpp"
#include "../../../lib/number/combination.cpp"

int main() {
    ll n, k;
    cin >> n >> k;

    if (n > k) {
        cout << 0 << endl;
        return 0;
    }

    using Int = modint1000000007;
    Combination<Int> comb;

    cout << comb.C(k, n) * comb.fact(n) << endl;
}
