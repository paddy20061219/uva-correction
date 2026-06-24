#include <bits/stdc++.h>
using namespace std;

// UVa 10359 - Tiling
// AC 版本：dp[n] = dp[n-1] + 2 * dp[n-2]
// 因為答案很大，所以用 string 自己做大數加法

string addString(string a, string b) {
    string ans = "";
    int carry = 0;

    int i = a.size() - 1;
    int j = b.size() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int x = 0;
        int y = 0;

        if (i >= 0) x = a[i] - '0';
        if (j >= 0) y = b[j] - '0';

        int sum = x + y + carry;
        ans.push_back(char(sum % 10 + '0'));
        carry = sum / 10;

        i--;
        j--;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

string multiplyTwo(string s) {
    return addString(s, s);
}

int main() {
    vector<string> dp(251);

    dp[0] = "1";
    dp[1] = "1";

    for (int i = 2; i <= 250; i++) {
        dp[i] = addString(dp[i - 1], multiplyTwo(dp[i - 2]));
    }

    int n;
    while (cin >> n) {
        cout << dp[n] << endl;
    }

    return 0;
}
