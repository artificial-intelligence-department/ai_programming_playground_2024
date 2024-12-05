#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n % 2 == 0) {
        // n парне: максимум груп розміром 2
        cout << n / 2 << endl;
        for (int i = 0; i < n / 2; i++) {
            cout << 2 << " ";
        }
    } else {
        // n непарне: одна група з 3, решта — з 2
        cout << (n - 3) / 2 + 1 << endl; // Одна група з 3 і решта з 2
        for (int i = 0; i < (n - 3) / 2; i++) {
            cout << 2 << " ";
        }
        cout << 3 << " ";
        
    }

    return 0;
}
