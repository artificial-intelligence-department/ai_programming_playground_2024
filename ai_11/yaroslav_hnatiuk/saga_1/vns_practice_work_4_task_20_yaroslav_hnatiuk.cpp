#include <iostream>
#include <cmath>
using namespace std;

int main() {
    for (double x = -4; x <= 4; x += 0.5) {
        double a = abs(x - 2);
        double b = abs(x + 1);

        cout << "Якщо x = " << x << ", то y = " << a + b << endl;
    }

    return 0;
}




