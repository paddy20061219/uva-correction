# UVa 11136 - Hoax or what

## 題目重點

這題每天會有一些收據金額。

每天要做的事情是：

1. 把今天所有收據金額放進去
2. 找出目前全部收據裡面最大的金額
3. 找出目前全部收據裡面最小的金額
4. 把 `最大 - 最小` 加到答案
5. 把這兩張收據刪掉

一直做完 `n` 天後，輸出總共付了多少錢。

因為要一直找最大、最小，還要刪掉，所以這題可以用：

```cpp
multiset<long long>
```

`multiset` 可以排序，也允許重複數字，很適合這題。

## 錯誤程式碼

```cpp
#include <iostream>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n && n != 0) {
        multiset<long long> s;

        // 我原本以為 n 就是收據數量
        // 但其實 n 是天數，後面每天還有 k 張收據
        long long x;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            cin >> x;
            s.insert(x);
        }

        if (!s.empty()) {
            ans = *s.rbegin() - *s.begin();
        }

        cout << ans << endl;
    }

    return 0;
}
```

## 錯誤原因

這份程式碼主要是把輸入格式看錯了。

題目的第一個數字 `n` 代表有幾天，不是代表有幾張收據。

每一天的輸入格式是：

```txt
k bill1 bill2 bill3 ...
```

其中 `k` 才是當天有幾張收據。

錯誤程式這邊：

```cpp
for (int i = 0; i < n; i++) {
    cin >> x;
    s.insert(x);
}
```

它只讀了 `n` 個數字，這樣會把每天的 `k` 也當成金額讀進去，整個資料就亂掉了。

另外這題不是最後只做一次 `最大 - 最小`。

正確做法是每天都要做一次：

```cpp
total += 最大值 - 最小值;
```

然後還要把最大和最小刪掉，剩下的收據會留到下一天繼續用。

## 正確程式碼

```cpp
#include <iostream>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    while (cin >> n && n != 0) {
        multiset<long long> bills;
        long long total = 0;

        for (int day = 0; day < n; day++) {
            int k;
            cin >> k;

            for (int i = 0; i < k; i++) {
                long long x;
                cin >> x;
                bills.insert(x);
            }

            auto small = bills.begin();
            auto big = prev(bills.end());

            total += *big - *small;

            bills.erase(big);
            bills.erase(small);
        }

        cout << total << "\n";
    }

    return 0;
}
```

## 心得

這題我覺得最容易錯的是輸入格式。

一開始看到 `n` 很容易以為它是收據數量，但其實它是天數。

而且每天收據放進去後，不是只看今天的收據，而是要看目前還留著的全部收據。

這題用 `multiset` 會比自己排序簡單很多，因為它可以一直維持排序，也可以處理重複的金額。

要刪最大值可以用：

```cpp
auto big = prev(bills.end());
```

因為 `end()` 不是最後一個元素，它是最後面再過去的位置，所以要用 `prev()`。

本份訂正有使用 AI 協助整理與檢查，但我有自己看過邏輯，主要是練習 `multiset` 的最大最小值操作。
