#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F"

#include "../../../lib/structure/lazy_segment_tree.cpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    LazySegmentTree<int> ruq(
            N, numeric_limits<int>::max(),
            numeric_limits<int>::max(),
            [](LL a, LL b){ return min(a, b); },
            [](LL a, LL b, int w){ return b; },
            [](LL a, LL b){ return b; }
            );

    while (Q--) {
        int C; cin >> C;
        if (C == 0) {
            int s, t, x;
            cin >> s >> t >> x;
            ruq.update(s, t+1, x);
        } else {
            int s, t;
            cin >> s >> t;
            cout << ruq.query(s, t+1) << endl;
        }
    }
}
