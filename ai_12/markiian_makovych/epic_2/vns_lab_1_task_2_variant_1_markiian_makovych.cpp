#include <iostream>

using namespace std;

int main()
{
    int m = 5, n = 5;
    int result = 0;

    result = m + --n;

    cout << "1) m+--n " << endl;

    cout << result << endl; // Результат 9 тому, що перед n стоїть префіксний декремент, який зменшує n до її використання

    m = 5;
    n = 5;
    cout << "2)m++<++n" << endl;
    result = m++ < ++n;
    cout << result << endl; // Результат TRUE, бо значення m збільшується після використання m, а значення n збільшується до використання

    m = 5;
    n = 5;

    result = n-- < --m;

    cout << "3)n--< --m" << endl;

    cout << result << endl; // Результат FALSE, бо значення n зменшується після обрахункців, а значення m до обрахунків

    return 0;
}