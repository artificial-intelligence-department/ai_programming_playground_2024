#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int amount = 500 - n;
    int count = 0;

    // 500
    count += amount / 500;
    amount %= 500;

    // 200
    count += amount / 200;
    amount %= 200;

    // 100
    count += amount / 100;
    amount %= 100;

    // 50
    count += amount / 50;
    amount %= 50;

    // 20
    count += amount / 20;
    amount %= 20;

    // 10
    count += amount / 10;
    amount %= 10;

    // 5
    count += amount / 5;
    amount %= 5;

    // 2
    count += amount / 2;
    amount %= 2;

    // 1
    count += amount;

    cout << count << endl;
    return 0;
}