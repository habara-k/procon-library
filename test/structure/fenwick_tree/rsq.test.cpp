#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B"

#include "../../../lib/structure/fenwick_tree.cpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    fenwick_tree<int> fw(N+1);
    while (Q--) {
        int t; cin >> t;
        if (t == 0) {
            int i, x; cin >> i >> x; --i;
            fw.add(i, x);
        } else {
            int s, t; cin >> s >> t; --s, --t;
            cout << fw.sum(s, t+1) << endl;
        }
    }
}
