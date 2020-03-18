#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_C"

#include "../../../lib/number/is_prime.cpp"

int main() {
    int n; cin >> n;

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;

        if (is_prime(a)) ++ans;
    }

    cout << ans << endl;
}
