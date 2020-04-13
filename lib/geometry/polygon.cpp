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
    for(int i = 0; i < U.size(); ++i) {
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
