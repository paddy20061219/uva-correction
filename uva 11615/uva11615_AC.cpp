#include <iostream>
#include <algorithm>
using namespace std;

int getDepth(long long x) {
    int depth = 0;

    while (x > 0) {
        depth++;
        x /= 2;
    }

    return depth;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        long long N, A, B;
        cin >> N >> A >> B;

        int da = getDepth(A);
        int db = getDepth(B);

        int deeper = max(da, db);

        long long total = (1LL << N) - 1;
        long long subtree = (1LL << (N - deeper + 1)) - 1;

        cout << total - subtree + 1 << endl;
    }

    return 0;
}
