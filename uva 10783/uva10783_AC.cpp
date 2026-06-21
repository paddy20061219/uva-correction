#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int a, b;
        cin >> a >> b;

        int sum = 0;

        for (int i = a; i <= b; i++) {
            if (i % 2 == 1) {
                sum += i;
            }
        }

        cout << "Case " << tc << ": " << sum << endl;
    }

    return 0;
}
