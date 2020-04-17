#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D"

#include "../../../lib/structure/dual_segment_tree.cpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    DualSegmentTree<int> ruq(
            N,
            [](int64_t a, int64_t b){ return b; },
            numeric_limits<int>::max()
            );

    while (Q--) {
        int C; cin >> C;
        if (C == 0) {
            int s, t, x;
            cin >> s >> t >> x;
            ruq.update(s, t+1, x);
        } else {
            int i;
            cin >> i;
            cout << ruq[i] << endl;
        }
    }
}
