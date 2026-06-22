# UVA 10020 - Minimal Coverage 訂正

## 題目重點

UVA 10020 是區間覆蓋題。

題目會給一個目標區間：

```txt
[0, M]
```

然後給很多個小區間：

```txt
l r
```

最後用：

```txt
0 0
```

代表這筆測資的區間輸入結束。

我們要從這些區間裡選出最少數量的區間，讓它們可以完整覆蓋 `[0, M]`。

如果沒辦法覆蓋，就輸出：

```txt
0
```

如果可以，就輸出選了幾個區間，然後輸出那些區間。

這題是 greedy 題。  
做法是：

1. 先依照左端點排序
2. 目前已經覆蓋到 `covered`
3. 找所有 `l <= covered` 的區間
4. 從裡面選右端點 `r` 最大的那個
5. 把 `covered` 更新成那個最大右端點
6. 一直做到 `covered >= M`

---

## 錯誤程式碼

```cpp
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

int main(){
    int l,r;

    while(l--){ // 錯誤：l 還沒有讀入，就拿來 while
        segment[0, M]{ // 錯誤：C++ 沒有這種寫法，而且 segment、M 都沒宣告
            if(i=1) // 錯誤：i 沒宣告，而且 = 是指定，不是比較
                cout<<
        }
    }

    return 0;
}
```

---

## 錯誤原因

這份程式還是草稿狀態，有很多語法還沒有完成。

第一個問題是：

```cpp
while(l--)
```

`l` 還沒有讀入任何值，就直接拿來跑迴圈。  
這樣不合理。

第二個問題是：

```cpp
segment[0, M]{
```

C++ 沒有這種寫法。  
如果要表示一個區間，通常會自己寫一個 struct：

```cpp
struct Segment {
    int l, r;
};
```

第三個問題是：

```cpp
if(i=1)
```

這裡有兩個錯：

1. `i` 沒有宣告
2. `=` 是指定，不是比較

如果要比較，應該是：

```cpp
if (i == 1)
```

不過 UVA 10020 其實不需要這樣寫。

這題真正要做的是「貪心選區間」。  
每一次都從可以接上的區間裡，選右端點最遠的那一個。

---

## 正確程式碼

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Segment {
    int l, r;
};

bool cmp(Segment a, Segment b) {
    if (a.l != b.l) return a.l < b.l;
    return a.r > b.r;
}

int main() {
    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++) {
        int M;
        cin >> M;

        vector<Segment> seg;
        int l, r;

        while (cin >> l >> r) {
            if (l == 0 && r == 0) {
                break;
            }

            seg.push_back({l, r});
        }

        sort(seg.begin(), seg.end(), cmp);

        vector<Segment> ans;
        int covered = 0;
        int i = 0;
        bool ok = true;

        while (covered < M) {
            int bestR = covered;
            Segment bestSeg;
            bool found = false;

            while (i < seg.size() && seg[i].l <= covered) {
                if (seg[i].r > bestR) {
                    bestR = seg[i].r;
                    bestSeg = seg[i];
                    found = true;
                }
                i++;
            }

            if (!found) {
                ok = false;
                break;
            }

            ans.push_back(bestSeg);
            covered = bestR;
        }

        if (tc > 0) {
            cout << endl;
        }

        if (!ok) {
            cout << 0 << endl;
        } else {
            cout << ans.size() << endl;

            for (int j = 0; j < ans.size(); j++) {
                cout << ans[j].l << " " << ans[j].r << endl;
            }
        }
    }

    return 0;
}
```

---

## 心得

這題是很典型的 interval greedy。

我覺得這題最重要的一句話是：

```txt
在所有左端點 <= covered 的區間裡，選右端點最大的。
```

因為目前已經覆蓋到 `covered`，所以下一段區間一定要能接上來。  
如果某個區間的左端點比 `covered` 還大，中間就會有空洞，不能選。

如果能接上的區間有很多個，就選延伸最遠的那個。  
這樣可以讓使用的區間數量最少。

這題容易錯在輸出格式。  
每筆測資中間要空一行，但是最後不要亂多印很多東西。

---

## AI 協助說明

這份訂正有使用 AI 協助整理錯誤原因、正確程式碼和 README。  
我有理解 UVA 10020 的重點是用 greedy 覆蓋 `[0, M]`，不是單純把區間全部輸出。
