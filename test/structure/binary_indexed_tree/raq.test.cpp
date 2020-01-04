#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E"

#include "../../../lib/structure/binary_indexed_tree.cpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    BIT<int> bit(N);
    while (Q--) {
        int q; cin >> q;
        if (q == 0) {
            int s, t, X;
            cin >> s >> t >> X;
            bit.add(s-1, X);
            bit.add(t, -X);
        } else {
            int i; cin >> i;
            cout << bit.sum(i-1) << endl;
        }
    }
}
