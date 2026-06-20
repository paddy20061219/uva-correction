#include <iostream>
using namespace std;

int main() {
    int a, b;

    while (cin >> a >> b) {
        if (a == 0 && b == 0)
            break;

        int carry = 0;
        int count = 0;

        while (a > 0 || b > 0) {
            int x = a % 10;
            int y = b % 10;

            int sum = x + y + carry;

            if (sum >= 10) {
                count++;
                carry = 1;
            } else {
                carry = 0;
            }

            a = a / 10;
            b = b / 10;
        }

        if (count == 0)
            cout << "No carry operation." << endl;
        else if (count == 1)
            cout << "1 carry operation." << endl;
        else
            cout << count << " carry operations." << endl;
    }

    return 0;
}
