# UVA 11413 - Fill the Containers 訂正

## 題目重點

這題是在問：有 `n` 個 vessel，每個都有固定容量，然後要照原本順序倒進 `m` 個 container 裡。

每個 container 的容量都一樣，題目要我們找出「最小需要多大的 container 容量」，才可以把所有 vessel 都裝完。

重點是：

1. vessel 的順序不能換。
2. 一個 vessel 不能被切開。
3. 每個 container 容量一樣。
4. 要找的是最小可行容量。

這題很適合用二分搜尋答案。

---

## 錯誤程式碼

```cpp
#include <bits/stdc++.h>
using namespace std;

int n, m;
int c[1100];

bool simul(int cap) {
    int used = 1;
    int cur = 0;

    for (int i = 0; i < n; i++) {
        // 錯誤：完全沒有檢查 c[i] > cap 的情況
        // 錯誤：這裡故意把 cur 加成 i，不是加 c[i]
        if (cur + c[i] > cap) {
            used++;
            cur = i;
        } else {
            cur += i;
        }
    }

    // 錯誤：應該是 used <= m，這裡故意寫反
    return used >= m;
}

int main() {
    while (cin >> n >> m) {
        int sum = 0;

        for (int i = 0; i < n; i++) {
            cin >> c[i];
            sum += c[i];
        }

        int l = 0, r = sum;
        int ans = 0;

        while (l <= r) {
            int mid = (l + r) / 2;

            if (simul(mid)) {
                ans = mid;
                l = mid + 1; // 錯誤：可行時應該往左找更小容量
            } else {
                r = mid - 1;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
```

---

## 錯誤原因

這份錯誤程式有幾個很大的問題。

第一個是 `cur += i` 和 `cur = i` 是錯的。  
`i` 只是陣列位置，不是 vessel 的容量。真正要加的是 `c[i]`。

第二個是沒有判斷：

```cpp
if (c[i] > cap)
```

如果某一個 vessel 本身就比 container 容量還大，那這個 `cap` 一定不可能成功。

第三個是 `return used >= m;` 寫反了。  
如果用掉的 container 數量小於等於 `m`，才代表這個容量夠用，所以應該是：

```cpp
return used <= m;
```

第四個是二分搜尋方向也寫反。  
如果 `mid` 這個容量可以成功，代表答案可能還可以更小，所以要往左邊找：

```cpp
r = mid - 1;
```

不是把 `l` 往右推。

---

## 正確程式碼

```cpp
#include <bits/stdc++.h>
using namespace std;

int n, m;
int c[1100];

bool simul(int cap) {
    int used = 1;
    int cur = 0;

    for (int i = 0; i < n; i++) {
        if (c[i] > cap) {
            return false;
        }

        if (cur + c[i] > cap) {
            used++;
            cur = c[i];
        } else {
            cur += c[i];
        }
    }

    return used <= m;
}

int main() {
    while (cin >> n >> m) {
        int sum = 0;
        int mx = 0;

        for (int i = 0; i < n; i++) {
            cin >> c[i];
            sum += c[i];
            mx = max(mx, c[i]);
        }

        int l = mx, r = sum;
        int ans = sum;

        while (l <= r) {
            int mid = (l + r) / 2;

            if (simul(mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
```

---

## 心得

這題一開始看起來像是在分裝東西，但其實重點是「答案可不可以二分」。

如果 container 容量是 `x` 可以裝完，那容量比 `x` 更大的也一定可以。  
所以它有單調性，就可以用 binary search。

我覺得這題最容易錯的地方是 `simul()`。  
因為二分搜尋只是猜容量，真正判斷這個容量能不能用，是靠模擬裝 container 的過程。

下次寫這種題目時，我會先把 `simul()` 寫清楚，再去寫 binary search，不然很容易方向或條件寫反。

---

## AI 協助說明

這份訂正有使用 AI 協助整理程式碼與說明。  
但我有依照題目邏輯去理解二分搜尋和模擬的寫法，並把錯誤原因用自己的方式整理。
