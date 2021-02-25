#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E"

#include "../../../lib/structure/fenwick_tree.cpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    fenwick_tree<int> fw(N+1);
    while (Q--) {
        int q; cin >> q;
        if (q == 0) {
            int s, t, X;
            cin >> s >> t >> X; --s, --t;
            fw.add(s, X);
            fw.add(t+1, -X);
        } else {
            int i; cin >> i; --i;
            cout << fw.sum(i+1) << endl;
        }
    }
}
