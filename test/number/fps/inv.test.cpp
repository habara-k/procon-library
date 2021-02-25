#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series"

#include "../../../lib/number/fps.cpp"

int main()
{
    int n; cin >> n;
    fps a(n);
    REP(i, n) {
        int x; cin >> x;
        a[i] = x;
    }
    for (auto x : a.inv()) {
        cout << x.val() << endl;
    }
    return 0;
}
