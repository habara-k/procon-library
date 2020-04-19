#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G"

#include "../../../lib/structure/lazy_randomized_binary_search_tree.cpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    LazyRandomizedBinarySearchTree<int64_t> tr(
            [](int64_t a, int64_t b){ return a+b; },
            [](int64_t a, int64_t b, int w){ return a+b*w; },
            [](int64_t a, int64_t b){ return a+b; },
            0, 0);
    tr.build(N);

    while (Q--) {
        int C; cin >> C;
        if (C == 0) {
            int S, T; int X;
            cin >> S >> T >> X;
            tr.update(S-1, T, X);
        } else {
            int S, T;
            cin >> S >> T;
            cout << tr.query(S-1, T) << endl;
        }
    }
}
