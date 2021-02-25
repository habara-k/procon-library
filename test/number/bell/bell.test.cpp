#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_G"

#include "../../../lib/number/modint.cpp"
#include "../../../lib/number/bell.cpp"

int main() {
    ll n, k; cin >> n >> k;

    using Int = modint1000000007;

    cout << Bell<Int>(n, k) << endl;
}
