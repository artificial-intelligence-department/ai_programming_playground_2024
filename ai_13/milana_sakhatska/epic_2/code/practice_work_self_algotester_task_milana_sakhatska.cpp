#include <iostream>
using namespace std;

int main() {
    // denominations = d
    int d[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
    int n;
    
    cout << "Введіть вартість подарунка: ";
    cin >> n;
    
    int count = 0;
 
    for (int i = 0; i < 9; ++i) {
        if (n >= d[i]) {
            count += n / d[i]; 
            n %= d[i];         
        }
    }
    
    cout << count << endl;
    
    return 0;
}
