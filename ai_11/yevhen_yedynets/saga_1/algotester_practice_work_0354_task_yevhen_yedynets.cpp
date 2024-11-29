#include <iostream>

using namespace std;

int main() {
    double sd, su, v;
    cin >> sd >> su >> v;

    double timeDown = sd / (v * 2.0);
    double timeUp = su / (v / 2.0);

    if (timeDown < timeUp) {
        cout << "Down" << endl;
    } else if (timeUp < timeDown) {
        cout << "Up" << endl;
    } else {
        cout << "Never mind" << endl;
    }

    return 0;
}
