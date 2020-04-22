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


# :heavy_check_mark: test/geometry/2D_template/parallel_orthogonal.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#a2c5f8fc0f05060a960f2bd934b33f5f">test/geometry/2D_template</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/geometry/2D_template/parallel_orthogonal.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-23 00:34:26+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_A">https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_A</a>


## Depends on

* :question: <a href="../../../../library/lib/geometry/2D_template.cpp.html">lib/geometry/2D_template.cpp</a>
* :question: <a href="../../../../library/lib/template.cpp.html">lib/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_A"

#include "../../../lib/geometry/2D_template.cpp"

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
#line 1 "test/geometry/2D_template/parallel_orthogonal.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_A"

#line 1 "lib/template.cpp"


#include <bits/stdc++.h>
using namespace std;

// type {{{
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using P = pair<int,int>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
// }}}


// macro {{{
#define REP(i,n) for (int i=0; i<(n); ++i)
#define RREP(i,n) for (int i=(int)(n)-1; i>=0; --i)
#define FOR(i,a,n) for (int i=(a); i<(n); ++i)
#define RFOR(i,a,n) for (int i=(int)(n)-1; i>=(a); --i)

#define SZ(x) ((int)(x).size())
#define all(x) begin(x),end(x)
// }}}


// debug {{{
#define dump(x) cerr<<#x<<" = "<<(x)<<endl
#define debug(x) cerr<<#x<<" = "<<(x)<<" (L"<<__LINE__<<")"<< endl;

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "[";
    REP (i, SZ(v)) {
        if (i) os << ", ";
        os << v[i];
    }
    return os << "]";
}

template<typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    return os << "(" << p.first << " " << p.second << ")";
}
// }}}


// chmax, chmin {{{
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
// }}}


// constants {{{
#define inf(T) (numeric_limits<T>::max() / 2)
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
// }}}


#line 2 "lib/geometry/2D_template.cpp"

using Real = double;
const Real PI = acos(-1);

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
    friend ostream& operator<<(ostream& os, const Line& l) {
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

struct Circle {
    Point p;
    Real r;
    Circle() {}
    Circle(const Point& p, Real r) : p(p), r(r) {}
};


int intersected(Circle c1, Circle c2) {
    if (c1.r < c2.r) swap(c1, c2);
    Real d = abs(c1.p - c2.p);
    if (c1.r + c2.r < d) return 4;
    if (eq(c1.r + c2.r, d)) return 3;
    if (c1.r - c2.r < d) return 2;
    if (eq(c1.r - c2.r, d)) return 1;
    return 0;
}

pair<Point,Point> crosspoint(const Circle& c, const Line& l) {
    Real h = distance(l, c.p);
    Point p = projection(l, c.p);
    if (eq(h, c.r)) return { p, p };
    Point u = l.a - l.b; u /= abs(u);
    Real d = sqrt(c.r * c.r - h * h);
    return { p + u * d, p - u * d };
}

pair<Point,Point> crosspoint(const Circle& c1, const Circle& c2) {
    Real d = abs(c2.p - c1.p), t = arg(c2.p - c1.p);
    Real a = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));
    return { c1.p + polar(c1.r, t + a),
             c1.p + polar(c1.r, t - a) };
}

pair<Point,Point> tangent(const Point& p, const Circle& c) {
    return crosspoint(c, Circle(p, sqrt(norm(p - c.p) - c.r * c.r)));
};

vector<Line> common_tangent(const Circle& c1, const Circle& c2) {
    vector<Line> lines;
    Point u = c2.p - c1.p;
    Real d = abs(u);
    if (eq(d, 0.0)) return lines;
    u /= d;
    for (Real s : { -1, 1 }) {
        Real h = (c1.r + s * c2.r) / d;
        if (eq(abs(h), 1.0)) {
            lines.emplace_back(
                    c1.p + u * h * c1.r,
                    c1.p + u * h * c1.r + rotate(u, PI / 2.0));
        } else if (abs(h) < 1) {
            Real a = acos(h);
            lines.emplace_back(
                    c1.p + u * polar(c1.r, a),
                    c2.p - s * u * polar(c2.r, a));
            lines.emplace_back(
                    c1.p + u * polar(c1.r, -a),
                    c2.p - s * u * polar(c2.r, -a));
        }
    }
    return lines;
}
#line 4 "test/geometry/2D_template/parallel_orthogonal.test.cpp"

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

