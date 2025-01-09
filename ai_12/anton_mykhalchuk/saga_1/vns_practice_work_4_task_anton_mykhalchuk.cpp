#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    cout << setw(10) << "Number" << setw(15) << "Square" << endl;
    for (int i = 1; i <= 5; ++i) {
        int oddNumber = 2 * i - 1;
        cout << setw(10) << oddNumber << setw(15) << oddNumber * oddNumber << endl;
    }
    return 0;
}