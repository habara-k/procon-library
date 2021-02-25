#include "../template.cpp"
#include "./edge.cpp"
#include "../structure/union_find.cpp"

template<typename T>
T kruskal(const vector<edge<T>> &es, int V) {

    UnionFind uf(V);
    T ret = 0;

    vector<int> ord(es.size());
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i,int j){
            return es[i].cost < es[j].cost;
            });

    for (auto i : ord) {
        auto &e = es[i];
        if (!uf.issame(e.from, e.to)) {
            ret += e.cost;
            uf.merge(e.from, e.to);
        }
    }

    return ret;
}
