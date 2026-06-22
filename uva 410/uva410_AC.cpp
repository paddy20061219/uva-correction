#include <bits/stdc++.h>
using namespace std;

int main() {
    int c, s;
    int tc = 1;

    while (cin >> c >> s) {
        vector<int> specimens(2 * c, 0);

        int total = 0;

        for (int i = 0; i < s; i++) {
            cin >> specimens[i];
            total += specimens[i];
        }

        sort(specimens.begin(), specimens.end());

        double avg = (double)total / c;
        double imbalance = 0;

        cout << "Set #" << tc++ << endl;

        for (int i = 0; i < c; i++) {
            int a = specimens[i];
            int b = specimens[2 * c - 1 - i];

            cout << " " << i << ":";

            if (a != 0) {
                cout << " " << a;
            }

            if (b != 0) {
                cout << " " << b;
            }

            cout << endl;

            imbalance += fabs((a + b) - avg);
        }

        cout << fixed << setprecision(5);
        cout << "IMBALANCE = " << imbalance << endl;
        cout << endl;
    }

    return 0;
}
