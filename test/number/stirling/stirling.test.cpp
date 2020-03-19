#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_I"

#include "../../../lib/number/modint.cpp"
#include "../../../lib/number/stirling.cpp"

int main() {
    int64_t n, k; cin >> n >> k;

    using Int = modint<MOD>;

    cout << Stirling<Int>(n, k) << endl;
}
