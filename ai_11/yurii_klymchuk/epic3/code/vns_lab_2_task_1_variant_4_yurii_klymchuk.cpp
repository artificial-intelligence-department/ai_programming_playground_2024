#include <iostream>

using namespace std;

int main(){
    int sum;
    for (int i = 20; i <= 100; i++){
        if(i % 3 == 0){
            sum += i;
        }
    }
    cout << "The sum of number from 20 to 100 aliquot 3: " << sum;
    return 0;
}