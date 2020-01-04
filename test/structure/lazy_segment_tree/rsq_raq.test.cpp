#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G"

#include "../../../lib/structure/lazy_segment_tree.cpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    LazySegmentTree<LL> raq_rsq(
            N, 0, 0,
            [](LL a, LL b){ return a + b; },
            [](LL a, LL b, int w){ return a + b*w; },
            [](LL a, LL b){ return a + b; }
            );

    while (Q--) {
        int C; cin >> C;
        if (C == 0) {
            int S, T; LL X;
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
