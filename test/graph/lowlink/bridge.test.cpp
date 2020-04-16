#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_3_B"

#include "../../../lib/graph/lowlink.cpp"

int main()
{
    int V, E; cin >> V >> E;
    vector<vector<int>> G(V);
    for (int i = 0; i < E; ++i) {
        int s, t; cin >> s >> t;
        G[s].push_back(t);
        G[t].push_back(s);
    }
    LowLink lowlink(G);

    lowlink.build();

    sort(lowlink.bridges.begin(), lowlink.bridges.end());
    for (const auto& p : lowlink.bridges) {
        printf("%d %d\n", p.first, p.second);
    }

    return 0;
}
