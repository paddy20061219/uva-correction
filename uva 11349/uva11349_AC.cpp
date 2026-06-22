#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        char c1, c2;
        long long n;

        cin >> c1 >> c2 >> n;

        long long total = n * n;
        vector<long long> a(total);

        bool ok = true;

        for (long long i = 0; i < total; i++) {
            cin >> a[i];

            if (a[i] < 0) {
                ok = false;
            }
        }

        for (long long i = 0; i < total; i++) {
            if (a[i] != a[total - 1 - i]) {
                ok = false;
                break;
            }
        }

        cout << "Test #" << tc << ": ";

        if (ok) {
            cout << "Symmetric." << endl;
        } else {
            cout << "Non-symmetric." << endl;
        }
    }

    return 0;
}
