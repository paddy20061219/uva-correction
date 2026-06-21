#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    while (getline(cin, s)) {
        int count[256] = {0};

        for (int i = 0; i < s.length(); i++) {
            count[(int)s[i]]++;
        }

        for (int i = 1; i <= 256; i++) {
            for (int j = 0; j < 256; j++) {
                if (count[j] == i) {
                    cout << j << " " << count[j] << endl;
                }
            }
        }
        cout << endl;
    }
    return 0;
}
