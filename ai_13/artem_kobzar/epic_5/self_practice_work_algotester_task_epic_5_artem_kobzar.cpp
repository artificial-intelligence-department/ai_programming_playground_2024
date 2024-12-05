#include <iostream>
#include <algorithm>

int main() {
    int n, k, z;
    std::cin >> n >> k >> z;
    int* prices = new int[n];

    for (int i = 0; i < n; ++i) {
        std::cin >> prices[i];
        prices[i] *= 2;
    }
    std::sort(prices, prices + n);
    int girls = 0;

    for (int i = 0; i < n; ++i) {
        if (z >= prices[i]) {
            z -= prices[i]; 
            ++girls; 
        } else {
            break;
        }
    }
    std::cout << std::min(girls, k) << std::endl;
    delete[] prices;

    return 0;
}
