#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_G"
#define ERROR "1e-5"

#include "../../../lib/geometry/geo2d.cpp"
using namespace geo2d;

int main()
{
    cout << fixed << setprecision(10);

    double x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    vector<Line> lines = common_tangent(
            Circle(Point(x1, y1), r1),
            Circle(Point(x2, y2), r2));

    vector<Point> points;
    for (Line& l : lines) points.push_back(l.a);
    sort(points.begin(), points.end(), [](Point& a, Point& b){ return a < b; });

    for (Point& p : points) {
        cout << p.real() << " " << p.imag() << endl;
    }

    return 0;
}
