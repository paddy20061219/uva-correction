#include <iostream>
using namespace std;

int main() {
    int n, b, h, w;

    while (cin >> n >> b >> h >> w) {
        int ans = b + 1;

        for (int i = 0; i < h; i++) {
            int p;
            cin >> p;

            for (int j = 0; j < w; j++) {
                int beds;
                cin >> beds;

                if (beds >= n) {
                    int cost = p * n;

                    if (cost <= b && cost < ans) {
                        ans = cost;
                    }
                }
            }
        }

        if (ans == b + 1) {
            cout << "stay home" << endl;
        } else {
            cout << ans << endl;
        }
    }

    return 0;
}
