#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_B"

#include "../../../lib/number/modint.cpp"
#include "../../../lib/number/factorial.cpp"
#include "../../../lib/number/combination.cpp"

int main() {
    LL n, k;
    cin >> n >> k;

    if (n > k) {
        cout << 0 << endl;
        return 0;
    }

    using Int = modint<MOD>;
    Fact<Int> fact(k);
    Comb<Int> comb(k);

    cout << comb(k, n) * fact[n] << endl;
}
