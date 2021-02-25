#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_formal_power_series"

#include "../../../lib/number/fps.cpp"

int main()
{
    int n, m; cin >> n >> m;
    fps a(n);
    REP(i, n) {
        int x; cin >> x;
        a[i] = x;
    }
    for (auto x : a.pow_inplace(m)) {
        cout << x.val() << endl;
    }
    return 0;
}
