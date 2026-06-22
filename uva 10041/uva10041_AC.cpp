#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int r;
        cin >> r;

        int s[505];

        for (int i = 0; i < r; i++) {
            cin >> s[i];
        }

        sort(s, s + r);

        int mid = s[r / 2];
        int ans = 0;

        for (int i = 0; i < r; i++) {
            ans += abs(s[i] - mid);
        }

        cout << ans << endl;
    }

    return 0;
}
