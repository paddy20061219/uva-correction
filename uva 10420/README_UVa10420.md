# UVa 10420 - List of Conquests

## 題目重點

這題會先給一個整數 `n`，代表後面有幾筆資料。

每一筆資料的格式大概像這樣：

```txt
Spain Donna Elvira
England Jane Doe
Spain Maria
```

每一行第一個字是國家，後面的人名其實不用管。

題目要我們統計每個國家出現幾次，最後按照國名字母順序輸出。

所以這題很適合用 `map<string, int>`。

因為 `map` 本身會自動照 key 排序，所以最後直接輸出就可以。

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

## 錯誤原因

這份程式碼有幾個問題。

第一個是題目不是 train sorting，也不是要讀一個長度 `l` 的陣列。

UVa 10420 是要讀國家名稱，然後統計每個國家出現幾次。

這裡：

```cpp
cin >> l;
int train[l];
```

跟題目完全不符合。

第二個是：

```cpp
t=0
```

這邊 `t` 沒有宣告，而且後面也少了分號，所以會編譯錯誤。

第三個是：

```cpp
while (n>0)
```

但是裡面沒有讓 `n--`，所以就算沒有 `return 0`，也可能變成無限迴圈。

這題正確做法應該是讀 `n` 行，每一行先讀國家，再用 `getline` 把後面的人名吃掉。

## 正確程式碼

```cpp
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, int> cnt;

    string country, name;
    getline(cin, name);

    for (int i = 0; i < n; i++) {
        cin >> country;
        getline(cin, name);

        cnt[country]++;
    }

    for (auto it = cnt.begin(); it != cnt.end(); it++) {
        cout << it->first << " " << it->second << "\n";
    }

    return 0;
}
```

## 心得

這題我覺得重點不是演算法很難，而是要看懂輸入。

每一行雖然有名字，但真正有用的只有第一個國家名稱。

一開始可能會想用陣列自己存，但其實用 `map` 會簡單很多，因為它可以幫我統計，也可以幫我照字母順序排列。

另外這題要注意 `cin` 跟 `getline` 混用，所以讀完 `n` 後要先用一次 `getline` 把換行吃掉。

本份訂正有使用 AI 協助整理與檢查，但我有自己看過程式邏輯，主要是練習 `map` 和輸入處理。
