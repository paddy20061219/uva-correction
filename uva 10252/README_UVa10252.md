# UVA 10252 - Common Permutation 訂正

## 題目重點

UVA 10252 是字串題。

題目會一直給兩行字串：

```txt
第一個字串
第二個字串
```

我們要找出兩個字串都有出現的字母。  
如果某個字母出現多次，就只能取兩邊比較少的次數。

例如：

```txt
pretty
women
```

`pretty` 裡面有 `e`、`t`、`p`、`r`、`y`  
`women` 裡面有 `w`、`o`、`m`、`e`、`n`

共同字母只有 `e`，所以輸出：

```txt
e
```

答案要按照字母順序輸出。

---

## 錯誤程式碼

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Segment
{
    int L, R;
};

bool comp(const Segment &s1, const Segment &s2)
{
    return s1.L < s2.L;
}

int main()
{  
    int T;
    cin >> T;

    while ( T-- )
    {
        int M;
        cin >> M;

        // 錯誤：這行宣告其實是函式，不是 vector
        vector<Segment> S();

        // 錯誤：UVA 10252 不是區間題，也沒有 T、M、Segment
        // 正確題目是每次讀兩行字串，找共同字母
        cout << "wrong answer" << endl;
    }

    return 0;
}
```

---

## 錯誤原因

這份程式最大的問題是題目方向完全錯了。

它看起來是在寫區間排序或區間覆蓋題，因為有：

```cpp
struct Segment
{
    int L, R;
};
```

可是 UVA 10252 不是區間題，是字串共同字母題。

UVA 10252 的輸入也不是先給 `T`。  
它是一直讀兩行字串直到 EOF：

```cpp
while (getline(cin, a)) {
    getline(cin, b);
}
```

另外，這行也很容易誤會：

```cpp
vector<Segment> S();
```

這不是建立一個 vector，而是宣告一個叫做 `S` 的函式。  
如果真的要建立 vector，要寫：

```cpp
vector<Segment> S;
```

不過這題根本不需要 `Segment`，只需要統計 26 個小寫字母出現次數。

---

## 正確程式碼

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;

    while (getline(cin, a)) {
        getline(cin, b);

        int cntA[26] = {0};
        int cntB[26] = {0};

        for (int i = 0; i < a.size(); i++) {
            if (a[i] >= 'a' && a[i] <= 'z') {
                cntA[a[i] - 'a']++;
            }
        }

        for (int i = 0; i < b.size(); i++) {
            if (b[i] >= 'a' && b[i] <= 'z') {
                cntB[b[i] - 'a']++;
            }
        }

        for (int i = 0; i < 26; i++) {
            int common = min(cntA[i], cntB[i]);

            for (int j = 0; j < common; j++) {
                cout << char('a' + i);
            }
        }

        cout << endl;
    }

    return 0;
}
```

---

## 心得

這題的重點是先看懂輸入格式。

它沒有測資數量 `T`，所以不能寫：

```cpp
cin >> T;
while (T--)
```

而是要一直用 `getline` 讀兩行。

我覺得這題最簡單的做法是開兩個陣列：

```cpp
int cntA[26];
int cntB[26];
```

分別記錄兩個字串裡每個字母出現幾次。

最後從 `a` 到 `z` 檢查，每個字母輸出：

```cpp
min(cntA[i], cntB[i])
```

次。

這題可以練習字元轉數字：

```cpp
'a' - 'a' = 0
'b' - 'a' = 1
'c' - 'a' = 2
```

所以可以用 `s[i] - 'a'` 當作陣列位置。

---

## AI 協助說明

這份訂正有使用 AI 協助整理錯誤原因、正確程式碼和 README。  
我有理解 UVA 10252 的重點是統計兩個字串共同字母，不是區間排序。
