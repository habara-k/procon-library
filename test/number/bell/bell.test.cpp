#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_G"

#include "../../../lib/number/modint.cpp"
#include "../../../lib/number/bell.cpp"

int main() {
    int64_t n, k; cin >> n >> k;

    using Int = modint<MOD>;
    Comb<Int> comb(k);

    cout << Bell(n, k, comb) << endl;
}
