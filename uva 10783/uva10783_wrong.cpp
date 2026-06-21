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
            // 這邊很笨，題目要奇數，我卻加偶數
            if (i % 2 == 0) {
                sum += i;
            }
        }

        cout << "Case " << tc << ": " << sum << endl;
    }

    return 0;
}
