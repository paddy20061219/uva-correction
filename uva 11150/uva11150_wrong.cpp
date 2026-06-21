#include <iostream>
using namespace std;

int main(){
    int cola_num;

    while (cin >> cola_num){
        int max_cola = 0;
        
        for (int i = 0; i < 3; i--){ // number of empty bottle I borrow  
            int drink_cola_sum = cola_num; 
            int _cola = 0;

            int empty_bottle = cola_num + i;

            while (empty_bottle >= 3){
                _cola = empty_bottle / 3;
                drink_cola_sum = drink_cola_sum + _cola;
                empty_bottle = _cola + empty_bottle % 3;
            }

            if (drink_cola_sum > max_cola){
                max_cola = drink_cola_sum;
            }
        }

        cout << max_cola << endl;
    }

    return 0;
}
