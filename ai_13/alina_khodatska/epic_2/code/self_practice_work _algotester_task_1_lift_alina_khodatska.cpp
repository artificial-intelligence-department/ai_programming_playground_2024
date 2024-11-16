#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    int prev_floor, current_floor;
    cin >> prev_floor;
    int total_time = 0;

    for (int i = 1; i < n; ++i) {
        cin >> current_floor;
        total_time += abs(current_floor - prev_floor) * t;
        prev_floor = current_floor;
    }

    cout << total_time << endl;
    return 0;
}
