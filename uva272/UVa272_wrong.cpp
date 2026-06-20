#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;

    while (cin >> s) {
        bool open = true;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '"') {
                if (open)
                    cout << "''";
                else
                    cout << "``";

                open = !open;
            } else {
                cout << s[i];
            }
        }

        cout << endl;
    }

    return 0;
}
