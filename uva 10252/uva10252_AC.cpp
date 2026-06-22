#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;

    while (getline(cin, a)) {
        getline(cin, b);

        int cntA[26] = {0};
        int cntB[26] = {0};

        for (int i = 0; i < a.size(); i++) {
            if (a[i] >= 'a' && a[i] <= 'z') {
                cntA[a[i] - 'a']++;
            }
        }

        for (int i = 0; i < b.size(); i++) {
            if (b[i] >= 'a' && b[i] <= 'z') {
                cntB[b[i] - 'a']++;
            }
        }

        for (int i = 0; i < 26; i++) {
            int common = min(cntA[i], cntB[i]);

            for (int j = 0; j < common; j++) {
                cout << char('a' + i);
            }
        }

        cout << endl;
    }

    return 0;
}
