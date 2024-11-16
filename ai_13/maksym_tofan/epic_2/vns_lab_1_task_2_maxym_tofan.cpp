#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    cout << "Enter m: ";
    int m;
    cin >> m;
    cout << "Enter n: ";
    int n;
    cin >> n;

    // Expression 1: m - ++n
    int expr1 = m - ++n;
    cout << "\nExpression 1 (m - ++n): " << expr1;

    // Expression 2: ++m > --n
    bool expr2 = (++m > --n);
    cout << "\nExpression 2 (++m > --n): " << (expr2 ? "true" : "false");

    // Expression 3: --n < ++m
    bool expr3 = (--n < ++m);
    cout << "\nExpression 3 (--n < ++m): " << (expr3 ? "true" : "false");

    return 0;
}
