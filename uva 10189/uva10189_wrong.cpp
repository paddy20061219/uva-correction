#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[1110][1110];

int main() {
    ios::sync_with_stdio(false);
    cin.tie();

    int T;
    cin >> T;
    cin.ignore();

    while (T--) {
        string s;
        getline(cin, s);
        int n = s.size();

        for (int i = 0; i < n; i++) dp[i][i] = 1;
        for (int i = 0; i < n-1; i++) dp[i][i+1] = (s[i]==s[i+1]) ? 2 : 1;

        for (int len = 3; len <= n; len++) {
            for (int i = 0; i+len-1 < n; i++) {
                int j = i+len-1;
                if (s[i] == s[j]) dp[i][j] = dp[i+1][j-1] + 2;
                else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }

        cout << (n ? dp[0][n-1] : 0) << "\n";
    }

    return 0;
}
