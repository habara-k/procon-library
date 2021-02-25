#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_J"

#include "../../../lib/number/modint.cpp"
#include "../../../lib/number/partition.cpp"

int main() {
    int n, k; cin >> n >> k;

    using Int = modint1000000007;
    cout << Partition<Int>(k, n) << endl;
}
