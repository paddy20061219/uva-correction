#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string s;
    bool first = true;

    while (getline(cin, s)) {
        int cnt[128] = {0};

        for (int i = 0; i < (int)s.length(); i++) {
            cnt[(int)s[i]]++;
        }

        vector<pair<int, int> > ans;

        for (int i = 0; i < 128; i++) {
            if (cnt[i] > 0) {
                ans.push_back(make_pair(i, cnt[i]));
            }
        }

        sort(ans.begin(), ans.end(), [](pair<int, int> a, pair<int, int> b) {
            if (a.second != b.second) return a.second < b.second;
            return a.first > b.first;
        });

        if (!first) {
            cout << endl;
        }
        first = false;

        for (int i = 0; i < (int)ans.size(); i++) {
            cout << ans[i].first << " " << ans[i].second << endl;
        }
    }

    return 0;
}
