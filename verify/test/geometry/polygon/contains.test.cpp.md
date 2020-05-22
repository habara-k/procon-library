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


# :heavy_check_mark: test/geometry/polygon/contains.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#c10cfff06167ed9a9fdd4e718d03bca1">test/geometry/polygon</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/geometry/polygon/contains.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-23 00:34:26+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_C">https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_C</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/lib/geometry/2D_template.cpp.html">lib/geometry/2D_template.cpp</a>
* :heavy_check_mark: <a href="../../../../library/lib/geometry/polygon.cpp.html">lib/geometry/polygon.cpp</a>
* :heavy_check_mark: <a href="../../../../library/lib/template.cpp.html">lib/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_C"

#include "../../../lib/geometry/polygon.cpp"

int main()
{
    int n; cin >> n;
    vector<Point> p(n);
    for (int i = 0; i < n; ++i) {
        double x, y; cin >> x >> y;
        p[i] = { x, y };
    }

    int q; cin >> q;
    while (q--) {
        double x, y; cin >> x >> y;
        cout << contains(p, Point{ x, y }) << endl;
    }

    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/geometry/polygon/contains.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_C"

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
    for (int i = 0; i < n; ++i) {
        if (ccw(U[i], U[(i + 1) % n], U[(i + 2) % n]) == -1) return false;
    }
    return true;
}

const int OUT = 0,
          ON = 1,
          IN = 2;
int contains(const Polygon &U, const Point &p) {
    int in = 0;
    for (int i = 0; i < U.size(); ++i) {
        Point a = U[i] - p, b = U[(i + 1) % U.size()] - p;
        if (cross(a, b) == 0 and dot(a, b) <= 0) return ON;
        if (a.imag() > b.imag()) swap(a, b);
        if (a.imag() <= 0 and 0 < b.imag() and cross(a, b) < 0) in ^= 1;
    }
    return in ? IN : OUT;
}

vector<Point> convex_hull(vector<Point>& p, bool includeOnLine = false) {
    int n = p.size(), k = 0;
    if (n <= 2) return p;
    sort(p.begin(), p.end());
    vector<Point> ch(n * 2);
    const Real BOUND = includeOnLine ? -EPS : EPS;
    for (int i = 0; i < n; ch[k++] = p[i++]) {
        while (k >= 2 and cross(ch[k-1] - ch[k-2], p[i] - ch[k-1]) < BOUND) --k;
    }
    for (int i = n-2, t = k+1; i >= 0; ch[k++] = p[i--]) {
        while (k >= t and cross(ch[k-1] - ch[k-2], p[i] - ch[k-1]) < BOUND) --k;
    }
    ch.resize(k-1);
    return ch;
}

Real convex_diameter(const Polygon &U) {
    int n = U.size();
    int is = 0, js = 0;
    for (int i = 1; i < n; ++i) {
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
    for (int i = 0; i < U.size(); ++i) {
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
#line 4 "test/geometry/polygon/contains.test.cpp"

int main()
{
    int n; cin >> n;
    vector<Point> p(n);
    for (int i = 0; i < n; ++i) {
        double x, y; cin >> x >> y;
        p[i] = { x, y };
    }

    int q; cin >> q;
    while (q--) {
        double x, y; cin >> x >> y;
        cout << contains(p, Point{ x, y }) << endl;
    }

    return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
