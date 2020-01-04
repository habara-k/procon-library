#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B"

#include "../../../lib/algorithm/binary_search.cpp"

int main() {
    int n; cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    int q; cin >> q;
    vector<int> t(q);
    for (int i = 0; i < q; ++i) {
        cin >> t[i];
    }

    int ans = 0;
    for (int i = 0; i < q; ++i) {
        int lb, ub, tmp;
        tie(tmp, lb) = my_binary_search(-1, n,
                [&](int m){ return s[m] >= t[i]; });
        tie(tmp, ub) = my_binary_search(-1, n,
                [&](int m){ return s[m] > t[i]; });
        if (ub - lb > 0) ans++;
    }
    cout << ans << endl;
}
