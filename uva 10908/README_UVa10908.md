# UVa 10908 - Largest Square

## 題目重點

這題會給一個字元矩陣，然後有很多次查詢。

每次查詢會給一個位置 `(r, c)`，要以這個位置當中心，找出最大的正方形。

要注意幾個地方：

1. 正方形的邊長一定是奇數，像是 `1、3、5、7`
2. 正方形裡面的字元都要跟中心點一樣
3. 查詢的位置是用 0-based，也就是第一列第一行是 `(0, 0)`
4. 每組測資輸出答案前，要先輸出原本的 `m n q`

我的想法是從邊長 `1` 開始，然後慢慢嘗試變成 `3、5、7...`。

如果超出邊界，或是正方形裡面有一格字元不一樣，就不能再變大。

## 錯誤程式碼

```cpp
#include <iostream>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        cout << n * n / 2 << endl;
    }
    return 0; 
}
```

## 錯誤原因

這份程式碼完全沒有照題目的輸入格式做。

UVa 10908 的輸入不是只有一個整數 `n`，而是會先有測資數量，接著每組有 `m n q`、字元矩陣、還有很多查詢。

題目也不是要算 `n * n / 2`，而是要在矩陣裡面找最大正方形。

所以錯的地方大概有：

```cpp
int n;
while (cin >> n)
```

這裡只讀一個整數，沒有讀矩陣。

```cpp
cout << n * n / 2 << endl;
```

這個公式跟題目沒有關係。

這題需要用 `vector<string>` 存整個矩陣，然後每次查詢都從中心點往外檢查。

## 正確程式碼

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int m, n, q;
        cin >> m >> n >> q;

        vector<string> grid(m);
        for (int i = 0; i < m; i++) {
            cin >> grid[i];
        }

        cout << m << " " << n << " " << q << "\n";

        while (q--) {
            int r, c;
            cin >> r >> c;

            char center = grid[r][c];
            int ans = 1;

            while (true) {
                int nextSize = ans + 2;
                int half = nextSize / 2;

                int top = r - half;
                int bottom = r + half;
                int left = c - half;
                int right = c + half;

                if (top < 0 || bottom >= m || left < 0 || right >= n) {
                    break;
                }

                bool ok = true;

                for (int i = top; i <= bottom; i++) {
                    for (int j = left; j <= right; j++) {
                        if (grid[i][j] != center) {
                            ok = false;
                        }
                    }
                }

                if (ok) {
                    ans = nextSize;
                }
                else {
                    break;
                }
            }

            cout << ans << "\n";
        }
    }

    return 0;
}
```

## 心得

這題一開始看起來像是矩陣題，但其實做法沒有到很難。

重點是要知道「中心點固定」，所以不用去找全部的正方形，只要從查詢給的位置慢慢往外擴大就好。

我覺得比較容易錯的是輸出格式，因為每組測資一開始要先印出 `m n q`。

另外也要記得邊長只能是奇數，所以每次都是加 2，不是加 1。

本份訂正有使用 AI 協助整理與檢查，但我有自己看過程式邏輯，主要是練習如何從中心點往外檢查矩陣。
