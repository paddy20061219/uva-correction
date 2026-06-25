# UVa 10242 - Fourth Point !!

## 題目重點

這題會給四個點，但是其中有兩個點其實是同一個點。

因為平行四邊形的兩條邊會共用一個點，所以要找出那個重複的點，然後用另外兩個點算出第四個點。

公式可以先記成：

```cpp
答案點 = 另外一點A + 另外一點B - 重複點
```

也就是：

```cpp
ans.x = a.x + b.x - same.x;
ans.y = a.y + b.y - same.y;
```

輸出要到小數點後 3 位。

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

## 錯誤原因

這份程式其實跟 UVa 10242 的題目不太有關。

題目輸入的是 4 個座標點，也就是 8 個小數，不是一個整數 `n`。

而且題目要算的是平行四邊形的第四個點，不是算 `n + n / 2`。

另外 `return 0;` 放在 `while` 裡面，代表只讀一次就結束了，UVa 題目通常要一直讀到 EOF。

這題也要用 `double`，不能只用 `int`，不然小數座標會壞掉。

## 正確程式碼

```cpp
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

struct Point {
    double x;
    double y;
};

bool samePoint(Point a, Point b) {
    return fabs(a.x - b.x) < 1e-9 && fabs(a.y - b.y) < 1e-9;
}

int main() {
    Point p1, p2, p3, p4;

    while (cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y) {
        Point same, a, b;

        if (samePoint(p1, p3)) {
            same = p1;
            a = p2;
            b = p4;
        }
        else if (samePoint(p1, p4)) {
            same = p1;
            a = p2;
            b = p3;
        }
        else if (samePoint(p2, p3)) {
            same = p2;
            a = p1;
            b = p4;
        }
        else {
            same = p2;
            a = p1;
            b = p3;
        }

        Point ans;
        ans.x = a.x + b.x - same.x;
        ans.y = a.y + b.y - same.y;

        cout << fixed << setprecision(3) << ans.x << " " << ans.y << endl;
    }

    return 0;
}
```

## 心得

這題一開始很容易看不懂，因為它不是要算面積或距離，而是要從四個點裡面找出重複的點。

我覺得重點是先把「哪個點重複」找出來，剩下就只是套公式。

這題也提醒我，讀題時要注意輸入格式，因為這題是小數座標，不能自己假設只有一個整數。

本份訂正有使用 AI 協助整理與檢查，但程式邏輯和內容我有再看過並理解。
