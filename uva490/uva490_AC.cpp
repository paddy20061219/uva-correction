#include <iostream>
#include <string>
using namespace std;

int main() {
    string line[100];
    int n = 0;
    int maxLen = 0;

    while (getline(cin, line[n])) {
        if ((int)line[n].size() > maxLen)
            maxLen = line[n].size();
        n++;
    }

    for (int col = 0; col < maxLen; col++) {
        for (int row = n - 1; row >= 0; row--) {
            if (col < (int)line[row].size())
                cout << line[row][col];
            else
                cout << ' ';
        }
        cout << endl;
    }

    return 0;
}
