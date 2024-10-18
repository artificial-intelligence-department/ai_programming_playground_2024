#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    vector <long long> cubes;
    int result=1;
    unsigned long long a;
    
    cout << "Введіть 5 сторін кубів : ";
    for (int i=0; i<5; i++) {
        cin >> a;
        if (a==0) {
            result = 2;

        }
        cubes.push_back(a);
    }

    if (result!=2) {
        for (int i=1; i<5; i++) {
        if (cubes[i] > cubes[i-1]) {
            result = 0;
            break;
        }
    }
    }

    switch(result) {
  case 0:
    cout << "LOSS";
    break;
  case 1:
    cout << "WIN";
    break;
  case 2:
    cout << "ERROR";
    break;
}
    return 0;
}