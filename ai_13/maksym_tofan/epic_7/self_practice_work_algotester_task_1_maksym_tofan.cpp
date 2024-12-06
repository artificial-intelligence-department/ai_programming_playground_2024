#include <iostream>
#include <climits>

using namespace std;

int main() {
    long long prev = LLONG_MAX; 

    for (int i = 0; i < 5; ++i) {
        long long a;
        cin >> a;

        if (a <= 0) {
            cout << "ERROR";
            return 0; // Оператор виходу з програми (відповідає п. 13)
        }

        if (a > prev) {
            cout << "LOSS";
            return 0; 
        }

        prev = a;
    }

    cout << "WIN"; // Оператор виведення (відповідає п. 14)
    return 0;
}
