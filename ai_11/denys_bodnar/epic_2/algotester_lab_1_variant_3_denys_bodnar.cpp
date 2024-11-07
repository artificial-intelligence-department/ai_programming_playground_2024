#include <iostream>
using namespace std;

int main() {
    long long a[5];

    cin >> a[0];

    if (a[0] <= 0 || a[0] > 1e12){
        cout << "ERROR";
        return 0;
    }

    for (int i = 1; i < 5; i++) {
        cin >> a[i];
        if (a[i] <= 0 || a[i] > 1e12) {
            cout << "ERROR" << endl;
            return 0;
        }
        else if (a[i] > a[i - 1]){
            cout << "LOSS" << endl;
            return 0;
        }
}
    cout << "WIN" << endl;
    return 0;
}
