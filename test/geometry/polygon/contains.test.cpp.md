---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/geometry/2D_template.cpp
    title: lib/geometry/2D_template.cpp
  - icon: ':heavy_check_mark:'
    path: lib/geometry/polygon.cpp
    title: lib/geometry/polygon.cpp
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_C
  bundledCode: "#line 1 \"test/geometry/polygon/contains.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_C\"\n\n#line\
    \ 1 \"lib/template.cpp\"\n\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \n// type {{{\nusing ll = long long;\nusing ull = unsigned long long;\nusing ld\
    \ = long double;\nusing P = pair<int,int>;\nusing vi = vector<int>;\nusing vll\
    \ = vector<ll>;\nusing vvi = vector<vector<int>>;\nusing vvll = vector<vector<ll>>;\n\
    // }}}\n\n\n// macro {{{\n#define REP(i,n) for (int i=0; i<(n); ++i)\n#define\
    \ RREP(i,n) for (int i=(int)(n)-1; i>=0; --i)\n#define FOR(i,a,n) for (int i=(a);\
    \ i<(n); ++i)\n#define RFOR(i,a,n) for (int i=(int)(n)-1; i>=(a); --i)\n\n#define\
    \ SZ(x) ((int)(x).size())\n#define all(x) begin(x),end(x)\n// }}}\n\n\n// debug\
    \ {{{\n#define dump(x) cerr<<#x<<\" = \"<<(x)<<endl\n#define debug(x) cerr<<#x<<\"\
    \ = \"<<(x)<<\" (L\"<<__LINE__<<\")\"<< endl;\n\ntemplate<typename T>\nostream&\
    \ operator<<(ostream& os, const vector<T>& v) {\n    os << \"[\";\n    REP (i,\
    \ SZ(v)) {\n        if (i) os << \", \";\n        os << v[i];\n    }\n    return\
    \ os << \"]\";\n}\n\ntemplate<typename T, typename U>\nostream& operator<<(ostream&\
    \ os, const pair<T, U>& p) {\n    return os << \"(\" << p.first << \" \" << p.second\
    \ << \")\";\n}\n// }}}\n\n\n// chmax, chmin {{{\ntemplate<class T>\nbool chmax(T&\
    \ a, const T& b) {\n    if (a < b) { a = b; return true; }\n    return false;\n\
    }\ntemplate<class T>\nbool chmin(T& a, const T& b) {\n    if (b < a) { a = b;\
    \ return true; }\n    return false;\n}\n// }}}\n\n\n// constants {{{\n#define\
    \ inf(T) (numeric_limits<T>::max() / 2)\nconst ll MOD = 1e9+7;\nconst ld EPS =\
    \ 1e-9;\n// }}}\n\n\n#line 2 \"lib/geometry/2D_template.cpp\"\n\nusing Real =\
    \ double;\nconst Real PI = acos(-1);\n\nusing Point = complex<Real>;\nnamespace\
    \ std {\n    bool operator<(const Point& a, const Point& b) {\n        if (a.real()\
    \ == b.real()) return a.imag() < b.imag();\n        return a.real() < b.real();\n\
    \    }\n}\nstruct Line {\n    Point a, b;\n    Line() {}\n    Line(const Point&\
    \ a, const Point& b) : a(a), b(b) {}\n    friend ostream& operator<<(ostream&\
    \ os, const Line& l) {\n        return os << \"[\" << l.a << \",\" << l.b << \"\
    ]\";\n    }\n};\nstruct Segment : Line {\n    Segment() = default;\n\n    Segment(const\
    \ Point& a, const Point& b) : Line(a, b) {}\n};\n\ninline bool eq(Real a, Real\
    \ b) { return abs(b - a) < EPS; }\n\nReal radian_to_degree(Real r) {\n    return\
    \ r * 180.0 / PI;\n}\n\nReal degree_to_radian(Real d) {\n    return d * PI / 180.0;\n\
    }\n\nPoint rotate(const Point &p, Real theta) {\n    return p * polar((Real)1.0,\
    \ theta);\n}\n\nReal cross(const Point& a, const Point& b) {\n    return a.real()\
    \ * b.imag() - a.imag() * b.real();\n}\n\nReal dot(const Point& a, const Point&\
    \ b) {\n    return a.real() * b.real() + a.imag() * b.imag();\n}\n\nPoint projection(const\
    \ Line& l, const Point& p) {\n    Real A = dot(l.b - l.a, p - l.a),\n        \
    \ B = dot(l.a - l.b, p - l.b);\n    return (A * l.b + B * l.a) / (A + B);\n}\n\
    \nbool parallel(const Line& l1, const Line& l2) {\n    return eq(cross(l1.a -\
    \ l1.b, l2.a - l2.b), 0.0);\n}\n\nbool orthogonal(const Line& l1, const Line&\
    \ l2) {\n    return eq(dot(l1.a - l1.b, l2.a - l2.b), 0.0);\n}\n\nconst int COUNTER_CLOCKWISE\
    \ = 1,\n          CLOCKWISE = -1,\n          ONLINE_BACK = 2,\n          ONLINE_FRONT\
    \ = -2,\n          ON_SEGMENT = 0;\nint ccw(const Point& a, Point b, Point c)\
    \ {\n    b = b - a, c = c - a;\n    if (cross(b, c) > EPS) return COUNTER_CLOCKWISE;\n\
    \    if (cross(b, c) < -EPS) return CLOCKWISE;\n    if (dot(b, c) < 0) return\
    \ ONLINE_BACK;\n    if (norm(b) < norm(c)) return ONLINE_FRONT;\n    return ON_SEGMENT;\n\
    }\n\nbool intersected(const Line& l, const Point& p) {\n    return abs(ccw(l.a,\
    \ l.b, p)) != 1;\n}\n\nbool intersected(const Segment& s, const Point& p) {\n\
    \    return ccw(s.a, s.b, p) == 0;\n}\n\nbool intersected(const Line& l, const\
    \ Segment& s) {\n    return cross(l.b - l.a, s.a - l.a) * cross(l.b - l.a, s.b\
    \ - l.a) < EPS;\n}\n\nbool intersected(const Segment& s1, const Segment& s2) {\n\
    \    return ccw(s1.a, s1.b, s2.a) * ccw(s1.a, s1.b, s2.b) <= 0 and\n         \
    \  ccw(s2.a, s2.b, s1.a) * ccw(s2.a, s2.b, s1.b) <= 0;\n}\n\nReal distance(const\
    \ Line& l, const Point& p) {\n    return abs(p - projection(l, p));\n}\n\nReal\
    \ distance(const Segment& s, const Point& p) {\n    Point r = projection(s, p);\n\
    \    if (intersected(s, r)) return abs(r - p);\n    return min(abs(s.a - p), abs(s.b\
    \ - p));\n}\n\nReal distance(const Line &l, const Segment &s) {\n    if (intersected(l,\
    \ s)) return 0;\n    return min(distance(l, s.a), distance(l, s.b));\n}\n\nReal\
    \ distance(const Segment& s1, const Segment& s2) {\n    if (intersected(s1, s2))\
    \ return 0.0;\n    return min({ distance(s1, s2.a), distance(s1, s2.b),\n    \
    \             distance(s2, s1.a), distance(s2, s1.b) });\n}\n\nPoint crosspoint(const\
    \ Line& l1, const Line& l2) {\n    Real A = cross(l2.a - l1.a, l2.b - l1.a),\n\
    \         B = cross(l2.b - l1.b, l2.a - l1.b);\n    return (A * l1.b + B * l1.a)\
    \ / (A + B);\n}\n\nstruct Circle {\n    Point p;\n    Real r;\n    Circle() {}\n\
    \    Circle(const Point& p, Real r) : p(p), r(r) {}\n};\n\n\nint intersected(Circle\
    \ c1, Circle c2) {\n    if (c1.r < c2.r) swap(c1, c2);\n    Real d = abs(c1.p\
    \ - c2.p);\n    if (c1.r + c2.r < d) return 4;\n    if (eq(c1.r + c2.r, d)) return\
    \ 3;\n    if (c1.r - c2.r < d) return 2;\n    if (eq(c1.r - c2.r, d)) return 1;\n\
    \    return 0;\n}\n\npair<Point,Point> crosspoint(const Circle& c, const Line&\
    \ l) {\n    Real h = distance(l, c.p);\n    Point p = projection(l, c.p);\n  \
    \  if (eq(h, c.r)) return { p, p };\n    Point u = l.a - l.b; u /= abs(u);\n \
    \   Real d = sqrt(c.r * c.r - h * h);\n    return { p + u * d, p - u * d };\n\
    }\n\npair<Point,Point> crosspoint(const Circle& c1, const Circle& c2) {\n    Real\
    \ d = abs(c2.p - c1.p), t = arg(c2.p - c1.p);\n    Real a = acos((c1.r * c1.r\
    \ + d * d - c2.r * c2.r) / (2 * c1.r * d));\n    return { c1.p + polar(c1.r, t\
    \ + a),\n             c1.p + polar(c1.r, t - a) };\n}\n\npair<Point,Point> tangent(const\
    \ Point& p, const Circle& c) {\n    return crosspoint(c, Circle(p, sqrt(norm(p\
    \ - c.p) - c.r * c.r)));\n};\n\nvector<Line> common_tangent(const Circle& c1,\
    \ const Circle& c2) {\n    vector<Line> lines;\n    Point u = c2.p - c1.p;\n \
    \   Real d = abs(u);\n    if (eq(d, 0.0)) return lines;\n    u /= d;\n    for\
    \ (Real s : { -1, 1 }) {\n        Real h = (c1.r + s * c2.r) / d;\n        if\
    \ (eq(abs(h), 1.0)) {\n            lines.emplace_back(\n                    c1.p\
    \ + u * h * c1.r,\n                    c1.p + u * h * c1.r + rotate(u, PI / 2.0));\n\
    \        } else if (abs(h) < 1) {\n            Real a = acos(h);\n           \
    \ lines.emplace_back(\n                    c1.p + u * polar(c1.r, a),\n      \
    \              c2.p - s * u * polar(c2.r, a));\n            lines.emplace_back(\n\
    \                    c1.p + u * polar(c1.r, -a),\n                    c2.p - s\
    \ * u * polar(c2.r, -a));\n        }\n    }\n    return lines;\n}\n#line 2 \"\
    lib/geometry/polygon.cpp\"\n\nusing Polygon = vector<Point>;\n\nReal area(const\
    \ Polygon& U) {\n    Real area = 0;\n    for (int i = 0; i < U.size(); ++i) {\n\
    \        area += cross(U[i], U[(i + 1) % U.size()]);\n    }\n    return area /\
    \ 2.0;\n}\n\nbool is_convex(const Polygon &U) {\n    int n = U.size();\n    for\
    \ (int i = 0; i < n; ++i) {\n        if (ccw(U[i], U[(i + 1) % n], U[(i + 2) %\
    \ n]) == -1) return false;\n    }\n    return true;\n}\n\nconst int OUT = 0,\n\
    \          ON = 1,\n          IN = 2;\nint contains(const Polygon &U, const Point\
    \ &p) {\n    int in = 0;\n    for (int i = 0; i < U.size(); ++i) {\n        Point\
    \ a = U[i] - p, b = U[(i + 1) % U.size()] - p;\n        if (cross(a, b) == 0 and\
    \ dot(a, b) <= 0) return ON;\n        if (a.imag() > b.imag()) swap(a, b);\n \
    \       if (a.imag() <= 0 and 0 < b.imag() and cross(a, b) < 0) in ^= 1;\n   \
    \ }\n    return in ? IN : OUT;\n}\n\nvector<Point> convex_hull(vector<Point>&\
    \ p, bool includeOnLine = false) {\n    int n = p.size(), k = 0;\n    if (n <=\
    \ 2) return p;\n    sort(p.begin(), p.end());\n    vector<Point> ch(n * 2);\n\
    \    const Real BOUND = includeOnLine ? -EPS : EPS;\n    for (int i = 0; i < n;\
    \ ch[k++] = p[i++]) {\n        while (k >= 2 and cross(ch[k-1] - ch[k-2], p[i]\
    \ - ch[k-1]) < BOUND) --k;\n    }\n    for (int i = n-2, t = k+1; i >= 0; ch[k++]\
    \ = p[i--]) {\n        while (k >= t and cross(ch[k-1] - ch[k-2], p[i] - ch[k-1])\
    \ < BOUND) --k;\n    }\n    ch.resize(k-1);\n    return ch;\n}\n\nReal convex_diameter(const\
    \ Polygon &U) {\n    int n = U.size();\n    int is = 0, js = 0;\n    for (int\
    \ i = 1; i < n; ++i) {\n        if (U[i].imag() > U[is].imag()) is = i;\n    \
    \    if (U[i].imag() < U[js].imag()) js = i;\n    }\n    Real maxnorm = norm(U[is]\
    \ - U[js]);\n\n    int i = is, j = js;\n    do {\n        if (cross(U[(i+1) %\
    \ n] - U[i], U[(j+1) % n] - U[j]) >= 0) {\n            j = (j+1) % n;\n      \
    \  } else {\n            i = (i+1) % n;\n        }\n        if (norm(U[i] - U[j])\
    \ > maxnorm) {\n            maxnorm = norm(U[i] - U[j]);\n        }\n    } while\
    \ (i != is or j != js);\n    return sqrt(maxnorm);\n}\n\nPolygon convex_cut(const\
    \ Polygon& U, const Line& l) {\n    Polygon ret;\n    for (int i = 0; i < U.size();\
    \ ++i) {\n        Point now = U[i], nxt = U[(i + 1) % U.size()];\n        if (ccw(l.a,\
    \ l.b, now) != -1) ret.push_back(now);\n        if (ccw(l.a, l.b, now) * ccw(l.a,\
    \ l.b, nxt) == -1) {\n            ret.push_back(crosspoint(Line{ now, nxt }, l));\n\
    \        }\n    }\n    return ret;\n}\n\nPolygon voronoi_cell(const Point& c,\
    \ const vector<Point>& ps, Polygon outer) {\n    for (const Point& p : ps) {\n\
    \        Point m = (p + c) / 2.0;\n        outer = convex_cut(outer,\n       \
    \             Line{ m, m + rotate(p - c, M_PI / 2) });\n    }\n    return outer;\n\
    }\n#line 4 \"test/geometry/polygon/contains.test.cpp\"\n\nint main()\n{\n    int\
    \ n; cin >> n;\n    vector<Point> p(n);\n    for (int i = 0; i < n; ++i) {\n \
    \       double x, y; cin >> x >> y;\n        p[i] = { x, y };\n    }\n\n    int\
    \ q; cin >> q;\n    while (q--) {\n        double x, y; cin >> x >> y;\n     \
    \   cout << contains(p, Point{ x, y }) << endl;\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_C\"\
    \n\n#include \"../../../lib/geometry/polygon.cpp\"\n\nint main()\n{\n    int n;\
    \ cin >> n;\n    vector<Point> p(n);\n    for (int i = 0; i < n; ++i) {\n    \
    \    double x, y; cin >> x >> y;\n        p[i] = { x, y };\n    }\n\n    int q;\
    \ cin >> q;\n    while (q--) {\n        double x, y; cin >> x >> y;\n        cout\
    \ << contains(p, Point{ x, y }) << endl;\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - lib/geometry/polygon.cpp
  - lib/geometry/2D_template.cpp
  - lib/template.cpp
  isVerificationFile: true
  path: test/geometry/polygon/contains.test.cpp
  requiredBy: []
  timestamp: '2020-04-23 00:34:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/geometry/polygon/contains.test.cpp
layout: document
redirect_from:
- /verify/test/geometry/polygon/contains.test.cpp
- /verify/test/geometry/polygon/contains.test.cpp.html
title: test/geometry/polygon/contains.test.cpp
---
