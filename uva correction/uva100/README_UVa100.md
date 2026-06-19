# UVa 100 - The 3n + 1 Problem 訂正紀錄

## 一、題目重點

UVa 100 要求輸入兩個整數 `i` 和 `j`，計算從 `i` 到 `j` 之間所有數字的 cycle length，並輸出其中最大的 cycle length。

需要注意：

1. 輸入可能是 `i < j`，也可能是 `i > j`
2. 輸出時必須保留原本輸入的順序
3. 計算過程中不能直接改到 for 迴圈的控制變數
4. cycle length 要從 1 開始算，因為數字本身也算一步

---

## 二、原本錯誤程式碼

```cpp
#include <iostream>
using namespace std;

int main() {
    int i, j;

    while (cin >> i >> j) {
        int maxCycle = 0;

        for (int n = i; n <= j; n++) {
            int count = 0;

            while (n != 1) {
                if (n % 2 == 0)
                    n = n / 2;
                else
                    n = n + 1;

                count++;
            }

            if (count > maxCycle)
                maxCycle = count;
        }

        cout << i << " " << j << " " << maxCycle << endl;
    }

    return 0;
}
```

---

## 三、錯誤原因

這份程式有幾個主要錯誤：

### 1. 奇數規則寫錯

題目規則是：

```cpp
n = 3 * n + 1;
```

但我原本寫成：

```cpp
n = n + 1;
```

這會讓整個 cycle length 計算結果完全錯誤。

---

### 2. 直接修改 for 迴圈變數

原本程式在 while 迴圈中直接改到 `n`：

```cpp
while (n != 1) {
    n = n / 2;
}
```

可是 `n` 同時也是 for 迴圈的控制變數：

```cpp
for (int n = i; n <= j; n++)
```

這樣會造成 for 迴圈流程錯亂，甚至可能無限迴圈。

---

### 3. 沒有處理 i > j 的情況

UVa 100 的輸入可能會出現：

```text
10 1
```

這時候仍然要計算 1 到 10 的最大 cycle length。

原本程式只寫：

```cpp
for (int n = i; n <= j; n++)
```

如果 `i > j`，迴圈完全不會執行。

---

### 4. count 起始值錯誤

cycle length 應該從 1 開始算，因為原本的數字本身也算一步。

原本寫：

```cpp
int count = 0;
```

會少算一次。

---

## 四、訂正後正確程式碼

```cpp
#include <iostream>
using namespace std;

int cycleLength(long long n) {
    int count = 1;

    while (n != 1) {
        if (n % 2 == 1)
            n = 3 * n + 1;
        else
            n = n / 2;

        count++;
    }

    return count;
}

int main() {
    int i, j;

    while (cin >> i >> j) {
        int start = min(i, j);
        int end = max(i, j);

        int maxCycle = 0;

        for (int n = start; n <= end; n++) {
            int len = cycleLength(n);

            if (len > maxCycle)
                maxCycle = len;
        }

        cout << i << " " << j << " " << maxCycle << endl;
    }

    return 0;
}
```

---

## 五、訂正後改善的地方

訂正後我把計算 cycle length 的部分獨立成一個函式：

```cpp
int cycleLength(long long n)
```

這樣可以避免直接修改 for 迴圈的變數。

另外，使用：

```cpp
int start = min(i, j);
int end = max(i, j);
```

可以正確處理 `i > j` 的輸入情況。

最後輸出時仍然保留原本的輸入順序：

```cpp
cout << i << " " << j << " " << maxCycle << endl;
```

這樣才符合 UVa 100 的輸出格式。

---

## 六、心得

這題看起來規則很簡單，但是如果沒有注意細節，很容易出錯。  
我這次主要錯在把奇數的規則寫錯，還有在計算過程中直接修改 for 迴圈的控制變數。  
訂正後我學到，在需要暫時計算某個數字變化時，應該使用函式或暫存變數，避免影響外層迴圈。  
另外，UVa 題目常常要求輸出格式完全正確，所以輸出時也要保留原本輸入的順序。
