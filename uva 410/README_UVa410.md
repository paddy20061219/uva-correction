# UVA 410 - Station Balance 訂正

## 題目重點

這題是要把一些 specimens 分到 `c` 個 chambers 裡。

每個 chamber 最多放 2 個 specimens。  
題目要我們盡量讓每個 chamber 的重量接近平均值。

輸入有：

- `c`：chamber 數量
- `s`：specimen 數量
- 接著有 `s` 個重量

因為每個 chamber 最多放 2 個，所以我們可以把 specimens 補成 `2 * c` 個。  
不足的地方補 `0`，代表空的位置。

做法是：

1. 建立大小為 `2 * c` 的陣列，全部先放 `0`
2. 把真的 specimen 重量依序放進去
3. 排序
4. 最小的配最大的
5. 算每組和平均值的差，加起來就是 imbalance

配對方式：

```cpp
specimens[i]
specimens[2 * c - 1 - i]
```

這樣可以讓重量比較平均。

---

## 錯誤程式碼

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    int tc=1,c,s,v;

    while(scanf("%d %d",&c,&s) != EOF){
        vector<int> specimens(2*c);
        int total = 0;

        for(int i=0;i<s;i++){
            cin >> v;

            // 錯誤：這裡把重量 v 當成陣列位置
            // 如果 v 很大，可能會超出 vector 範圍
            specimens[v] = v;

            total += v;
        }

        double avg = (double)total/c,imbalance=0;

        sort(specimens.begin(),specimens.end());

        printf("Set #%d\n",tc++);

        for(int i=0;i<c;i++){
            printf(" %d:",i);

            if(specimens[i]) printf(" %d",specimens[i]);

            if(specimens[specimens.size()-1-i])
                printf(" %d",specimens[specimens.size()-1-i]);

            printf("\n");

            imbalance += abs(avg-(specimens[i]+specimens[specimens.size()-1-i]));
        }

        printf("IMBALANCE = %.5f\n",imbalance);
        printf("\n");
    }

    return 0;
}
```

---

## 錯誤原因

這份程式的大方向其實接近正確，因為有想到：

```cpp
vector<int> specimens(2*c);
sort(specimens.begin(), specimens.end());
```

也有想到用最小配最大。

可是最大的錯誤是這行：

```cpp
specimens[v] = v;
```

`v` 是 specimen 的重量，不是陣列位置。

例如如果 `c = 2`，那 vector 大小只有：

```txt
2 * c = 4
```

合法位置只有：

```txt
0 1 2 3
```

可是如果 specimen 重量是 `10`，寫：

```cpp
specimens[10] = 10;
```

就會超出範圍，程式可能直接壞掉。

正確寫法應該是用 `i` 當位置：

```cpp
cin >> specimens[i];
```

因為我們只是要把輸入的重量依序放進 vector。

另外，算 imbalance 時建議用：

```cpp
fabs((a + b) - avg)
```

因為 `avg` 是 `double`，用 `fabs` 比較清楚。

---

## 正確程式碼

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int c, s;
    int tc = 1;

    while (cin >> c >> s) {
        vector<int> specimens(2 * c, 0);

        int total = 0;

        for (int i = 0; i < s; i++) {
            cin >> specimens[i];
            total += specimens[i];
        }

        sort(specimens.begin(), specimens.end());

        double avg = (double)total / c;
        double imbalance = 0;

        cout << "Set #" << tc++ << endl;

        for (int i = 0; i < c; i++) {
            int a = specimens[i];
            int b = specimens[2 * c - 1 - i];

            cout << " " << i << ":";

            if (a != 0) {
                cout << " " << a;
            }

            if (b != 0) {
                cout << " " << b;
            }

            cout << endl;

            imbalance += fabs((a + b) - avg);
        }

        cout << fixed << setprecision(5);
        cout << "IMBALANCE = " << imbalance << endl;
        cout << endl;
    }

    return 0;
}
```

---

## 心得

這題重點是「補 0 後排序，再頭尾配對」。

一開始可能會想很複雜，要怎麼分配才最平均。  
但因為一個 chamber 最多放 2 個，所以可以用比較簡單的貪心想法：

```txt
最輕的配最重的
第二輕的配第二重的
...
```

這樣可以避免兩個很重的被放在一起。

我覺得這題最容易錯的是 vector 的位置。  
輸入的重量只是資料，不可以直接拿來當 index。

像這行：

```cpp
specimens[v] = v;
```

看起來好像有放進去，但其實很危險。  
應該要用第幾個輸入 `i` 來放：

```cpp
specimens[i] = v;
```

或直接：

```cpp
cin >> specimens[i];
```

---

## AI 協助說明

這份訂正有使用 AI 協助整理錯誤原因、正確程式碼和 README。  
我有理解 UVA 410 的重點是排序後頭尾配對，並計算每個 chamber 跟平均值的差距。
