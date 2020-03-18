#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/5/ALDS1_5_D"

#include "../../../lib/algorithm/inversion.cpp"

int main()
{
    int n;
    cin >> n;
    vector<int64_t> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    cout << inversion(A) << endl;

    return 0;
}
