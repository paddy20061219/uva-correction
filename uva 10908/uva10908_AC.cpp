#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int m, n, q;
        cin >> m >> n >> q;

        vector<string> grid(m);
        for (int i = 0; i < m; i++) {
            cin >> grid[i];
        }

        cout << m << " " << n << " " << q << "\n";

        while (q--) {
            int r, c;
            cin >> r >> c;

            char center = grid[r][c];
            int ans = 1;

            while (true) {
                int nextSize = ans + 2;
                int half = nextSize / 2;

                int top = r - half;
                int bottom = r + half;
                int left = c - half;
                int right = c + half;

                if (top < 0 || bottom >= m || left < 0 || right >= n) {
                    break;
                }

                bool ok = true;

                for (int i = top; i <= bottom; i++) {
                    for (int j = left; j <= right; j++) {
                        if (grid[i][j] != center) {
                            ok = false;
                        }
                    }
                }

                if (ok) {
                    ans = nextSize;
                }
                else {
                    break;
                }
            }

            cout << ans << "\n";
        }
    }

    return 0;
}
