#include <iostream>
#include <vector>
#include <algorithm> // для max функції

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> elements(n);
    for (int i = 0; i < n; ++i) {
        cin >> elements[i];
    }

    vector<int> lengths(n, 1); 
    
    int max_length = 1; 

    // Алгоритм пошуку найбільшої зростаючої підпослідовності
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (elements[i] > elements[j]) {
                lengths[i] = max(lengths[i], lengths[j] + 1);
            }
        }
        max_length = max(max_length, lengths[i]);
    }

    cout << max_length << endl;

    return 0;
}
