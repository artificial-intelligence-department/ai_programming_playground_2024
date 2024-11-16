#include <iostream>
using namespace std;

int main() {
    int x;
    int counter = 0;
    cin >> x;

    while (x > 0) {

        switch (x % 10) {
            case 4:
            case 7:
                counter++;
                break;
        }
        x /= 10;
    }
    
    cout << counter;
}
