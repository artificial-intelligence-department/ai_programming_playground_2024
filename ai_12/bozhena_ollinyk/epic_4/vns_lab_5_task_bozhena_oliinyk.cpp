#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX_SIZE = 100;

bool isUnique(int twoDim[][MAX_SIZE], int rows, int cols, int value)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (twoDim[i][j] == value)
            {
                return false;
            }
        }
    }
    return true;
}

void convertTo1D(int twoDim[][MAX_SIZE], int oneDim[], int rows, int cols)
{
    int index = 0;

    bool usedRows[MAX_SIZE] = {false};
    srand(time(0));

    for (int i = 0; i < rows; ++i)
    {
        int row;
        do
        {
            row = rand() % rows;
        } while (usedRows[row]);
        usedRows[row] = true;

        for (int j = 0; j < cols; ++j)
        {
            oneDim[index++] = twoDim[row][j];
        }
    }
    bool usedCols[MAX_SIZE] = {false};
    for (int j = 0; j < cols; ++j)
    {
        int col;
        do
        {
            col = rand() % cols;
        } while (usedCols[col]);
        usedCols[col] = true;

        for (int i = 0; i < rows; ++i)
        {
            oneDim[index++] = twoDim[i][col];
        }
    }
}

void restore2DArray(int oneDim[], int twoDim[][MAX_SIZE], int rows, int cols)
{
    int index = 0;

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            twoDim[i][j] = oneDim[index++];
        }
    }

    int orderRow = 0;
    for (int i = rows * cols; i < rows * cols + rows; ++i)
    {
        int orient = oneDim[i];

        int rowIndex;
        bool found = false;
        for (rowIndex = 0; rowIndex < rows; ++rowIndex)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (twoDim[rowIndex][j] == orient)
                {
                    found = true;
                    break;
                }
            }
            if (found)
                break;
        }

        int temp[MAX_SIZE];
        for (int j = 0; j < cols; ++j)
        {
            temp[j] = twoDim[rowIndex][j];
        }

        for (int j = rowIndex; j > orderRow; --j)
        {
            for (int k = 0; k < cols; ++k)
            {
                twoDim[j][k] = twoDim[j - 1][k];
            }
        }

        for (int j = 0; j < cols; ++j)
        {
            twoDim[orderRow][j] = temp[j];
        }
        orderRow++;
    }
}

int main()
{
    int rows, cols;

size:
    cout << "Введіть кількість рядків: ";
    cin >> rows;
    cout << "Введіть кількість стовпців: ";
    cin >> cols;

    if (rows > MAX_SIZE || cols > MAX_SIZE)
    {
        cout << "Розмірність перевищує максимальний дозволений розмір!" << endl;
        goto size;
    }

    int twoDim[MAX_SIZE][MAX_SIZE];
    cout << "Введіть елементи двовимірного масиву:" << endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            int value;
            bool unique = false;
            while (!unique)
            {
                cout << "Елемент [" << i << "][" << j << "]: ";
                cin >> value;

                if (isUnique(twoDim, rows, cols, value))
                {
                    unique = true;
                    twoDim[i][j] = value;
                }
                else
                {
                    cout << "Цей елемент уже існує в масиві, спробуйте ще раз." << endl;
                }
            }
        }
    }

    cout << "Двовимірний масив:" << endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cout << twoDim[i][j] << " ";
        }
        cout << endl;
    }

    int oneDim[MAX_SIZE * MAX_SIZE];
    convertTo1D(twoDim, oneDim, rows, cols);

    cout << "Одновимірний масив (після переписування):" << endl;
    for (int i = 0; i < rows * cols * 2; ++i)
    {
        cout << oneDim[i] << " ";
    }
    cout << endl;

    int restoredTwoDim[MAX_SIZE][MAX_SIZE];
    restore2DArray(oneDim, restoredTwoDim, rows, cols);

    cout << "Відновлений двовимірний масив:" << endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cout << restoredTwoDim[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
