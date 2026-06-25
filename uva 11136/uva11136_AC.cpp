#include <iostream>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    while (cin >> n && n != 0) {
        multiset<long long> bills;
        long long total = 0;

        for (int day = 0; day < n; day++) {
            int k;
            cin >> k;

            for (int i = 0; i < k; i++) {
                long long x;
                cin >> x;
                bills.insert(x);
            }

            auto small = bills.begin();
            auto big = prev(bills.end());

            total += *big - *small;

            bills.erase(big);
            bills.erase(small);
        }

        cout << total << "\n";
    }

    return 0;
}
