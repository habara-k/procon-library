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


# :heavy_check_mark: test/geometry/template/parallel_orthogonal.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#a79aedaaed5c1b5c37445aecc90bb581">test/geometry/template</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/geometry/template/parallel_orthogonal.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-11 20:26:19+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_A">https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_A</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/lib/geometry/template.cpp.html">lib/geometry/template.cpp</a>
* :heavy_check_mark: <a href="../../../../library/lib/template.cpp.html">lib/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_A"

#include "../../../lib/geometry/template.cpp"

int main()
{
    int q; cin >> q;
    while (q--) {
        double x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        Segment l1{Point{x1, y1}, Point{x2, y2}},
                l2{Point{x3, y3}, Point{x4, y4}};

        if (parallel(l1, l2)) {
            cout << 2 << endl;
        } else if (orthogonal(l1, l2)) {
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
#line 1 "test/geometry/template/parallel_orthogonal.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_A"

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

#line 2 "lib/geometry/template.cpp"

using Real = double;
Real EPS = 1e-8;

// 2-dim

using Point =  complex<Real>;
struct Segment {
    Point a, b;
    Segment() {}
    Segment(const Point& a, const Point& b) : a(a), b(b) {}
    friend ostream &operator<<(ostream &os, Segment &l) {
        return os << "[" << l.a << "," << l.b << "]";
    }
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

Point projection(const Segment& l, const Point& p) {
    Real A = dot(l.b - l.a, p - l.a),
         B = dot(l.a - l.b, p - l.b);
    return (A * l.b + B * l.a) / (A + B);
}

bool parallel(
        const Point &a1, const Point &b1,
        const Point &a2, const Point &b2) {
    return eq(cross(a1-b1, a2-b2), 0.);
}

bool parallel(const Segment& l1, const Segment& l2) {
    return parallel(l1.a, l1.b, l2.a, l2.b);
}

bool orthogonal(
        const Point &a1, const Point &b1,
        const Point &a2, const Point &b2) {
    return eq(dot(a1-b1, a2-b2), 0.);
}

bool orthogonal(const Segment& l1, const Segment& l2) {
    return orthogonal(l1.a, l1.b, l2.a, l2.b);
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

bool intersected(
        const Point& a1, const Point& b1,
        const Point& a2, const Point& b2) {
    return ccw(a1, b1, a2) * ccw(a1, b1, b2) <= 0 and
           ccw(a2, b2, a1) * ccw(a2, b2, b1) <= 0;
}

bool intersected(const Segment& l1, const Segment& l2) {
    return intersected(l1.a, l1.b, l2.a, l2.b);
}

Real distance(const Segment& l, const Point& p) {
    if (dot(l.b - l.a, p - l.a) < EPS) return abs(p - l.a);
    if (dot(l.a - l.b, p - l.b) < EPS) return abs(p - l.b);
    return abs(cross(l.b - l.a, p - l.a)) / abs(l.b - l.a);
}

Real distance(const Segment& l, const Segment& m) {
    if (intersected(l, m)) return 0.;
    return min({ distance(l, m.a), distance(l, m.b),
                 distance(m, l.a), distance(m, l.b) });
}

Point crosspoint(const Segment& l, const Segment& m) {
    Real A = cross(m.a - l.a, m.b - l.a),
         B = cross(m.b - l.b, m.a - l.b);
    return (A * l.b + B * l.a) / (A + B);
}

// 3-dim

struct Point3D {
    double x, y, z;
    Point3D() {}
    Point3D(double x, double y, double z) : x(x), y(y), z(z) {}
    Point3D operator+(const Point3D& b) const {
        return Point3D(x + b.x, y + b.y, z + b.z);
    }
    Point3D operator-(const Point3D& b) const {
        return Point3D(x - b.x, y - b.y, z - b.z);
    }
    friend double norm(const Point3D& p) {
        return p.x * p.x + p.y * p.y + p.z * p.z;
    };
    friend double abs(const Point3D& p) { return sqrt(norm(p)); }

    friend ostream &operator<<(ostream &os, Point3D &p) {
        return os << "(" << p.x << "," << p.y << "," << p.z << ")";
    }
    friend istream &operator>>(istream &is, Point3D &p) {
        return is >> p.x >> p.y >> p.z;
    }
};
struct Segment3D {
    Point3D a, b;
    Segment3D() {}
    Segment3D(const Point3D& a, const Point3D& b) : a(a), b(b) {}
    friend ostream &operator<<(ostream &os, Segment3D &l) {
        return os << "[" << l.a << "," << l.b << "]";
    }
    friend istream &operator>>(istream &is, Segment3D &l) {
        return is >> l.a >> l.b;
    }
};

double dot(const Point3D &a, const Point3D &b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Point3D cross(const Point3D &a, const Point3D &b) {
    double x = a.y * b.z - a.z * b.y,
           y = a.z * b.x - a.x * b.z,
           z = a.x * b.y - a.y * b.x;
    return Point3D(x, y, z);
}

bool parallel(
        const Point3D &a1, const Point3D &a2,
        const Point3D &b1, const Point3D &b2) {
    return eq(abs(cross(a1-b1, a2-b2)), 0.);
}

bool parallel(const Segment3D& l1, const Segment3D& l2) {
    return parallel(l1.a, l1.b, l2.a, l2.b);
}

double distance(const Segment3D &l, const Point3D &p) {
    if (dot(l.b - l.a, p - l.a) < EPS) return abs(p - l.a);
    if (dot(l.a - l.b, p - l.b) < EPS) return abs(p - l.b);
    return abs(cross(l.b - l.a, p - l.a)) / abs(l.b - l.a);
}
#line 4 "test/geometry/template/parallel_orthogonal.test.cpp"

int main()
{
    int q; cin >> q;
    while (q--) {
        double x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        Segment l1{Point{x1, y1}, Point{x2, y2}},
                l2{Point{x3, y3}, Point{x4, y4}};

        if (parallel(l1, l2)) {
            cout << 2 << endl;
        } else if (orthogonal(l1, l2)) {
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

