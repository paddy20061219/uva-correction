# UVA 10041 - Vito's Family 訂正

## 題目重點

UVA 10041 是在找 Vito 應該住在哪一條街號，讓他到所有親戚家的距離總和最小。

每筆測資會給：

- `r`：親戚數量
- 接著有 `r` 個數字，代表每個親戚家的街號

我們要輸出最短的總距離。

這題的重點是：  
要讓總距離最小，位置要選在「中位數」。

例如親戚住在：

```txt
2 4 6
```

選 `4` 最好，距離是：

```txt
|2-4| + |4-4| + |6-4| = 2 + 0 + 2 = 4
```

所以答案是 `4`。

---

## 錯誤程式碼

```cpp
#include <iostream>

using namespace std;

int main()
{
    int num[500];
    int c = 0;
    int x;

    while( cin >> num[c] )
    {
        x = num[c];

        for(int i = 0 ; i <= c ; i++)
        {
            if( x <= num[i] )
            {
                for(int j = c+1 ; j > i;j--)
                {
                    num[j] = num[j-1];
                }

                num[i] = x;
                break;
            }
        }

        // 錯誤：這段是在輸出目前讀到數字的中位數
        // UVA 10041 要的是每筆測資算最短總距離
        if(c%2 ==0)
            cout<<num[c/2]<<endl;
        else
            cout<<(num[c/2]+num[c/2+1])/2<<endl;

        c++;
    }

    return 0;
}
```

---

## 錯誤原因

這份程式最大的問題是題目方向錯了。

它做的事情是：

1. 一直讀數字
2. 把目前讀到的數字排好
3. 每讀一個數字就輸出一次中位數

這比較像另一題「Running Median」的感覺。

可是 UVA 10041 的輸入格式不是這樣。  
UVA 10041 會先給測資數量：

```cpp
int T;
cin >> T;
```

然後每筆測資會給親戚數量 `r`，再給 `r` 個街號。

所以不能寫成：

```cpp
while (cin >> num[c])
```

另外，這題不是要輸出中位數本身。  
中位數只是拿來當 Vito 家的位置，最後要輸出的是「距離總和」。

例如：

```txt
2 4 6
```

中位數是 `4`，但輸出不是 `4`，而是：

```txt
4
```

這剛好一樣只是巧合。  
如果是：

```txt
1 2 10
```

中位數是 `2`，但答案是：

```txt
|1-2| + |2-2| + |10-2| = 9
```

所以要輸出 `9`，不是 `2`。

---

## 正確程式碼

```cpp
#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int r;
        cin >> r;

        int s[505];

        for (int i = 0; i < r; i++) {
            cin >> s[i];
        }

        sort(s, s + r);

        int mid = s[r / 2];
        int ans = 0;

        for (int i = 0; i < r; i++) {
            ans += abs(s[i] - mid);
        }

        cout << ans << endl;
    }

    return 0;
}
```

---

## 心得

這題的關鍵是知道「中位數」可以讓距離總和最小。

一開始可能會想試每一個位置，看哪個總距離最小。  
但其實不用那麼麻煩，只要排序後拿中間那個數字就可以。

步驟大概是：

1. 讀入親戚家的街號
2. 排序
3. 取中位數
4. 把每個親戚到中位數的距離加起來

我覺得這題容易錯的地方是把「中位數」當成答案直接輸出。  
但正確答案是距離總和，不是中位數的位置。

---

## AI 協助說明

這份訂正有使用 AI 協助整理錯誤原因、正確程式碼和 README。  
我有理解 UVA 10041 的重點是用中位數求最短總距離，不是單純輸出中位數。
