#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int rows, columns;
    cin >> rows >> columns;

    vector<string> crossWord(rows);
    vector<vector<int>> toDelete(rows, vector<int>(columns, 0));

    for (int i = 0; i < rows; i++)
    {
        cin >> crossWord[i];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            char a = crossWord[i][j];

            for (int k = 0; k < rows; k++)
            {
                if (i != k && crossWord[k][j] == a)
                {
                    toDelete[k][j] = 1;
                    toDelete[i][j] = 1;
                }
            }

            for (int k = 0; k < columns; k++)
            {
                if (j != k && crossWord[i][k] == a)
                {
                    toDelete[i][k] = 1;
                    toDelete[i][j] = 1;
                }
            }
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (toDelete[i][j] == 0)
            {
                cout << crossWord[i][j];
            }
        }
    }

    return 0;
}
