#include "../template.cpp"

using Real = double;
Real EPS = 1e-8;

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
