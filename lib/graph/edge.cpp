#ifndef EDGE
#define EDGE
#include "../template.cpp"

template<typename T>
struct edge {
    int src, to;
    T cost;
};

using Graph = vector<vector<edge<T>>>;

#endif
