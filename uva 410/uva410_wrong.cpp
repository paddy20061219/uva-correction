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
