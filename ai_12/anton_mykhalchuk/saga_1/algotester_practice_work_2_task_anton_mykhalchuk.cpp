#include <iostream>

using namespace std;

int main() {
    long long n;
    cin >> n;
    int divisors[9] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
    int amount = 0;
    
    for (int i = 0; i < 9; i++) {
        if (n >= divisors[i]) {
            int k = n / divisors[i];
            amount += k;
            n -= divisors[i] * k;
        }
    }
    
    cout << amount;
    
    return 0;
}
