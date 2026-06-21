#include <iostream>
using namespace std;

int main() {
    long long S, D;

    while (cin >> S >> D) {
        // 錯誤想法：以為答案就是 S + D
        // 這完全沒有把每天累加的人數算進去
        cout << S + D << endl;
    }

    return 0;
}
