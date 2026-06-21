# UVa 299 - Train Swapping

## 題目重點

這題是給你幾組火車車廂的順序，  
每一組都要算要交換幾次相鄰車廂，才能把火車排成由小到大。

其實就是算「逆序數」。

例如：

```text
3 1 2
```

因為 `3` 比 `1` 大，也比 `2` 大，  
所以需要交換 2 次。

UVa 299 的輸出格式一定要長這樣：

```text
Optimal train swapping takes X swaps.
```

這個格式要完全一樣，不然也會 Wrong Answer。

---

## 錯誤程式碼

```cpp
#include <iostream>
using namespace std;
int main() {
    int N, L, t[5], c=0;
    cin >> N;

        cout << "Train cost:" << c;
    }
}
```

---

## 錯誤原因

這份程式目前有幾個很明顯的問題：

1. 最後多了一個 `}`，所以會編譯錯誤。
2. 只讀了 `N`，但是沒有讀每一組火車長度 `L`。
3. 沒有把火車車廂資料讀進來。
4. 沒有做交換，也沒有計算交換次數。
5. `t[5]` 陣列太小，題目不一定只有 5 節車廂。
6. 輸出格式錯了，題目要的是：
   ```text
   Optimal train swapping takes X swaps.
   ```
   不是 `Train cost:`。

所以這份程式還沒有真正解到 Train Swapping 這題。

---

## 正確程式碼

```cpp
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    while (N--) {
        int L;
        cin >> L;

        int train[60];

        for (int i = 0; i < L; i++) {
            cin >> train[i];
        }

        int swaps = 0;

        for (int i = 0; i < L; i++) {
            for (int j = 0; j < L - 1; j++) {
                if (train[j] > train[j + 1]) {
                    int temp = train[j];
                    train[j] = train[j + 1];
                    train[j + 1] = temp;
                    swaps++;
                }
            }
        }

        cout << "Optimal train swapping takes " << swaps << " swaps." << endl;
    }

    return 0;
}
```

---

## 心得

這題其實不用想太複雜，因為車廂數量不大，  
可以直接用 bubble sort 一邊排序一邊數交換幾次。

我一開始只想到要印出一個答案，  
但忘記這題要讀很多組測資，而且輸出格式要完全照題目。  
訂正後比較清楚的是：只要兩個相鄰車廂順序錯了就交換，交換一次就把答案加一。

本次訂正有使用 AI 協助整理錯誤原因與正確解法，但我有重新看過題目邏輯。
