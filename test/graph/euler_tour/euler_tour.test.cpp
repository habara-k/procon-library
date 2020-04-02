#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_D"

#include "../../../lib/graph/euler_tour.cpp"
#include "../../../lib/structure/binary_indexed_tree.cpp"

int main() {
    int n; cin >> n;
    vector<vector<int>> G(n);
    for (int i = 0; i < n; ++i) {
        int k; cin >> k; G[i].resize(k);
        for (int j = 0; j < k; ++j) {
            cin >> G[i][j];
        }
    }

    EulerTour tour(G);
    tour.build(0);

    BIT<int> bit(2*n);
    int q; cin >> q;
    for (int t = 0; t < q; ++t) {
        int c; cin >> c;
        if (c == 1) {
            int v; cin >> v;
            cout << bit.sum(tour.ds[v]) << endl;
        }
        if (c == 0) {
            int v, w; cin >> v >> w;
            bit.add(tour.ds[v], w);
            bit.add(tour.us[v], -w);
        }
    }
}
