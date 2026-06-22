#include<iostream>
#include<string>
#include<alogrithm> // 錯誤：algorithm 拼錯

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int root_val;
    int cas = 0;

    // 錯誤：main 這裡直接結束，完全沒有讀 UVA 679 的 D 和 I
} 

void build_tree(int pos, vector<int>& sums, int& min_pos, int& max_pos) {
    int val;
    cin >> val;

    if (val == -1) {
        return;
    }

    sums[pos] += val;
    min_pos = min(min_pos, pos);
    max_pos = max(max_pos, pos);

    build_tree(pos - 1, sums, min_pos, max_pos);
    build_tree(pos + 1, sums, min_pos, max_pos);
}
