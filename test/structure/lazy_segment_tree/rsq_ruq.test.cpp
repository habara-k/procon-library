#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I"

#include "../../../lib/structure/lazy_segment_tree.cpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    LazySegmentTree<LL> rsq_ruq(
            N, 0, numeric_limits<LL>::max(),
            [](LL a, LL b){ return a + b; },
            [](LL a, LL b, int w){ return b*w; },
            [](LL a, LL b){ return b; }
            );

    while (Q--) {
        int C; cin >> C;
        if (C == 0) {
            int S, T; LL X;
            cin >> S >> T >> X;
            rsq_ruq.update(S, T+1, X);
        } else {
            int S, T;
            cin >> S >> T;
            cout << rsq_ruq.query(S, T+1) << endl;
        }
    }
}
