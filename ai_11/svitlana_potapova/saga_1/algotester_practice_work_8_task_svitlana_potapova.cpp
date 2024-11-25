#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

int main()
{
    int X, Y, n, k, xi, yi;
    cin >> X >> Y >> n >> k;

    vector<double> dist(n);

    for (int i = 0; i < n; i++) {
        cin >> xi >> yi;
        double dx = xi - X;
        double dy = yi - Y;
        dist[i] = sqrt(dx * dx + dy * dy);
    }

    sort(dist.begin(), dist.end());
    cout << fixed << setprecision(9) << dist[k - 1];

    return 0;
}


