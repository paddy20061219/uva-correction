# UVa 10341 - Solve It

## 題目重點

這題要解一個方程式：

```text
p * e^(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x^2 + u = 0
```

題目要找的 `x` 範圍是：

```text
0 <= x <= 1
```

如果有解，要輸出到小數點後 4 位。  
如果沒有解，要輸出：

```text
No solution
```

這題的重點不是暴力試很多數字，  
而是用二分搜尋找答案。

因為在題目限制下，這個函數在 `[0,1]` 會是單調遞減，  
所以可以用 binary search。

---

## 錯誤程式碼

```cpp
#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define ft first
#define sec second
#define pr pair<int,int>
#define ISCC ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int t,n,m,cas;
vector<int> a;

int main()
{
    while(cin>>n>>m&&n){
        a.clear();
        for(int i=0, b ;i<n;i++) cin>>b,a.pb(b);
    }

    return 0;
}
```

---

## 錯誤原因

這份程式主要是題目方向錯了。

UVa 10341 不是讀 `n` 個數字放進 vector，  
而是每一筆測資會給 6 個係數：

```text
p q r s t u
```

然後要拿這 6 個係數去解方程式。

主要錯誤：

1. 只讀了 `n` 和 `m`，但題目要讀 `p q r s t u` 六個數。
2. `vector<int> a` 跟這題沒有關係。
3. `while(cin >> n >> m && n)` 也不對，因為這題不是用 `n = 0` 當結束。
4. 完全沒有計算函數值。
5. 沒有判斷 `[0,1]` 之間有沒有解。
6. 沒有用二分搜尋找答案。
7. 沒有照題目要求輸出小數點後 4 位。

所以這份程式比較像是別題的輸入模板，還沒有開始解 10341。

---

## 正確程式碼

```cpp
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int p, q, r, s, t, u;

double f(double x) {
    return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

int main() {
    while (cin >> p >> q >> r >> s >> t >> u) {
        double left = 0.0;
        double right = 1.0;

        double fLeft = f(left);
        double fRight = f(right);

        if (fLeft * fRight > 0) {
            cout << "No solution" << endl;
            continue;
        }

        for (int i = 0; i < 100; i++) {
            double mid = (left + right) / 2.0;

            if (f(mid) > 0) {
                left = mid;
            } else {
                right = mid;
            }
        }

        cout << fixed << setprecision(4) << (left + right) / 2.0 << endl;
    }

    return 0;
}
```

---

## 心得

這題一開始看起來公式很可怕，  
但其實真正要做的事情是二分搜尋。

我覺得這題可以先記一個想法：

```text
如果 f(0) 和 f(1) 同號，代表中間沒有解
如果不同號，就用二分搜慢慢逼近答案
```

因為答案只要小數點後 4 位，  
所以二分搜跑 100 次已經很夠了。

這次訂正有使用 AI 協助整理錯誤原因與正確解法，但我有重新理解二分搜為什麼可以用。
