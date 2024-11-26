#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, Q;
    cin >> N;

    // Ініціалізація матриці
    vector<vector<int>> grid(N, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            char ch;
            cin >> ch;
            grid[i][j] = ch - '0'; // Перетворення символу на цифру
        }
    }

    // Зберігаємо інформацію про використані числа для кожного рядка та стовпця
    vector<vector<bool>> usedInRow(N, vector<bool>(N + 1, false));
    vector<vector<bool>> usedInCol(N, vector<bool>(N + 1, false));

    // Заповнюємо дані про використані числа
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int val = grid[i][j];
            if (val != 0)
            {
                usedInRow[i][val] = true;
                usedInCol[j][val] = true;
            }
        }
    }

    // Зчитуємо кількість запитів
    cin >> Q;
    vector<pair<int, int>> queries(Q);
    for (int i = 0; i < Q; i++)
    {
        cin >> queries[i].first >> queries[i].second;
        queries[i].first--; // Перетворення до 0-індексації
        queries[i].second--;
    }

    // Обробка кожного запиту
    for (int i = 0; i < Q; i++)
    {
        int x = queries[i].first;
        int y = queries[i].second;

        if (grid[x][y] != 0)
        {
            // Якщо клітинка вже заповнена, виводимо 1 і значення клітинки
            cout << "1 " << grid[x][y] << endl;
            continue;
        }

        // Формування списку можливих чисел на основі `usedInRow` та `usedInCol`
        vector<int> possibleNumbers;
        for (int num = 1; num <= N; num++)
        {
            if (!usedInRow[x][num] && !usedInCol[y][num])
            {
                possibleNumbers.push_back(num);
            }
        }

        // Виводимо результат для поточного запиту
        if (possibleNumbers.empty())
        {
            cout << "0" << endl;
        }
        else
        {
            cout << possibleNumbers.size() << " ";
            for (int k = 0; k < possibleNumbers.size(); k++)
            {
                cout << possibleNumbers[k];
                if (k < possibleNumbers.size() - 1)
                { 
                    cout << " ";
                }
            }
            cout << endl;
        }
    }

    return 0;
}
