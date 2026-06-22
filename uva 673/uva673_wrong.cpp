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
