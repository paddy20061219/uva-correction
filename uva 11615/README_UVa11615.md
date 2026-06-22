# UVA 11615 - Family Tree 訂正

## 題目重點

這題可以把 family tree 想成一棵完整二元樹。

如果樹有 `N` 層，那總節點數是：

```txt
2^N - 1
```

節點編號跟 heap 很像：

```txt
1
2 3
4 5 6 7
...
```

所以要求某個節點在哪一層，可以一直除以 2。

例如：

```txt
1 在第 1 層
2, 3 在第 2 層
4, 5, 6, 7 在第 3 層
```

這題會給 `N A B`。  
我們要看 `A` 和 `B` 哪一個在比較深的層數，然後用那一層算子樹大小。

如果比較深的是第 `d` 層，那它下面那棵子樹的大小是：

```txt
2^(N - d + 1) - 1
```

最後答案是：

```txt
總節點數 - 子樹大小 + 1
```

也就是：

```txt
(2^N - 1) - (2^(N - d + 1) - 1) + 1
```

---

## 錯誤程式碼

```cpp
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int getDepth(int x) {
    int depth = 0;

    while (x > 0) {
        depth--;   // 錯誤：深度應該越來越大，不是越來越小
        x /-= 2;   // 錯誤：C++ 沒有 /-= 這種寫法
    }

    return depth;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, a, b;
        cin >> n >> a >> b;

        int da = getDepth(a);
        int db = getDepth(b);

        // 錯誤：下面只是亂印深度，還沒有照題目公式算答案
        cout << max(da, db) << endl;
    }

    return 0;
}
```

---

## 錯誤原因

這份程式主要錯在 `getDepth()`。

這行是錯的：

```cpp
depth--;
```

深度應該越算越大，所以要寫：

```cpp
depth++;
```

例如 `x = 6`：

```txt
6 -> 3 -> 1 -> 0
```

總共除 3 次，所以 6 在第 3 層。

第二個錯誤是：

```cpp
x /-= 2;
```

C++ 沒有 `/=` 前面再加減號這種寫法。  
如果要讓 `x` 除以 2，應該寫：

```cpp
x /= 2;
```

第三個錯誤是，只算出深度還不夠。  
題目最後要的是根據總節點數和子樹大小算答案，不是直接輸出深度。

---

## 正確程式碼

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int getDepth(long long x) {
    int depth = 0;

    while (x > 0) {
        depth++;
        x /= 2;
    }

    return depth;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        long long N, A, B;
        cin >> N >> A >> B;

        int da = getDepth(A);
        int db = getDepth(B);

        int deeper = max(da, db);

        long long total = (1LL << N) - 1;
        long long subtree = (1LL << (N - deeper + 1)) - 1;

        cout << total - subtree + 1 << endl;
    }

    return 0;
}
```

---

## 心得

這題重點不是建樹，而是用編號規則去算。

一開始看到 family tree，可能會想用陣列或真的把樹建出來。  
但其實不用，因為完整二元樹的節點數和子樹大小都可以用 `2` 的次方算。

我覺得這題最重要的是先會算節點在哪一層：

```cpp
while (x > 0) {
    depth++;
    x /= 2;
}
```

然後再把第幾層代入公式。

這題也提醒我，寫 C++ 運算子時要小心。  
`x /= 2` 是對的，但 `x /-= 2` 不是合法語法。

---

## AI 協助說明

這份訂正有使用 AI 協助整理錯誤原因、正確程式碼和 README。  
我有理解這題的重點是完整二元樹、節點深度和子樹大小公式。
