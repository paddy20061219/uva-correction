#include <iostream>
using namespace std;

using ll = long long;

__int128 sumFromSToN(ll S, ll N) {
    // S + (S+1) + ... + N
    return (__int128)(S + N) * (N - S + 1) / 2;
}

int main() {
    ll S, D;

    while (cin >> S >> D) {
        ll left = S;
        ll right = S;

        // 先把右邊界變大，直到一定可以住到第 D 天
        while (sumFromSToN(S, right) < D) {
            right *= 2;
        }

        // 二分搜：找最小的 right，使得累加總和 >= D
        while (left < right) {
            ll mid = left + (right - left) / 2;

            if (sumFromSToN(S, mid) >= D) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        cout << left << endl;
    }

    return 0;
}
