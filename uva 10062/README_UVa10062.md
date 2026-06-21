# UVa 10062 - Tell me the frequencies!

## 題目重點

這題會給很多行字串，  
每一行都要統計每個字元出現幾次。

輸出格式是：

```text
ASCII碼 出現次數
```

排序規則很重要：

1. 出現次數少的先輸出
2. 如果出現次數一樣，ASCII code 較大的先輸出
3. 不同測資之間要空一行

例如如果 `A` 和 `B` 都出現 1 次，  
因為 `B` 的 ASCII 比 `A` 大，所以要先印 `B`。

---

## 錯誤程式碼

```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    while (getline(cin, s)) {
        int count[256] = {0};

        for (int i = 0; i < s.length(); i++) {
            count[(int)s[i]]++;
        }

        for (int i = 1; i <= 256; i++) {
            for (int j = 0; j < 256; j++) {
                if (count[j] == i) {
                    cout << j << " " << count[j] << endl;
                }
            }
        }
        cout << endl;
    }
    return 0;
}
```

---

## 錯誤原因

這份程式其實已經有抓到題目核心：  
要用陣列統計每個 ASCII 字元出現次數。

但是還是會 Wrong Answer，主要是排序規則錯了。

你的程式：

```cpp
for (int j = 0; j < 256; j++)
```

這樣同樣頻率時會從 ASCII 小的先印。  
可是 UVa 10062 要求同樣頻率時，ASCII code 大的先印。

所以應該像這樣排：

```text
出現次數小的先
如果次數一樣，ASCII 大的先
```

另外還有一個小問題：

```cpp
for (int i = 1; i <= 256; i++)
```

這樣只會印出出現次數 1 到 256 的字元。  
如果某個字元在一行中出現超過 256 次，就可能漏掉。

所以比較穩的寫法是把有出現的字元放進 vector，  
再用 `sort()` 自訂排序規則。

---

## 正確程式碼

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string s;
    bool first = true;

    while (getline(cin, s)) {
        int cnt[128] = {0};

        for (int i = 0; i < (int)s.length(); i++) {
            cnt[(int)s[i]]++;
        }

        vector<pair<int, int> > ans;

        for (int i = 0; i < 128; i++) {
            if (cnt[i] > 0) {
                ans.push_back(make_pair(i, cnt[i]));
            }
        }

        sort(ans.begin(), ans.end(), [](pair<int, int> a, pair<int, int> b) {
            if (a.second != b.second) return a.second < b.second;
            return a.first > b.first;
        });

        if (!first) {
            cout << endl;
        }
        first = false;

        for (int i = 0; i < (int)ans.size(); i++) {
            cout << ans[i].first << " " << ans[i].second << endl;
        }
    }

    return 0;
}
```

---

## 心得

這題看起來只是統計字元，  
但其實最容易錯的是排序。

我原本的想法是先照頻率掃，再照 ASCII 從小到大印，  
可是題目同頻率時剛好要反過來，ASCII 大的要先印。

訂正後我覺得用 `vector<pair<int,int>>` 再 `sort()` 比較清楚，  
因為可以直接寫出「頻率小的先，ASCII 大的先」這個規則。

本次訂正有使用 AI 協助整理錯誤原因與正確解法，但我有重新理解排序規則。
