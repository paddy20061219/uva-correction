#include <iostream>
using namespace std;

int main() {
    int a, b;

    while (cin >> a >> b) {
        int carry = 0;

        while (a > 0 && b > 0) {
            int x = a % 10;
            int y = b % 10;

            if (x + y > 10)
                carry++;

            a = a / 10;
            b = b / 10;
        }

        cout << carry << " carry operations." << endl;
    }

    return 0;
}
