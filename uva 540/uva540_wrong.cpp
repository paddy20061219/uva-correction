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
