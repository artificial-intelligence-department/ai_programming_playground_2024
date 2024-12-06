#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int totalSquares = 0;

    for (int k = 1; k <= n; k++) {
        totalSquares += (n - k + 1) * (n - k + 1);
    }

    cout << totalSquares << endl;

    return 0;
}
