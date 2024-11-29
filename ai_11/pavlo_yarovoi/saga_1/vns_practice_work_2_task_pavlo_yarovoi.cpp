#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int Quadrant1 = 0, Quadrant2 = 0, Quadrant3 = 0, Quadrant4 = 0;

    for (int i = 0; i < 10; i++) {
        double x, y;
        cout << "Enter coordinates of point " << i + 1 << " (x, y): ";
        cin >> x >> y;

        if (x > 0 && y > 0) {
            Quadrant1++;
        } else if (x < 0 && y > 0) {
            Quadrant2++;
        } else if (x < 0 && y < 0) {
            Quadrant3++;
        } else if (x > 0 && y < 0) {
            Quadrant4++;
        }
    }

    cout << "Number of points in the first quadrant: " << Quadrant1 << endl;
    cout << "Number of points in the second quadrant: " << Quadrant2 << endl;
    cout << "Number of points in the third quadrant: " << Quadrant3 << endl;
    cout << "Number of points in the fourth quadrant: " << Quadrant4 << endl;

    int maxCount = max({Quadrant1, Quadrant2, Quadrant3, Quadrant4});

    if (maxCount == Quadrant1 && maxCount !=0) {
        cout << "The most points are in the first quadrant." << endl;
    }
    else if (maxCount == Quadrant2 && maxCount !=0) {
        cout << "The most points are in the second quadrant." << endl;
    }
    else if (maxCount == Quadrant3 && maxCount !=0) {
        cout << "The most points are in the third quadrant." << endl;
    }
    else if (maxCount == Quadrant4 && maxCount !=0) {
        cout << "The most points are in the fourth quadrant." << endl;
    }
    else {
        cout << "Wrong data" << endl;
    }
    return 0;
}