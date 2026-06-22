#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;

    while (cin >> n && n) {
        queue<int> q;

        for (int i = 1; i <= n; i++) {
            q.push(i);
        }

        cout << "Discarded cards:";

        bool first = true;

        while (q.size() > 1) {
            int discard = q.front();
            q.pop();

            if (first) {
                cout << " " << discard;
                first = false;
            } else {
                cout << ", " << discard;
            }

            int moveCard = q.front();
            q.pop();
            q.push(moveCard);
        }

        cout << endl;
        cout << "Remaining card: " << q.front() << endl;
    }

    return 0;
}
