#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <vector>
using namespace std;

//0183
//breath of fire

struct Coord {
    int x;
    int y;
};

double calcDistance(int x1, int y1, int x2, int y2) {
    return sqrt(static_cast<double>(pow(x1 - x2, 2) + pow(y1 - y2, 2)));
}

int main() {
    Coord house;
    cin >> house.x >> house.y;
    
    int n, k;
    cin >> n >> k;
    
    vector<Coord> points(n); 
    vector<double> distance(n);

    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
        distance[i] = calcDistance(house.x, house.y, points[i].x, points[i].y);
    }

    sort(distance.begin(), distance.end());
    cout << setprecision(13) << distance[k - 1];
    return 0;
}
