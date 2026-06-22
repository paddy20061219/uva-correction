#include <bits/stdc++.h>
using namespace std;

int n, m;
int c[1100];

bool simul(int cap) {
    int used = 1;
    int cur = 0;

    for (int i = 0; i < n; i++) {
        if (c[i] > cap) {
            return false;
        }

        if (cur + c[i] > cap) {
            used++;
            cur = c[i];
        } else {
            cur += c[i];
        }
    }

    return used <= m;
}

int main() {
    while (cin >> n >> m) {
        int sum = 0;
        int mx = 0;

        for (int i = 0; i < n; i++) {
            cin >> c[i];
            sum += c[i];
            mx = max(mx, c[i]);
        }

        int l = mx, r = sum;
        int ans = sum;

        while (l <= r) {
            int mid = (l + r) / 2;

            if (simul(mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
