#include <iostream>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n && n != 0) {
        multiset<long long> s;

        // 我原本以為 n 就是收據數量
        // 但其實 n 是天數，後面每天還有 k 張收據
        long long x;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            cin >> x;
            s.insert(x);
        }

        if (!s.empty()) {
            ans = *s.rbegin() - *s.begin();
        }

        cout << ans << endl;
    }

    return 0;
}
