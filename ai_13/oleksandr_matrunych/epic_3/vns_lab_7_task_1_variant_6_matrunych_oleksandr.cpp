#include <iostream>
#include <algorithm>
using namespace std;

int min(int value) {
    return value;
}

template <typename... Args>
int min(int first, Args... rest) {
    return std::min(first, ::min(rest...)); 
}

int main() {
    cout << "Min of 5 numbers: " << min(76, 126, 45, 102, 99) << endl;
    cout << "Min of 10 numbers: " << min(219, 18, 9, 152, 7, 46, 30, 22, 108, 20) << endl;
    cout << "Min of 12 numbers: " << min(50, 40, 30, 20, 10, -2, 100, 15, 25, 35, 45, 55) << endl;

    return 0;
}
