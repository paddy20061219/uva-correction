# UVA 673 - Parentheses Balance 訂正

## 題目重點

這題是判斷每一行括號有沒有平衡。

會出現的括號有兩種：

```txt
()
[]
```

每一行如果括號配對正確，就輸出：

```txt
Yes
```

如果不正確，就輸出：

```txt
No
```

例如：

```txt
([])
```

是正確的，因為 `[` 有配到 `]`，`(` 也有配到 `)`。

但是：

```txt
([)]
```

是錯的，因為括號順序交錯了。

這題最常用的做法是 stack。

---

## 錯誤程式碼

```cpp
#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

int t;
string s;
stack<char>st;

int main(){
    cin>>t
    getchar();

    while(t--){
        getline(cin,s);

        while(!st.empty())
            sp.pop();

        // 錯誤：下面還沒真的判斷括號
        cout << "Yes" << endl;
    }

    return 0;
}
```

---

## 錯誤原因

這份程式有幾個很明顯的問題。

第一個是這行少了分號：

```cpp
cin>>t
```

應該要寫成：

```cpp
cin >> t;
```

第二個是這行變數名字打錯：

```cpp
sp.pop();
```

前面宣告的是：

```cpp
stack<char> st;
```

所以應該是：

```cpp
st.pop();
```

第三個是雖然有宣告 stack，但是還沒有真的判斷括號。  
不能每次都直接輸出 `Yes`，要看括號有沒有正確配對。

第四個是這題要用 `getline` 讀一整行。  
因為讀完 `t` 之後，換行符號還留在輸入裡，所以要先用：

```cpp
cin.ignore();
```

不然第一筆可能會讀到空字串。

---

## 正確程式碼

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string s;
        getline(cin, s);

        stack<char> st;
        bool ok = true;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[') {
                st.push(s[i]);
            } else if (s[i] == ')') {
                if (st.empty() || st.top() != '(') {
                    ok = false;
                    break;
                }
                st.pop();
            } else if (s[i] == ']') {
                if (st.empty() || st.top() != '[') {
                    ok = false;
                    break;
                }
                st.pop();
            }
        }

        if (!st.empty()) {
            ok = false;
        }

        if (ok) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
```

---

## 心得

這題的重點是 stack。

遇到左括號 `(` 或 `[` 就先放進 stack。  
遇到右括號 `)` 或 `]` 時，就檢查 stack 最上面的括號是不是對應的左括號。

如果 stack 是空的，代表右括號太早出現，所以一定錯。  
如果最後 stack 還有東西，代表有左括號沒有配到右括號，也是不平衡。

這題我覺得很適合練習 stack，因為它的規則很直覺。  
只要記得「最後進去的左括號，要最先被配掉」就可以理解。

---

## AI 協助說明

這份訂正有使用 AI 協助整理錯誤原因、正確程式碼和 README。  
我有理解 stack 的做法，也知道這題不是只算左右括號數量，而是要檢查順序。
