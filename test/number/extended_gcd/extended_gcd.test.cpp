#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E"

#include "../../../lib/number/extended_gcd.cpp"

int main() {
    LL a, b; cin >> a >> b;
    LL x, y;
    extended_gcd(a, b, x, y);
    cout << x << " " << y << endl;
}
