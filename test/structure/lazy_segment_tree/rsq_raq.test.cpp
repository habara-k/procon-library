#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G"

#include "../../../lib/structure/lazy_segment_tree.cpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    LazySegmentTree<int64_t> raq_rsq(
            N, 0, 0,
            [](int64_t a, int64_t b){ return a + b; },
            [](int64_t a, int64_t b, int w){ return a + b*w; },
            [](int64_t a, int64_t b){ return a + b; }
            );

    while (Q--) {
        int C; cin >> C;
        if (C == 0) {
            int S, T; int64_t X;
            cin >> S >> T >> X;
            --S, --T;
            raq_rsq.update(S, T+1, X);
        } else {
            int S, T;
            cin >> S >> T;
            --S, --T;
            cout << raq_rsq.query(S, T+1) << endl;
        }
    }
}
