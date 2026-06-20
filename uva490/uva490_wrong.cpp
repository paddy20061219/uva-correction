#include <iostream>
#include <string>
using namespace std;

int main() {
    string s[100];
    int n = 0;

    while (cin >> s[n]) {
        n++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = s[i].size() - 1; j >= 0; j--) {
            cout << s[i][j];
        }
        cout << endl;
    }

    return 0;
}
