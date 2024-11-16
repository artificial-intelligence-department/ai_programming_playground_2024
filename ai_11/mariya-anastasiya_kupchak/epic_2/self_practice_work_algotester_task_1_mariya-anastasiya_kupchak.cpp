#include <iostream>

using namespace std;

int main()
{
    long long a[5];

    cin >> a[0];  // вводимо перший елемент масиву сторін кубів
    
    for (int i = 1; i < 5; i++)  // вводимо елементи масиву за допомогою циклу
    {
        cin >> a[i];
        
        if (a[i-1] < a[i])  // перевіряємо, чи виконується умова програшу
        {
            cout << "LOSS";
            return 0;
        }

        if (a[i] <= 0)  // перевіряємо кожен елемент на коректність
        {
            cout << "ERROR";
            return 0;
        }
    }

    cout << "WIN";

    return 0;
    
}