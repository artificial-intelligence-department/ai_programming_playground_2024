#include <iostream>
using namespace std;

int main() {
    unsigned int n;
    cout << "n = ";
    cin >> n;
    int max = 0;  
    int a = 0;  

    while (n > 0) {
        if (n & 1) {
            a++;  
            max = (max > a)? max : a;  
        } else {
            a = 0;  
        }
        n >>= 1 ;  
    }

    cout <<"Max = " << max << endl;  
    return 0;
}
