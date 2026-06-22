#include <iostream>

using namespace std;

int main()
{
    int num[500];
    int c = 0;
    int x;

    while( cin >> num[c] )
    {
        x = num[c];

        for(int i = 0 ; i <= c ; i++)
        {
            if( x <= num[i] )
            {
                for(int j = c+1 ; j > i;j--)
                {
                    num[j] = num[j-1];
                }

                num[i] = x;
                break;
            }
        }

        // 錯誤：這段是在輸出目前讀到數字的中位數
        // UVA 10041 要的是每筆測資算最短總距離
        if(c%2 ==0)
            cout<<num[c/2]<<endl;
        else
            cout<<(num[c/2]+num[c/2+1])/2<<endl;

        c++;
    }

    return 0;
}
