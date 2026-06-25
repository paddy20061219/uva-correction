#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, int> cnt;

    string country, name;
    getline(cin, name);

    for (int i = 0; i < n; i++) {
        cin >> country;
        getline(cin, name);

        cnt[country]++;
    }

    for (auto it = cnt.begin(); it != cnt.end(); it++) {
        cout << it->first << " " << it->second << "\n";
    }

    return 0;
}
