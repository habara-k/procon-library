#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E"

#include "../../../lib/structure/binary_indexed_tree.cpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    BIT<int> bit(N+1);
    while (Q--) {
        int q; cin >> q;
        if (q == 0) {
            int s, t, X;
            cin >> s >> t >> X; --s, --t;
            bit.add(s, X);
            bit.add(t+1, -X);
        } else {
            int i; cin >> i; --i;
            cout << bit.sum(i) << endl;
        }
    }
}
