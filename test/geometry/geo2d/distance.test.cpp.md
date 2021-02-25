---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/geometry/geo2d.cpp
    title: lib/geometry/geo2d.cpp
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: 1e-8
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_D
  bundledCode: "#line 1 \"test/geometry/geo2d/distance.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_D\"\n#define\
    \ ERROR \"1e-8\"\n\n#line 1 \"lib/template.cpp\"\n\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#define REP(i,n) for (int i=0; i<(n); ++i)\n#define ALL(x)\
    \ begin(x),end(x)\n#define DUMP(x) cerr<<#x<<\" = \"<<(x)<<endl\n\nstruct fast_ios\
    \ {\n    fast_ios() {\n        std::cin.tie(nullptr);\n        ios::sync_with_stdio(false);\n\
    \        cout << fixed << setprecision(20);\n    };\n} fast_ios_;\n\nusing ll\
    \ = long long;\n\ntemplate<class T>\nbool chmin(T &a, T b) {\n    if (a > b) {\
    \ a = b; return true; }\n    return false;\n}\ntemplate<class T>\nbool chmax(T\
    \ &a, T b) {\n    if (a < b) { a = b; return true; }\n    return false;\n}\n\n\
    template<class T>\nostream &operator<<(ostream &os, const vector<T> &v);\ntemplate<class\
    \ T, class U>\nostream &operator<<(ostream &os, const pair<T, U> &p);\ntemplate<class\
    \ T, class U>\nostream &operator<<(ostream &os, const map<T, U> &mp);\n\ntemplate<class\
    \ T>\nostream &operator<<(ostream &os, const vector<T> &v) {\n    os << '[';\n\
    \    REP(i, v.size()) {\n        if (i) os << ',';\n        os << v[i];\n    }\n\
    \    return os << ']';\n}\n\ntemplate<class T, class U>\nostream &operator<<(ostream\
    \ &os, const pair<T, U> &p) {\n    return os << '(' << p.first << ' ' << p.second\
    \ << ')';\n}\n\ntemplate<class T, class U>\nostream &operator<<(ostream &os, const\
    \ map<T, U> &mp) {\n    os << '{';\n    for (const auto &p : mp) {\n        os\
    \ << p << endl;\n    }\n    return os << '}';\n}\n\nconst int INF = numeric_limits<int>::max();\n\
    const ll LINF = numeric_limits<ll>::max();\n\ntemplate<class T>\nstruct edge {\n\
    \    int from, to; T cost;\n    edge(int to, T cost) :\n        from(-1), to(to),\
    \ cost(cost) {}\n    edge(int from, int to, T cost) :\n        from(from), to(to),\
    \ cost(cost) {}\n};\n\n\n#line 2 \"lib/geometry/geo2d.cpp\"\n\nnamespace geo2d\
    \ {\n\nusing Real = double;\nconst Real PI = acos(-1);\nconst Real EPS = 1e-9;\n\
    \nusing Point = complex<Real>;\nbool operator<(const Point& a, const Point& b)\
    \ {\n    if (a.real() == b.real()) return a.imag() < b.imag();\n    return a.real()\
    \ < b.real();\n}\n\nstruct Line {\n    Point a, b;\n    Line() {}\n    Line(const\
    \ Point& a, const Point& b) : a(a), b(b) {}\n    friend ostream& operator<<(ostream&\
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
    \ * u * polar(c2.r, -a));\n        }\n    }\n    return lines;\n}\n\n} // namespace\
    \ geo2d\n#line 5 \"test/geometry/geo2d/distance.test.cpp\"\nusing namespace geo2d;\n\
    \nint main()\n{\n    cout << fixed << setprecision(10);\n\n    int q; cin >> q;\n\
    \    while (q--) {\n        double x1, y1, x2, y2, x3, y3, x4, y4;\n        cin\
    \ >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;\n        Segment l1{Point{x1,\
    \ y1}, Point{x2, y2}},\n                l2{Point{x3, y3}, Point{x4, y4}};\n\n\
    \        cout << distance(l1, l2) << endl;\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_D\"\
    \n#define ERROR \"1e-8\"\n\n#include \"../../../lib/geometry/geo2d.cpp\"\nusing\
    \ namespace geo2d;\n\nint main()\n{\n    cout << fixed << setprecision(10);\n\n\
    \    int q; cin >> q;\n    while (q--) {\n        double x1, y1, x2, y2, x3, y3,\
    \ x4, y4;\n        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;\n    \
    \    Segment l1{Point{x1, y1}, Point{x2, y2}},\n                l2{Point{x3, y3},\
    \ Point{x4, y4}};\n\n        cout << distance(l1, l2) << endl;\n    }\n\n    return\
    \ 0;\n}\n"
  dependsOn:
  - lib/geometry/geo2d.cpp
  - lib/template.cpp
  isVerificationFile: true
  path: test/geometry/geo2d/distance.test.cpp
  requiredBy: []
  timestamp: '2021-02-25 17:59:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/geometry/geo2d/distance.test.cpp
layout: document
redirect_from:
- /verify/test/geometry/geo2d/distance.test.cpp
- /verify/test/geometry/geo2d/distance.test.cpp.html
title: test/geometry/geo2d/distance.test.cpp
---