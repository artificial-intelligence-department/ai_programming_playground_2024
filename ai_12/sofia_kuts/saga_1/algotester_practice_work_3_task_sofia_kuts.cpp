#include <iostream>
#include <vector>
using namespace std;

int main() {

    int denominations[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
    int size = sizeof(denominations) / sizeof(denominations[0]);

  
    int n;
    cin >> n;

    int count = 0;

    for (int i = 0; i < size; i++) {
        if (n == 0) break; 
        count += n / denominations[i]; 
        n %= denominations[i]; 
    }

    cout << count << endl;

    return 0;
}
