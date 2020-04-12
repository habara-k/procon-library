---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: lib/geometry/polygon.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#7096d029078708cdbb96f2303d66dee8">lib/geometry</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/geometry/polygon.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-12 12:25:45+09:00




## Depends on

* :heavy_check_mark: <a href="2D_template.cpp.html">lib/geometry/2D_template.cpp</a>
* :heavy_check_mark: <a href="../template.cpp.html">lib/template.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/geometry/polygon/area.test.cpp.html">test/geometry/polygon/area.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/geometry/polygon/contains.test.cpp.html">test/geometry/polygon/contains.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/geometry/polygon/convex_cut.test.cpp.html">test/geometry/polygon/convex_cut.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/geometry/polygon/convex_hull.test.cpp.html">test/geometry/polygon/convex_hull.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/geometry/polygon/diameter.test.cpp.html">test/geometry/polygon/diameter.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/geometry/polygon/is_convex.test.cpp.html">test/geometry/polygon/is_convex.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "./2D_template.cpp"

using Polygon = vector<Point>;

Real area(const Polygon& U) {
    Real area = 0;
    for (int i = 0; i < U.size(); ++i) {
        area += cross(U[i], U[(i + 1) % U.size()]);
    }
    return area / 2.0;
}

bool is_convex(const Polygon &U) {
    int n = U.size();
    for (int i = 0; i < n; i++) {
        if (ccw(U[i], U[(i + 1) % n], U[(i + 2) % n]) == -1) return false;
    }
    return true;
}

const int OUT = 0,
          ON = 1,
          IN = 2;
int contains(const Polygon &U, const Point &p) {
    int in = 0;
    for(int i = 0; i < U.size(); i++) {
        Point a = U[i] - p, b = U[(i + 1) % U.size()] - p;
        if (cross(a, b) == 0 and dot(a, b) <= 0) return ON;
        if (a.imag() > b.imag()) swap(a, b);
        if (a.imag() <= 0 and 0 < b.imag() and cross(a, b) < 0) in ^= 1;
    }
    return in ? IN : OUT;
}

vector<Point> convex_hull(vector<Point>& p) {
    int n = p.size(), k = 0;
    if (n <= 2) return p;
    sort(p.begin(), p.end());
    vector<Point> ch(n * 2);
    for (int i = 0; i < n; ch[k++] = p[i++]) {
        while (k >= 2 and cross(ch[k-1] - ch[k-2], p[i] - ch[k-1]) < -EPS) --k;
    }
    for (int i = n-2, t = k+1; i >= 0; ch[k++] = p[i--]) {
        while (k >= t and cross(ch[k-1] - ch[k-2], p[i] - ch[k-1]) < -EPS) --k;
    }
    ch.resize(k-1);
    return ch;
}

Real convex_diameter(const Polygon &U) {
    int n = U.size();
    int is = 0, js = 0;
    for (int i = 1; i < n; i++) {
        if (U[i].imag() > U[is].imag()) is = i;
        if (U[i].imag() < U[js].imag()) js = i;
    }
    Real maxnorm = norm(U[is] - U[js]);

    int i = is, j = js;
    do {
        if (cross(U[(i+1) % n] - U[i], U[(j+1) % n] - U[j]) >= 0) {
            j = (j+1) % n;
        } else {
            i = (i+1) % n;
        }
        if (norm(U[i] - U[j]) > maxnorm) {
            maxnorm = norm(U[i] - U[j]);
        }
    } while (i != is or j != js);
    return sqrt(maxnorm);
}

Polygon convex_cut(const Polygon& U, const Line& l) {
    Polygon ret;
    for (int i = 0; i < U.size(); i++) {
        Point now = U[i], nxt = U[(i + 1) % U.size()];
        if (ccw(l.a, l.b, now) != -1) ret.push_back(now);
        if (ccw(l.a, l.b, now) * ccw(l.a, l.b, nxt) == -1) {
            ret.push_back(crosspoint(Line{ now, nxt }, l));
        }
    }
    return ret;
}

Polygon voronoi_cell(const Point& c, const vector<Point>& ps, Polygon outer) {
    for (const Point& p : ps) {
        Point m = (p + c) / 2.0;
        outer = convex_cut(outer,
                    Line{ m, m + rotate(p - c, M_PI / 2) });
    }
    return outer;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "lib/template.cpp"


#include <bits/stdc++.h>
using namespace std;

template<class T>
bool chmax(T& a, const T& b) {
    if (a < b) { a = b; return true; }
    return false;
}
template<class T>
bool chmin(T& a, const T& b) {
    if (b < a) { a = b; return true; }
    return false;
}

// std::vector Declaration
template<typename T>
vector<T> make_v(size_t a) { return vector<T>(a); }
template<typename T, typename... Ts>
auto make_v(size_t a, Ts... ts) {
    return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}

// std::vector Declaration and Initialization
template<typename T>
vector<T> make_vector(size_t a, T x) { return vector<T>(a, x); }
template<typename T, typename U, typename... Ts>
auto make_vector(size_t a, U b, Ts... ts) {
    return vector<decltype(make_vector<T>(b,ts...))>(a, make_vector<T>(b, ts...));
}

// std::vector Input
template<typename T>
istream& operator>>(istream& is, vector<T>& v) {
    for (auto &e : v) is >> e;
    return is;
}

// std::vector Debug
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "[";
    bool a = 1;
    for (auto e : v) {
        os << (a ? "" : " ");
        os << e;
        a = 0;
    }
    os << "]";
    return os;
}

// std::array Debug
template<typename T, size_t n>
ostream& operator<<(ostream& os, const array<T, n>& v) {
    os << "[";
    bool a = 1;
    for (auto e : v) {
        os << (a ? "" : " ");
        os << e;
        a = 0;
    }
    os << "]";
    return os;
}

// std::deque Debug
template<typename T>
ostream& operator<<(ostream& os, const deque<T>& d) {
    os << "[";
    bool a = 1;
    for (auto e : d) {
        os << (a ? "" : " ");
        os << e;
        a = 0;
    }
    os << "]";
    return os;
}

// std::pair Debug
template<typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << "(" << p.first << " " << p.second << ")";
    return os;
}

// std::set Debug
template<typename T>
ostream& operator<<(ostream& os, const set<T>& st) {
    os << "{";
    bool a = 1;
    for (auto e : st) {
        os << (a ? "" : " ");
        os << e;
        a = 0;
    }
    os << "}";
    return os;
}

// std::multiset Debug
template<typename T>
ostream& operator<<(ostream& os, const multiset<T>& st) {
    os << "{";
    bool a = 1;
    for (auto e : st) {
        os << (a ? "" : " ");
        os << e;
        a = 0;
    }
    os << "}";
    return os;
}

// std::map Debug
template<typename T, typename U>
ostream& operator<<(ostream& os, const map<T, U>& mp) {
    os << "{";
    bool a = 1;
    for (auto e : mp) {
        os << (a ? "" : " ");
        os << e.first << ":" << e.second;
        a = 0;
    }
    os << "}";
    return os;
}

// std::tuple Debug
template<int N, class Tuple>
void out(ostream& os, const Tuple& t){}
template<int N, class Tuple, class H, class ...Ts>
void out(ostream& os, const Tuple& t) {
    if (N) os << " ";
    os << get<N>(t);
    out<N+1,Tuple,Ts...>(os, t);
}
template<class ...Ts>
ostream& operator<<(ostream& os, const tuple<Ts...>& t) {
    os << "(";
    out<0,tuple<Ts...>,Ts...>(os, t);
    os << ")";
    return os;
}

// Debug
#define DUMP(x) cerr<<#x<<" = "<<(x)<<endl

// Weighted edge
template<typename T>
struct edge {
    int src, to;
    T cost;

    edge() {}
    edge(int to, T cost) : src(-1), to(to), cost(cost) {}
    edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

    friend ostream& operator<<(ostream& os, const edge& e) {
        return os << "(" << e.src << "->" << e.to << ":" << e.cost << ")";
    }
};

using LL = int64_t;

#define fs first
#define sc second

const int64_t MOD = 1e9+7;

#line 2 "lib/geometry/2D_template.cpp"

using Real = double;
Real EPS = 1e-8;

using Point = complex<Real>;
namespace std {
    bool operator<(const Point& a, const Point& b) {
        if (a.real() == b.real()) return a.imag() < b.imag();
        return a.real() < b.real();
    }
}
struct Line {
    Point a, b;
    Line() {}
    Line(const Point& a, const Point& b) : a(a), b(b) {}
    friend ostream& operator<<(ostream& os, Line& l) {
        return os << "[" << l.a << "," << l.b << "]";
    }
};
struct Segment : Line {
    Segment() = default;

    Segment(const Point& a, const Point& b) : Line(a, b) {}
};

inline bool eq(Real a, Real b) { return abs(b - a) < EPS; }

Real radian_to_degree(Real r) {
    return r * 180.0 / M_PI;
}

Real degree_to_radian(Real d) {
    return d * M_PI / 180.0;
}

Point rotate(const Point &p, Real theta) {
    return p * polar(1., theta);
}

Real cross(const Point& a, const Point& b) {
    return a.real() * b.imag() - a.imag() * b.real();
}

Real dot(const Point& a, const Point& b) {
    return a.real() * b.real() + a.imag() * b.imag();
}

Point projection(const Line& l, const Point& p) {
    Real A = dot(l.b - l.a, p - l.a),
         B = dot(l.a - l.b, p - l.b);
    return (A * l.b + B * l.a) / (A + B);
}

bool parallel(const Line& l1, const Line& l2) {
    return eq(cross(l1.a - l1.b, l2.a - l2.b), 0.0);
}

bool orthogonal(const Line& l1, const Line& l2) {
    return eq(dot(l1.a - l1.b, l2.a - l2.b), 0.0);
}

const int COUNTER_CLOCKWISE = 1,
          CLOCKWISE = -1,
          ONLINE_BACK = 2,
          ONLINE_FRONT = -2,
          ON_SEGMENT = 0;
int ccw(const Point& a, Point b, Point c) {
    b = b - a, c = c - a;
    if (cross(b, c) > EPS) return COUNTER_CLOCKWISE;
    if (cross(b, c) < -EPS) return CLOCKWISE;
    if (dot(b, c) < 0) return ONLINE_BACK;
    if (norm(b) < norm(c)) return ONLINE_FRONT;
    return ON_SEGMENT;
}

bool intersected(const Line& l, const Point& p) {
    return abs(ccw(l.a, l.b, p)) != 1;
}

bool intersected(const Segment& s, const Point& p) {
    return ccw(s.a, s.b, p) == 0;
}

bool intersected(const Line& l, const Segment& s) {
    return cross(l.b - l.a, s.a - l.a) * cross(l.b - l.a, s.b - l.a) < EPS;
}

bool intersected(const Segment& s1, const Segment& s2) {
    return ccw(s1.a, s1.b, s2.a) * ccw(s1.a, s1.b, s2.b) <= 0 and
           ccw(s2.a, s2.b, s1.a) * ccw(s2.a, s2.b, s1.b) <= 0;
}

Real distance(const Line& l, const Point& p) {
    return abs(p - projection(l, p));
}

Real distance(const Segment& s, const Point& p) {
    Point r = projection(s, p);
    if (intersected(s, r)) return abs(r - p);
    return min(abs(s.a - p), abs(s.b - p));
}

Real distance(const Line &l, const Segment &s) {
    if (intersected(l, s)) return 0;
    return min(distance(l, s.a), distance(l, s.b));
}

Real distance(const Segment& s1, const Segment& s2) {
    if (intersected(s1, s2)) return 0.0;
    return min({ distance(s1, s2.a), distance(s1, s2.b),
                 distance(s2, s1.a), distance(s2, s1.b) });
}

Point crosspoint(const Line& l1, const Line& l2) {
    Real A = cross(l2.a - l1.a, l2.b - l1.a),
         B = cross(l2.b - l1.b, l2.a - l1.b);
    return (A * l1.b + B * l1.a) / (A + B);
}
#line 2 "lib/geometry/polygon.cpp"

using Polygon = vector<Point>;

Real area(const Polygon& U) {
    Real area = 0;
    for (int i = 0; i < U.size(); ++i) {
        area += cross(U[i], U[(i + 1) % U.size()]);
    }
    return area / 2.0;
}

bool is_convex(const Polygon &U) {
    int n = U.size();
    for (int i = 0; i < n; i++) {
        if (ccw(U[i], U[(i + 1) % n], U[(i + 2) % n]) == -1) return false;
    }
    return true;
}

const int OUT = 0,
          ON = 1,
          IN = 2;
int contains(const Polygon &U, const Point &p) {
    int in = 0;
    for(int i = 0; i < U.size(); i++) {
        Point a = U[i] - p, b = U[(i + 1) % U.size()] - p;
        if (cross(a, b) == 0 and dot(a, b) <= 0) return ON;
        if (a.imag() > b.imag()) swap(a, b);
        if (a.imag() <= 0 and 0 < b.imag() and cross(a, b) < 0) in ^= 1;
    }
    return in ? IN : OUT;
}

vector<Point> convex_hull(vector<Point>& p) {
    int n = p.size(), k = 0;
    if (n <= 2) return p;
    sort(p.begin(), p.end());
    vector<Point> ch(n * 2);
    for (int i = 0; i < n; ch[k++] = p[i++]) {
        while (k >= 2 and cross(ch[k-1] - ch[k-2], p[i] - ch[k-1]) < -EPS) --k;
    }
    for (int i = n-2, t = k+1; i >= 0; ch[k++] = p[i--]) {
        while (k >= t and cross(ch[k-1] - ch[k-2], p[i] - ch[k-1]) < -EPS) --k;
    }
    ch.resize(k-1);
    return ch;
}

Real convex_diameter(const Polygon &U) {
    int n = U.size();
    int is = 0, js = 0;
    for (int i = 1; i < n; i++) {
        if (U[i].imag() > U[is].imag()) is = i;
        if (U[i].imag() < U[js].imag()) js = i;
    }
    Real maxnorm = norm(U[is] - U[js]);

    int i = is, j = js;
    do {
        if (cross(U[(i+1) % n] - U[i], U[(j+1) % n] - U[j]) >= 0) {
            j = (j+1) % n;
        } else {
            i = (i+1) % n;
        }
        if (norm(U[i] - U[j]) > maxnorm) {
            maxnorm = norm(U[i] - U[j]);
        }
    } while (i != is or j != js);
    return sqrt(maxnorm);
}

Polygon convex_cut(const Polygon& U, const Line& l) {
    Polygon ret;
    for (int i = 0; i < U.size(); i++) {
        Point now = U[i], nxt = U[(i + 1) % U.size()];
        if (ccw(l.a, l.b, now) != -1) ret.push_back(now);
        if (ccw(l.a, l.b, now) * ccw(l.a, l.b, nxt) == -1) {
            ret.push_back(crosspoint(Line{ now, nxt }, l));
        }
    }
    return ret;
}

Polygon voronoi_cell(const Point& c, const vector<Point>& ps, Polygon outer) {
    for (const Point& p : ps) {
        Point m = (p + c) / 2.0;
        outer = convex_cut(outer,
                    Line{ m, m + rotate(p - c, M_PI / 2) });
    }
    return outer;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

