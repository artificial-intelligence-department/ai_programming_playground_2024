#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;

    cin >> n;
    if (n <= 0 || n > 100) {
        return 1;
    }

    vector<int> firstArray(n);
    for (int i = 0; i < n; ++i) {
        cin >> firstArray[i];
        if (firstArray[i] < 0 || firstArray[i] > 100) {
            return 1;
        }
    }

    cin >> m;
    if (m <= 0 || m > 100) {
        return 1;
    }

    vector<int> secondArray(m);
    for (int i = 0; i < m; ++i) {
        cin >> secondArray[i];
        if (secondArray[i] < 0 || secondArray[i] > 100) {
            return 1;
        }
    }

    int commonCount = 0;
    int totalUnique = 0;

    for (int x : secondArray) {
        for (int y : firstArray) {
            if (x == y) {
                ++commonCount;
                break;
            }
        }
    }

    totalUnique = n + m - commonCount;

    cout << commonCount << endl;
    cout << totalUnique << endl;

    return 0;
}
