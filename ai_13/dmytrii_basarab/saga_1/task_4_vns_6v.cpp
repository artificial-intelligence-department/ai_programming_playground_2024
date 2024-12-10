#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Введіть кількість парних чисел (n): ";
    cin >> n;

    switch (n) {//в коді використано оператори break і continue
            case -1:
            cout << "error";
            return 0;
                break;
    }

    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        if (i % 2 == 0) {
            sum += i;
        }
        if (i % 2 != 0) {
            continue;
        }
    }

    cout << "Сума перших " << n << " парних чисел: " << sum << endl;

    return 0;
}