#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n;
    int caseNum = 1;

    while (cin >> n) {
        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        set<int> s;

        // 我原本只檢查數字有沒有重複
        // 但 B2-Sequence 要檢查的是「兩兩相加的和」有沒有重複
        bool ok = true;

        for (int i = 0; i < n; i++) {
            if (s.count(a[i])) {
                ok = false;
            }
            s.insert(a[i]);
        }

        cout << "Case #" << caseNum << ": ";

        if (ok) {
            cout << "It is a B2-Sequence.\n\n";
        }
        else {
            cout << "It is not a B2-Sequence.\n\n";
        }

        caseNum++;
    }

    return 0;
}
