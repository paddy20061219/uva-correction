# UVa 10035 - Primary Arithmetic 訂正紀錄

## 一、題目重點

UVa 10035 要求判斷兩個整數相加時，會產生幾次進位。

每一組輸入有兩個非負整數，當輸入為：

```text
0 0
```

代表程式結束。

需要注意：

1. 要從個位數開始相加
2. 每一位都要加上上一位的進位
3. 如果總和大於或等於 10，就會產生一次進位
4. 輸入 `0 0` 時不能輸出結果，要直接結束

---

## 二、原本錯誤程式碼

```cpp
#include <iostream>
using namespace std;

int main() {
    int a, b;

    while (cin >> a >> b) {
        int carry = 0;

        while (a > 0 && b > 0) {
            int x = a % 10;
            int y = b % 10;

            if (x + y > 10)
                carry++;

            a = a / 10;
            b = b / 10;
        }

        cout << carry << " carry operations." << endl;
    }

    return 0;
}
```

---

## 三、錯誤原因

這份程式有幾個主要錯誤：

### 1. 沒有處理 0 0 結束條件

題目規定輸入：

```text
0 0
```

時要結束程式，不能繼續輸出。

原本程式少了：

```cpp
if (a == 0 && b == 0)
    break;
```

所以會多輸出一行錯誤答案。

---

### 2. 進位判斷條件錯誤

原本寫成：

```cpp
if (x + y > 10)
```

但如果兩位數字相加剛好等於 10，也會產生進位。

正確應該是：

```cpp
if (x + y + c >= 10)
```

其中 `c` 是上一位留下來的進位。

---

### 3. 沒有加上上一位的進位

加法時不能只算：

```cpp
x + y
```

還要加上上一位的進位：

```cpp
x + y + c
```

如果漏掉上一位的進位，後面的計算結果就會錯。

---

### 4. 只算到兩個數字都有位數為止

原本寫成：

```cpp
while (a > 0 && b > 0)
```

這樣如果兩個數字長度不同，剩下的位數就不會被計算。

正確應該要寫成：

```cpp
while (a > 0 || b > 0)
```

這樣才會把比較長的那個數字也算完。

---

### 5. 輸出格式沒有處理單複數

題目要求：

如果沒有進位：

```text
No carry operation.
```

如果有一次進位：

```text
1 carry operation.
```

如果有兩次以上進位：

```text
2 carry operations.
```

原本程式不管幾次都輸出：

```text
carry operations.
```

所以輸出格式會錯。

---

## 四、訂正後正確程式碼

```cpp
#include <iostream>
using namespace std;

int main() {
    int a, b;

    while (cin >> a >> b) {
        if (a == 0 && b == 0)
            break;

        int carry = 0;
        int count = 0;

        while (a > 0 || b > 0) {
            int x = a % 10;
            int y = b % 10;

            int sum = x + y + carry;

            if (sum >= 10) {
                count++;
                carry = 1;
            } else {
                carry = 0;
            }

            a = a / 10;
            b = b / 10;
        }

        if (count == 0)
            cout << "No carry operation." << endl;
        else if (count == 1)
            cout << "1 carry operation." << endl;
        else
            cout << count << " carry operations." << endl;
    }

    return 0;
}
```

---

## 五、訂正後改善的地方

訂正後先判斷結束條件：

```cpp
if (a == 0 && b == 0)
    break;
```

這樣遇到 `0 0` 就不會多輸出。

接著使用：

```cpp
while (a > 0 || b > 0)
```

可以處理兩個數字長度不同的情況。

每一位相加時，也加入上一位的進位：

```cpp
int sum = x + y + carry;
```

如果 `sum >= 10`，就代表這一位有產生進位。

最後根據進位次數分別輸出正確格式：

```cpp
No carry operation.
1 carry operation.
2 carry operations.
```

這樣才符合 UVa 10035 的輸出規定。

---

## 六、心得

這題看起來只是簡單的加法，但是細節很多。  
我原本沒有注意到 `0 0` 是結束條件，也沒有把上一位的進位加進下一位的計算。  
訂正後我學到，在處理加法進位問題時，應該從個位數開始一位一位算，而且每一位都要記得加上前一位的 carry。  
另外，UVa 題目很重視輸出格式，所以像單數 `operation` 和複數 `operations` 也要分清楚。
