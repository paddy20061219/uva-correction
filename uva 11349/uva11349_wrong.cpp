#include <iostream>
#include <vector>

using namespace std;

void solve(int caseNum) {
    char c1, c2;
    long long n;

    cin >> c1 >> c2 >> n;

    long long totalElements = n * n;
    vector<long long> a(totalElements);

    for (int i = 0; i < totalElements; i++) {
        cin >> a[i];
    }

    bool ok = true;

    // 錯誤：只檢查前一半是不是正數，完全沒有檢查對稱
    for (int i = 0; i < totalElements / 2; i++) {
        if (a[i] < 0) {
            ok = false;
        }
    }

    // 錯誤：中間或後半部如果是負數，這裡可能沒檢查到
    // 錯誤：UVA 11349 要檢查 a[i] == a[totalElements - 1 - i]

    if (ok) {
        cout << "Test #" << caseNum << ": Symmetric." << endl;
    } else {
        cout << "Test #" << caseNum << ": Non-symmetric." << endl;
    }
}

int main() {
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}
