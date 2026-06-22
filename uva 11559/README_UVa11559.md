# UVA 11559 - Event Planning 訂正

## 題目重點

這題是要幫一群人找旅館。

輸入有：

- `n`：參加人數
- `b`：預算
- `h`：旅館數量
- `w`：每間旅館有幾週可以選

每間旅館會給：

1. 每個人的價錢 `p`
2. 接下來 `w` 個週末的床位數

只要某個週末床位數 `>= n`，而且總價 `p * n` 沒超過預算，就可以選。  
最後要輸出最便宜的方案。  
如果都沒有可以住的，就輸出：

```txt
stay home
```

---

## 錯誤程式碼

```cpp
#include<iostream>

#define haku author

using namespace std;

int main(){
    int n,b,h,w;
    int p,tmp,min;

    min = b+1; // 錯誤：這時候 b 還沒有讀進來

    while(cin>>n>>b>>h>>w){
        for( int i =0; i<h; i++){
            cin>>p;
            for(int j=0;j<w;j++){
                cin>>tmp;
                if(tmp>=n){
                    if(p*n < min) min = p*n;
                }
            }
        }

        if(min>b) cout<<"stay home"<<endl;
        else cout<<min<<endl;
    }

    return 0;
}
```

---

## 錯誤原因

這份程式最大的問題是：

```cpp
min = b + 1;
```

放在 `while(cin >> n >> b >> h >> w)` 外面。

可是 `b` 是在 while 裡面才讀到的，所以一開始 `b` 根本還沒有正確的值。  
這樣 `min` 會變成亂數相關的結果，答案可能會亂掉。

而且 UVA 11559 有很多筆測資。  
每一筆測資都要重新找一次最小花費，所以 `min` 也要每次重新設定。

也就是要放在這裡：

```cpp
while (cin >> n >> b >> h >> w) {
    int ans = b + 1;
}
```

另外，原本的程式雖然有檢查床位數夠不夠：

```cpp
if (tmp >= n)
```

但比較安全的寫法是也直接檢查總價不能超過預算：

```cpp
if (cost <= b && cost < ans)
```

這樣最後判斷會比較清楚。

---

## 正確程式碼

```cpp
#include <iostream>
using namespace std;

int main() {
    int n, b, h, w;

    while (cin >> n >> b >> h >> w) {
        int ans = b + 1;

        for (int i = 0; i < h; i++) {
            int p;
            cin >> p;

            for (int j = 0; j < w; j++) {
                int beds;
                cin >> beds;

                if (beds >= n) {
                    int cost = p * n;

                    if (cost <= b && cost < ans) {
                        ans = cost;
                    }
                }
            }
        }

        if (ans == b + 1) {
            cout << "stay home" << endl;
        } else {
            cout << ans << endl;
        }
    }

    return 0;
}
```

---

## 心得

這題不難，主要就是把每一家旅館和每個週末都檢查一次。

我覺得最容易錯的地方是多筆測資。  
像 `ans` 或 `min` 這種紀錄答案的變數，每次讀到新的一筆測資都要重新初始化。

這題不用排序，也不用 DP。  
只要直接暴力檢查所有旅館跟所有週末就可以了，因為資料範圍不大。

---

## AI 協助說明

這份訂正有使用 AI 幫忙整理錯誤原因、正確程式碼和 README。  
但我有照題目的輸入輸出邏輯理解一次，特別是為什麼 `ans` 要放在每筆測資裡面重新設定。
