#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A"

#include "../../../lib/graph/ford_fulkerson.cpp"

int main() {
    int V, E;
    cin >> V >> E;
    FordFulkerson<int> g(V);
    for(int i = 0; i < E; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        g.add_edge(a, b, c);
    }
    cout << g.max_flow(0, V-1) << endl;
}
