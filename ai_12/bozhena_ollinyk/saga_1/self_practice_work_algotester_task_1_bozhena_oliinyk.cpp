#include <iostream>
#include <algorithm>

using namespace std;

//0052
// вболівальниці

int main() {
    int prices[10], n, k, z; 

    cin >> n >> k >> z;
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    sort(prices, prices + n);  
    int girls = 0;      
    int cost = 0;      

    for (int i = 0; i < n; i++) {
        if (cost + 2 * prices[i] > z) {
            break;  
        }
        cost += 2 * prices[i];
        girls++;
        if (girls == k) {
            break;  
        }
    }

    cout << girls << endl;

    return 0;
}
