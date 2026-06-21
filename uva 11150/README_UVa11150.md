# UVa 11150 - Cola 訂正

## 題目重點

這題是在算喝可樂的最大數量。

規則大概是：

- 一開始有 `n` 瓶可樂
- 喝完一瓶會得到一個空瓶
- 每 3 個空瓶可以換 1 瓶新的可樂
- 題目允許最後可以用「借空瓶」的想法，讓答案變最大

這題最後其實可以用一個很短的公式：

```text
答案 = n + n / 2
```

因為喝掉原本的 `n` 瓶之外，大約每 2 瓶原本的可樂可以多換出 1 瓶。

例如：

```text
n = 10
答案 = 10 + 10 / 2 = 15
```

---

## 錯誤程式碼

```cpp
#include <iostream>
using namespace std;

int main(){
    int cola_num;

    while (cin >> cola_num){
        int max_cola = 0;
        
        for (int i = 0; i < 3; i--){ // number of empty bottle I borrow  
            int drink_cola_sum = cola_num; 
            int _cola = 0;

            int empty_bottle = cola_num + i;

            while (empty_bottle >= 3){
                _cola = empty_bottle / 3;
                drink_cola_sum = drink_cola_sum + _cola;
                empty_bottle = _cola + empty_bottle % 3;
            }

            if (drink_cola_sum > max_cola){
                max_cola = drink_cola_sum;
            }
        }

        cout << max_cola << endl;
    }

    return 0;
}
```

---

## 錯誤原因

我這份原本想法是想枚舉「借幾個空瓶」，可是程式裡有一個很嚴重的錯誤：

```cpp
for (int i = 0; i < 3; i--)
```

這邊 `i` 一開始是 `0`，然後每次變成 `-1`、`-2`、`-3` ...

可是條件是：

```cpp
i < 3
```

所以它會一直成立，程式就跑不完，會變成 TLE 或根本沒有正常輸出。

如果只是要從 0、1、2 枚舉，應該要寫：

```cpp
for (int i = 0; i < 3; i++)
```

不過這題其實不用寫這麼複雜。UVa 11150 有很簡單的規律，直接輸出：

```cpp
n + n / 2
```

就可以了。

---

## 正確程式碼

```cpp
#include <iostream>
using namespace std;

int main() {
    long long n;

    while (cin >> n) {
        cout << n + n / 2 << endl;
    }

    return 0;
}
```

---

## 心得

這題我一開始想用模擬去做，而且還想把借空瓶的數量一個一個試出來。

可是這樣比較容易把迴圈寫錯，像這次 `i--` 就會讓程式卡死。

這題比較好的方式是先觀察規律：

```text
最多可以喝的瓶數 = 原本的瓶數 + 原本瓶數的一半
```

以後遇到這種「空瓶換飲料」的題目，可以先試小數字，看有沒有固定公式，不一定要硬寫很多層模擬。

---

## AI assistance note

這份訂正有使用 AI 幫忙整理錯誤原因和正確寫法，但我有把自己原本的錯誤邏輯放進來一起檢討。
