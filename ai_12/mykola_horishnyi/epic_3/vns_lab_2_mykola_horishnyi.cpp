#include <iostream>
using namespace std ;

int main() {
    int sum = 0;

    for (int i = 1; i < 200; i += 2)
    { 
        sum += i;                    
    }
    cout << "The sum of odd numbers less than 200: " << sum ;



    return 0;
}



