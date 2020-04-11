#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A"

#include "../../../lib/structure/segment_tree.cpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    SegmentTree<int> rmq(
            N,
            [&](int a, int b){ return min(a, b); },
            numeric_limits<int>::max());
    while (Q--) {
        int T, X, Y;
        cin >> T >> X >> Y;
        if (T == 0) rmq.update(X, [&](int x){ return Y; });
        else printf("%d\n", rmq.query(X, Y + 1));
    }
}
