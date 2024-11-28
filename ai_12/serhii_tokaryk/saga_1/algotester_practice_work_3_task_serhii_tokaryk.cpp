#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isWinningPosition(int a, int b, int c) {
    return (a ^ b ^ c) != 0;
}

int main() {
    int n;
    cin >> n; 

    int supermanWins = 0, batmanWins = 0;

    for (int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;

        if (isWinningPosition(a, b, c)) {
            supermanWins++;
        } else {
            batmanWins++;
        }
    }

    cout << supermanWins << "-" << batmanWins << endl;

    return 0;
}
