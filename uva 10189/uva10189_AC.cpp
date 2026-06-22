#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, m;
    int field = 1;

    while (cin >> n >> m) {
        if (n == 0 && m == 0) {
            break;
        }

        string g[105];

        for (int i = 0; i < n; i++) {
            cin >> g[i];
        }

        if (field > 1) {
            cout << endl;
        }

        cout << "Field #" << field++ << ":" << endl;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == '*') {
                    cout << '*';
                } else {
                    int cnt = 0;

                    for (int dx = -1; dx <= 1; dx++) {
                        for (int dy = -1; dy <= 1; dy++) {
                            if (dx == 0 && dy == 0) {
                                continue;
                            }

                            int ni = i + dx;
                            int nj = j + dy;

                            if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                                if (g[ni][nj] == '*') {
                                    cnt++;
                                }
                            }
                        }
                    }

                    cout << cnt;
                }
            }
            cout << endl;
        }
    }

    return 0;
}
