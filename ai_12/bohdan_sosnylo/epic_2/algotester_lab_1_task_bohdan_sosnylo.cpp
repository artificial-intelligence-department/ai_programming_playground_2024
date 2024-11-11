#include <iostream>
using namespace std;

int main() {
    long a[5];
    string res = "WIN";

    
    for (int i = 0; i < 5; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < 5; i++) {
        if (a[i] <= 0) {
            res = "ERROR";
            break;
        }

        if (i > 0 && a[i] > a[i - 1]) {
            res = "LOSS";
            break;
            
        }
    }

    cout << res;
    return 0;
}

