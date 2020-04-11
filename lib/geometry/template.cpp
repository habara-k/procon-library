#include "../template.cpp"

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
