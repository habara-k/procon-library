#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1308"

#include "../../../lib/number/modint.cpp"
#include "../../../lib/number/matrix.cpp"

int main() {
    using mint = modint<2>;

    while (true) {
        int m, n, d; cin >> m >> n >> d;
        if (m == 0) break;

        Matrix<mint> A(n*m);
        REP(i1, n) {
            REP(j1, m) {
                A[i1*m + j1][i1*m + j1] = 1;
                REP(i2, n) {
                    REP(j2, m) {
                        if (abs(i1 - i2) + abs(j1 - j2) == d) {
                            A[i1*m + j1][i2*m + j2] = 1;
                        }
                    }
                }
            }
        }
        vector<mint> b(n*m);
        REP(i, n*m) cin >> b[i];

        auto res = linear_equation<mint>(A, b, [](mint a){ return a.x; }, 1e-9);
        cout << !res.empty() << endl;
    }
    return 0;
}
