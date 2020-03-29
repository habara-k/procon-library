#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_A"

#include "../../../lib/graph/re_rooting.cpp"

int main() {
    int n; cin >> n;
    vector<vector<edge<int>>> G(n);

    using P = pair<int,int>;

    ReRooting<int,P> tr(
            n,
            [](P a, P b){
                vector<int> v{a.fs,a.sc,b.fs,b.sc};
                sort(v.rbegin(),v.rend());
                return make_pair(v[0],v[1]);
                },
            [](P a, int w){
                return make_pair(a.fs+w, 0);
                },
            P{0,0});

    for (int i = 0; i < n-1; ++i) {
        int s, t, w; cin >> s >> t >> w;
        tr.add_edge(s, t, w);
    }

    int ans = 0;
    for (auto &p : tr.solve()) {
        chmax(ans, p.fs);
    }

    cout << ans << endl;
}
