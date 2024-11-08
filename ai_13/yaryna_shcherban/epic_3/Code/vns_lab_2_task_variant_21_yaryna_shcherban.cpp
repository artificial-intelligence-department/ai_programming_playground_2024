#include <iostream>
#include <cmath>

using namespace std;

unsigned long long factorial(int n) {
    if ( n >= 2 ){
        return n * factorial ( n - 1 );
    } else if (n == 1){
        return n;
    } 
    return 1;
}

int main() {
    int n;
    double sum = 0;

    for ( n = 1 ; n <= 13 ; n++) {
        sum += log ((double) factorial (n)) / pow (n , 2);
    }
    cout << "The sum of the series is : " << sum << endl;
    return 0;
}
