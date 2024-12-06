#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout << "Таблиця степенів двійки від нульової до десятої:" << endl;
    cout << "--------------------------------------------" << endl;
    cout << " Степінь | 2^степінь" << endl;
    cout << "--------------------------------------------" << endl;

    for (int i = 0; i <= 10; ++i) {
        cout << "    " << i << "    |   " << pow(2, i) << endl;
    }

    return 0;
}