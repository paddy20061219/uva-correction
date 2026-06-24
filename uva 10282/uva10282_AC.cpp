#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<string, string> dict;
    string line;

    // 先讀字典，直到空白行
    while (getline(cin, line)) {
        if (line == "") break;

        string english, foreign;
        stringstream ss(line);
        ss >> english >> foreign;

        dict[foreign] = english;
    }

    // 後面每一行都是要查的外文單字
    string word;
    while (cin >> word) {
        if (dict.count(word)) {
            cout << dict[word] << "\n";
        } else {
            cout << "eh\n";
        }
    }

    return 0;
}
