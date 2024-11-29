// Variant 7

#include <iostream>

using namespace std;

int main() 
{
    int n;

    cout << "Введіть кількість членів ряду: ";
    cin >> n;

    int sum = 0;
    int a = 1;

    for (int i = 0; i < n; ++i) 
    {
        sum += a;
        a += 2;
    }

    cout << "Сума перших " << n << " членів ряду: " << sum << endl;

    return 0;
}
