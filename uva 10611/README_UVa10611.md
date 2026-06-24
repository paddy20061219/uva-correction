# UVa 10611 - The Playboy Chimp

## 題目重點

這題會給你一排女生黑猩猩的身高，身高是已經排序好的。

後面會有很多次查詢，每次給一個男生黑猩猩的身高 `x`，要找：

```text
比 x 矮的最高身高
比 x 高的最矮身高
```

如果找不到，就輸出 `X`。

例如身高是：

```text
1 4 5 7
```

查詢 `5`：

```text
比 5 矮的最高是 4
比 5 高的最矮是 7
```

所以輸出：

```text
4 7
```

---

## 錯誤程式碼

檔案：`uva10611_wrong.cpp`

```cpp
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>


using namespace std;

int main(){
    cout<<fixed<<setw(n)<<setfill('0')<<output;
    cout<<hex<<decimal;

    char upper = 'A'+x;
    char lowerCh= 'a'+x;
    int idx=lowerCh-'a';

    cout<<fixed<<setprecision(n)<<doublenum;


}
```

---

## 錯誤原因

這份錯誤程式碼完全寫錯方向了。

主要問題：

1. 題目不是在考輸出格式  
   所以 `setw`、`setfill`、`setprecision` 都不是這題重點。

2. 程式裡有很多變數沒有宣告  
   例如：

```cpp
n
output
x
doublenum
```

這樣會直接編譯失敗。

3. `cout << hex << decimal;` 也不是這題需要的東西  
   而且 C++ 裡常用的是 `dec`，不是 `decimal`。

4. 題目真正要做的是「查詢身高」  
   要讀入陣列，然後對每個查詢找出左邊答案和右邊答案。

---

## 正確程式碼

檔案：`uva10611_AC.cpp`

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> h(n);

    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    int q;
    cin >> q;

    while (q--) {
        int x;
        cin >> x;

        // 找第一個 >= x 的位置
        int pos1 = lower_bound(h.begin(), h.end(), x) - h.begin();

        // 找第一個 > x 的位置
        int pos2 = upper_bound(h.begin(), h.end(), x) - h.begin();

        if (pos1 == 0) {
            cout << "X";
        } else {
            cout << h[pos1 - 1];
        }

        cout << " ";

        if (pos2 == n) {
            cout << "X";
        } else {
            cout << h[pos2];
        }

        cout << "\n";
    }

    return 0;
}
```

---

## 心得

這題重點是要知道 `lower_bound` 和 `upper_bound` 的差別。

```cpp
lower_bound
```

會找第一個 `>= x` 的位置，所以它的前一個位置就是「比 x 小的最大值」。

```cpp
upper_bound
```

會找第一個 `> x` 的位置，所以它自己就是「比 x 大的最小值」。

如果位置超出範圍，就要輸出 `X`。  
這題比自己用迴圈慢慢找更適合用二分搜尋，因為查詢可能很多。

---

## AI 協助說明

這份訂正有使用 AI 幫忙整理程式碼和 README 說明，但我有照題目的查詢邏輯去理解，並保留成比較像初學者訂正時會寫的版本。
