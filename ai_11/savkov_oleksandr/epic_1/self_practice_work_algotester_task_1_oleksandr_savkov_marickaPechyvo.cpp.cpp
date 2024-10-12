#include <iostream>

using namespace std;


int main() {
    int pach;
    int shtyk;
    long long summ = 0;
    cin >> pach;
 
    for(int i = 1; i <= pach; i++ ){
         cin >> shtyk; 
          shtyk = shtyk - 1;
         summ += shtyk;
    }

    cout << summ;
    return 0;
}