#define PROBLEM "https://judge.yosupo.jp/problem/exp_of_formal_power_series"

#include "../../../lib/number/fps.cpp"

int main()
{
    int n; cin >> n;
    fps a(n);
    REP(i, n) {
        int x; cin >> x;
        a[i] = x;
    }
    //cout << a.inv() << '\n';
    //cout << a.log_inplace() << '\n';
    cout << a.exp_inplace() << '\n';
    //cout << a.pow_inplace(m) << '\n';
    return 0;
}
