#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1181"

#include "../../../lib/other/dice.cpp"

int main()
{
    while (true) {
        int n; cin >> n;
        if (n == 0) break;

        vector<vector<int>> h(2*n+1, vector<int>(2*n+1));
        vector<vector<int>> v(2*n+1, vector<int>(2*n+1));

        for (int k = 0; k < n; ++k) {
            int t, f; cin >> t >> f;
            Dice dice(1,6,2,5,3,4);
            if (dice.U != t) dice.rollR();
            if (dice.U != t) dice.rollR();
            if (dice.U != t) dice.rollR();
            if (dice.U != t) dice.rollF();
            if (dice.U != t) dice.rollF();
            if (dice.U != t) dice.rollF();
            if (dice.F != f) dice.rollU();
            if (dice.F != f) dice.rollU();
            if (dice.F != f) dice.rollU();
            assert(dice.F == f and dice.U == t);

            for (int i = n, j = n;;) {
                if (dice.L == 6 and h[i+1][j] < h[i][j]) {
                    dice.rollB();
                    ++i;
                }
                else if (dice.R == 6 and h[i-1][j] < h[i][j]) {
                    dice.rollF();
                    --i;
                }
                else if (dice.F == 6 and h[i][j+1] < h[i][j]) {
                    dice.rollL();
                    ++j;
                }
                else if (dice.B == 6 and h[i][j-1] < h[i][j]) {
                    dice.rollR();
                    --j;
                }
                else if (dice.L == 5 and h[i+1][j] < h[i][j]) {
                    dice.rollB();
                    ++i;
                }
                else if (dice.R == 5 and h[i-1][j] < h[i][j]) {
                    dice.rollF();
                    --i;
                }
                else if (dice.F == 5 and h[i][j+1] < h[i][j]) {
                    dice.rollL();
                    ++j;
                }
                else if (dice.B == 5 and h[i][j-1] < h[i][j]) {
                    dice.rollR();
                    --j;
                }
                else if (dice.L == 4 and h[i+1][j] < h[i][j]) {
                    dice.rollB();
                    ++i;
                }
                else if (dice.R == 4 and h[i-1][j] < h[i][j]) {
                    dice.rollF();
                    --i;
                }
                else if (dice.F == 4 and h[i][j+1] < h[i][j]) {
                    dice.rollL();
                    ++j;
                }
                else if (dice.B == 4 and h[i][j-1] < h[i][j]) {
                    dice.rollR();
                    --j;
                }
                else {
                    ++h[i][j];
                    v[i][j] = dice.U;
                    break;
                }
            }

        }
        vector<int> cnt(6);
        for (int i = 0; i <= 2*n; ++i) {
            for (int j = 0; j <= 2*n; ++j) {
                if (v[i][j]) ++cnt[v[i][j]-1];
            }
        }

        for (int i = 0; i < 6; ++i) {
            if (i) cout << " ";
            cout << cnt[i];
        }
        cout << endl;
    }

    return 0;
}
