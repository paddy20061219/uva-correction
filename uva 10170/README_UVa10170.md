# UVa 10170 - The Hotel with Infinite Rooms 訂正

## 題目重點

這題是在說有一間無限房間的旅館。

第一團客人有 `S` 個人，會住 `S` 天。
下一團客人會有 `S + 1` 個人，再下一團是 `S + 2` 個人，以此類推。

題目給我們 `S` 和 `D`，要找第 `D` 天的時候，是哪一團客人在住。
答案就是那一團的人數。

也就是要找最小的 `N`，讓：

```text
S + (S + 1) + (S + 2) + ... + N >= D
```

然後輸出 `N`。

---

## 錯誤程式碼

```cpp
#include <iostream>
using namespace std;

int main() {
    long long S, D;

    while (cin >> S >> D) {
        // 錯誤想法：以為答案就是 S + D
        // 這完全沒有把每天累加的人數算進去
        cout << S + D << endl;
    }

    return 0;
}
```

---

## 錯誤原因

我一開始把題目想太簡單了，以為從 `S` 開始，加上第 `D` 天就可以得到答案。

可是這題不是直接算 `S + D`。

它其實是在做一段連續數字的累加：

```text
S, S+1, S+2, S+3, ...
```

每一團住的天數都等於那團的人數，所以要一直累加，直到累加天數大於或等於 `D`。

例如：

```text
S = 3, D = 10
```

累加過程：

```text
3       -> 第 3 天
3 + 4   -> 第 7 天
3 + 4 + 5 -> 第 12 天
```

第 10 天落在 `5` 這團，所以答案是 `5`，不是 `3 + 10 = 13`。

---

## 正確程式碼

```cpp
#include <iostream>
using namespace std;

using ll = long long;

__int128 sumFromSToN(ll S, ll N) {
    // S + (S+1) + ... + N
    return (__int128)(S + N) * (N - S + 1) / 2;
}

int main() {
    ll S, D;

    while (cin >> S >> D) {
        ll left = S;
        ll right = S;

        // 先把右邊界變大，直到一定可以住到第 D 天
        while (sumFromSToN(S, right) < D) {
            right *= 2;
        }

        // 二分搜：找最小的 right，使得累加總和 >= D
        while (left < right) {
            ll mid = left + (right - left) / 2;

            if (sumFromSToN(S, mid) >= D) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        cout << left << endl;
    }

    return 0;
}
```

---

## 心得

這題看起來像簡單加法，但其實重點是「累加到超過某一天」。

如果直接用 `while` 一個一個加，觀念比較好懂，可是數字很大的時候可能會跑太久。
所以這裡用二分搜找答案。

我覺得這題要記住一件事：

```text
找最小的 N，讓總和 >= D
```

這種題目常常可以用二分搜來寫。

本份訂正有使用 AI 協助整理和檢查，但我有自己理解題意和錯誤原因。
