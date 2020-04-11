#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B"

#include "../../../lib/structure/segment_tree.cpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    SegmentTree<int> segt(
            N, [](int a,int b){ return a+b; }, 0);
    while (Q--) {
        int T, X, Y;
        cin >> T >> X >> Y;
        if (T == 0) segt.update(X-1, [&](int a){ return a+Y; });
        else printf("%d\n", segt.query(X-1, Y));
    }
}
