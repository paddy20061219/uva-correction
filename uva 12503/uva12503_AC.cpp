#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> move(n + 1);
        int pos = 0;

        for (int i = 1; i <= n; i++) {
            string s;
            cin >> s;

            if (s == "LEFT") {
                move[i] = -1;
            }
            else if (s == "RIGHT") {
                move[i] = 1;
            }
            else {
                string as_word;
                int x;
                cin >> as_word >> x;

                move[i] = move[x];
            }

            pos += move[i];
        }

        cout << pos << endl;
    }

    return 0;
}
