# UVA 10935 - Throwing cards away I 訂正

## 題目重點

這題是在模擬丟牌。

一開始有 `1` 到 `n` 張牌，排成一疊，`1` 在最上面。

每一輪要做兩件事：

1. 把最上面的牌丟掉，並輸出它
2. 把新的最上面那張牌移到最下面

一直做到只剩一張牌。  
最後要輸出被丟掉的牌，還有最後剩下的牌。

輸出格式很重要，例如：

```txt
Discarded cards: 1, 3, 5, 7, 4, 2
Remaining card: 6
```

這題適合用 `queue`，因為牌是從前面拿，移動的牌放到後面。

---

## 錯誤程式碼

```cpp
#include<queue>
#include<iostream>

using namespace std;

int main(){
    int n,i,j,k;
    while(cin >> n && n){
        queue<int> qu;
        for (i=1; i<=n; ++i){
            qu.push(i);
        }

        cout << "Discarded cards:";
        bool first = true;

        while(qu.size()>1){
            if (first){
                cout << " " << qu.front();
                first = false;
                // 錯誤：這裡只有印出來，沒有真的把牌丟掉
            }else{
                cout << " " << qu.front();
                qu.pop();

                j = qu.front();
                qu.pop();
                qu.push(j);
            }

            // 錯誤：Remaining card 不應該在 while 裡面一直輸出
            cout << endl;
            cout << "Remaining card:" << qu.front() << endl;
        }
    }

    return 0;
}
```

---

## 錯誤原因

這份程式大方向是對的，因為有想到要用 `queue`。  
但是模擬的步驟有幾個地方錯了。

第一個錯誤是第一張牌只印出來，沒有真的 `pop()` 掉：

```cpp
if (first){
    cout << " " << qu.front();
    first = false;
}
```

這樣第一張牌還留在 queue 裡，下一輪又會被處理一次，結果就不對。

正確做法應該是每一輪都先丟掉最上面的牌：

```cpp
int discard = q.front();
q.pop();
```

第二個錯誤是輸出格式少了逗號。  
題目要求丟掉的牌中間要用 `, ` 分開，不是只有空格。

例如要輸出：

```txt
Discarded cards: 1, 3, 5
```

不是：

```txt
Discarded cards: 1 3 5
```

第三個錯誤是：

```cpp
cout << "Remaining card:" << qu.front() << endl;
```

被放在 `while(qu.size()>1)` 裡面。  
這樣每丟一次牌就會輸出一次 remaining card，格式會完全不符合題目。

應該等到迴圈結束，只剩一張牌時才輸出。

另外，題目格式是：

```cpp
cout << "Remaining card: " << q.front() << endl;
```

`card:` 後面要有一個空格。

---

## 正確程式碼

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;

    while (cin >> n && n) {
        queue<int> q;

        for (int i = 1; i <= n; i++) {
            q.push(i);
        }

        cout << "Discarded cards:";

        bool first = true;

        while (q.size() > 1) {
            int discard = q.front();
            q.pop();

            if (first) {
                cout << " " << discard;
                first = false;
            } else {
                cout << ", " << discard;
            }

            int moveCard = q.front();
            q.pop();
            q.push(moveCard);
        }

        cout << endl;
        cout << "Remaining card: " << q.front() << endl;
    }

    return 0;
}
```

---

## 心得

這題重點就是照題目一步一步模擬。

我一開始容易錯在以為「印出來」就等於「丟掉」，但其實 queue 裡面的資料還在。  
所以每次丟牌一定要做：

```cpp
q.pop();
```

還有這題輸出格式很嚴格，逗號和空格都要注意。  
UVA 題目常常不是邏輯錯，而是格式少一個空格就 Wrong Answer。

這題可以拿來練習 `queue`：

- `front()` 看最前面的值
- `pop()` 拿掉最前面的值
- `push()` 放到最後面

---

## AI 協助說明

這份訂正有使用 AI 協助整理錯誤原因、正確程式碼和 README。  
我有理解 queue 的模擬方式，也知道每一輪要先丟一張，再把下一張移到最後。
