#include <iostream>
using namespace std;

int main() {
    int i, j;

    while (cin >> i >> j) {
        int maxCycle = 0;

        for (int n = i; n <= j; n++) {
            int count = 0;

            while (n != 1) {
                if (n % 2 == 0)
                    n = n / 2;
                else
                    n = n + 1;   

                count++;
            }

            if (count > maxCycle)
                maxCycle = count;
        }

        cout << i << " " << j << " " << maxCycle << endl;
    }

    return 0;
}