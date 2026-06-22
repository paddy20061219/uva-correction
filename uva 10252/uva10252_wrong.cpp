#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Segment
{
    int L, R;
};

bool comp(const Segment &s1, const Segment &s2)
{
    return s1.L < s2.L;
}

int main()
{  
    int T;
    cin >> T;

    while ( T-- )
    {
        int M;
        cin >> M;

        // 錯誤：這行宣告其實是函式，不是 vector
        vector<Segment> S();

        // 錯誤：UVA 10252 不是區間題，也沒有 T、M、Segment
        // 正確題目是每次讀兩行字串，找共同字母
        cout << "wrong answer" << endl;
    }

    return 0;
}
