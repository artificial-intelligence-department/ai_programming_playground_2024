#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int type;  // оголошуємо змінну для типу даних(float або double)
    
    cout << "Choose type double(type 1) or float(type 2): ";
    cin >> type;  // записуємо обраний тип даних для операцій

    if (type == 1)  // якщо користувач обрав тип даних double
    {
        double a = 1000;
        double b = 0.0001;

        double op1, op2, op3, op4, op5;

        op1 = pow((a + b), 3);  // обчислюємо першу дужку ((a + b)^3)
        op2 = (pow(a, 3) + (3 * pow(a, 2) * b));  // обчислюємо другу дужку ((a^3)+3(a^2)b)
        op3 = op1 - op2;  // обчислюємо значення в чисельнику
        op4 = (3 * a * pow(b, 2)) + pow(b, 3);  // обчислюємо значення в знаменнику (3a(b^2)+(b^3))
        op5 = op3 / op4;  // обчислюємо значення цілого виразу
        cout << op5 << endl;  // виводимо результат обчислень
    }

    else if (type == 2)  // якщо користувач обрав тип даних float
    {
        // проробляємо операції ідентичні до першого типу даних
        float a = 1000;
        float b = 0.0001;
        
        float op1, op2, op3, op4, op5;
        
        op1 = pow((a + b), 3);
        op2 = (pow(a, 3) + (3 * pow(a, 2) * b));
        op3 = op1 - op2;
        op4 = (3 * a * pow(b, 2)) + pow(b, 3);
        op5 = op3 / op4;
        cout << op5 << endl;
    }

    else  // якщо користувач ввів значення, яке не відповідає жодному типу даних
    {
        cout << "Please, choose valid type";
    }

    return 0;
    
}