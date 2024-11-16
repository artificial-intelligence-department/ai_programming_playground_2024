#include <iostream>
using namespace std;

int main()
{
    long long prev_cube, current_cube;
    cin >> prev_cube; // перший кубик, який стоїть на підлозі.

    if (prev_cube <= 0) // довжина ребра куба має недійсне значення.
    {
        cout << "ERROR";
        return 0;
    }

    for (int i = 2; i <= 5; i++) // цикл де кожен наступний куб перевіряється на те, чи він менший або рівний кубу на вершині, і якщо так, то він стає новою вершиною.
    {
        cin >> current_cube;

        if (current_cube <= 0) // недійсна довжина ребра кубика, який мо хочемо поставити на вершину.
        {
            cout << "ERROR";
            return 0;
        }

        if (current_cube > prev_cube) // довжина  ребра кубика більший за попередній.
        {
            cout << "LOSS";
            return 0;
        }
        prev_cube = current_cube; // після успішного проходження перевірки, кубик стає вершиною.
    }
    cout << "WIN";
    return 0;
}
