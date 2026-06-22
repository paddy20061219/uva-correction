# UVA 540 - Team Queue 訂正

## 題目重點

這題叫 Team Queue，意思是「隊伍裡面還要分隊伍」。

普通 queue 是先進先出。  
但是這題有 team 的概念。

規則是：

1. 如果某個人的 team 目前已經在隊伍裡，他要排在自己 team 的最後面。
2. 如果他的 team 目前不在隊伍裡，他的 team 要排到整個大隊伍的最後面。
3. `DEQUEUE` 時，要輸出最前面 team 的第一個人。
4. 如果某個 team 的人全部出隊了，這個 team 也要從大 queue 裡拿掉。

所以這題可以用兩層 queue：

```cpp
queue<int> team_q;
queue<int> member_q[1005];
```

`team_q` 負責記錄目前哪些 team 在大隊伍裡。  
`member_q[tid]` 負責記錄某個 team 裡面的人。

---

## 錯誤程式碼

```cpp
#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

int team_id[1000000];

int main(){
    int t, case_num=1;

    while(cin>>t && t){
        // 錯誤：題目格式要 Scenario #1，不是 Scenario#1
        cout<<"Scenario#"<<case_num++<<endl;

        for(int i=0;i<t;++i){
            int n, member;
            cin>>n;
            while(n--){
                cin>>member;
                team_id[member]=i;
            }
        }

        queue<int> team_q;
        queue<int> member_q[1005];

        string cmd;
        while(cin>>cmd && cmd!="STOP"){
            if(cmd =="ENQUEUE"){
                int x;
                cin >>x;

                int tid = team_id[x];

                if(member_q[tid].empty()){
                    team_q.push(tid);
                }

                member_q[tid].push(x);
            }else if (cmd=="DEQUEUE"){
                int tid = team_q.front();

                cout<<member_q[tid].front()<<endl;
                member_q[tid].pop();

                if(member_q[tid].empty()){
                    team_q.pop();
                }
            }
        }

        cout<<endl;
    }

    return 0;
}
```

---

## 錯誤原因

這份程式其實邏輯大致是對的，已經有用到兩層 queue。

比較容易被 UVA 判錯的地方是輸出格式。

原本寫的是：

```cpp
cout<<"Scenario#"<<case_num++<<endl;
```

可是題目要求是：

```txt
Scenario #1
```

中間要有一個空格。

所以正確寫法是：

```cpp
cout << "Scenario #" << case_num++ << endl;
```

UVA 很常因為少一個空格或冒號位置不對就 Wrong Answer。  
這題演算法對了，但格式錯還是會錯。

另外，這題要注意每個 scenario 結束後，要多印一個空行：

```cpp
cout << endl;
```

這個原本有做到，所以保留。

---

## 正確程式碼

```cpp
#include <iostream>
#include <queue>
using namespace std;

int team_id[1000000];

int main() {
    int t;
    int case_num = 1;

    while (cin >> t && t) {
        cout << "Scenario #" << case_num++ << endl;

        for (int i = 0; i < t; i++) {
            int n;
            cin >> n;

            for (int j = 0; j < n; j++) {
                int member;
                cin >> member;
                team_id[member] = i;
            }
        }

        queue<int> team_q;
        queue<int> member_q[1005];

        string cmd;

        while (cin >> cmd && cmd != "STOP") {
            if (cmd == "ENQUEUE") {
                int x;
                cin >> x;

                int tid = team_id[x];

                if (member_q[tid].empty()) {
                    team_q.push(tid);
                }

                member_q[tid].push(x);
            } else if (cmd == "DEQUEUE") {
                int tid = team_q.front();

                cout << member_q[tid].front() << endl;
                member_q[tid].pop();

                if (member_q[tid].empty()) {
                    team_q.pop();
                }
            }
        }

        cout << endl;
    }

    return 0;
}
```

---

## 心得

這題一開始看起來只是 queue，但其實不能只用一個 queue。

如果只把所有人直接丟進同一個 queue，就沒辦法做到「同一個 team 的人要排在一起」這件事。

比較好想的方式是：

- 大 queue：記錄 team 的順序
- 小 queue：每個 team 自己排自己的成員

`ENQUEUE` 的時候，如果這個 team 還沒出現在大 queue，才把 team 放進去。  
如果 team 已經在裡面，就只要把人放進自己的 team queue。

`DEQUEUE` 的時候，先看大 queue 最前面的 team，從那個 team queue 拿人出來。

這題讓我比較清楚知道 queue 不一定只能用一個，有時候可以用「queue 裡面代表另一群 queue」的想法來解。

---

## AI 協助說明

這份訂正有使用 AI 協助整理錯誤原因、正確程式碼和 README。  
我有理解這題的重點是用兩層 queue，不是單純把所有人排成一條隊伍。
