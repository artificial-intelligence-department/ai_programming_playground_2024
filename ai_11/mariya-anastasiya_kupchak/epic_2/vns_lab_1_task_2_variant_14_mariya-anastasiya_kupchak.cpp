#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n, m;
    int op1;  // оголошуємо змінну для результату першої операції
    bool op2, op3;  // оголошуємо змінні для результатів нерівностей

    cout << "Input n: ";
    cin >> n;  // вводимо значення першої змінної
    cout << "Input m: ";
    cin >> m;  // вводимо значення другої змінної

    op1 = m + (--n);

    cout << "Operation 1 = " << op1 << endl;

    if((m++) < (++n))  // обчислюємо результат першої нерівності, записуємо в змінну і виводимо його
    {
        op2 = 1;
        cout << "Operation 2 = true" << endl;
    }
    else
    {
        op2 = 0;
        cout << "Operation 2 = false" << endl;
    }

    if((n--) < (--m))  // обчислюємо результат другої нерівності, записуємо в змінну і виводимо його
    {
        op3 = 1;
        cout << "Operation 3 = true" << endl;
    }
    else
    {
        op3 = 0;
        cout << "Operation 3 = false" << endl;
    }

    return 0;
    
}