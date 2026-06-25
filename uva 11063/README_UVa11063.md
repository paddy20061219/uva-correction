# UVa 11063 - B2-Sequence

## 題目重點

這題要判斷一個數列是不是 B2-Sequence。

B2-Sequence 大概有幾個條件：

1. 數字要是正整數
2. 數列要遞增
3. 任兩個數字相加的結果不能重複

比較容易漏掉的是第 3 點。

例如數列：

```txt
1 2 4
```

可以算：

```txt
1+1 = 2
1+2 = 3
1+4 = 5
2+2 = 4
2+4 = 6
4+4 = 8
```

這些和都沒有重複，所以是 B2-Sequence。

這題可以用 `set` 來記錄出現過的和，如果發現某個和已經出現過，就代表不是 B2-Sequence。

## 錯誤程式碼

```cpp
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n;
    int caseNum = 1;

    while (cin >> n) {
        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        set<int> s;

        // 我原本只檢查數字有沒有重複
        // 但 B2-Sequence 要檢查的是「兩兩相加的和」有沒有重複
        bool ok = true;

        for (int i = 0; i < n; i++) {
            if (s.count(a[i])) {
                ok = false;
            }
            s.insert(a[i]);
        }

        cout << "Case #" << caseNum << ": ";

        if (ok) {
            cout << "It is a B2-Sequence.\n\n";
        }
        else {
            cout << "It is not a B2-Sequence.\n\n";
        }

        caseNum++;
    }

    return 0;
}
```

## 錯誤原因

這份程式碼有讀入數列，也有用到 `set`，但是檢查錯東西了。

它只檢查數列裡面的數字本身有沒有重複：

```cpp
if (s.count(a[i])) {
    ok = false;
}
```

可是 UVa 11063 要檢查的是：

```cpp
a[i] + a[j]
```

這些兩兩相加的結果有沒有重複。

而且它也沒有檢查數列是不是正整數，也沒有檢查是不是遞增。

所以像下面這種可能會被錯誤程式誤判：

```txt
1 2 3
```

因為數字本身沒有重複，但其實：

```txt
1 + 3 = 4
2 + 2 = 4
```

和重複了，所以不是 B2-Sequence。

## 正確程式碼

```cpp
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int caseNum = 1;

    while (cin >> n) {
        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        bool ok = true;

        for (int i = 0; i < n; i++) {
            if (a[i] <= 0) {
                ok = false;
            }

            if (i > 0 && a[i] <= a[i - 1]) {
                ok = false;
            }
        }

        set<int> sums;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int sum = a[i] + a[j];

                if (sums.count(sum)) {
                    ok = false;
                }

                sums.insert(sum);
            }
        }

        cout << "Case #" << caseNum << ": ";

        if (ok) {
            cout << "It is a B2-Sequence.\n\n";
        }
        else {
            cout << "It is not a B2-Sequence.\n\n";
        }

        caseNum++;
    }

    return 0;
}
```

## 心得

這題我覺得最容易搞錯的是，以為只要數字本身不重複就好了。

但這題真正要檢查的是兩個數字相加後的結果，這點跟普通的 set 去重不太一樣。

寫法上可以用兩層 for 迴圈，把 `i` 到 `j` 的所有組合都算一次。

這裡 `j` 從 `i` 開始，是因為同一個數字可以跟自己相加，例如 `a[0] + a[0]`。

另外輸出格式也要注意：

```txt
Case #1: It is a B2-Sequence.
```

後面還要空一行。

本份訂正有使用 AI 協助整理與檢查，但我有自己看過程式邏輯，主要是練習 `set` 和兩層迴圈。
