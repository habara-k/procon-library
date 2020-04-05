#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G"

#include "../../../lib/structure/randomized_binary_search_tree.cpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    RandomizedBinarySearchTree<int64_t> rsq_raq(
            [](int64_t a, int64_t b){ return a+b; },
            [](int64_t a, int64_t b, int w){ return a+b*w; },
            [](int64_t a, int64_t b){ return a+b; },
            0, 0);
    rsq_raq.build(N);

    while (Q--) {
        int C; cin >> C;
        if (C == 0) {
            int S, T; int X;
            cin >> S >> T >> X;
            rsq_raq.update(S-1, T, X);
        } else {
            int S, T;
            cin >> S >> T;
            cout << rsq_raq.query(S-1, T) << endl;
        }
    }
}
