#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

bool canSeeKTimes(double r, int k, const vector<double>& distances) {
    int count = 0;
    for (double d : distances) {
        if (d <= r) {
            count++;
        }
        if (count >= k) {
            return true;
        }
    }
    return false;
}

int main() {
    int X, Y;
    int n, k;
    cin >> X >> Y;
    cin >> n >> k;

    if (X < 0 || X > 1e9 || Y < 0 || Y > 1e9) {
        return 0;
    }

    if (n < 1 || n > 100 || k < 1 || k > n) {
        return 0;
    }

    vector<double> distances(n);
    for (int i = 0; i < n; i++) {
        int xi, yi;
        cin >> xi >> yi;
        if (xi < 0 || xi > 1e9 || yi < 0 || yi > 1e9) {
            return 0;
        }
        distances[i] = distance(X, Y, xi, yi);
    }

    sort(distances.begin(), distances.end());

    double left = 0.0, right = distances.back();
    double answer = right;

    while (right - left > 1e-4) {
        double mid = (left + right) / 2.0;
        if (canSeeKTimes(mid, k, distances)) {
            answer = mid;
            right = mid;
        } else {
            left = mid;
        }
    }

    cout.precision(6);
    cout << fixed << answer << endl;

    return 0;
}



