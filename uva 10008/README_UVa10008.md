# UVa 10008 - What's Cryptanalysis?

## 題目重點

這題會先給一個整數 `n`，代表接下來有 `n` 行句子。

我們要統計所有英文字母出現幾次。

重點：

1. 大寫和小寫要算同一個字母  
   例如 `a` 和 `A` 都算 `A`
2. 不是英文字母的東西不用算  
   例如空白、逗號、句點都不用
3. 輸出時要照出現次數由大到小排
4. 如果次數一樣，要照字母順序由 A 到 Z 排

---

## 錯誤程式碼

```cpp
#include<iostream>

using namespace std;

int main(){
    int i,j;
    int n,l;

    cin>>n;

    while (n>0){
        cin>>l;

        int train[l];
        t=0
          return 0;
    }
}
```

---

## 錯誤原因

這份程式主要問題是把題目方向想錯了。

UVa 10008 不是處理火車、陣列交換或排序數字，  
而是要讀入很多行文字，然後統計英文字母出現次數。

比較明顯的錯誤：

1. `int train[l];` 這個比較像 Train Swapping 題目的寫法，跟本題無關。
2. `t=0` 沒有宣告 `t`，而且少了分號。
3. `while (n>0)` 裡面沒有讓 `n--`，會造成邏輯錯誤。
4. 一開始 `cin >> n` 之後，後面應該用 `getline` 讀整行文字，不是再讀一個整數 `l`。
5. 沒有統計字母，也沒有做排序輸出。

所以這份程式連編譯都會出錯，也沒有解到 UVa 10008 的題目要求。

---

## 正確程式碼

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();

    vector<int> cnt(26, 0);

    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);

        for (int j = 0; j < (int)line.size(); j++) {
            if (isalpha(line[j])) {
                char c = toupper(line[j]);
                cnt[c - 'A']++;
            }
        }
    }

    vector<pair<char, int> > ans;

    for (int i = 0; i < 26; i++) {
        if (cnt[i] > 0) {
            ans.push_back(make_pair(char('A' + i), cnt[i]));
        }
    }

    sort(ans.begin(), ans.end(), [](pair<char, int> a, pair<char, int> b) {
        if (a.second != b.second) return a.second > b.second;
        return a.first < b.first;
    });

    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }

    return 0;
}
```

---

## 心得

這題一開始很容易以為是要處理一堆資料排序，  
但其實最重要的是「字元處理」。

我覺得這題要注意 `cin >> n` 後面要加 `cin.ignore()`，  
不然第一個 `getline` 可能會讀到空行。

另外排序的地方也要小心，  
不是只排次數而已，次數一樣時還要照字母順序排。

本次訂正有使用 AI 協助整理錯誤原因與正確解法，但程式邏輯我有重新理解並確認。
