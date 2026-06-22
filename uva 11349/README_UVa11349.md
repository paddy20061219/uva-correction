# UVA 11349 - Symmetric Matrix 訂正

## 題目重點

這題是判斷一個矩陣是不是 symmetric matrix。

輸入格式比較特別，每筆測資會長得像：

```txt
N = 3
```

所以可以用：

```cpp
char c1, c2;
long long n;
cin >> c1 >> c2 >> n;
```

來讀掉 `N`、`=` 和矩陣大小 `n`。

接著會有 `n * n` 個數字。  
題目要判斷這個矩陣是不是 symmetric。

這題的 symmetric 不是只看左上到右下對角線，而是要看整個矩陣攤平成一排後，前後是不是一樣。

也就是要檢查：

```cpp
a[i] == a[total - 1 - i]
```

另外，只要矩陣裡有負數，就一定是 `Non-symmetric.`。

---

## 錯誤程式碼

```cpp
#include <iostream>
#include <vector>

using namespace std;

void solve(int caseNum) {
    char c1, c2;
    long long n;

    cin >> c1 >> c2 >> n;

    long long totalElements = n * n;
    vector<long long> a(totalElements);

    for (int i = 0; i < totalElements; i++) {
        cin >> a[i];
    }

    bool ok = true;

    // 錯誤：只檢查前一半是不是正數，完全沒有檢查對稱
    for (int i = 0; i < totalElements / 2; i++) {
        if (a[i] < 0) {
            ok = false;
        }
    }

    // 錯誤：中間或後半部如果是負數，這裡可能沒檢查到
    // 錯誤：UVA 11349 要檢查 a[i] == a[totalElements - 1 - i]

    if (ok) {
        cout << "Test #" << caseNum << ": Symmetric." << endl;
    } else {
        cout << "Test #" << caseNum << ": Non-symmetric." << endl;
    }
}

int main() {
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}
```

---

## 錯誤原因

這份程式有讀到 `N = n`，也有把矩陣數字讀進來，方向算是有開始對。

但是它沒有真的檢查對稱。

原本只寫：

```cpp
for (int i = 0; i < totalElements / 2; i++) {
    if (a[i] < 0) {
        ok = false;
    }
}
```

這樣只檢查前一半有沒有負數。  
可是 UVA 11349 要檢查兩件事：

第一，所有數字都不能是負數：

```cpp
if (a[i] < 0) ok = false;
```

第二，前後位置要一樣：

```cpp
if (a[i] != a[total - 1 - i]) ok = false;
```

例如一個矩陣攤平成：

```txt
1 2 3 2 1
```

它前後是對稱的。

但如果是：

```txt
1 2 3 4 1
```

就不是對稱，因為 `2` 和 `4` 對不起來。

---

## 正確程式碼

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        char c1, c2;
        long long n;

        cin >> c1 >> c2 >> n;

        long long total = n * n;
        vector<long long> a(total);

        bool ok = true;

        for (long long i = 0; i < total; i++) {
            cin >> a[i];

            if (a[i] < 0) {
                ok = false;
            }
        }

        for (long long i = 0; i < total; i++) {
            if (a[i] != a[total - 1 - i]) {
                ok = false;
                break;
            }
        }

        cout << "Test #" << tc << ": ";

        if (ok) {
            cout << "Symmetric." << endl;
        } else {
            cout << "Non-symmetric." << endl;
        }
    }

    return 0;
}
```

---

## 心得

這題我覺得最容易誤會的是 symmetric 的檢查方式。

如果用二維矩陣去想，可能會想成檢查：

```cpp
matrix[i][j] == matrix[j][i]
```

但這題比較簡單，可以直接把所有數字存成一維陣列，然後檢查前後是否一樣。

所以核心只有這行：

```cpp
a[i] == a[total - 1 - i]
```

還有題目有說數字不能是負的，所以讀入時順便檢查負數。

這題也要小心輸出格式：

```txt
Test #1: Symmetric.
```

`#`、冒號、空格和句點都要一樣。

---

## AI 協助說明

這份訂正有使用 AI 協助整理錯誤原因、正確程式碼和 README。  
我有理解這題的重點是檢查負數，還有用一維陣列判斷前後對稱。
