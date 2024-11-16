#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    // Перевірка можливості розподілу студентів
    if (n < k || n > 3 * k) {
        cout << "Impossible" << endl;
        return 0;
    }

    vector<int> teams(k, 1); 
    int remaining = n - k;   

    for (int i = 0; i < k && remaining > 0; i++) {
        int add = min(2, remaining); 
        teams[i] += add; 
        remaining -= add; 
    }

    for (int j = 0; j < k; j++) {
        cout << teams[j] << " ";
    }
    cout << endl;

    return 0;
}
