#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double hx = 0.5;
    double a = 2.4;
    double z;
    cout << "Result for every x" << endl;
    for(int x = -3; x <= 3; x++) {      // 10. цикл for для кожного х
        if(x + 1 == 0) {    // 5. умовний оператор, для перевірки існування функції у точці
            cout << x << ": the function breaks" << endl;
        } else {
            z = (cos(x) - 1)/(x + 1);
            cout << x << ": " << z << endl;
        }
    }


    return 0;
}