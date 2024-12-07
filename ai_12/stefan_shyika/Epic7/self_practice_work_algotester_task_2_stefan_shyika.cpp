#include <iostream>
using namespace std;

int main() {
    int s_d, s_u, v;
    cin >> s_d >> s_u >> v;
    
    double t_down = (double)s_d / (2 * v);  // час для вниз
    double t_up = (double)2 * s_u / v;      // час для вгору
    
    if (t_down < t_up) {
        cout << "Down" << endl;
    } else if (t_down > t_up) {
        cout << "Up" << endl;
    } else {
        cout << "Never mind" << endl;
    }
}
