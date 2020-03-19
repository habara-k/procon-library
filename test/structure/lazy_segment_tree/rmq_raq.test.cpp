#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H"

#include "../../../lib/structure/lazy_segment_tree.cpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    LazySegmentTree<int64_t> rmq_raq(
            N, numeric_limits<int64_t>::max(), 0,
            [](int64_t a, int64_t b){ return min(a, b); },
            [](int64_t a, int64_t b, int w){ return a + b; },
            [](int64_t a, int64_t b){ return a + b; }
            );
    for (int i = 0; i < N; ++i) {
        rmq_raq.set(i, 0);
    }
    rmq_raq.build();

    while (Q--) {
        int C; cin >> C;
        if (C == 0) {
            int S, T; int64_t X;
            cin >> S >> T >> X;
            rmq_raq.update(S, T+1, X);
        } else {
            int S, T;
            cin >> S >> T;
            cout << rmq_raq.query(S, T+1) << endl;
        }
    }
}