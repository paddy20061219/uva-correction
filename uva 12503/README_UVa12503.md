# UVa 12503 - Robot Instructions 訂正

## 題目重點

這題是在模擬機器人的移動。

機器人一開始位置是 `0`。

每一個指令可能是：

```text
LEFT
RIGHT
SAME AS x
```

意思是：

- `LEFT`：往左走一步，所以位置 `-1`
- `RIGHT`：往右走一步，所以位置 `+1`
- `SAME AS x`：照第 `x` 個指令做一樣的動作

最後要輸出機器人的位置。

要注意，輸入第一個數字是測資數量 `T`，不是直接拿來算答案。

---

## 錯誤程式碼

```cpp
#include<iostream>

using namespace std;

int main(){
    int n;
    while (cin>>n){
        cout<<n+n/2<<endl;
        return 0;
    }
}
```

---

## 錯誤原因

我這份錯誤程式其實完全沒有照題目做。

主要問題：

1. `n` 不是拿來算 `n + n / 2`
2. 題目要讀很多行指令，但是程式沒有讀 `LEFT`、`RIGHT`、`SAME AS`
3. `return 0` 放在 while 裡面，所以讀到第一個數字就結束了
4. UVa 12503 是模擬題，不是數學公式題

例如題目給：

```text
3
LEFT
RIGHT
SAME AS 1
```

正確作法應該是：

```text
LEFT      -> -1
RIGHT     -> +1
SAME AS 1 -> 跟第 1 個一樣，也就是 -1
```

最後位置是：

```text
-1 + 1 - 1 = -1
```

不是用 `n + n / 2` 算。

---

## 正確程式碼

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> move(n + 1);
        int pos = 0;

        for (int i = 1; i <= n; i++) {
            string s;
            cin >> s;

            if (s == "LEFT") {
                move[i] = -1;
            }
            else if (s == "RIGHT") {
                move[i] = 1;
            }
            else {
                string as_word;
                int x;
                cin >> as_word >> x;

                move[i] = move[x];
            }

            pos += move[i];
        }

        cout << pos << endl;
    }

    return 0;
}
```

---

## 心得

這題我一開始把它想成算數字，但其實它是很基本的模擬題。

重點不是公式，而是要把每一個指令存起來，因為 `SAME AS x` 會用到前面第 `x` 個指令。

之後看到這種題目，我應該先看清楚輸入格式，尤其是第一個數字是不是測資數量。

---

## AI assistance note

這份訂正有使用 AI 協助整理錯誤原因和產生正確程式碼，但我有照題目邏輯重新理解一次。
