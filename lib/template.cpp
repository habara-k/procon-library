#ifndef TEMPLATE
#define TEMPLATE
#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for (int i=0; i<(n); ++i)
#define ALL(x) begin(x),end(x)
#define DUMP(x) cerr<<#x<<" = "<<(x)<<endl

struct fast_ios {
    fast_ios() {
        std::cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    };
} fast_ios_;

using ll = long long;

template<class T>
bool chmin(T &a, T b) {
    if (a > b) { a = b; return true; }
    return false;
}
template<class T>
bool chmax(T &a, T b) {
    if (a < b) { a = b; return true; }
    return false;
}

template<class T>
ostream &operator<<(ostream &os, const vector<T> &v);
template<class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p);
template<class T, class U>
ostream &operator<<(ostream &os, const map<T, U> &mp);

template<class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    os << '[';
    REP(i, v.size()) {
        if (i) os << ',';
        os << v[i];
    }
    return os << ']';
}

template<class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
    return os << '(' << p.first << ' ' << p.second << ')';
}

template<class T, class U>
ostream &operator<<(ostream &os, const map<T, U> &mp) {
    os << '{';
    for (const auto &p : mp) {
        os << p << endl;
    }
    return os << '}';
}

const int INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();

template<class T>
struct edge {
    int from, to; T cost;
    edge(int to, T cost) :
        from(-1), to(to), cost(cost) {}
    edge(int from, int to, T cost) :
        from(from), to(to), cost(cost) {}
};

#endif
