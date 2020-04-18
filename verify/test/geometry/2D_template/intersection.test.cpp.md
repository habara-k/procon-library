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
<script type="text/javascript" src="../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../assets/css/copy-button.css" />


# :heavy_check_mark: test/geometry/2D_template/intersection.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#a2c5f8fc0f05060a960f2bd934b33f5f">test/geometry/2D_template</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/geometry/2D_template/intersection.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-13 13:33:45+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_B">https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_B</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/lib/geometry/2D_template.cpp.html">lib/geometry/2D_template.cpp</a>
* :heavy_check_mark: <a href="../../../../library/lib/template.cpp.html">lib/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_B"

#include "../../../lib/geometry/2D_template.cpp"

int main()
{
    int q; cin >> q;
    while (q--) {
        double x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        Segment l1{Point{x1, y1}, Point{x2, y2}},
                l2{Point{x3, y3}, Point{x4, y4}};

        if (intersected(l1, l2)) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }

    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/geometry/2D_template/intersection.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_B"

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
const Real EPS = 1e-8, PI = acos(-1);

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
    return r * 180.0 / PI;
}

Real degree_to_radian(Real d) {
    return d * PI / 180.0;
}

Point rotate(const Point &p, Real theta) {
    return p * polar((Real)1.0, theta);
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
#line 4 "test/geometry/2D_template/intersection.test.cpp"

int main()
{
    int q; cin >> q;
    while (q--) {
        double x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        Segment l1{Point{x1, y1}, Point{x2, y2}},
                l2{Point{x3, y3}, Point{x4, y4}};

        if (intersected(l1, l2)) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }

    return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

