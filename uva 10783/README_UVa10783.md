# UVa 10783 - Odd Sum 訂正

## 題目重點

這題叫 **Odd Sum**。

題目會先給一個整數 `T`，代表有幾組測資。
每一組測資有兩個整數 `a` 和 `b`，要算出從 `a` 到 `b` 之間所有 **奇數** 的總和。

輸出格式要長這樣：

```text
Case 1: 9
Case 2: 8
```

重點就是：

- `a` 到 `b` 都要包含進去
- 只加奇數
- 每一筆都要輸出 `Case x: 答案`

---

## 錯誤程式碼

```cpp
#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int a, b;
        cin >> a >> b;

        int sum = 0;

        for (int i = a; i <= b; i++) {
            // 這邊很笨，題目要奇數，我卻加偶數
            if (i % 2 == 0) {
                sum += i;
            }
        }

        cout << "Case " << tc << ": " << sum << endl;
    }

    return 0;
}
```

---

## 錯誤原因

這題題目是要加 **odd integers**，也就是奇數。

可是錯誤程式裡面寫的是：

```cpp
if (i % 2 == 0)
```

`i % 2 == 0` 代表這個數是偶數，所以整個方向就錯了。
例如 `1 到 5`，正確應該是：

```text
1 + 3 + 5 = 9
```

但是錯誤程式會算成：

```text
2 + 4 = 6
```

所以答案會 WA。

---

## 正確程式碼

```cpp
#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int a, b;
        cin >> a >> b;

        int sum = 0;

        for (int i = a; i <= b; i++) {
            if (i % 2 == 1) {
                sum += i;
            }
        }

        cout << "Case " << tc << ": " << sum << endl;
    }

    return 0;
}
```

---

## 心得

這題其實不難，主要是要看清楚題目要的是奇數和，不是偶數和。
我一開始如果只看到 `sum` 可能會直接寫迴圈加起來，但這樣會忘記判斷奇偶。

這題也提醒我，UVa 題目除了邏輯以外，輸出格式也很重要。
`Case 1: 9` 中間的空格和冒號都要照題目要求寫，不然也可能錯。

---

## AI 協助說明

這份訂正有使用 AI 幫忙整理題目重點、錯誤原因和程式碼格式。
我有確認主要邏輯是：讀入多筆測資，對每組 `a` 到 `b` 的範圍只加奇數，最後照 `Case x: ans` 輸出。
