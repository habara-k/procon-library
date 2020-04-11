#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I"

#include "../../../lib/structure/lazy_segment_tree.cpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    LazySegmentTree<int> rsq_ruq(
            N,
            [](int a, int b){ return a + b; },
            [](int a, int b, int w){ return b*w; },
            [](int a, int b){ return b; },
            0, numeric_limits<int>::max()
            );

    while (Q--) {
        int C; cin >> C;
        if (C == 0) {
            int S, T; int X;
            cin >> S >> T >> X;
            rsq_ruq.update(S, T+1, X);
        } else {
            int S, T;
            cin >> S >> T;
            cout << rsq_ruq.query(S, T+1) << endl;
        }
    }
}
