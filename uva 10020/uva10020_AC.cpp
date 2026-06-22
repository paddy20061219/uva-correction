#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Segment {
    int l, r;
};

bool cmp(Segment a, Segment b) {
    if (a.l != b.l) return a.l < b.l;
    return a.r > b.r;
}

int main() {
    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++) {
        int M;
        cin >> M;

        vector<Segment> seg;
        int l, r;

        while (cin >> l >> r) {
            if (l == 0 && r == 0) {
                break;
            }

            seg.push_back({l, r});
        }

        sort(seg.begin(), seg.end(), cmp);

        vector<Segment> ans;
        int covered = 0;
        int i = 0;
        bool ok = true;

        while (covered < M) {
            int bestR = covered;
            Segment bestSeg;
            bool found = false;

            while (i < seg.size() && seg[i].l <= covered) {
                if (seg[i].r > bestR) {
                    bestR = seg[i].r;
                    bestSeg = seg[i];
                    found = true;
                }
                i++;
            }

            if (!found) {
                ok = false;
                break;
            }

            ans.push_back(bestSeg);
            covered = bestR;
        }

        if (tc > 0) {
            cout << endl;
        }

        if (!ok) {
            cout << 0 << endl;
        } else {
            cout << ans.size() << endl;

            for (int j = 0; j < ans.size(); j++) {
                cout << ans[j].l << " " << ans[j].r << endl;
            }
        }
    }

    return 0;
}
