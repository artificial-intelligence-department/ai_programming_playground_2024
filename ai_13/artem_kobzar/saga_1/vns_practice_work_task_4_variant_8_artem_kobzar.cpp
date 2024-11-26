#include <iostream>
using namespace std;

int main() {
    int n;    
    double sum = 0;

    cout << "Введіть кількість членів ряду: ";
    cin >> n;

    if (n <= 0) {
        cout << "Кількість членів ряду має бути додатнім числом!" << endl;
        return 1;
    }

    for (int i = 1; i <= n; i++) {
        sum += 1.0 / i;
    }
    cout << "Сума перших " << n << " членів ряду: " << sum << endl;
    
    return 0;
}
