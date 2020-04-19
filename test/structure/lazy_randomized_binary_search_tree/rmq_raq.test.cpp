#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H"

#include "../../../lib/structure/lazy_randomized_binary_search_tree.cpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    LazyRandomizedBinarySearchTree<int64_t> tr(
            [](int64_t a, int64_t b){ return min(a,b); },
            [](int64_t a, int64_t b, int w){ return a+b; },
            [](int64_t a, int64_t b){ return a+b; },
            numeric_limits<int64_t>::max(), 0);
    tr.build(vector<int64_t>(N, 0));

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
