#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
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
    
    Coord points[1000]; 
    double distance[1000];

    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    for (int i = 0; i < n; i++) {
        distance[i] = calcDistance(house.x, house.y, points[i].x, points[i].y);
    }

    sort(distance, distance + n);
    cout << setprecision(13) << distance[k - 1];
    return 0;
}
  