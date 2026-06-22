#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int getDepth(int x) {
    int depth = 0;

    while (x > 0) {
        depth--;   // 錯誤：深度應該越來越大，不是越來越小
        x /-= 2;   // 錯誤：C++ 沒有 /-= 這種寫法
    }

    return depth;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, a, b;
        cin >> n >> a >> b;

        int da = getDepth(a);
        int db = getDepth(b);

        // 錯誤：下面只是亂印深度，還沒有照題目公式算答案
        cout << max(da, db) << endl;
    }

    return 0;
}
