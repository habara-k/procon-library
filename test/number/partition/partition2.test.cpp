#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_L"

#include "../../../lib/number/modint.cpp"
#include "../../../lib/number/partition.cpp"

int main() {
    int n, k; cin >> n >> k;

    using Int = modint<MOD>;
    cout << Partition<Int>(k, n) - Partition<Int>(k-1, n) << endl;
}
