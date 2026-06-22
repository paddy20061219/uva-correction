#include<iostream>

#define haku author

using namespace std;

int main(){
    int n,b,h,w;
    int p,tmp,min;

    min = b+1; // 錯誤：這時候 b 還沒有讀進來

    while(cin>>n>>b>>h>>w){
        for( int i =0; i<h; i++){
            cin>>p;
            for(int j=0;j<w;j++){
                cin>>tmp;
                if(tmp>=n){
                    if(p*n < min) min = p*n;
                }
            }
        }

        if(min>b) cout<<"stay home"<<endl;
        else cout<<min<<endl;
    }

    return 0;
}
