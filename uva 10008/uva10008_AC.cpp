#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();

    vector<int> cnt(26, 0);

    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);

        for (int j = 0; j < (int)line.size(); j++) {
            if (isalpha(line[j])) {
                char c = toupper(line[j]);
                cnt[c - 'A']++;
            }
        }
    }

    vector<pair<char, int> > ans;

    for (int i = 0; i < 26; i++) {
        if (cnt[i] > 0) {
            ans.push_back(make_pair(char('A' + i), cnt[i]));
        }
    }

    sort(ans.begin(), ans.end(), [](pair<char, int> a, pair<char, int> b) {
        if (a.second != b.second) return a.second > b.second;
        return a.first < b.first;
    });

    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }

    return 0;
}
