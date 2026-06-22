#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int x;
        cin >> x;

        int mn = x;
        int mx = x;

        for (int i = 1; i < n; i++) {
            cin >> x;

            if (x < mn) mn = x;
            if (x > mx) mx = x;
        }

        cout << (mx - mn) * 2 << endl;
    }

    return 0;
}
