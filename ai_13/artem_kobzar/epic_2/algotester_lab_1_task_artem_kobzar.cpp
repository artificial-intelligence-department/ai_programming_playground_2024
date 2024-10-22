#include <iostream>
using namespace std;

int main() {
   long long cubes[5];
   cout<<"Enter the sides of the cube: ";
 
    for (int i = 0; i < 5; ++i) {
        cin >> cubes[i];
        if (cubes[i] <= 0) {
            cout << "ERROR\n";
            return 0;
        }
    }
    for (int i = 1; i < 5; ++i) {
        if (cubes[i] > cubes[i - 1]) {
            cout << "LOSS\n";
            return 0;
        }
    }
    cout << "WIN\n";
    return 0;
}
