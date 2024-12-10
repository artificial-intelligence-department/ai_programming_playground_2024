#include <iostream>
using namespace std;

int main() {
    int n, sum = 0;

    cout << "Enter the number of even positive integers to sum: ";
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        sum += i * 2;
    }

    cout << "The sum of the first " << n << " even positive integers is: " << sum << endl;

    return 0;
}
