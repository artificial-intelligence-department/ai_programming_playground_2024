#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a[5], b[5], c[5]; // одновимірні масиви щоб не робити 15 змінних
    for (size_t i = 0; i < 5; i++) // цикл for щоб пройтись по всіх елементах
    {
        cout << "Enter the sides of triangle #" << i + 1 << ": ";
        cin >> a[i] >> b[i] >> c[i]; // Оператори виведення та введення даних
        if (a[i] <= 0 || b[i] <= 0 || c[i] <= 0)
        {
            cout << "Sides of the triangle cant be below or equal zero. Try again\n";
            i--;
            continue; // continue щоб пропустити зайві операції
        }
        if (a[i] <= b[i] && a[i] <= c[i]) // умовні оператори щоб зробити умову
        {
            cout << "Longest high will be on the side with lenght " << a[i] << endl;
        }
        else if (b[i] <= a[i] && b[i] <= c[i])
        {
            cout << "Longest high will be on the side with lenght " << b[i] << endl;
        }
        else if (c[i] <= b[i] && c[i] <= a[i])
        {
            cout << "Longest high will be on the side with lenght " << c[i] << endl;
        }
    }
}