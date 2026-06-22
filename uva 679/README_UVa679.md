# UVA 679 - Dropping Balls 訂正

## 題目重點

UVA 679 這題是在模擬球從一棵完整二元樹掉下來。

每個節點都有一個開關。  
球經過節點時，會依照目前開關方向往左或往右，然後開關會反轉。

題目給：

- `D`：樹的深度
- `I`：第幾顆球

要輸出第 `I` 顆球最後會掉到哪一個節點。

節點編號像 heap 一樣：

```txt
root = 1
left child = node * 2
right child = node * 2 + 1
```

這題不用真的建樹。  
只要根據 `I` 是奇數還是偶數，判斷每一層要往左還是往右。

---

## 錯誤程式碼

```cpp
#include<iostream>
#include<string>
#include<alogrithm> // 錯誤：algorithm 拼錯

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int root_val;
    int cas = 0;

    // 錯誤：main 這裡直接結束，完全沒有讀 UVA 679 的 D 和 I
} 

void build_tree(int pos, vector<int>& sums, int& min_pos, int& max_pos) {
    int val;
    cin >> val;

    if (val == -1) {
        return;
    }

    sums[pos] += val;
    min_pos = min(min_pos, pos);
    max_pos = max(max_pos, pos);

    build_tree(pos - 1, sums, min_pos, max_pos);
    build_tree(pos + 1, sums, min_pos, max_pos);
}
```

---

## 錯誤原因

這份程式有幾個問題。

第一個是標頭檔拼錯：

```cpp
#include<alogrithm>
```

正確是：

```cpp
#include <algorithm>
```

第二個是用了 `vector<int>`，但是沒有引入：

```cpp
#include <vector>
```

第三個是 `main()` 裡面沒有真的處理 UVA 679 的輸入。  
UVA 679 要讀的是：

```cpp
int T;
cin >> T;

while (T--) {
    int D, I;
    cin >> D >> I;
}
```

第四個是這份程式的方向比較像在寫「樹的垂直加總」，不是 UVA 679。  
UVA 679 不需要建樹，也不需要 `sums`、`min_pos`、`max_pos`。

這題重點是：  
如果第 `I` 顆球到了某個節點：

- `I` 是奇數，往左走
- `I` 是偶數，往右走

走左邊後：

```cpp
I = (I + 1) / 2;
```

走右邊後：

```cpp
I = I / 2;
```

一直走到第 `D` 層，就可以得到答案。

---

## 正確程式碼

```cpp
#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int D, I;
        cin >> D >> I;

        int node = 1;

        for (int level = 1; level < D; level++) {
            if (I % 2 == 1) {
                node = node * 2;
                I = (I + 1) / 2;
            } else {
                node = node * 2 + 1;
                I = I / 2;
            }
        }

        cout << node << endl;
    }

    return 0;
}
```

---

## 心得

這題一開始可能會想真的建一棵二元樹，然後每顆球都丟一次。  
可是這樣其實很麻煩，而且資料大時也不好做。

比較簡單的方法是只追第 `I` 顆球的路線。

因為每個節點的球會左右左右輪流走。  
所以如果目前是第奇數顆到這個節點，就往左。  
如果是第偶數顆到這個節點，就往右。

這題讓我學到，有些樹題不一定要真的建樹。  
只要知道節點編號規則，就可以用數學和迴圈直接算。

---

## AI 協助說明

這份訂正有使用 AI 協助整理錯誤原因、正確程式碼和 README。  
我有理解 UVA 679 的重點是判斷第 `I` 顆球在每一層要往左或往右，不是建整棵樹。
