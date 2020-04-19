#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I"

#include "../../../lib/structure/lazy_randomized_binary_search_tree.cpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    LazyRandomizedBinarySearchTree<int64_t> tr(
            [](int64_t a, int64_t b){ return a + b; },
            [](int64_t a, int64_t b, int w){ return b*w; },
            [](int64_t a, int64_t b){ return b; },
            0, numeric_limits<int64_t>::max());
    tr.build(N);

    while (Q--) {
        int C; cin >> C;
        if (C == 0) {
            int S, T; int X;
            cin >> S >> T >> X;
            tr.update(S, T+1, X);
        } else {
            int S, T;
            cin >> S >> T;
            cout << tr.query(S, T+1) << endl;
        }
    }
}
