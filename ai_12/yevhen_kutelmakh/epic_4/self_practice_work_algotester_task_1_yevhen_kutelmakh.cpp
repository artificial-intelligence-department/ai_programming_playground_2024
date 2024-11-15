#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

/*
Вогняне дихання
https://algotester.com/uk/ArchiveProblem/DisplayWithFile/20076
*/

struct Coor{
    int x;
    int y;
};


int main() {
    Coor house;
    cin >> house.x >> house.y;
    int n, k;
    cin >> n >> k;
    vector<Coor> points(n);
    for(int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    vector<double> dist(n);
    for(int i = 0; i < n; i++) {
        dist[i] = sqrt(static_cast<double>(pow(house.x - points[i].x, 2) + pow(house.y - points[i].y, 2)));
    }
    sort(dist.begin(), dist.end());
    cout << setprecision(13) << dist[k-1];
    return 0;
}