#include <iostream>
using namespace std;

void func1_2(int **matrix)
{
    int *minElems = new int[5];
    int *maxElems = new int[5];
    for (int i = 0; i < 5; i++)
    {
        int min = matrix[0][i];
        int max = matrix[0][i];
        for (int j = 0; j < 5; j++)
        {
            if (min > matrix[j][i])
            {
                min = matrix[j][i];
            }
            if (max < matrix[j][i])
            {
                max = matrix[j][i];
            }
        }
        minElems[i] = min;
        maxElems[i] = max;
    }
    cout << "Max elems in cols: ";
    for (int i = 0; i < 5; i++)
    {
        cout << maxElems[i] << " ";
    }
    cout << endl;
    cout << "Min elems in cols: ";
    for (int i = 0; i < 5; i++)
    {
        cout << minElems[i] << " ";
    }
    cout << endl;
    delete[] minElems;
    delete[] maxElems;
}

void func3_4(int **matrix)
{
    int *minElems = new int[5];
    int *maxElems = new int[5];
    for (int i = 0; i < 5; i++)
    {
        int min = matrix[i][0];
        int max = matrix[i][0];
        for (int j = 0; j < 5; j++)
        {
            if (min > matrix[i][j])
            {
                min = matrix[i][j];
            }
            if (max < matrix[i][j])
            {
                max = matrix[i][j];
            }
        }
        minElems[i] = min;
        maxElems[i] = max;
    }
    cout << "Max elems in rows: ";
    for (int i = 0; i < 5; i++)
    {
        cout << maxElems[i] << " ";
    }
    cout << endl;
    cout << "Min elems in rows: ";
    for (int i = 0; i < 5; i++)
    {
        cout << minElems[i] << " ";
    }
    cout << endl;
    delete[] minElems;
    delete[] maxElems;
}

void func5(int **matrix)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    srand(time(nullptr));
    int **matrix = new int *[5];

    for (int i = 0; i < 5; i++)
    {
        matrix[i] = new int[5];
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> matrix[i][j];
        }
    }
    cout << endl;
    cout << endl;
    func1_2(matrix);
    func3_4(matrix);
    cout << endl;
    for (int i = 4; i >= 0; i--)
    {
        for (int j = 4; j >= 0; j--)
        {
            cout << matrix[j][i] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 4; i >= 0; i--)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << matrix[j][i] << " ";
        }
        cout << endl;
    }
    cout << endl;
    func5(matrix);
    cout << endl;
    int rotated[5][5];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            rotated[j][5 - 1 - i] = matrix[i][j];
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    delete[] matrix;

    //-----------------------------------------------------------------

    cout << "\n-----------Sorting-------------" << endl;
    const int size = 10;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 20;
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    //--------------------------------

    cout << "\nSelection sort: ";
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[i])
            {
                swap(arr[j], arr[i]);
            }
        }
    }

    //--------------------------------

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    //--------------------------------

    cout << "\nBubble sort: ";
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = size - 1; j > i; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(arr[j], arr[j - 1]);
            }
        }
    }

    //--------------------------------

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    //--------------------------------

    cout << "\nInsertion sort: ";
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j;
        for (j = i - 1; j >= 0 && arr[j] > key; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
    }

    //--------------------------------

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}