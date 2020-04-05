#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F"

#include "../../../lib/structure/randomized_binary_search_tree.cpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    RandomizedBinarySearchTree<int64_t> ruq(
            [](int64_t a, int64_t b){ return min(a,b); },
            [](int64_t a, int64_t b, int w){ return b; },
            [](int64_t a, int64_t b){ return b; },
            (1LL<<31)-1, numeric_limits<int64_t>::max());
    ruq.build(N);

    while (Q--) {
        int C; cin >> C;
        if (C == 0) {
            int S, T; int X;
            cin >> S >> T >> X;
            ruq.update(S, T+1, X);
        } else {
            int S, T;
            cin >> S >> T;
            cout << ruq.query(S, T+1) << endl;
        }
    }
}
