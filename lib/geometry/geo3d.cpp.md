---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/template.cpp\"\n\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n#define REP(i,n) for (int i=0; i<(n); ++i)\n#define ALL(x)\
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
    \ cost(cost) {}\n};\n\n\n#line 2 \"lib/geometry/geo3d.cpp\"\n\nnamespace geo3d\
    \ {\n\nusing Real = double;\nconst Real PI = acos(-1);\nconst EPS = 1e-9;\n\n\
    struct Point3D {\n    double x, y, z;\n    Point3D() {}\n    Point3D(double x,\
    \ double y, double z) : x(x), y(y), z(z) {}\n    Point3D operator+(const Point3D&\
    \ b) const {\n        return Point3D(x + b.x, y + b.y, z + b.z);\n    }\n    Point3D\
    \ operator-(const Point3D& b) const {\n        return Point3D(x - b.x, y - b.y,\
    \ z - b.z);\n    }\n    friend double norm(const Point3D& p) {\n        return\
    \ p.x * p.x + p.y * p.y + p.z * p.z;\n    };\n    friend double abs(const Point3D&\
    \ p) { return sqrt(norm(p)); }\n\n    friend ostream &operator<<(ostream &os,\
    \ Point3D &p) {\n        return os << \"(\" << p.x << \",\" << p.y << \",\" <<\
    \ p.z << \")\";\n    }\n    friend istream &operator>>(istream &is, Point3D &p)\
    \ {\n        return is >> p.x >> p.y >> p.z;\n    }\n};\nstruct Segment3D {\n\
    \    Point3D a, b;\n    Segment3D() {}\n    Segment3D(const Point3D& a, const\
    \ Point3D& b) : a(a), b(b) {}\n    friend ostream &operator<<(ostream &os, Segment3D\
    \ &l) {\n        return os << \"[\" << l.a << \",\" << l.b << \"]\";\n    }\n\
    \    friend istream &operator>>(istream &is, Segment3D &l) {\n        return is\
    \ >> l.a >> l.b;\n    }\n};\n\ninline bool eq(Real a, Real b) { return abs(b -\
    \ a) < EPS; }\n\ndouble dot(const Point3D &a, const Point3D &b) {\n    return\
    \ a.x * b.x + a.y * b.y + a.z * b.z;\n}\n\nPoint3D cross(const Point3D &a, const\
    \ Point3D &b) {\n    double x = a.y * b.z - a.z * b.y,\n           y = a.z * b.x\
    \ - a.x * b.z,\n           z = a.x * b.y - a.y * b.x;\n    return Point3D(x, y,\
    \ z);\n}\n\nbool parallel(\n        const Point3D &a1, const Point3D &a2,\n  \
    \      const Point3D &b1, const Point3D &b2) {\n    return eq(abs(cross(a1-b1,\
    \ a2-b2)), 0.);\n}\n\nbool parallel(const Segment3D& l1, const Segment3D& l2)\
    \ {\n    return parallel(l1.a, l1.b, l2.a, l2.b);\n}\n\ndouble distance(const\
    \ Segment3D &l, const Point3D &p) {\n    if (dot(l.b - l.a, p - l.a) < EPS) return\
    \ abs(p - l.a);\n    if (dot(l.a - l.b, p - l.b) < EPS) return abs(p - l.b);\n\
    \    return abs(cross(l.b - l.a, p - l.a)) / abs(l.b - l.a);\n}\n\n} // namespace\
    \ geo3d\n"
  code: "#include \"../template.cpp\"\n\nnamespace geo3d {\n\nusing Real = double;\n\
    const Real PI = acos(-1);\nconst EPS = 1e-9;\n\nstruct Point3D {\n    double x,\
    \ y, z;\n    Point3D() {}\n    Point3D(double x, double y, double z) : x(x), y(y),\
    \ z(z) {}\n    Point3D operator+(const Point3D& b) const {\n        return Point3D(x\
    \ + b.x, y + b.y, z + b.z);\n    }\n    Point3D operator-(const Point3D& b) const\
    \ {\n        return Point3D(x - b.x, y - b.y, z - b.z);\n    }\n    friend double\
    \ norm(const Point3D& p) {\n        return p.x * p.x + p.y * p.y + p.z * p.z;\n\
    \    };\n    friend double abs(const Point3D& p) { return sqrt(norm(p)); }\n\n\
    \    friend ostream &operator<<(ostream &os, Point3D &p) {\n        return os\
    \ << \"(\" << p.x << \",\" << p.y << \",\" << p.z << \")\";\n    }\n    friend\
    \ istream &operator>>(istream &is, Point3D &p) {\n        return is >> p.x >>\
    \ p.y >> p.z;\n    }\n};\nstruct Segment3D {\n    Point3D a, b;\n    Segment3D()\
    \ {}\n    Segment3D(const Point3D& a, const Point3D& b) : a(a), b(b) {}\n    friend\
    \ ostream &operator<<(ostream &os, Segment3D &l) {\n        return os << \"[\"\
    \ << l.a << \",\" << l.b << \"]\";\n    }\n    friend istream &operator>>(istream\
    \ &is, Segment3D &l) {\n        return is >> l.a >> l.b;\n    }\n};\n\ninline\
    \ bool eq(Real a, Real b) { return abs(b - a) < EPS; }\n\ndouble dot(const Point3D\
    \ &a, const Point3D &b) {\n    return a.x * b.x + a.y * b.y + a.z * b.z;\n}\n\n\
    Point3D cross(const Point3D &a, const Point3D &b) {\n    double x = a.y * b.z\
    \ - a.z * b.y,\n           y = a.z * b.x - a.x * b.z,\n           z = a.x * b.y\
    \ - a.y * b.x;\n    return Point3D(x, y, z);\n}\n\nbool parallel(\n        const\
    \ Point3D &a1, const Point3D &a2,\n        const Point3D &b1, const Point3D &b2)\
    \ {\n    return eq(abs(cross(a1-b1, a2-b2)), 0.);\n}\n\nbool parallel(const Segment3D&\
    \ l1, const Segment3D& l2) {\n    return parallel(l1.a, l1.b, l2.a, l2.b);\n}\n\
    \ndouble distance(const Segment3D &l, const Point3D &p) {\n    if (dot(l.b - l.a,\
    \ p - l.a) < EPS) return abs(p - l.a);\n    if (dot(l.a - l.b, p - l.b) < EPS)\
    \ return abs(p - l.b);\n    return abs(cross(l.b - l.a, p - l.a)) / abs(l.b -\
    \ l.a);\n}\n\n} // namespace geo3d\n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/geometry/geo3d.cpp
  requiredBy: []
  timestamp: '2021-02-25 17:59:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/geometry/geo3d.cpp
layout: document
redirect_from:
- /library/lib/geometry/geo3d.cpp
- /library/lib/geometry/geo3d.cpp.html
title: lib/geometry/geo3d.cpp
---
