# UVa 10282 - Babelfish

## 題目重點

這題是字典查詢題。

前半段輸入是字典，每一行有兩個單字：

```text
英文單字 外文單字
```

中間會有一個空白行，代表字典輸入結束。

後半段輸入是很多個外文單字，要把它翻譯回英文。  
如果查不到，就輸出：

```text
eh
```

例如：

```text
dog ogday
cat atcay

ogday
atcay
pig
```

輸出：

```text
dog
cat
eh
```

---

## 錯誤程式碼

檔案：`uva10282_wrong.cpp`

```cpp
#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main()
{   

    string current;

    int t = 1;

    cin >> current;
    while (current != "eh")
    {
        printf("Case %d: ", t);

        if (current == "atcay")
            printf("cat\n");
        else if (current == "ittenkay")
            printf("eh\n");


        else
            printf("loops\n");
        ++t;

        cin >> current;
    }
    return 0;
}
```

---

## 錯誤原因

我這個錯法主要有幾個問題：

1. 題目不是要輸出 `Case 1:` 這種格式  
   UVa 10282 只要直接輸出翻譯結果。

2. 不能把單字寫死在 `if else` 裡面  
   因為測資的字典有很多單字，不可能只判斷 `atcay` 或 `ittenkay`。

3. 停止條件也看錯了  
   題目是「字典和查詢中間有空白行」，不是讀到 `eh` 就停止。

4. 沒有把前面的字典存起來  
   這題重點應該是用 `map` 或 `unordered_map` 存：

```cpp
外文單字 -> 英文單字
```

---

## 正確程式碼

檔案：`uva10282_AC.cpp`

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<string, string> dict;
    string line;

    // 先讀字典，直到空白行
    while (getline(cin, line)) {
        if (line == "") break;

        string english, foreign;
        stringstream ss(line);
        ss >> english >> foreign;

        dict[foreign] = english;
    }

    // 後面每一行都是要查的外文單字
    string word;
    while (cin >> word) {
        if (dict.count(word)) {
            cout << dict[word] << "\n";
        } else {
            cout << "eh\n";
        }
    }

    return 0;
}
```

---

## 心得

這題一開始容易以為是字串轉換題，但其實它比較像「查字典」。

我覺得比較重要的是要看懂輸入格式：  
前面是建立字典，中間空白行分隔，後面才是查詢。

這題用 `unordered_map` 很方便，因為可以直接用外文單字當 key，查到就輸出英文，查不到就輸出 `eh`。

---

## AI 協助說明

這份訂正有使用 AI 幫忙整理程式碼和 README 說明，但我有照題目的輸入輸出邏輯去理解，並保留成比較像初學者自己訂正時會寫的版本。
