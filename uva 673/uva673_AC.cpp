#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string s;
        getline(cin, s);

        stack<char> st;
        bool ok = true;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[') {
                st.push(s[i]);
            } else if (s[i] == ')') {
                if (st.empty() || st.top() != '(') {
                    ok = false;
                    break;
                }
                st.pop();
            } else if (s[i] == ']') {
                if (st.empty() || st.top() != '[') {
                    ok = false;
                    break;
                }
                st.pop();
            }
        }

        if (!st.empty()) {
            ok = false;
        }

        if (ok) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
