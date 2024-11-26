#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> penguins(n);
    
    for (int i = 0; i < n; i++) {
        cin >> penguins[i].first >> penguins[i].second;
    }

    int x_max = 0;
    int y_max = 0;

    for (int i = 0; i < n; i++) {
        x_max = max(x_max, penguins[i].first);
        y_max = max(y_max, penguins[i].second);
    }

    long long total_time = 0;
    
    for (int i = 0; i < n; i++) {
        total_time += (x_max - penguins[i].first) + (y_max - penguins[i].second);
    }

    cout << total_time << endl;

    return 0;
}