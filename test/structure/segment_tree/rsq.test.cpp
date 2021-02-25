#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B"

#include "../../../lib/structure/segment_tree.cpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    SegmentTree<int> tr(
            N, [](int a,int b){ return a+b; }, 0);
    while (Q--) {
        int T, X, Y;
        cin >> T >> X >> Y;
        if (T == 0) tr.update(X-1, [&](int a){ return a+Y; });
        else cout << tr.query(X-1, Y) << endl;
    }
}
