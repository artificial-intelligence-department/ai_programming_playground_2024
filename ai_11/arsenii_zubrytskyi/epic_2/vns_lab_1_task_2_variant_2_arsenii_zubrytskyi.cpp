#include <iostream>
using namespace std;

int main() {
    int n = 5, m = 3;

    cout << "For int: " << ++n * ++m << endl;

    cout << "For int: " << (m++ < n) << endl;

    cout << "For int: " << (n++ > m) << endl;

    return 0;
}
