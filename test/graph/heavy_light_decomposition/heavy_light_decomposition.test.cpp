#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_E"

#include "../../../lib/graph/heavy_light_decomposition.cpp"
#include "../../../lib/structure/lazy_segment_tree.cpp"

int main()
{
    int n; cin >> n;
    vector<vector<int>> G(n);
    for (int i = 0; i < n; ++i) {
        int k; cin >> k;
        G[i].resize(k);
        for (int j = 0; j < k; ++j) {
            cin >> G[i][j];
        }
    }

    HLDecomposition hld(G);
    hld.build();

    LazySegmentTree<LL> segt(
            n,
            [](LL a,LL b){ return a+b; },
            [](LL a,LL b,int w){ return a+b*w; },
            [](LL a,LL b){ return a+b; },
            0, 0);

    int q; cin >> q;
    for (int t = 0; t < q; ++t) {
        int c; cin >> c;
        if (c == 0) {
            int v, w; cin >> v >> w;
            hld.update(0, v, [&](int a,int b){ segt.update(a,b,w); }, true);
        }
        if (c == 1) {
            int v; cin >> v;
            LL ret = hld.query(0, v,
                    [&](int a,int b){ return segt.query(a,b); },
                    [&](LL a,LL b){ return a+b; }, 0LL, true);
            cout << ret << endl;
        }
    }

    return 0;
}
