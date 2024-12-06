#include <iostream>
#include <cmath>

using namespace std;

int main(){

    double x, y;
    cout << "Enter X \n";
    cin >> x;
    for ( int i = 1; i <= 10; i++){
        y += (pow(x, i) / i);
        cout << "Для i = " << i << ", y = " << y << endl;
    }
    
    return 0;
}