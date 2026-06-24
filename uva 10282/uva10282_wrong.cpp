#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main()
{   

    string current;

    int t = 1;

    cin >> current;
    while (current != "eh")
    {
        printf("Case %d: ", t);

        if (current == "atcay")
            printf("cat\n");
        else if (current == "ittenkay")
            printf("eh\n");


        else
            printf("loops\n");
        ++t;

        cin >> current;
    }
    return 0;
}
