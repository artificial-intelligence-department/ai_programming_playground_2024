#include <iostream>
#include <vector>

using namespace std;

pair<int, int> simulateDrones(const vector<int>& speeds, string& result) {
    int left = 0;
    int right = speeds.size() - 1;

    while (true) {
        if (left == right) {
            result = "Collision";
            return {left + 1, right + 1};
        } else if (left + 1 == right) {
            result = "Stopped";
            return {left + 1, right + 1};
        } else if (left > right) {
            result = "Miss";
            return {left + 1, right + 1};
        }

        left += speeds[left];
        right -= speeds[right];
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> speeds(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> speeds[i];
    }

    string result;
    auto finalPositions = simulateDrones(speeds, result);

    cout << finalPositions.first << " " << finalPositions.second << endl;
    cout << result << endl;

    return 0;
}
