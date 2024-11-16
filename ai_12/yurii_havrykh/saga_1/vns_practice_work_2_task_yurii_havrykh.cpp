#include<bits/stdc++.h>

using namespace std;

int main() {
    float x = 0.5, a = 0.1, step_x = 0.2, step_a = 0.3, y;
    cout << "Points (x , y):" << endl;
    while (x <= 3.1) {
        if (x <= 2) {
            y = cos(a * x + 2);
        } else {
            y = tan(abs(x - 2 * a));
        }
        printf("(%8.6f , %9.6f)\n", x, y);
        x += step_x;
        a += step_a;
    }
}