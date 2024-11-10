#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> oddNumbers, evenNumbers;

    int t;
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (t % 2 == 0) {
            evenNumbers.push_back(t);
        } else {
            oddNumbers.push_back(t);
        }
    }


    int sizeOdd = oddNumbers.size(), sizeEven = evenNumbers.size();


    if (sizeOdd == 0 || sizeEven == 0) {
        cout << -1;
    }
    else if (abs(sizeOdd - sizeEven) <= 1) {
        if (sizeOdd >= sizeEven) {
            for (int i = 0; i < sizeEven; i++) {
                cout << oddNumbers[i] << ' ' << evenNumbers[i] << ' ';
            }

            if (sizeOdd > sizeEven) cout << oddNumbers[sizeOdd-1];
        }
        else {
            for (int i = 0; i < sizeOdd; i++) {
                cout << evenNumbers[i] << ' ' << oddNumbers[i] << ' ';
            }

            if (sizeEven > sizeOdd) cout << evenNumbers[sizeEven - 1];
        }
    }
    else {
        cout << -1;
    }

    

    return 0;
}

