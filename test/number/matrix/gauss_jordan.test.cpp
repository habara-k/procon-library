#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1328"

#include "../../../lib/number/matrix.cpp"

int main() {
    while (true) {
        int d; cin >> d;
        if (d == 0) break;

        vector<double> f(d+3);
        REP(i, d+3) cin >> f[i];

        REP(i, d+3) {
            int cnt = 0;
            Matrix<double> A(d+2, d+1);
            vector<double> b(d+2);
            REP(j, d+3) {
                if (j == i) continue;
                double p = 1.0;
                REP(k, d+1) {
                    A[cnt][k] = p;
                    p *= j;
                }
                b[cnt] = f[j];
                ++cnt;
            }
            auto res = linear_equation<double>(A, b, [](double x){ return abs(x); }, 1e-5);
            if (!res.empty()) {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}
