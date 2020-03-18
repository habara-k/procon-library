#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_C"

#include "../../../lib/number/prime_table.cpp"

int main() {
    int n; cin >> n;

    vector<bool> table = prime_table(1e8);

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;

        if (table[a]) ++ans;
    }

    cout << ans << endl;
}
