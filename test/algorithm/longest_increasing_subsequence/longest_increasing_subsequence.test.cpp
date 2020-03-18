#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_D"

#include "../../../lib/algorithm/longest_increasing_subsequence.cpp"

int main()
{
    int n; cin >> n;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << LIS(a) << endl;

    return 0;
}
