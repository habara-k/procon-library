#ifndef EDGE
#define EDGE
#include "../template.cpp"

template<typename T>
struct edge {
    int src, to;
    T cost;

    friend ostream& operator<<(ostream& os, const edge& e) {
        return os << "(" << e.src << "->" << e.to << ":" << e.cost << ")";
    }
};

template<typename T>
using Graph = vector<vector<edge<T>>>;

#endif
