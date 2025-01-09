#include <iostream>
#include <vector>
#include <iomanip> 
#include <algorithm> 
using namespace std;

bool canMakeCandles(const vector<int>& lengths, int n, double length) {
    int count = 0;
    for (int l : lengths) {
        count += static_cast<int>(l / length); 
    }
    return count >= n; 
}

int main() {
    int n, m;
    cin >> n >> m; 

    vector<int> lengths(m);
    for (int i = 0; i < m; ++i) {
        cin >> lengths[i]; 
    }

    double low = 0.0, high = *max_element(lengths.begin(), lengths.end());
    double result = 0.0;

    while (high - low > 1e-7) {
        double mid = (low + high) / 2.0;
        if (canMakeCandles(lengths, n, mid)) {
            result = mid; 
            low = mid; 
        } else {
            high = mid; 
        }
    }

    cout << fixed << setprecision(7) << result << endl;

    return 0;
}