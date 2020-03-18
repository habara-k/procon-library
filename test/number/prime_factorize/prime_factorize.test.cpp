#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A"

#include "../../../lib/number/prime_factorize.cpp"

int main() {
    int n; cin >> n;

    map<int64_t, int> fact = prime_factorize(n);

    cout << n << ":";

    for (auto tp : fact) {
        for (int i = 0; i < tp.second; ++i) {
            cout << " " << tp.first;
        }
    }
    cout << endl;
}
