#include <iostream>
using namespace std;

int main() {
    double m, n, op_1, op_2, op_3;

    cout << "n: ";
    cin >> n;
    cout << "m: ";
    cin >> m;

    op_1 = n++ - m;
    op_2 = m-- > n;
    op_3 = n-- > m;

    cout << "Result 1: " << op_1 << endl;
    cout << "Result 2: " << (op_2 ? "True" : "False") << endl;
    cout << "Result 3: " << (op_3 ? "True" : "False") << endl;
}