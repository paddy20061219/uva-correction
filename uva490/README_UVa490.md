# UVa 490 - Rotating Sentences 訂正紀錄

## 一、題目重點

UVa 490 要求把輸入的多行句子旋轉 90 度。

原本的文字要往右旋轉，所以輸出時要：

1. 從第 0 欄開始輸出
2. 每一欄都要從最後一行往第一行輸出
3. 如果某一行長度不夠，要補空白
4. 不能吃掉原本輸入中的空白

例如原本輸入有多行文字，旋轉後要把直的欄位變成橫的輸出。

---

## 二、原本錯誤程式碼

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s[100];
    int n = 0;

    while (cin >> s[n]) {
        n++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = s[i].size() - 1; j >= 0; j--) {
            cout << s[i][j];
        }
        cout << endl;
    }

    return 0;
}
```

---

## 三、錯誤原因

這份程式有幾個主要錯誤：

### 1. 使用 cin >> s 會吃掉空白

原本程式使用：

```cpp
cin >> s[n]
```

這樣遇到空白就會停止，只會讀到一個單字。

可是 UVa 490 的輸入是句子，句子中間可能有空白，所以必須保留整行內容。

正確應該使用：

```cpp
getline(cin, line[n])
```

這樣才能讀入完整一行。

---

### 2. 只是把每一行反過來，不是真正旋轉

原本程式做的是：

```cpp
for (int j = s[i].size() - 1; j >= 0; j--)
```

這只是把每一行字串左右反轉。

但是 UVa 490 要的是整個文字矩陣旋轉 90 度，不是單純反轉每一行。

---

### 3. 沒有找出最長行長度

因為每一行長度可能不同，所以要先找出最長的那一行：

```cpp
int maxLen = 0;
```

旋轉時要輸出到 `maxLen` 欄。

原本程式沒有處理這件事，所以遇到長短不同的句子會錯。

---

### 4. 沒有補空白

旋轉時，如果某一行比較短，該位置沒有字元，就要補空白：

```cpp
cout << ' ';
```

如果沒有補空白，輸出的排版就會錯。

---

## 四、訂正後正確程式碼

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string line[100];
    int n = 0;
    int maxLen = 0;

    while (getline(cin, line[n])) {
        if ((int)line[n].size() > maxLen)
            maxLen = line[n].size();
        n++;
    }

    for (int col = 0; col < maxLen; col++) {
        for (int row = n - 1; row >= 0; row--) {
            if (col < (int)line[row].size())
                cout << line[row][col];
            else
                cout << ' ';
        }
        cout << endl;
    }

    return 0;
}
```

---

## 五、訂正後改善的地方

訂正後改用：

```cpp
getline(cin, line[n])
```

可以完整讀取每一行，包含中間的空白。

接著記錄最長行長度：

```cpp
if ((int)line[n].size() > maxLen)
    maxLen = line[n].size();
```

輸出時使用兩層迴圈：

```cpp
for (int col = 0; col < maxLen; col++)
    for (int row = n - 1; row >= 0; row--)
```

代表先固定欄位，再從最後一行往上輸出，這樣就能達到旋轉 90 度的效果。

如果某一行太短，沒有該欄位的字元，就輸出空白：

```cpp
cout << ' ';
```

這樣可以保持旋轉後的格式正確。

---

## 六、心得

這題看起來像是字串處理，但其實重點是把輸入想成一個二維矩陣。  
我原本只是把每一行反轉，沒有真正做到矩陣旋轉。  
訂正後我學到，處理句子輸入時要用 `getline()`，不能用 `cin >>`，不然空白會不見。  
另外，遇到每一行長度不一樣的題目時，要特別注意補空白，否則輸出格式會錯。
