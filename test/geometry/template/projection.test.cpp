#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_A"

#include "../../../lib/geometry/template.cpp"

int main()
{
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    Segment l{Point{x1, y1}, Point{x2, y2}};
    int q; cin >> q;
    while (q--) {
        double x, y; cin >> x >> y;
        Point p{x, y};
        Point c = projection(l, p);
        cout << c.real() << " " << c.imag() << endl;
    }

    return 0;
}
