#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    int prevFloor, currFloor;
    cin >> prevFloor;

    int totalTime = 0;
    for (int i = 1; i < n; i++) {
        cin >> currFloor;
        totalTime += abs(currFloor - prevFloor) * t;
        prevFloor = currFloor;
    }

    cout << totalTime << endl;
    return 0;
}
