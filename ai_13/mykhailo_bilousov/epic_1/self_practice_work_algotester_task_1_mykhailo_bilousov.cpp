#include <iostream>
using namespace std;

int main() {
    int coins[9] = {1,2,5,10,20,50,100,200,500};
    int n;
    int res = 0;
    cin >> n;
    for (int i = 8; i >= 0; i--) {
        res += n / coins[i];
        n %= coins[i];
    }
    cout << res << endl;
}