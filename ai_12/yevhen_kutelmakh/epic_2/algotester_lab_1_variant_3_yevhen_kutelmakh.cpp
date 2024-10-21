#include <iostream>
using namespace std;
int main() {
    long long a[5];
    for(int i = 0; i < 5; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < 5; i++) {
        if(a[i] < 1) {
            cout << "ERROR";
            return 0;
        }
        if(i < 4) {
            if(a[i] < a[i+1]) {
                cout << "LOSS";
                return 0;
            }
        }
    }
    cout << "WIN";
    return 0;
}