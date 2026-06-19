#include <iostream>
using namespace std;

int cycleLength(long long n) {
    int count = 1;

    while (n != 1) {
        if (n % 2 == 1)
            n = 3 * n + 1;
        else
            n = n / 2;

        count++;
    }

    return count;
}

int main() {
    int i, j;

    while (cin >> i >> j) {
        int start = min(i, j);
        int end = max(i, j);

        int maxCycle = 0;

        for (int n = start; n <= end; n++) {
            int len = cycleLength(n);

            if (len > maxCycle)
                maxCycle = len;
        }

        cout << i << " " << j << " " << maxCycle << endl;
    }

    return 0;
}