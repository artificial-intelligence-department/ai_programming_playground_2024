#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long h[4], d[4];


    for (int i = 0; i < 4; ++i) {
        cin >> h[i];
    }


    for ( ) {
        cin >> d[i];
    }


    for (int i = 0; i < 4; ++i) {
        if (d[i] > h[i]) {
            cout << "ERROR" << endl;
            return 0;
        }
    }


    for (int i = 0; i < 4; ++i) {  
        h[i] -= d[i];  


        long long heightmax = *max_element(h, h + 4);
        long long heightmin = *min_element(h, h + 4);


        if (heightmax >= 2 * heightmin) {
            cout << "NO" << endl;
            return 0;
        }
    }

    for (int i = 0; i < 4; ++i) {
        if (h[i] <= 0) {
            cout << "NO" << endl;
            return 0;
        }
    }


    cout << "YES" << endl;
    return 0;
}