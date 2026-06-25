#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int caseNum = 1;

    while (cin >> n) {
        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        bool ok = true;

        for (int i = 0; i < n; i++) {
            if (a[i] <= 0) {
                ok = false;
            }

            if (i > 0 && a[i] <= a[i - 1]) {
                ok = false;
            }
        }

        set<int> sums;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int sum = a[i] + a[j];

                if (sums.count(sum)) {
                    ok = false;
                }

                sums.insert(sum);
            }
        }

        cout << "Case #" << caseNum << ": ";

        if (ok) {
            cout << "It is a B2-Sequence.\n\n";
        }
        else {
            cout << "It is not a B2-Sequence.\n\n";
        }

        caseNum++;
    }

    return 0;
}
