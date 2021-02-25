#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_D"

#include "../../../lib/tree/euler_tour.cpp"
#include "../../../lib/structure/fenwick_tree.cpp"

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

    fenwick_tree<int> fw(2*n);
    int q; cin >> q;
    while (q--) {
        int c; cin >> c;
        if (c == 1) {
            int v; cin >> v;
            cout << fw.sum(0, tour.ds[v]+1) << endl;
        }
        if (c == 0) {
            int v, w; cin >> v >> w;
            fw.add(tour.ds[v], w);
            fw.add(tour.us[v], -w);
        }
    }
}
