#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> h(n);

    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    int q;
    cin >> q;

    while (q--) {
        int x;
        cin >> x;

        // 找第一個 >= x 的位置
        int pos1 = lower_bound(h.begin(), h.end(), x) - h.begin();

        // 找第一個 > x 的位置
        int pos2 = upper_bound(h.begin(), h.end(), x) - h.begin();

        if (pos1 == 0) {
            cout << "X";
        } else {
            cout << h[pos1 - 1];
        }

        cout << " ";

        if (pos2 == n) {
            cout << "X";
        } else {
            cout << h[pos2];
        }

        cout << "\n";
    }

    return 0;
}
