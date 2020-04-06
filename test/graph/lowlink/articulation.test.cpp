#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_3_A"

#include "../../../lib/graph/lowlink.cpp"

int main()
{
    int V, E; cin >> V >> E;
    LowLink lowlink(V);
    for (int i = 0; i < E; ++i) {
        int s, t; cin >> s >> t;
        lowlink.add_edge(s, t);
    }

    lowlink.build();

    sort(lowlink.articulations.begin(), lowlink.articulations.end());
    for (int v : lowlink.articulations) {
        cout << v << endl;
    }
}
