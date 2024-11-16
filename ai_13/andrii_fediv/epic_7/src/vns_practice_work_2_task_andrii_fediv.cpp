#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float y, field[2] = {0.5, 3.1}, x = field[0], a = 0.1, ha = 0.3, hx = 0.2; // #2 одна дійсна змінна | використано для корректного відображення та обробки даних
    do
    {
        y = (x <= 2 ? tan(abs(x - 2 * a)) : cos(a * x + 2));
        cout << y << endl;
        a += ha;
        x += hx;
    } while (x < field[1]);// #8 do while цикл | робить як мінімум 1 прохід а далі залежно від х

    return 0;
}