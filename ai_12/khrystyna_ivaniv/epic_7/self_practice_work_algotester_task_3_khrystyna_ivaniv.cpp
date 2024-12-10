#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int price[10], n, k, z; 

    cin >> n >> k >> z;

    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }

    sort(price, price + n);  
    int girls = 0;      
    int cost = 0;      

    for (int i = 0; i < n; i++) {
        if (cost + 2 * price[i] > z) {
            break;  
        }
        cost += 2 * price[i];
        girls++;
        if (girls == k) {
            break;  
        }
    }

    cout << girls << endl;

    return 0;
}
