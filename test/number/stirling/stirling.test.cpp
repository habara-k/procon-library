#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_I"

#include "../../../lib/number/modint.cpp"
#include "../../../lib/number/stirling.cpp"

int main() {
    LL n, k; cin >> n >> k;

    using Int = modint<MOD>;
    Comb<Int> comb(k);

    cout << Stirling(n, k, comb) << endl;
}
