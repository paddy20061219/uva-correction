#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int p, q, r, s, t, u;

double f(double x) {
    return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

int main() {
    while (cin >> p >> q >> r >> s >> t >> u) {
        double left = 0.0;
        double right = 1.0;

        double fLeft = f(left);
        double fRight = f(right);

        if (fLeft * fRight > 0) {
            cout << "No solution" << endl;
            continue;
        }

        for (int i = 0; i < 100; i++) {
            double mid = (left + right) / 2.0;

            if (f(mid) > 0) {
                left = mid;
            } else {
                right = mid;
            }
        }

        cout << fixed << setprecision(4) << (left + right) / 2.0 << endl;
    }

    return 0;
}
