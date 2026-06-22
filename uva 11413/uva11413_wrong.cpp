#include <bits/stdc++.h>
using namespace std;

int n, m;
int c[1100];

bool simul(int cap) {
    int used = 1;
    int cur = 0;

    for (int i = 0; i < n; i++) {
        // 錯誤：完全沒有檢查 c[i] > cap 的情況
        // 錯誤：這裡故意把 cur 加成 i，不是加 c[i]
        if (cur + c[i] > cap) {
            used++;
            cur = i;
        } else {
            cur += i;
        }
    }

    // 錯誤：應該是 used <= m，這裡故意寫反
    return used >= m;
}

int main() {
    while (cin >> n >> m) {
        int sum = 0;

        for (int i = 0; i < n; i++) {
            cin >> c[i];
            sum += c[i];
        }

        int l = 0, r = sum;
        int ans = 0;

        while (l <= r) {
            int mid = (l + r) / 2;

            if (simul(mid)) {
                ans = mid;
                l = mid + 1; // 錯誤：可行時應該往左找更小容量
            } else {
                r = mid - 1;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
