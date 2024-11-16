#include <iostream>

using namespace std;

int sumOfDigits(int n) // Функція розрахунку суми цифр
{
    int sum = 0;
    while (n != 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
};

int main()
{

    int n;
    int count = 0;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        if (sumOfDigits(i) == 4 || sumOfDigits(i) == 7 || sumOfDigits(i) == 47 || sumOfDigits(i) == 44) // Перевірка чи сума чисел є щасливою

            count++;
    }

    if (n == 4) // Якщо число дорівнює 4
    {
        count = 1;
    }
    if (n == 7) // Якщо число дорівнює 7
    {
        count = 2;
    }

    cout << count << endl;
    return 0;
}