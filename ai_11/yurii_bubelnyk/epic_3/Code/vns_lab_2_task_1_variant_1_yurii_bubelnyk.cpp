#include <iostream>
using namespace std;

int main (){
    int sum = 0;
    for (int i = 1; i < 200; i++){
        if(i % 3 == 0)
            sum += i;
    }
    cout << sum;
    return 0;
}
