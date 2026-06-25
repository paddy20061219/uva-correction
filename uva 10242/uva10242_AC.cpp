#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

struct Point {
    double x;
    double y;
};

bool samePoint(Point a, Point b) {
    return fabs(a.x - b.x) < 1e-9 && fabs(a.y - b.y) < 1e-9;
}

int main() {
    Point p1, p2, p3, p4;

    while (cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y) {
        Point same, a, b;

        if (samePoint(p1, p3)) {
            same = p1;
            a = p2;
            b = p4;
        }
        else if (samePoint(p1, p4)) {
            same = p1;
            a = p2;
            b = p3;
        }
        else if (samePoint(p2, p3)) {
            same = p2;
            a = p1;
            b = p4;
        }
        else {
            same = p2;
            a = p1;
            b = p3;
        }

        Point ans;
        ans.x = a.x + b.x - same.x;
        ans.y = a.y + b.y - same.y;

        cout << fixed << setprecision(3) << ans.x << " " << ans.y << endl;
    }

    return 0;
}
