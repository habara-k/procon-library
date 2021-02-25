#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_E"

#include "../../../lib/tree/hld.cpp"
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

    LazySegmentTree<int64_t> segt(
            n,
            [](int64_t a,int64_t b){ return a+b; },
            [](int64_t a,int64_t b,int w){ return a+b*w; },
            [](int64_t a,int64_t b){ return a+b; },
            0, 0);

    int q; cin >> q;
    for (int t = 0; t < q; ++t) {
        int c; cin >> c;
        if (c == 0) {
            int v, w; cin >> v >> w;
            hld.update(0, v, [&](int64_t a,int64_t b){ segt.update(a,b,w); }, true);
        }
        if (c == 1) {
            int v; cin >> v;
            int64_t ret = hld.query(0, v,
                    [&](int64_t a,int64_t b){ return segt.query(a,b); },
                    [&](int64_t a,int64_t b){ return a+b; }, 0LL, true);
            cout << ret << endl;
        }
    }

    return 0;
}
