#include <iostream>
#include <cmath>

using namespace std;

//використав дійсну змінну, вивід, цикл вайл,
//математичні операції

int main () {
    float h_x = 0.5, x = -4.0;
    cout << "x\ty=|x|\n";
    while (x <= 4){
        float y = abs(x);
        cout << x << "\t" << y << endl;
        x += h_x;
    }
    return 0;
}