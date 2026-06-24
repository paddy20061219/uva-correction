#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while(T--) {
        int N;
        cin >> N;

        int dp[2][2] = {};

        for(int i = 0; i < 2; i++) {
            int line,tiling;
            cin >> price >> weight;

            for(int w =250; w >= line; w--) {
                dp[w] = max(dp[w], dp[w - tiling]);
            }
        }

        int G;
        cin >> G;

        int ans = 0;


        for(int i = 0; i < N; i++) {
            int maxtiling;
            cin >> maxtiling;

            ans += dp[0];
        }


      cout << ans << endl;
    }

    return 0;
}
