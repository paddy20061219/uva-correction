# UVA 10189 - Minesweeper 訂正

## 題目重點

UVA 10189 是踩地雷題。

輸入會給很多個地圖，每個地圖有：

```txt
n m
```

代表有 `n` 列、`m` 行。

接著會有 `n` 行字串，裡面可能有：

```txt
* 代表地雷
. 代表空格
```

我們要把每一個 `.` 換成它周圍 8 格裡面有幾個地雷。

周圍 8 格就是：

```txt
左上 上 右上
左   自己 右
左下 下 右下
```

如果原本是 `*`，就保持 `*` 不變。

輸出格式要長這樣：

```txt
Field #1:
...
```

不同 field 中間要空一行。

---

## 錯誤程式碼

```cpp
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[1110][1110];

int main() {
    ios::sync_with_stdio(false);
    cin.tie();

    int T;
    cin >> T;
    cin.ignore();

    while (T--) {
        string s;
        getline(cin, s);
        int n = s.size();

        for (int i = 0; i < n; i++) dp[i][i] = 1;
        for (int i = 0; i < n-1; i++) dp[i][i+1] = (s[i]==s[i+1]) ? 2 : 1;

        for (int len = 3; len <= n; len++) {
            for (int i = 0; i+len-1 < n; i++) {
                int j = i+len-1;
                if (s[i] == s[j]) dp[i][j] = dp[i+1][j-1] + 2;
                else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }

        cout << (n ? dp[0][n-1] : 0) << "\n";
    }

    return 0;
}
```

---

## 錯誤原因

這份程式最大的問題是：它不是在解 UVA 10189。

它看起來是在做字串 DP，功能比較像「最長回文子序列」。  
可是 UVA 10189 要處理的是地圖，不是字串回文。

UVA 10189 的輸入不是先給 `T` 筆測資，而是一直讀：

```cpp
n m
```

直到讀到：

```txt
0 0
```

才停止。

所以這段就不適合：

```cpp
int T;
cin >> T;
while (T--) {
    ...
}
```

另外，這題不需要 `dp`。  
要做的是對每一個格子檢查周圍 8 個方向有幾個 `*`。

也就是要用兩層迴圈掃地圖，再用另外兩層小迴圈掃附近格子。

---

## 正確程式碼

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, m;
    int field = 1;

    while (cin >> n >> m) {
        if (n == 0 && m == 0) {
            break;
        }

        string g[105];

        for (int i = 0; i < n; i++) {
            cin >> g[i];
        }

        if (field > 1) {
            cout << endl;
        }

        cout << "Field #" << field++ << ":" << endl;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == '*') {
                    cout << '*';
                } else {
                    int cnt = 0;

                    for (int dx = -1; dx <= 1; dx++) {
                        for (int dy = -1; dy <= 1; dy++) {
                            if (dx == 0 && dy == 0) {
                                continue;
                            }

                            int ni = i + dx;
                            int nj = j + dy;

                            if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                                if (g[ni][nj] == '*') {
                                    cnt++;
                                }
                            }
                        }
                    }

                    cout << cnt;
                }
            }
            cout << endl;
        }
    }

    return 0;
}
```

---

## 心得

這題重點是看清楚輸入格式和題目類型。

我原本的程式方向完全跑到 DP 去了，但 UVA 10189 其實是簡單的二維陣列模擬。

這題我覺得要注意三件事：

1. 結束條件是 `0 0`
2. 每個 field 的輸出格式要對
3. 檢查周圍 8 格時不能超出陣列範圍

寫二維陣列題目的時候，我覺得最容易錯的是邊界。  
所以每次算 `ni`、`nj` 後，都要先檢查：

```cpp
ni >= 0 && ni < n && nj >= 0 && nj < m
```

這樣才不會去讀到地圖外面。

---

## AI 協助說明

這份訂正有使用 AI 協助整理錯誤原因、正確程式碼和 README。  
我有理解 UVA 10189 的重點是二維地圖和周圍 8 格檢查，不是 DP。
