# UVa 10359 - Tiling 訂正

## 題目重點

這題是要算 `2 x n` 的長方形有幾種鋪法。

可以使用的東西大概是：

- 直的 domino
- 橫的 domino
- `2 x 2` 的方塊

題目會一直輸入 `n`，直到 EOF 結束。

這題有兩個重點：

1. 不是背包題
2. 答案非常大，`int`、`long long` 都不夠

所以要用 DP 加上大數字串處理。

---

## 錯誤程式碼

```cpp
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
```

---

## 錯誤原因

這份程式主要是把題目想成背包問題了，  
可是 UVa 10359 不是要選物品，也沒有 price、weight 這種東西。

而且還有幾個很明顯的錯誤：

### 1. 輸入格式錯了

UVa 10359 的輸入不是先給 `T` 測資數量。

正確輸入是：

```cpp
int n;
while (cin >> n) {
    ...
}
```

也就是一直讀到 EOF。

---

### 2. `price` 和 `weight` 沒有宣告

程式裡有這行：

```cpp
cin >> price >> weight;
```

可是前面只有宣告：

```cpp
int line,tiling;
```

所以這份程式會直接編譯錯誤。

---

### 3. `dp[2][2]` 根本不夠用

程式宣告：

```cpp
int dp[2][2] = {};
```

可是後面卻寫：

```cpp
dp[w]
```

這樣維度也不對，而且 `w` 還跑到 250，  
陣列大小完全不夠。

---

### 4. 題目答案會超過 long long

UVa 10359 的 `n` 可以到 250，答案很大。

所以不能用：

```cpp
int
long long
```

要用 `string` 來自己做大數加法。

---

## 正確程式碼

```cpp
#include <bits/stdc++.h>
using namespace std;

// UVa 10359 - Tiling
// AC 版本：dp[n] = dp[n-1] + 2 * dp[n-2]
// 因為答案很大，所以用 string 自己做大數加法

string addString(string a, string b) {
    string ans = "";
    int carry = 0;

    int i = a.size() - 1;
    int j = b.size() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int x = 0;
        int y = 0;

        if (i >= 0) x = a[i] - '0';
        if (j >= 0) y = b[j] - '0';

        int sum = x + y + carry;
        ans.push_back(char(sum % 10 + '0'));
        carry = sum / 10;

        i--;
        j--;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

string multiplyTwo(string s) {
    return addString(s, s);
}

int main() {
    vector<string> dp(251);

    dp[0] = "1";
    dp[1] = "1";

    for (int i = 2; i <= 250; i++) {
        dp[i] = addString(dp[i - 1], multiplyTwo(dp[i - 2]));
    }

    int n;
    while (cin >> n) {
        cout << dp[n] << endl;
    }

    return 0;
}
```

---

## 解法想法

假設 `dp[n]` 代表 `2 x n` 的長方形有幾種鋪法。

看最左邊開始放，可以分成幾種情況。

### 情況 1：放一個直的 domino

如果第一欄放一個直的 domino，剩下就是：

```text
2 x (n - 1)
```

所以有：

```cpp
dp[n - 1]
```

種方法。

---

### 情況 2：放兩個橫的 domino

如果前兩欄放兩個橫的 domino，剩下就是：

```text
2 x (n - 2)
```

所以有：

```cpp
dp[n - 2]
```

種方法。

---

### 情況 3：放一個 2 x 2 的方塊

如果前兩欄直接放一個 `2 x 2` 方塊，剩下也是：

```text
2 x (n - 2)
```

所以也是：

```cpp
dp[n - 2]
```

種方法。

---

所以總共是：

```cpp
dp[n] = dp[n - 1] + dp[n - 2] + dp[n - 2];
```

也就是：

```cpp
dp[n] = dp[n - 1] + 2 * dp[n - 2];
```

---

## 為什麼要用 string

因為 `n = 250` 的時候，答案已經大到一般整數裝不下。

所以我用字串來存數字，  
然後自己寫一個 `addString()` 做直式加法。

`multiplyTwo()` 其實也只是：

```cpp
return addString(s, s);
```

這樣就不用另外寫乘法，比較簡單。

---

## 心得

這題一開始會看起來像普通 DP，  
但比較麻煩的是答案太大，不能直接用 `int`。

我原本的錯誤程式整個想成背包，  
所以輸入格式、變數、DP 陣列都錯掉。

訂正後我覺得這題重點是先把轉移式想清楚：

```cpp
dp[n] = dp[n - 1] + 2 * dp[n - 2]
```

再處理大數加法就可以了。

---

## AI assistance note

這份訂正有使用 AI 幫忙整理錯誤原因和正確解法。  
我有照自己的理解把說明改成比較像上課訂正筆記的寫法。
