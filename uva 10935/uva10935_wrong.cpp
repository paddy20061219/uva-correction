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
